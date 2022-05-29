#ifndef PLOTWINDOW_HH
#define PLOTWINDOW_HH

#include <QDialog>
#include "qcustomplot.h"
#include "memsdata.hh"

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = nullptr);
    ~PlotWindow();

private slots:
    void new_data_received(rawData data);

private:
    void MakePlot();

    Ui::PlotWindow *ui;
    double _time;
};

#endif // PLOTWINDOW_HH
