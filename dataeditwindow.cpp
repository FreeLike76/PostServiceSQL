#include "dataeditwindow.h"
#include "ui_dataeditwindow.h"

DataEditWindow::DataEditWindow(QString id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataEditWindow)
{
    ui->setupUi(this);
    rowModel = new QSqlTableModel();
    rowModel->setTable("Shipments");
    rowModel->setFilter("ShipmentID = " + id);
    rowModel->select();
    ui->tableView->setModel(rowModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

DataEditWindow::~DataEditWindow()
{
    delete ui;
}
