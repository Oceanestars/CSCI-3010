#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QString>

/*
    Oceane Andreis
    Date: October 23 2019
    Problem Set 8
    This is my mainwindow.cpp and I have #include <QString> because I'm using QString::number
 */

//Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Have a good day");

}

//Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
}

/**
    Return nothing.
    This function will keep track of how many time you've pressed the button and output the result in the status bar.
    @param none.
    @return nothing.
*/
void MainWindow::on_pushButton_clicked()
{

    count++;
    std::cout << count << std::endl;
    //QDebug(count);
    QString string_num = QString::number(count);
    ui->statusbar->showMessage(string_num);
}
