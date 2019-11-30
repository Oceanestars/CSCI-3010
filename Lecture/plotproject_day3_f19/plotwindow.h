#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "point.h"

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();

    static bool get_delete_mode() {return PlotWindow::delete_mode_;}

private slots:
    // default signal -> default slot
    void on_randomButton_clicked();

    // default signal -> custom slot
    // 1. implement SlotTest
    // 2. connect to a signal
    void SlotTest();

    void AddPoint();

    void PointClickedSlot(Point * p);


    void on_deletePoints_clicked();

    void DeletePointSlot(Point *p);

private:
    Ui::PlotWindow *ui;

    QGraphicsScene *scene;

    static int random_clicks_;

    // Day 3, Task 1
    bool first_point_;
    Point * actual_point_clicked_;

    // Day 3, Task 2
    static bool delete_mode_;
};

#endif // PLOTWINDOW_H
