#ifndef EDITSELECTWINDOW_H
#define EDITSELECTWINDOW_H

#include <QDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <dataeditwindow.h>

namespace Ui {
class EditSelectWindow;
}

class EditSelectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditSelectWindow(QWidget *parent = nullptr);
    ~EditSelectWindow();

private slots:

    void on_buttonDelete_clicked();

    void on_buttonFind_clicked();

private:
    Ui::EditSelectWindow *ui;
    QMessageBox* errorMessage;
    QSqlQuery* delRow;
    DataEditWindow* editor;
};

#endif // EDITSELECTWINDOW_H
