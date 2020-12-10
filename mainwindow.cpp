#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbLogin = new LoginWindow();
    dbSelectBy = new SelectWindow();
    dbInsert = new InsertWindow();
    dbEdit = new EditSelectWindow();
    dbLogin->exec();
    tableModel = new QSqlQueryModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshTable()
{
    ui->tableView->setModel(tableModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

void MainWindow::on_buttonSelect_clicked()
{
    tableModel->setQuery("select * from shipments");
    refreshTable();
}

void MainWindow::on_buttonSelectBy_clicked()
{
    dbSelectBy->exec();
    tableModel->setQuery("select * from shipments where " + dbSelectBy->selectColumn + " = " + dbSelectBy->selectValue);
    refreshTable();
}

void MainWindow::on_buttonOffices_clicked()
{
    officesTable = new TableWindow("Offices");
    officesTable->show();
}

void MainWindow::on_buttonClients_clicked()
{
    clientsTable = new TableWindow("Customers");
    clientsTable->show();
}

void MainWindow::on_buttonAdd_clicked()
{
    dbInsert->show();
}

void MainWindow::on_buttonModify_clicked()
{
    dbEdit->exec();
}

void MainWindow::on_buttonLabels_clicked()
{
    labelsTable = new TableWindow("InfoLabels");
    labelsTable->show();
}
