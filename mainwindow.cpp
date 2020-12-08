#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbLogin = new LoginWindow();
    dbLogin->exec();
    tableModel = new QSqlQueryModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_buttonSelect_clicked()
{
    tableModel->setQuery("select * from shipments");
    refreshTable();
}

void MainWindow::refreshTable()
{
    ui->tableView->setModel(tableModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}
