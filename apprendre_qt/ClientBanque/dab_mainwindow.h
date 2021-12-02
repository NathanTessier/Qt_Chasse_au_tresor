#ifndef DAB_MAINWINDOW_H
#define DAB_MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DAB_MainWindow; }
QT_END_NAMESPACE

class DAB_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DAB_MainWindow(QWidget *parent = nullptr);
    ~DAB_MainWindow();

private:
    Ui::DAB_MainWindow *ui;
};
#endif // DAB_MAINWINDOW_H
