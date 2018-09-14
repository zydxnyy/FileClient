/********************************************************************************
** Form generated from reading UI file 'FileProperty.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPROPERTY_H
#define UI_FILEPROPERTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilePropDialog
{
public:
    QPushButton *okButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer;
    QLabel *Label;
    QLineEdit *filenameEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *Label_2;
    QLineEdit *projnameEdit;
    QLabel *Label_3;
    QLineEdit *filesizeEdit;
    QLabel *Label_4;
    QLineEdit *createdEdit;
    QLabel *Label_5;
    QLineEdit *emailEdit;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QLabel *Label_6;
    QLineEdit *pathEdit;
    QLabel *label;
    QLineEdit *fileHashEdit;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QDialog *FilePropDialog)
    {
        if (FilePropDialog->objectName().isEmpty())
            FilePropDialog->setObjectName(QStringLiteral("FilePropDialog"));
        FilePropDialog->resize(400, 401);
        okButton = new QPushButton(FilePropDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(110, 360, 171, 28));
        formLayoutWidget = new QWidget(FilePropDialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 381, 341));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::FieldRole, verticalSpacer);

        Label = new QLabel(formLayoutWidget);
        Label->setObjectName(QStringLiteral("Label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Label);

        filenameEdit = new QLineEdit(formLayoutWidget);
        filenameEdit->setObjectName(QStringLiteral("filenameEdit"));
        filenameEdit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, filenameEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::FieldRole, verticalSpacer_2);

        Label_2 = new QLabel(formLayoutWidget);
        Label_2->setObjectName(QStringLiteral("Label_2"));

        formLayout->setWidget(5, QFormLayout::LabelRole, Label_2);

        projnameEdit = new QLineEdit(formLayoutWidget);
        projnameEdit->setObjectName(QStringLiteral("projnameEdit"));
        projnameEdit->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, projnameEdit);

        Label_3 = new QLabel(formLayoutWidget);
        Label_3->setObjectName(QStringLiteral("Label_3"));

        formLayout->setWidget(7, QFormLayout::LabelRole, Label_3);

        filesizeEdit = new QLineEdit(formLayoutWidget);
        filesizeEdit->setObjectName(QStringLiteral("filesizeEdit"));
        filesizeEdit->setReadOnly(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, filesizeEdit);

        Label_4 = new QLabel(formLayoutWidget);
        Label_4->setObjectName(QStringLiteral("Label_4"));

        formLayout->setWidget(9, QFormLayout::LabelRole, Label_4);

        createdEdit = new QLineEdit(formLayoutWidget);
        createdEdit->setObjectName(QStringLiteral("createdEdit"));
        createdEdit->setReadOnly(true);

        formLayout->setWidget(9, QFormLayout::FieldRole, createdEdit);

        Label_5 = new QLabel(formLayoutWidget);
        Label_5->setObjectName(QStringLiteral("Label_5"));

        formLayout->setWidget(11, QFormLayout::LabelRole, Label_5);

        emailEdit = new QLineEdit(formLayoutWidget);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));
        emailEdit->setReadOnly(true);

        formLayout->setWidget(11, QFormLayout::FieldRole, emailEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(6, QFormLayout::FieldRole, verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(8, QFormLayout::FieldRole, verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(10, QFormLayout::FieldRole, verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(12, QFormLayout::FieldRole, verticalSpacer_6);

        Label_6 = new QLabel(formLayoutWidget);
        Label_6->setObjectName(QStringLiteral("Label_6"));

        formLayout->setWidget(13, QFormLayout::LabelRole, Label_6);

        pathEdit = new QLineEdit(formLayoutWidget);
        pathEdit->setObjectName(QStringLiteral("pathEdit"));
        pathEdit->setReadOnly(true);

        formLayout->setWidget(13, QFormLayout::FieldRole, pathEdit);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(15, QFormLayout::LabelRole, label);

        fileHashEdit = new QLineEdit(formLayoutWidget);
        fileHashEdit->setObjectName(QStringLiteral("fileHashEdit"));
        fileHashEdit->setReadOnly(true);

        formLayout->setWidget(15, QFormLayout::FieldRole, fileHashEdit);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(14, QFormLayout::FieldRole, verticalSpacer_7);


        retranslateUi(FilePropDialog);
        QObject::connect(okButton, SIGNAL(clicked()), FilePropDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(FilePropDialog);
    } // setupUi

    void retranslateUi(QDialog *FilePropDialog)
    {
        FilePropDialog->setWindowTitle(QApplication::translate("FilePropDialog", "\346\226\207\344\273\266\345\261\236\346\200\247", nullptr));
        okButton->setText(QApplication::translate("FilePropDialog", "OK", nullptr));
        Label->setText(QApplication::translate("FilePropDialog", "\346\226\207\344\273\266\345\220\215:", nullptr));
        Label_2->setText(QApplication::translate("FilePropDialog", "\346\211\200\345\261\236\351\241\271\347\233\256:", nullptr));
        Label_3->setText(QApplication::translate("FilePropDialog", "\346\226\207\344\273\266\345\244\247\345\260\217:", nullptr));
        Label_4->setText(QApplication::translate("FilePropDialog", "\345\210\233\345\273\272\346\227\266\351\227\264:", nullptr));
        Label_5->setText(QApplication::translate("FilePropDialog", "\346\213\245\346\234\211\350\200\205:", nullptr));
        Label_6->setText(QApplication::translate("FilePropDialog", "\350\267\257\345\276\204:", nullptr));
        label->setText(QApplication::translate("FilePropDialog", "\346\226\207\344\273\266MD5:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilePropDialog: public Ui_FilePropDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPROPERTY_H
