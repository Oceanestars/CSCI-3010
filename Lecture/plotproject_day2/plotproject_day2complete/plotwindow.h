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
    bool get_delete_point();
    void set_delete_point();

private slots:
    // default signal -> default slot
    void on_randomButton_clicked();

    // default signal -> custom slot
    // 1. implement SlotTest
    // 2. connect to a signal
    void SlotTest();

    void AddPoint();

    void PointClickedSlot(Point *p);

    void on_deletePoints_clicked();

public slots:


private:
    Ui::PlotWindow *ui;
     bool switch2=true;
     Point *p1data;
    QGraphicsScene *scene;
    bool delete_mode_;

    static int random_clicks_;
};

#endif // PLOTWINDOW_H
