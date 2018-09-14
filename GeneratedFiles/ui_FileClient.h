/********************************************************************************
** Form generated from reading UI file 'FileClient.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILECLIENT_H
#define UI_FILECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileClientClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FileClientClass)
    {
        if (FileClientClass->objectName().isEmpty())
            FileClientClass->setObjectName(QStringLiteral("FileClientClass"));
        FileClientClass->resize(1200, 650);
        FileClientClass->setMinimumSize(QSize(1200, 650));
        FileClientClass->setMaximumSize(QSize(1200, 650));
        centralWidget = new QWidget(FileClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 1190, 600));
        tabWidget->setMinimumSize(QSize(1190, 600));
        tabWidget->setMaximumSize(QSize(1190, 600));
        FileClientClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(FileClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FileClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FileClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FileClientClass->setStatusBar(statusBar);

        retranslateUi(FileClientClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(FileClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *FileClientClass)
    {
        FileClientClass->setWindowTitle(QApplication::translate("FileClientClass", "\346\226\207\344\273\266\344\274\240\350\276\223\345\256\242\346\210\267\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileClientClass: public Ui_FileClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILECLIENT_H
