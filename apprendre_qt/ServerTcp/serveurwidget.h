#ifndef SERVEURWIDGET_H
#define SERVEURWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ServeurWidget; }
QT_END_NAMESPACE

class ServeurWidget : public QWidget
{
    Q_OBJECT

public:
    ServeurWidget(QWidget *parent = nullptr);
    ~ServeurWidget();

private:
    Ui::ServeurWidget *ui;
};
#endif // SERVEURWIDGET_H
