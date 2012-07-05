/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 5. Jul 19:40:05 2012
**      by: Qt User Interface Compiler version 4.8.0
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
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *guessPushButton;
    QLabel *guessLabel;
    QSpinBox *guessSelect;
    QLabel *handLabel;
    QSpinBox *handSelect;
    QLabel *indexLabel;
    QTableWidget *playersTableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(528, 243);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        guessPushButton = new QPushButton(centralWidget);
        guessPushButton->setObjectName(QString::fromUtf8("guessPushButton"));
        guessPushButton->setGeometry(QRect(420, 138, 81, 51));
        guessLabel = new QLabel(centralWidget);
        guessLabel->setObjectName(QString::fromUtf8("guessLabel"));
        guessLabel->setGeometry(QRect(10, 138, 121, 21));
        guessSelect = new QSpinBox(centralWidget);
        guessSelect->setObjectName(QString::fromUtf8("guessSelect"));
        guessSelect->setGeometry(QRect(60, 138, 42, 22));
        handLabel = new QLabel(centralWidget);
        handLabel->setObjectName(QString::fromUtf8("handLabel"));
        handLabel->setGeometry(QRect(170, 141, 46, 20));
        handSelect = new QSpinBox(centralWidget);
        handSelect->setObjectName(QString::fromUtf8("handSelect"));
        handSelect->setGeometry(QRect(210, 138, 42, 22));
        handSelect->setMaximum(3);
        indexLabel = new QLabel(centralWidget);
        indexLabel->setObjectName(QString::fromUtf8("indexLabel"));
        indexLabel->setGeometry(QRect(10, 170, 111, 21));
        playersTableWidget = new QTableWidget(centralWidget);
        if (playersTableWidget->columnCount() < 5)
            playersTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        playersTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        playersTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        playersTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        playersTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        playersTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        playersTableWidget->setObjectName(QString::fromUtf8("playersTableWidget"));
        playersTableWidget->setGeometry(QRect(10, 0, 511, 121));
        playersTableWidget->setColumnCount(5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 528, 21));
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
        QTableWidgetItem *___qtablewidgetitem = playersTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "n\302\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = playersTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Nome", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = playersTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "M\303\243o", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = playersTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Palpite", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = playersTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Vit\303\263rias", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
