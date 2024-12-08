#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../include/numeric_methods.h"
#include "qmath.h"
#include <functional>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chart1 = new QChart();
    chart1->legend()->setVisible(true);

    Ox1 = new QValueAxis();
    Ox1->setLabelFormat("%.5lf");
    Ox1->setTickCount(11);
    Ox1->setTitleText("t, с");
    chart1->addAxis(Ox1, Qt::AlignBottom);

    Oy1 = new QValueAxis();
    Oy1->setLabelFormat("%.5lf");
    Oy1->setTickCount(11);
    Oy1->setTitleText("U, V");
    chart1->addAxis(Oy1, Qt::AlignLeft);

    chart2 = new QChart();
    chart2->legend()->setVisible(true);

    Ox2 = new QValueAxis();
    Ox2->setLabelFormat("%.5lf");
    Ox2->setTickCount(11);
    Ox2->setTitleText("U");
    chart2->addAxis(Ox2, Qt::AlignBottom);

    Oy2 = new QValueAxis();
    Oy2->setLabelFormat("%.5lf");
    Oy2->setTickCount(11);
    Oy2->setTitleText("V");
    chart2->addAxis(Oy2, Qt::AlignLeft);

    chart3 = new QChart();
    chart3->legend()->setVisible(true);

    Ox3 = new QValueAxis();
    Ox3->setLabelFormat("%.5lf");
    Ox3->setTickCount(11);
    Ox3->setTitleText("log(N)");
    chart3->addAxis(Ox3, Qt::AlignBottom);

    Oy3 = new QValueAxis();
    Oy3->setLabelFormat("%.5lf");
    Oy3->setTickCount(11);
    Oy3->setTitleText("U-V");
    chart3->addAxis(Oy3, Qt::AlignLeft);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    setGraphics1();
    setGraphics2();
    setGraphics3();

    rashet();

    updateGraphics1();
    updateGraphics2();
    updateGraphics3();
}


void MainWindow::on_lineEdit_editingFinished()
{
    bool ok;
    ui->lineEdit->text().toDouble(&ok);

    if (ok == false)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Недопустимые символы");
        msgBox.exec();

        ui->pushButton->setEnabled(false);

        return;
    }

//    if (Eps < 0.)
//    {
//        QMessageBox msgBox;
//        msgBox.setWindowTitle("Ошибка");
//        msgBox.setText("Точность не может быть отрицательной");
//        msgBox.exec();

//        flagEps = false;

//        ui->pushButton->setEnabled(false);

//        return;
//    }
}


void MainWindow::on_lineEdit_2_editingFinished()
{
    bool ok;
    ui->lineEdit_2->text().toDouble(&ok);

    if (ok == false)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Недопустимые символы");
        msgBox.exec();

        ui->pushButton->setEnabled(false);
        return;

    }

    //    if (Eps < 0.)
    //    {
    //        QMessageBox msgBox;
    //        msgBox.setWindowTitle("Ошибка");
    //        msgBox.setText("Точность не может быть отрицательной");
    //        msgBox.exec();

    //        flagEps = false;

    //        ui->pushButton->setEnabled(false);

    //        return;
    //    }
}


void MainWindow::on_lineEdit_3_editingFinished()
{
    bool ok;
    ui->lineEdit_3->text().toDouble(&ok);

    if (ok == false)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Недопустимые символы");
        msgBox.exec();

        ui->pushButton->setEnabled(false);

        return;
    }

    //    if (Eps < 0.)
    //    {
    //        QMessageBox msgBox;
    //        msgBox.setWindowTitle("Ошибка");
    //        msgBox.setText("Точность не может быть отрицательной");
    //        msgBox.exec();

    //        flagEps = false;

    //        ui->pushButton->setEnabled(false);

    //        return;
    //    }
}


void MainWindow::on_splitter_splitterMoved(int pos, int index)
{
    int curWid = ui->tableWidget->geometry().width();
    int num = ui->tableWidget->columnCount();

    for (int i = 0; i < num; i++)
    {
        ui->tableWidget->setColumnWidth(i, curWid / num);
    }
}

void MainWindow::setGraphics1()
{
    chart1->removeAllSeries();

    Ut = new QLineSeries();
    Ut->setName("U(t)");

    Vt = new QLineSeries();
    Vt->setName("V(t)");

    //ui->graphics->zoomIt(true);
}

void MainWindow::setGraphics2()
{
    chart2->removeAllSeries();

    VU = new QLineSeries();
    VU->setName("V(U)");
}

void MainWindow::setGraphics3()
{
    chart3->removeAllSeries();

    errorU = new QLineSeries();
    errorU->setName("errorU");

    errorV = new QLineSeries();
    errorV->setName("errorV");
}

void MainWindow::updateGraphics1()
{
    chart1->addSeries(Vt);
    chart1->addSeries(Ut);

    ui->graphics->setChart(chart1);

    Vt->attachAxis(Ox1);
    Vt->attachAxis(Oy1);

    Ut->attachAxis(Ox1);
    Ut->attachAxis(Oy1);
}

void MainWindow::updateGraphics2()
{
    chart2->addSeries(VU);

    ui->phaseflat->setChart(chart2);

    VU->attachAxis(Ox2);
    VU->attachAxis(Oy2);
}

void MainWindow::updateGraphics3()
{
    chart3->addSeries(errorU);
    chart3->addSeries(errorV);

    ui->erroratnum->setChart(chart3);

    errorU->attachAxis(Ox3);
    errorU->attachAxis(Oy3);

    errorV->attachAxis(Ox3);
    errorV->attachAxis(Oy3);
}

void MainWindow::setTable()
{

}

void MainWindow::rashet()
{
    equation.setNewParam(70, 12., 42.5, 19600, 1, 0.0015, M_PI / 4.);
    NumericMethods methods;

    double x1 = equation.V0 * qCos(equation.alpha);
    double y1 = equation.V0 * qSin(equation.alpha);
    std::vector<double> v{x1, y1};

    std::vector<double(Meshersky::*)(double, double, double)> f1 = {&Meshersky::equation11, &Meshersky::equation12};
    std::vector<double(Meshersky::*)(double, double, double)> f2 = {&Meshersky::equation21, &Meshersky::equation22};

    *Vt  << QPointF(0., 0.);

    for (int i = 1; i <= 200; i++)
    {
        double t = static_cast<double>(i) * 0.2;
        double x2;

        if (t <= 1)
        {
            v = methods.Eler(equation, t, 0.2, v, f1[0], f1[1]);
            x2 = equation.equation12(t, v[0], v[1]);
        }
        else
        {
            v = methods.Eler(equation, t, 0.2, v, f2[0], f2[1]);
            x2 = equation.equation22(t, v[0], v[1]);
        }


        *Vt  << QPointF(t, equation.y(t, v[1], x2));
    }
}

