#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Equilibreuse; }
QT_END_NAMESPACE

class Equilibreuse : public QMainWindow
{
    Q_OBJECT

public:
    Equilibreuse(QWidget *parent = nullptr);
    ~Equilibreuse();

private:
    Ui::Equilibreuse *ui;
};
#endif // EQUILIBREUSE_H
