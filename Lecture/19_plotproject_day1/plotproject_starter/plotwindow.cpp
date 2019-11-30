#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include "plotwindow.h"
#include "ui_plotwindow.h"
#include <point.h>

// Names: Oceane Andreis
//
//

int PlotWindow::random_clicks_ = 0;

PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotWindow)
{
    // we need to set up the ui before we draw on our scene
    ui->setupUi(this);

    // scene is a pointer field of plot window
    scene = new QGraphicsScene;

    QGraphicsView * view = ui->plotGraphicsView;
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());


    srand(time(0));


    qDebug() << "Here's an example debugging statement";


    // Day 1, Task 2, number 5:
    // use the scene->addLine method to add lines to your scene for the x and y axes.
    // you may find the view->frameSize.[width()|height()] methods helpful as well.

       int width = view->frameSize().width();
       int height = view->frameSize().height();
       // Add a line:
    // scene->addLine(x_pos_start, y_pos_start, x_pos_end, y_pos_end)
     scene->addLine(width/2,0,width/2,height); //x stays the same but y moves, goes up and down
     scene->addLine(0,height/2,width,height/2); //y stays the same but x move, goes left and right

    // Day 1, Task 4, number 2:
    // connect the random button's &QAbstractButton::pressed event to the PlotWindow's new slot
    // connect(sender, sender signal, receiver, receiver slot)
    connect(ui->randomButton, &QAbstractButton::pressed, this, &PlotWindow::SlotTest);


    //day 2
    int x_adj = 0 + (ui->plotGraphicsView->frameSize().width() / 2);
    int y_adj = (0  + (ui->plotGraphicsView->frameSize().height() / 2));
    Point *task5 = new Point(QColor (255, 255, 255),x_adj,y_adj);
    scene->addItem(task5);

    connect(ui->addButton, &QAbstractButton::pressed, this, &PlotWindow::addButton_clicked);


}



PlotWindow::~PlotWindow()
{
    delete ui;
}

void PlotWindow::on_randomButton_clicked()
{
    //qDebug() << "Here's an example debugging statement";
    qDebug("Task 4 part 2");
}

void PlotWindow::SlotTest(){

    qDebug("Task 5 part 1");

}

void PlotWindow::addButton_clicked(){

    qDebug("day 2");
    // &safe is the address of a boolean value that will be set to True if the
    // method successfully converted the text to an int and False otherwise
    bool safe = false;
    int x = ui->xCoord->text().toInt(&safe);
    if (!safe) {
        return;
    }
    int y = ui->yCoord->text().toInt(&safe);
    if (!safe) {
        return;
    }

    int x_adj = x + (ui->plotGraphicsView->frameSize().width() / 2);
    int y_adj = (-y  + (ui->plotGraphicsView->frameSize().height() / 2));
    Point *task5 = new Point(QColor (255, 255, 255),x_adj,y_adj);
     connect(task5, &Point::PointSelected, this, &PlotWindow::PointClickedSlot);
     //PointSelected is our signal
    scene->addItem(task5);

}
void PlotWindow::PointClickedSlot(int x, int y){
    qDebug()<<"point clicked slot";
}
