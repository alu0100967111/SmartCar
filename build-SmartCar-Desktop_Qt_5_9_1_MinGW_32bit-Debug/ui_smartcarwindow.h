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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SmartCarWindow
{
public:
    QGridLayout *gridLayout;

    void setupUi(QDialog *SmartCarWindow)
    {
        if (SmartCarWindow->objectName().isEmpty())
            SmartCarWindow->setObjectName(QStringLiteral("SmartCarWindow"));
        SmartCarWindow->resize(400, 300);
        SmartCarWindow->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(SmartCarWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        retranslateUi(SmartCarWindow);

        QMetaObject::connectSlotsByName(SmartCarWindow);
    } // setupUi

    void retranslateUi(QDialog *SmartCarWindow)
    {
        SmartCarWindow->setWindowTitle(QApplication::translate("SmartCarWindow", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SmartCarWindow: public Ui_SmartCarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTCARWINDOW_H
