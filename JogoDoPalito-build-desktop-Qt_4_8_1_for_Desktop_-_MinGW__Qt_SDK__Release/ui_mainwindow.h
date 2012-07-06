/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 6. Jul 11:10:12 2012
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
    QTableWidget *playersTableWidget;
    QLabel *winnersLabel;
    QLabel *nameLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(455, 371);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        guessPushButton = new QPushButton(centralWidget);
        guessPushButton->setObjectName(QString::fromUtf8("guessPushButton"));
        guessPushButton->setGeometry(QRect(270, 130, 171, 41));
        guessLabel = new QLabel(centralWidget);
        guessLabel->setObjectName(QString::fromUtf8("guessLabel"));
        guessLabel->setGeometry(QRect(140, 138, 121, 21));
        guessSelect = new QSpinBox(centralWidget);
        guessSelect->setObjectName(QString::fromUtf8("guessSelect"));
        guessSelect->setGeometry(QRect(190, 138, 42, 22));
        handLabel = new QLabel(centralWidget);
        handLabel->setObjectName(QString::fromUtf8("handLabel"));
        handLabel->setGeometry(QRect(10, 141, 46, 20));
        handSelect = new QSpinBox(centralWidget);
        handSelect->setObjectName(QString::fromUtf8("handSelect"));
        handSelect->setGeometry(QRect(50, 138, 42, 22));
        handSelect->setMaximum(3);
        playersTableWidget = new QTableWidget(centralWidget);
        if (playersTableWidget->columnCount() < 4)
            playersTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        playersTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        playersTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        playersTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        playersTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        playersTableWidget->setObjectName(QString::fromUtf8("playersTableWidget"));
        playersTableWidget->setGeometry(QRect(10, 0, 431, 121));
        playersTableWidget->setColumnCount(4);
        winnersLabel = new QLabel(centralWidget);
        winnersLabel->setObjectName(QString::fromUtf8("winnersLabel"));
        winnersLabel->setGeometry(QRect(10, 240, 431, 61));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        winnersLabel->setFont(font);
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(10, 180, 121, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 455, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Basquete de Bolso", 0, QApplication::UnicodeUTF8));
        guessPushButton->setText(QApplication::translate("MainWindow", "Enviar palpite", 0, QApplication::UnicodeUTF8));
        guessLabel->setText(QApplication::translate("MainWindow", "Palpite", 0, QApplication::UnicodeUTF8));
        handLabel->setText(QApplication::translate("MainWindow", "M\303\243o", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = playersTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Nome", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = playersTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "M\303\243o", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = playersTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Palpite", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = playersTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Vit\303\263rias", 0, QApplication::UnicodeUTF8));
        winnersLabel->setText(QString());
        nameLabel->setText(QApplication::translate("MainWindow", "Nome: ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
