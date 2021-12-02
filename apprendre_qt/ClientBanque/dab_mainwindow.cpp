#include "dab_mainwindow.h"
#include "ui_dab_mainwindow.h"

DAB_MainWindow::DAB_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DAB_MainWindow)
{
    ui->setupUi(this);
}

DAB_MainWindow::~DAB_MainWindow()
{
    delete ui;
}

