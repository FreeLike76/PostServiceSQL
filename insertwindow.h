#ifndef INSERTWINDOW_H
#define INSERTWINDOW_H

#include <QDialog>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class InsertWindow;
}

class InsertWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InsertWindow(QWidget *parent = nullptr);
    ~InsertWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::InsertWindow *ui;
    QMessageBox* errorMsg;
};

#endif // INSERTWINDOW_H
