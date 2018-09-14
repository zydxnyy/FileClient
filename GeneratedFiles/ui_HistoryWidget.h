/********************************************************************************
** Form generated from reading UI file 'HistoryWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYWIDGET_H
#define UI_HISTORYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryWidget
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *HistoryWidget)
    {
        if (HistoryWidget->objectName().isEmpty())
            HistoryWidget->setObjectName(QStringLiteral("HistoryWidget"));
        HistoryWidget->resize(1190, 550);
        textEdit = new QTextEdit(HistoryWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 1151, 511));
        textEdit->setReadOnly(true);

        retranslateUi(HistoryWidget);

        QMetaObject::connectSlotsByName(HistoryWidget);
    } // setupUi

    void retranslateUi(QWidget *HistoryWidget)
    {
        HistoryWidget->setWindowTitle(QApplication::translate("HistoryWidget", "\345\216\206\345\217\262\347\272\252\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HistoryWidget: public Ui_HistoryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWIDGET_H
