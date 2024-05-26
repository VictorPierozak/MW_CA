#include "mainwindow.h"
#include"../inc/postproc.hpp"
#include "./ui_mainwindow.h"

#include<thread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->result->setScene(&m_scene);

    ui->current->setEnabled(false);
    ui->remove_grain->setEnabled(false);
    ui->reverse_grain->setEnabled(true);

    connect(ui->start, &QPushButton::clicked, this, &MainWindow::OnStartClick);
    connect(ui->current, &QCheckBox::stateChanged, this, &MainWindow::OnCurrentChecked);
    connect(ui->remove_grain, &QPushButton::clicked, this, &MainWindow::OnRemoveGrainClick);
    connect(ui->reverse_grain, &QPushButton::clicked, this, &MainWindow::OnReverseClick);
    connect(ui->decreaseZ, &QPushButton::clicked, this, &MainWindow::OnDecreaseZClick);
    connect(ui->increaseZ, &QPushButton::clicked, this, &MainWindow::OnIncreaseZClick);
}

void MainWindow::OnStartClick()
{
    int dimX = ui->dimX->toPlainText().toInt();
    int dimY = ui->dimY->toPlainText().toInt();
    int dimZ = ui->dimZ->toPlainText().toInt();
    int iterations = ui->iterations->toPlainText().toInt();
    int grainsnumber = ui->grain_number->toPlainText().toInt();
    QString generator_type = ui->generator->currentText();
    QString nucleation_type = ui->nucleation->currentText();
    QString neighbourhood_type = ui->neighbourhood->currentText();
    QString bc = ui->bc->currentText();

    if(ui->current->isChecked() == false)
    {
        m_manager = std::make_shared<GenerationManager>(dimX, dimY, dimZ, iterations);
        if(nucleation_type == Nucleation_Random)
        {
            m_manager->setNucleator(std::shared_ptr<Nucleator>(new RandomUniformNucleator(grainsnumber)));
        }
        else if(nucleation_type == Nucleation_Uniform)
        {
            m_manager->setNucleator(std::shared_ptr<Nucleator>(new UniformNucleator2D(grainsnumber)));
        }
    }


    if(neighbourhood_type == N_Moore)
    {
        m_manager->setNeighbourhood(std::shared_ptr<Neighbourhood>(new Moore));
    }
    else if(neighbourhood_type == N_Neumann)
    {
        m_manager->setNeighbourhood(std::shared_ptr<Neighbourhood>(new Neumann));
    }

    if(bc == L_Periodic)
    {
        m_manager->setBC(std::shared_ptr<BC>(new Periodic(dimX, dimY, dimZ)));
    }
    else if(bc == L_Absorption)
    {
        m_manager->setBC(std::shared_ptr<BC>(new Absorption(dimX, dimY, dimZ)));
    }

    int threads_number = 1;

    if(ui->multithreading->isChecked()) threads_number = std::thread::hardware_concurrency();

    m_manager->setThreadsNumber(threads_number);

    if(generator_type == L_CA)
    {
        m_manager->setRule(std::shared_ptr<Rule>(new MostNumerous));
        m_manager->startCA();
    }
    else if(generator_type == L_MC)
    {
        m_manager->setRule(std::shared_ptr<Rule>(new MC));
        m_manager->startMC();
    }

    ui->current->setEnabled(true);
    ui->remove_grain->setEnabled(true);
    ui->reverse_grain->setEnabled(true);
    updateResults();
    loadImage();
}

void MainWindow::updateResults()
{
    toBmp(m_manager->domain(), m_manager->stateNumber(), L_Res_Path.toStdString(), m_colors);
    m_z = 0;
}

void MainWindow::OnCurrentChecked(int n)
{
    if(n == Qt::Unchecked)
    {
        ui->nucleation->setEnabled(true);
        ui->grain_number->setEnabled(true);
        ui->dimX->setEnabled(true);
        ui->dimY->setEnabled(true);
        ui->dimZ->setEnabled(true);
    }
    else
    {
        ui->nucleation->setEnabled(false);
        ui->dimX->setEnabled(false);
        ui->dimY->setEnabled(false);
        ui->dimZ->setEnabled(false);
        ui->grain_number->setEnabled(false);
    }
}

void MainWindow::OnReverseClick()
{
    int newState = m_manager->stateNumber() + 1;
    m_manager->domain().for_each([newState](m_int& cc){if(cc == Domain::Void) cc = 1; else cc = Domain::Void; });
    updateResults();
    loadImage();
}

void MainWindow::OnRemoveGrainClick()
{
    int id = ui->remove_id->toPlainText().toInt();
    removeState(m_manager->domain(), id);
    updateResults();
    loadImage();
}

void MainWindow::OnExportClick()
{
    toTxt(m_manager->domain(), L_Res_Path.toStdString());
}
void MainWindow::OnIncreaseZClick()
{
    m_z++;
    if(m_z >= m_manager->domain().dimZ()) m_z = 0;
    loadImage();
}

void MainWindow::OnDecreaseZClick()
{
    m_z--;
    if(m_z < 0) m_z =  m_manager->domain().dimZ()-1;
    loadImage();
}

void MainWindow::loadImage()
{
    m_scene.clear();

    ui->z_layer->display(m_z);

    m_pixmap.load(L_Res_Path + L_Image_Name + L_Separator + QString::number(m_z) +".bmp");

    if(ui->result->width() / m_pixmap.width() < ui->result->height() / m_pixmap.height())
        m_pixmap = m_pixmap.scaledToWidth(ui->result->width()*0.9);
    else
        m_pixmap = m_pixmap.scaledToHeight(ui->result->height()*0.9);

    m_scene.addPixmap(m_pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

