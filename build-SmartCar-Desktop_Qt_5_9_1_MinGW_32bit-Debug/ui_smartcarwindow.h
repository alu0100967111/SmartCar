/********************************************************************************
** Form generated from reading UI file 'smartcarwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTCARWINDOW_H
#define UI_SMARTCARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmartCarWindow
{
public:
    QWidget *SmartCarWidget;

    void setupUi(QMainWindow *SmartCarWindow)
    {
        if (SmartCarWindow->objectName().isEmpty())
            SmartCarWindow->setObjectName(QStringLiteral("SmartCarWindow"));
        SmartCarWindow->resize(760, 600);
        SmartCarWidget = new QWidget(SmartCarWindow);
        SmartCarWidget->setObjectName(QStringLiteral("SmartCarWidget"));
        SmartCarWidget->setSizeIncrement(QSize(1, 1));
        SmartCarWindow->setCentralWidget(SmartCarWidget);

        retranslateUi(SmartCarWindow);

        QMetaObject::connectSlotsByName(SmartCarWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SmartCarWindow)
    {
        SmartCarWindow->setWindowTitle(QApplication::translate("SmartCarWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SmartCarWindow: public Ui_SmartCarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTCARWINDOW_H
