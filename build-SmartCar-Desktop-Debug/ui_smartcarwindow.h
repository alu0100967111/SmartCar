/********************************************************************************
** Form generated from reading UI file 'smartcarwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTCARWINDOW_H
#define UI_SMARTCARWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmartCarWindow
{
public:
    QWidget *SmartCarWidget;

    void setupUi(QMainWindow *SmartCarWindow)
    {
        if (SmartCarWindow->objectName().isEmpty())
            SmartCarWindow->setObjectName(QString::fromUtf8("SmartCarWindow"));
        SmartCarWindow->resize(760, 600);
        SmartCarWidget = new QWidget(SmartCarWindow);
        SmartCarWidget->setObjectName(QString::fromUtf8("SmartCarWidget"));
        SmartCarWidget->setSizeIncrement(QSize(1, 1));
        SmartCarWindow->setCentralWidget(SmartCarWidget);

        retranslateUi(SmartCarWindow);

        QMetaObject::connectSlotsByName(SmartCarWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SmartCarWindow)
    {
        SmartCarWindow->setWindowTitle(QApplication::translate("SmartCarWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SmartCarWindow: public Ui_SmartCarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTCARWINDOW_H
