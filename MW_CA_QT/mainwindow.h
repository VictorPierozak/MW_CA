#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include<QGraphicsScene>
#include<memory.h>
#include"../inc/postproc.hpp"
#include"../inc/GenerationManager.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void OnStartClick();
    void OnRemoveGrainClick();
    void OnReverseClick();
    void OnCurrentChecked(int n);
    void OnExportClick();
    void OnIncreaseZClick();
    void OnDecreaseZClick();
private:
    const QString L_CA = "CA";
    const QString L_MC = "MC";

    const QString Nucleation_Random = "Random";
    const QString Nucleation_Uniform = "Uniform";

    const QString N_Moore = "Moore";
    const QString N_Neumann = "Neumann";
    const QString N_Random = "Random";

    const QString L_Periodic = "Periodic";
    const QString L_Absorption = "Absorption";

    const QString L_Res_Path = "../res/";
    const QString L_Image_Name = "ms";
    const QString L_Separator = "_";

    QImage m_image;
    QPixmap m_pixmap;
    QGraphicsScene m_scene;

    QGraphicsPixmapItem m_graphic_item;
    int m_z;
    std::vector<color> m_colors;

    Ui::MainWindow *ui;
    std::shared_ptr<GenerationManager> m_manager;

    void loadImage();
    void updateResults();
};
#endif // MAINWINDOW_H
