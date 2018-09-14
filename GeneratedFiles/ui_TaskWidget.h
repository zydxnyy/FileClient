/********************************************************************************
** Form generated from reading UI file 'TaskWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKWIDGET_H
#define UI_TASKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskWidget
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *TaskWidget)
    {
        if (TaskWidget->objectName().isEmpty())
            TaskWidget->setObjectName(QStringLiteral("TaskWidget"));
        TaskWidget->resize(1190, 550);
        listWidget = new QListWidget(TaskWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(19, 19, 1151, 511));

        retranslateUi(TaskWidget);

        QMetaObject::connectSlotsByName(TaskWidget);
    } // setupUi

    void retranslateUi(QWidget *TaskWidget)
    {
        TaskWidget->setWindowTitle(QApplication::translate("TaskWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskWidget: public Ui_TaskWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWIDGET_H
