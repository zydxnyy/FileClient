/********************************************************************************
** Form generated from reading UI file 'TaskItem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKITEM_H
#define UI_TASKITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskItemWidget
{
public:
    QProgressBar *progressBar;
    QLabel *filenameLabel;
    QLabel *iconLabel;
    QLabel *elapsedTimelabel;
    QLabel *remainTimeLabel;
    QPushButton *pauseBtn;
    QPushButton *stopBtn;
    QLabel *speedLabel;

    void setupUi(QWidget *TaskItemWidget)
    {
        if (TaskItemWidget->objectName().isEmpty())
            TaskItemWidget->setObjectName(QStringLiteral("TaskItemWidget"));
        TaskItemWidget->resize(1096, 68);
        progressBar = new QProgressBar(TaskItemWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(60, 30, 391, 31));
        progressBar->setValue(0);
        progressBar->setInvertedAppearance(false);
        filenameLabel = new QLabel(TaskItemWidget);
        filenameLabel->setObjectName(QStringLiteral("filenameLabel"));
        filenameLabel->setGeometry(QRect(60, 5, 440, 16));
        iconLabel = new QLabel(TaskItemWidget);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));
        iconLabel->setGeometry(QRect(10, 30, 31, 31));
        elapsedTimelabel = new QLabel(TaskItemWidget);
        elapsedTimelabel->setObjectName(QStringLiteral("elapsedTimelabel"));
        elapsedTimelabel->setGeometry(QRect(670, 20, 121, 21));
        remainTimeLabel = new QLabel(TaskItemWidget);
        remainTimeLabel->setObjectName(QStringLiteral("remainTimeLabel"));
        remainTimeLabel->setGeometry(QRect(830, 20, 121, 21));
        pauseBtn = new QPushButton(TaskItemWidget);
        pauseBtn->setObjectName(QStringLiteral("pauseBtn"));
        pauseBtn->setGeometry(QRect(990, 20, 31, 28));
        stopBtn = new QPushButton(TaskItemWidget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setGeometry(QRect(1050, 20, 31, 28));
        speedLabel = new QLabel(TaskItemWidget);
        speedLabel->setObjectName(QStringLiteral("speedLabel"));
        speedLabel->setGeometry(QRect(530, 20, 141, 21));

        retranslateUi(TaskItemWidget);
        QObject::connect(pauseBtn, SIGNAL(clicked()), TaskItemWidget, SLOT(toggleSlot()));
        QObject::connect(stopBtn, SIGNAL(clicked()), TaskItemWidget, SLOT(stopSlot()));

        QMetaObject::connectSlotsByName(TaskItemWidget);
    } // setupUi

    void retranslateUi(QWidget *TaskItemWidget)
    {
        TaskItemWidget->setWindowTitle(QApplication::translate("TaskItemWidget", "Form", nullptr));
        filenameLabel->setText(QApplication::translate("TaskItemWidget", "filename:size", nullptr));
        iconLabel->setText(QApplication::translate("TaskItemWidget", "Icon", nullptr));
        elapsedTimelabel->setText(QApplication::translate("TaskItemWidget", "elapsed time", nullptr));
        remainTimeLabel->setText(QApplication::translate("TaskItemWidget", "remained time", nullptr));
        pauseBtn->setText(QString());
        stopBtn->setText(QString());
        speedLabel->setText(QApplication::translate("TaskItemWidget", "speed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskItemWidget: public Ui_TaskItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKITEM_H
