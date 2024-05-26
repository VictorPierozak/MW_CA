/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *dimX;
    QTextEdit *dimY;
    QTextEdit *dimZ;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *iterations;
    QLabel *label_4;
    QComboBox *generator;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *neighbourhood;
    QLabel *label_7;
    QComboBox *nucleation;
    QPushButton *start;
    QCheckBox *current;
    QPushButton *reverse_grain;
    QTextEdit *remove_id;
    QPushButton *remove_grain;
    QTextEdit *grain_number;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *bc;
    QCheckBox *multithreading;
    QGraphicsView *result;
    QPushButton *decreaseZ;
    QPushButton *increaseZ;
    QLCDNumber *z_layer;
    QPushButton *export_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        dimX = new QTextEdit(centralwidget);
        dimX->setObjectName(QString::fromUtf8("dimX"));
        dimX->setGeometry(QRect(160, 10, 161, 31));
        dimY = new QTextEdit(centralwidget);
        dimY->setObjectName(QString::fromUtf8("dimY"));
        dimY->setGeometry(QRect(160, 50, 161, 31));
        dimZ = new QTextEdit(centralwidget);
        dimZ->setObjectName(QString::fromUtf8("dimZ"));
        dimZ->setGeometry(QRect(160, 90, 161, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 66, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 66, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 66, 17));
        iterations = new QTextEdit(centralwidget);
        iterations->setObjectName(QString::fromUtf8("iterations"));
        iterations->setGeometry(QRect(160, 130, 161, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 151, 17));
        generator = new QComboBox(centralwidget);
        generator->addItem(QString());
        generator->addItem(QString());
        generator->setObjectName(QString::fromUtf8("generator"));
        generator->setGeometry(QRect(160, 240, 86, 25));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 250, 111, 17));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 280, 151, 17));
        neighbourhood = new QComboBox(centralwidget);
        neighbourhood->addItem(QString());
        neighbourhood->addItem(QString());
        neighbourhood->addItem(QString());
        neighbourhood->setObjectName(QString::fromUtf8("neighbourhood"));
        neighbourhood->setGeometry(QRect(160, 270, 86, 25));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 310, 131, 17));
        nucleation = new QComboBox(centralwidget);
        nucleation->addItem(QString());
        nucleation->addItem(QString());
        nucleation->setObjectName(QString::fromUtf8("nucleation"));
        nucleation->setGeometry(QRect(160, 300, 86, 25));
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(80, 400, 141, 25));
        current = new QCheckBox(centralwidget);
        current->setObjectName(QString::fromUtf8("current"));
        current->setGeometry(QRect(10, 340, 211, 23));
        reverse_grain = new QPushButton(centralwidget);
        reverse_grain->setObjectName(QString::fromUtf8("reverse_grain"));
        reverse_grain->setGeometry(QRect(10, 510, 221, 25));
        remove_id = new QTextEdit(centralwidget);
        remove_id->setObjectName(QString::fromUtf8("remove_id"));
        remove_id->setGeometry(QRect(170, 470, 61, 31));
        remove_grain = new QPushButton(centralwidget);
        remove_grain->setObjectName(QString::fromUtf8("remove_grain"));
        remove_grain->setGeometry(QRect(10, 470, 151, 25));
        grain_number = new QTextEdit(centralwidget);
        grain_number->setObjectName(QString::fromUtf8("grain_number"));
        grain_number->setGeometry(QRect(160, 170, 161, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 180, 151, 17));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 220, 131, 17));
        bc = new QComboBox(centralwidget);
        bc->addItem(QString());
        bc->addItem(QString());
        bc->setObjectName(QString::fromUtf8("bc"));
        bc->setGeometry(QRect(160, 210, 86, 25));
        multithreading = new QCheckBox(centralwidget);
        multithreading->setObjectName(QString::fromUtf8("multithreading"));
        multithreading->setGeometry(QRect(10, 370, 151, 23));
        result = new QGraphicsView(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(370, 10, 401, 411));
        decreaseZ = new QPushButton(centralwidget);
        decreaseZ->setObjectName(QString::fromUtf8("decreaseZ"));
        decreaseZ->setGeometry(QRect(370, 430, 111, 25));
        increaseZ = new QPushButton(centralwidget);
        increaseZ->setObjectName(QString::fromUtf8("increaseZ"));
        increaseZ->setGeometry(QRect(660, 430, 111, 25));
        z_layer = new QLCDNumber(centralwidget);
        z_layer->setObjectName(QString::fromUtf8("z_layer"));
        z_layer->setGeometry(QRect(530, 430, 91, 23));
        export_2 = new QPushButton(centralwidget);
        export_2->setObjectName(QString::fromUtf8("export_2"));
        export_2->setGeometry(QRect(370, 510, 401, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(start, SIGNAL(clicked()), MainWindow, SLOT(OnStartClick()));
        QObject::connect(current, SIGNAL(stateChanged(int)), MainWindow, SLOT(OnCurrentChecked(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "DIM X", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "DIM Y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "DIM Z", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Number of iterations", nullptr));
        generator->setItemText(0, QCoreApplication::translate("MainWindow", "CA", nullptr));
        generator->setItemText(1, QCoreApplication::translate("MainWindow", "MC", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Generator type", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Neighbourhood type", nullptr));
        neighbourhood->setItemText(0, QCoreApplication::translate("MainWindow", "Moore", nullptr));
        neighbourhood->setItemText(1, QCoreApplication::translate("MainWindow", "Neumann", nullptr));
        neighbourhood->setItemText(2, QCoreApplication::translate("MainWindow", "Random", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "Nucleation", nullptr));
        nucleation->setItemText(0, QCoreApplication::translate("MainWindow", "Random", nullptr));
        nucleation->setItemText(1, QCoreApplication::translate("MainWindow", "Uniform", nullptr));

        start->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        current->setText(QCoreApplication::translate("MainWindow", "Use current microstructure", nullptr));
        reverse_grain->setText(QCoreApplication::translate("MainWindow", "Reverse grains/pourus", nullptr));
        remove_grain->setText(QCoreApplication::translate("MainWindow", "Remove grain (ID)", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Number of grains", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Boundry Condition", nullptr));
        bc->setItemText(0, QCoreApplication::translate("MainWindow", "Periodic", nullptr));
        bc->setItemText(1, QCoreApplication::translate("MainWindow", "Absorption", nullptr));

        multithreading->setText(QCoreApplication::translate("MainWindow", "Multithreading", nullptr));
        decreaseZ->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        increaseZ->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        export_2->setText(QCoreApplication::translate("MainWindow", "Export to txt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
