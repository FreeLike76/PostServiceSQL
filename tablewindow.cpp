#include "tablewindow.h"
#include "ui_tablewindow.h"

TableWindow::TableWindow(QString table, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);
    QSqlQueryModel* tableModel = new QSqlQueryModel();
    tableModel->setQuery("select * from " + table);
    ui->tableView->setModel(tableModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}

TableWindow::~TableWindow()
{
    delete ui;
}
