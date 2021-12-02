#include "equilibreuse.h"
#include "ui_equilibreuse.h"

Equilibreuse::Equilibreuse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equilibreuse)
{
    ui->setupUi(this);
}

Equilibreuse::~Equilibreuse()
{
    delete ui;
}

