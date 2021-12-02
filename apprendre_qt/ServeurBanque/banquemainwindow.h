#ifndef BANQUEMAINWINDOW_H
#define BANQUEMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BanqueMainWindow; }
QT_END_NAMESPACE

class BanqueMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    BanqueMainWindow(QWidget *parent = nullptr);
    ~BanqueMainWindow();

private:
    Ui::BanqueMainWindow *ui;
};
#endif // BANQUEMAINWINDOW_H
