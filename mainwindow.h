#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "loginwindow.h"
#include "selectwindow.h"
#include "tablewindow.h"

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
    SelectWindow* dbSelectBy;
private slots:
    void on_buttonSelect_clicked();

    void on_buttonSelectBy_clicked();

    void on_buttonOffices_clicked();

    void on_buttonClients_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel* tableModel;
    void refreshTable();
    TableWindow* clientsTable;
    TableWindow* officesTable;
};
#endif // MAINWINDOW_H
