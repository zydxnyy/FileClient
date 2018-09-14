/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer;
    QLabel *emal_label;
    QLineEdit *email_edit;
    QLabel *password_label;
    QLineEdit *password_edit;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *login_btn;
    QCheckBox *checkBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        formLayoutWidget = new QWidget(Dialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 30, 341, 221));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer);

        emal_label = new QLabel(formLayoutWidget);
        emal_label->setObjectName(QStringLiteral("emal_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, emal_label);

        email_edit = new QLineEdit(formLayoutWidget);
        email_edit->setObjectName(QStringLiteral("email_edit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, email_edit);

        password_label = new QLabel(formLayoutWidget);
        password_label->setObjectName(QStringLiteral("password_label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, password_label);

        password_edit = new QLineEdit(formLayoutWidget);
        password_edit->setObjectName(QStringLiteral("password_edit"));
        password_edit->setEchoMode(QLineEdit::Password);
        password_edit->setClearButtonEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, password_edit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::FieldRole, verticalSpacer_3);

        login_btn = new QPushButton(formLayoutWidget);
        login_btn->setObjectName(QStringLiteral("login_btn"));

        formLayout->setWidget(6, QFormLayout::SpanningRole, login_btn);

        checkBox = new QCheckBox(formLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        formLayout->setWidget(5, QFormLayout::LabelRole, checkBox);


        retranslateUi(Dialog);
        QObject::connect(login_btn, SIGNAL(clicked()), Dialog, SLOT(login_slot()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\347\231\273\351\231\206", nullptr));
        emal_label->setText(QApplication::translate("Dialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        email_edit->setPlaceholderText(QString());
        password_label->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        password_edit->setPlaceholderText(QString());
        login_btn->setText(QApplication::translate("Dialog", "\347\231\273\351\231\206", nullptr));
        checkBox->setText(QApplication::translate("Dialog", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
