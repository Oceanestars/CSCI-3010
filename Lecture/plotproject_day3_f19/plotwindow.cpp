#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include "plotwindow.h"
#include "ui_plotwindow.h"
#include "point.h"

// Names: Deanne A.
// Musaab a.
// Oceane Andreis

int PlotWindow::random_clicks_ = 0;

bool PlotWindow::delete_mode_ = false;

PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotWindow),
    first_point_(true)
{
    // we need to set up the ui before we draw on our scene
    ui->setupUi(this);

    // scene is a pointer field of plot window
    scene = new QGraphicsScene;

    // QGraphicsView is a container for a QGraphicsScene
    QGraphicsView * view = ui->plotGraphicsView;
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());


    srand(time(nullptr));


    qDebug() << "Here's an example debugging statement";



    // Day 1, Task 2, number 5:
    // use the scene->addLine method to add lines to your scene for the x and y axes.
    // you may find the view->frameSize.[width()|height()] methods helpful as well.
    int x_mid = view->frameSize().height() / 2;
    int y_mid = view->frameSize().width() / 2;

    // draw the axes
    scene->addLine(0, x_mid, view->frameSize().width(), x_mid);
    scene->addLine(y_mid, 0, y_mid, view->frameSize().height());


    // Day 1, Task 5, number 2:
    // connect the random button's &QAbstractButton::pressed event to the PlotWindow's new slot
    // connect(sender, sender signal, receiver, receiver slot)
    connect(ui->randomButton, &QAbstractButton::pressed, this, &PlotWindow::SlotTest);


    // signals and slots in Qt are loosely coupled

    // Day 2, Task 2
    connect(ui->addButton, &QAbstractButton::clicked, this, &PlotWindow::AddPoint);


}



PlotWindow::~PlotWindow()
{
    delete ui;
}

// Day 1, Task 4, number 2
void PlotWindow::on_randomButton_clicked()
{
    qDebug() << "random button clicked";
}


// Day 1, Task 5, number 1
void PlotWindow::SlotTest()
{
    qDebug() << "random button pressed";
}

// Day 2, Task 2
void PlotWindow::AddPoint() {
    bool safe = false;
    int x = ui->xCoord->text().toInt(&safe);
    if (!safe) {
        return;
    }
    // do the same thing for the y coordinate
    int y = ui->yCoord->text().toInt(&safe);
    if (!safe) {
        return;
    }
    // then create your point and add it to the scene!
    QColor c(0, 0, 155);
    int x_adj = x + (ui->plotGraphicsView->frameSize().width() / 2);
    // account for the width of the point
    x_adj = x_adj - Point::get_width() / 2;
    int y_adj = (-1 * y + (ui->plotGraphicsView->frameSize().height() / 2));
    // account for the height of the point (which is the same as the width because it's a circle)
    y_adj = y_adj - Point::get_width() / 2;
    Point * p = new Point(c, x_adj, y_adj);
    connect(p, &Point::PointSelected, this, &PlotWindow::PointClickedSlot);
    connect(p,&Point::DeleteMe,this, &PlotWindow::DeletePointSlot);
    scene->addItem(p);


}

// Day 2, Task 3
void PlotWindow::PointClickedSlot(Point * p) {

    qDebug() << p->get_x();
    qDebug() << p->get_y();
    qDebug() << "point clicked slot!";
    qDebug() << "you want your slot in the object that reacts to the signal!";


    // Day 3, Task 1
    if (first_point_) {
        std::string p1 = "Point 1: (" + std::to_string(p->get_x()) + ", "
                + std::to_string(p->get_y()) + ")";
        QString s(p1.c_str());
        ui->point1Label->setText(s);
        actual_point_clicked_ = p;
    } else {
        std::string p2 = "Point 2: (" + std::to_string(p->get_x()) + ", "
                + std::to_string(p->get_y()) + ")";
        QString s(p2.c_str());
        ui->point2Label->setText(s);
        std::string dist = std::to_string(actual_point_clicked_->Distance(*p));
        QString d(dist.c_str());
        ui->distanceLabel->setText(d);

    }
    first_point_ = !first_point_;

    // add this line of code if your labels aren't being updated
    //repaint();
}

// Day 3, Task 2
void PlotWindow::on_deletePoints_clicked()
{
    PlotWindow::delete_mode_ = ! PlotWindow::delete_mode_;
    qDebug() << "current delete mode" << PlotWindow::delete_mode_;
    if (PlotWindow::get_delete_mode()) {
        ui->centralWidget->setCursor(Qt::CrossCursor);
    } else {
        ui->centralWidget->setCursor(Qt::ArrowCursor);
    }
    // add this line of code if your labels aren't being updated
    //repaint();
}
void PlotWindow::DeletePointSlot(Point *p){
    scene->removeItem(p);
}
