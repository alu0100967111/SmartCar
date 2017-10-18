/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(497, 243);
        MainWindow->setWindowOpacity(1);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionAyuda = new QAction(MainWindow);
        actionAyuda->setObjectName(QStringLiteral("actionAyuda"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setEnabled(true);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(491, 151));

        verticalLayout->addWidget(label);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        inputfilas = new QLineEdit(groupBox);
        inputfilas->setObjectName(QStringLiteral("inputfilas"));

        verticalLayout_3->addWidget(inputfilas);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        inputcol = new QLineEdit(groupBox);
        inputcol->setObjectName(QStringLiteral("inputcol"));

        verticalLayout_4->addWidget(inputcol);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        inputobs = new QLineEdit(groupBox);
        inputobs->setObjectName(QStringLiteral("inputobs"));

        verticalLayout_5->addWidget(inputobs);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout);

        simular = new QPushButton(groupBox);
        simular->setObjectName(QStringLiteral("simular"));

        verticalLayout_6->addWidget(simular);


        gridLayout_2->addLayout(verticalLayout_6, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filas = new QLabel(groupBox);
        filas->setObjectName(QStringLiteral("filas"));

        horizontalLayout_2->addWidget(filas);

        columnas = new QLabel(groupBox);
        columnas->setObjectName(QStringLiteral("columnas"));

        horizontalLayout_2->addWidget(columnas);

        obstaculos = new QLabel(groupBox);
        obstaculos->setObjectName(QStringLiteral("obstaculos"));

        horizontalLayout_2->addWidget(obstaculos);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 497, 21));
        menuHola = new QMenu(menuBar);
        menuHola->setObjectName(QStringLiteral("menuHola"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simulador", Q_NULLPTR));
        actionAyuda->setText(QApplication::translate("MainWindow", "A cerca de", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Bienvenido al simulador de coche aut\303\263nomo</span></p></body></html>", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Configuraci\303\263n", Q_NULLPTR));
        simular->setText(QApplication::translate("MainWindow", "Simular", Q_NULLPTR));
        filas->setText(QApplication::translate("MainWindow", "Filas", Q_NULLPTR));
        columnas->setText(QApplication::translate("MainWindow", "Columnas", Q_NULLPTR));
        obstaculos->setText(QApplication::translate("MainWindow", "Obst\303\241culos", Q_NULLPTR));
        menuHola->setTitle(QApplication::translate("MainWindow", "Ayuda", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
