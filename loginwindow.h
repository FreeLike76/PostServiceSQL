#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    QMessageBox* errorMsg;
    bool dbConnected;
private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
    QSqlDatabase db;
};

#endif // LOGINWINDOW_H
