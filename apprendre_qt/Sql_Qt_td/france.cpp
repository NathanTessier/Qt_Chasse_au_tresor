#include "france.h"
#include "ui_france.h"

France::France(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::France)
{
    ui->setupUi(this);
}

France::~France()
{
    delete ui;
}

