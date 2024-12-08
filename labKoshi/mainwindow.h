#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QtCharts>

#include "../include/equation_meshersky.h"

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

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_splitter_splitterMoved(int pos, int index);

private:
    Meshersky equation;

    QLineSeries* Ut = nullptr; // график U(t)
    QLineSeries* Vt = nullptr; // график V(t)
    QLineSeries* VU = nullptr; // график V(U)
    QLineSeries* errorU = nullptr; // график errorU
    QLineSeries* errorV = nullptr; // график errorV

    QChart* chart1 = nullptr;
    QChart* chart2 = nullptr;
    QChart* chart3 = nullptr;

    QValueAxis* Ox1 = nullptr;
    QValueAxis* Oy1 = nullptr;
    QValueAxis* Ox2 = nullptr;
    QValueAxis* Oy2 = nullptr;
    QValueAxis* Ox3 = nullptr;
    QValueAxis* Oy3 = nullptr;

    void setGraphics1();
    void setGraphics2();
    void setGraphics3();
    void updateGraphics1();
    void updateGraphics2();
    void updateGraphics3();

    void setTable();

    void rashet();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
