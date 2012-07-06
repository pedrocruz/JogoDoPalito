/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created: Thu 5. Jul 21:19:39 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDIALOG_H
#define UI_CONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConnectionDialog
{
public:
    QLineEdit *ipLineEdit;
    QLineEdit *portLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *okButton;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;

    void setupUi(QDialog *ConnectionDialog)
    {
        if (ConnectionDialog->objectName().isEmpty())
            ConnectionDialog->setObjectName(QString::fromUtf8("ConnectionDialog"));
        ConnectionDialog->resize(190, 234);
        ipLineEdit = new QLineEdit(ConnectionDialog);
        ipLineEdit->setObjectName(QString::fromUtf8("ipLineEdit"));
        ipLineEdit->setGeometry(QRect(10, 60, 171, 20));
        portLineEdit = new QLineEdit(ConnectionDialog);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(10, 110, 171, 20));
        label = new QLabel(ConnectionDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 211, 16));
        label_2 = new QLabel(ConnectionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 241, 16));
        label_3 = new QLabel(ConnectionDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 191, 16));
        okButton = new QPushButton(ConnectionDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(10, 200, 171, 23));
        nameLabel = new QLabel(ConnectionDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(10, 140, 141, 16));
        nameLineEdit = new QLineEdit(ConnectionDialog);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(10, 160, 171, 20));

        retranslateUi(ConnectionDialog);

        QMetaObject::connectSlotsByName(ConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDialog)
    {
        ConnectionDialog->setWindowTitle(QApplication::translate("ConnectionDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConnectionDialog", "Ip:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConnectionDialog", "Porta:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ConnectionDialog", "Qual o endere\303\247o a ser conectado?", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("ConnectionDialog", "Ok", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("ConnectionDialog", "Qual o seu nome?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDialog: public Ui_ConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
