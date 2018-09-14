/********************************************************************************
** Form generated from reading UI file 'MyExplorer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYEXPLORER_H
#define UI_MYEXPLORER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mylistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MyExplorer
{
public:
    QPushButton *prevBtn;
    QPushButton *nextBtn;
    QPushButton *outBtn;
    MyListwidget *listWidget;
    QLineEdit *pathEdit;

    void setupUi(QWidget *MyExplorer)
    {
        if (MyExplorer->objectName().isEmpty())
            MyExplorer->setObjectName(QStringLiteral("MyExplorer"));
        MyExplorer->resize(530, 540);
        MyExplorer->setAcceptDrops(true);
        prevBtn = new QPushButton(MyExplorer);
        prevBtn->setObjectName(QStringLiteral("prevBtn"));
        prevBtn->setGeometry(QRect(10, 100, 70, 31));
        nextBtn = new QPushButton(MyExplorer);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));
        nextBtn->setGeometry(QRect(90, 100, 71, 31));
        outBtn = new QPushButton(MyExplorer);
        outBtn->setObjectName(QStringLiteral("outBtn"));
        outBtn->setGeometry(QRect(170, 100, 81, 31));
        listWidget = new MyListwidget(MyExplorer);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 140, 511, 391));
        listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget->setAcceptDrops(true);
        listWidget->setProperty("showDropIndicator", QVariant(false));
        listWidget->setDragEnabled(true);
        listWidget->setDragDropOverwriteMode(false);
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        pathEdit = new QLineEdit(MyExplorer);
        pathEdit->setObjectName(QStringLiteral("pathEdit"));
        pathEdit->setEnabled(true);
        pathEdit->setGeometry(QRect(10, 70, 511, 25));
        pathEdit->setReadOnly(true);
        pathEdit->setClearButtonEnabled(true);

        retranslateUi(MyExplorer);
        QObject::connect(prevBtn, SIGNAL(clicked()), MyExplorer, SLOT(previous()));
        QObject::connect(nextBtn, SIGNAL(clicked()), MyExplorer, SLOT(next()));
        QObject::connect(outBtn, SIGNAL(clicked()), MyExplorer, SLOT(outDir()));
        QObject::connect(listWidget, SIGNAL(doubleClicked(QModelIndex)), MyExplorer, SLOT(enterDirSlot(QModelIndex)));
        QObject::connect(listWidget, SIGNAL(customContextMenuRequested(QPoint)), MyExplorer, SLOT(menu(QPoint)));

        QMetaObject::connectSlotsByName(MyExplorer);
    } // setupUi

    void retranslateUi(QWidget *MyExplorer)
    {
        MyExplorer->setWindowTitle(QApplication::translate("MyExplorer", "Form", nullptr));
        prevBtn->setText(QApplication::translate("MyExplorer", "\345\220\216\351\200\200", nullptr));
        nextBtn->setText(QApplication::translate("MyExplorer", "\345\211\215\350\277\233", nullptr));
        outBtn->setText(QApplication::translate("MyExplorer", "\344\270\212\344\270\200\347\272\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyExplorer: public Ui_MyExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYEXPLORER_H
