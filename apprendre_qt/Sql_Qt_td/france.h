#ifndef FRANCE_H
#define FRANCE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class France; }
QT_END_NAMESPACE

class France : public QWidget
{
    Q_OBJECT

public:
    France(QWidget *parent = nullptr);
    ~France();

private:
    Ui::France *ui;
};
#endif // FRANCE_H
