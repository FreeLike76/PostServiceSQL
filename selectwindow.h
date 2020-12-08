#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H

#include <QDialog>

namespace Ui {
class SelectWindow;
}

class SelectWindow : public QDialog
{
    Q_OBJECT

public:
    QString selectColumn;
    QString selectValue;
    explicit SelectWindow(QWidget *parent = nullptr);
    ~SelectWindow();

private slots:
    void on_buttonSelect_clicked();

private:
    Ui::SelectWindow *ui;
};

#endif // SELECTWINDOW_H
