/********************************************************************************
** Form generated from reading UI file 'UploadWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADWIDGET_H
#define UI_UPLOADWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadWidget
{
public:
    QPushButton *uploadBtn;
    QPushButton *downloadBtn;

    void setupUi(QWidget *UploadWidget)
    {
        if (UploadWidget->objectName().isEmpty())
            UploadWidget->setObjectName(QStringLiteral("UploadWidget"));
        UploadWidget->resize(1190, 550);
        UploadWidget->setMinimumSize(QSize(1190, 550));
        UploadWidget->setMaximumSize(QSize(1190, 550));
        uploadBtn = new QPushButton(UploadWidget);
        uploadBtn->setObjectName(QStringLiteral("uploadBtn"));
        uploadBtn->setGeometry(QRect(540, 240, 80, 28));
        downloadBtn = new QPushButton(UploadWidget);
        downloadBtn->setObjectName(QStringLiteral("downloadBtn"));
        downloadBtn->setGeometry(QRect(540, 280, 80, 28));

        retranslateUi(UploadWidget);
        QObject::connect(uploadBtn, SIGNAL(clicked()), UploadWidget, SLOT(uploadSlot()));
        QObject::connect(downloadBtn, SIGNAL(clicked()), UploadWidget, SLOT(downloadSlot()));

        QMetaObject::connectSlotsByName(UploadWidget);
    } // setupUi

    void retranslateUi(QWidget *UploadWidget)
    {
        UploadWidget->setWindowTitle(QApplication::translate("UploadWidget", "Form", nullptr));
        uploadBtn->setText(QString());
        downloadBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UploadWidget: public Ui_UploadWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADWIDGET_H
