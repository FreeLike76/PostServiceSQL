#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "loginwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    LoginWindow* dbLogin;
private slots:
    void on_buttonSelect_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel* tableModel;
    void refreshTable();
};
#endif // MAINWINDOW_H
