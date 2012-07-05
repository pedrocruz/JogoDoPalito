/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 5. Jul 17:55:46 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QPushButton *guessPushButton;
    QLabel *guessLabel;
    QSpinBox *guessSelect;
    QLabel *handLabel;
    QSpinBox *handSelect;
    QLabel *indexLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(422, 319);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(5, 0, 411, 191));
        guessPushButton = new QPushButton(centralWidget);
        guessPushButton->setObjectName(QString::fromUtf8("guessPushButton"));
        guessPushButton->setGeometry(QRect(314, 200, 81, 51));
        guessLabel = new QLabel(centralWidget);
        guessLabel->setObjectName(QString::fromUtf8("guessLabel"));
        guessLabel->setGeometry(QRect(10, 200, 121, 21));
        guessSelect = new QSpinBox(centralWidget);
        guessSelect->setObjectName(QString::fromUtf8("guessSelect"));
        guessSelect->setGeometry(QRect(60, 200, 42, 22));
        handLabel = new QLabel(centralWidget);
        handLabel->setObjectName(QString::fromUtf8("handLabel"));
        handLabel->setGeometry(QRect(170, 203, 46, 20));
        handSelect = new QSpinBox(centralWidget);
        handSelect->setObjectName(QString::fromUtf8("handSelect"));
        handSelect->setGeometry(QRect(210, 200, 42, 22));
        indexLabel = new QLabel(centralWidget);
        indexLabel->setObjectName(QString::fromUtf8("indexLabel"));
        indexLabel->setGeometry(QRect(20, 232, 111, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 422, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        guessPushButton->setText(QApplication::translate("MainWindow", "Enviar palpite", 0, QApplication::UnicodeUTF8));
        guessLabel->setText(QApplication::translate("MainWindow", "Palpite", 0, QApplication::UnicodeUTF8));
        handLabel->setText(QApplication::translate("MainWindow", "M\303\243o", 0, QApplication::UnicodeUTF8));
        indexLabel->setText(QApplication::translate("MainWindow", "Seu \303\255ndice \303\251:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
