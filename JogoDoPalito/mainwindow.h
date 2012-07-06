#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <basketsocket.h>
#include <connectiondialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    BasketSocket *bSocket;
    ConnectionDialog *connectionDialog;

private:
    Ui::MainWindow *ui;

private slots:
    void resultsReceived();
    void connectToServer();
    void on_guessPushButton_clicked();
    void drawPlayersList();
    void setIndex();
    void drawWinnersList();
};

#endif // MAINWINDOW_H
