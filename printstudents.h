#ifndef PRINTSTUDENTS_H
#define PRINTSTUDENTS_H

#include <QDialog>

namespace Ui {
class printstudents;
}

class printstudents : public QDialog
{
    Q_OBJECT

public:
    explicit printstudents(QWidget *parent = 0);
    ~printstudents();

private:
    Ui::printstudents *ui;
};

#endif // PRINTSTUDENTS_H
