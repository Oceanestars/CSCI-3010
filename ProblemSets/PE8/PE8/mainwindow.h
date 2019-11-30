#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/*
    Oceane Andreis
    Date: October 23 2019
    Problem Set 8
    This is my mainwindow.h and I have added a private field(count) in my MainWindow class
 */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int count;
};
#endif // MAINWINDOW_H
