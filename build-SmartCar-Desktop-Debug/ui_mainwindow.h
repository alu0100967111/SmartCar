/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAyuda;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *inputfilas;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *inputcol;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *inputobs;
    QPushButton *simular;
    QHBoxLayout *horizontalLayout_2;
    QLabel *filas;
    QLabel *columnas;
    QLabel *obstaculos;
    QMenuBar *menuBar;
    QMenu *menuHola;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(497, 243);
        MainWindow->setWindowOpacity(1);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionAyuda = new QAction(MainWindow);
        actionAyuda->setObjectName(QString::fromUtf8("actionAyuda"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setEnabled(true);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(491, 151));

        verticalLayout->addWidget(label);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        inputfilas = new QLineEdit(groupBox);
        inputfilas->setObjectName(QString::fromUtf8("inputfilas"));

        verticalLayout_3->addWidget(inputfilas);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        inputcol = new QLineEdit(groupBox);
        inputcol->setObjectName(QString::fromUtf8("inputcol"));

        verticalLayout_4->addWidget(inputcol);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        inputobs = new QLineEdit(groupBox);
        inputobs->setObjectName(QString::fromUtf8("inputobs"));

        verticalLayout_5->addWidget(inputobs);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout);

        simular = new QPushButton(groupBox);
        simular->setObjectName(QString::fromUtf8("simular"));

        verticalLayout_6->addWidget(simular);


        gridLayout_2->addLayout(verticalLayout_6, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        filas = new QLabel(groupBox);
        filas->setObjectName(QString::fromUtf8("filas"));

        horizontalLayout_2->addWidget(filas);

        columnas = new QLabel(groupBox);
        columnas->setObjectName(QString::fromUtf8("columnas"));

        horizontalLayout_2->addWidget(columnas);

        obstaculos = new QLabel(groupBox);
        obstaculos->setObjectName(QString::fromUtf8("obstaculos"));

        horizontalLayout_2->addWidget(obstaculos);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 497, 21));
        menuHola = new QMenu(menuBar);
        menuHola->setObjectName(QString::fromUtf8("menuHola"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuHola->menuAction());
        menuHola->addAction(actionAyuda);

        retranslateUi(MainWindow);
        QObject::connect(inputcol, SIGNAL(returnPressed()), simular, SLOT(click()));
        QObject::connect(inputfilas, SIGNAL(returnPressed()), simular, SLOT(click()));
        QObject::connect(inputobs, SIGNAL(returnPressed()), simular, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simulador", 0, QApplication::UnicodeUTF8));
        actionAyuda->setText(QApplication::translate("MainWindow", "A cerca de", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Bienvenido al simulador de coche aut\303\263nomo</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Configuraci\303\263n", 0, QApplication::UnicodeUTF8));
        simular->setText(QApplication::translate("MainWindow", "Simular", 0, QApplication::UnicodeUTF8));
        filas->setText(QApplication::translate("MainWindow", "Filas", 0, QApplication::UnicodeUTF8));
        columnas->setText(QApplication::translate("MainWindow", "Columnas", 0, QApplication::UnicodeUTF8));
        obstaculos->setText(QApplication::translate("MainWindow", "Obst\303\241culos", 0, QApplication::UnicodeUTF8));
        menuHola->setTitle(QApplication::translate("MainWindow", "Ayuda", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
