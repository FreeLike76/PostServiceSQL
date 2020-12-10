#include "editselectwindow.h"
#include "ui_editselectwindow.h"

EditSelectWindow::EditSelectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSelectWindow)
{
    ui->setupUi(this);
    errorMessage = new QMessageBox();
}

EditSelectWindow::~EditSelectWindow()
{
    delete ui;
}


void EditSelectWindow::on_buttonDelete_clicked()
{
    delRow = new QSqlQuery();
    delRow->prepare("delete from Shipments where ShipmentID = " + ui->lineEdit->text());
    if(!delRow->exec())
    {
        errorMessage->setText("Shipments: deletion failed!");
    }
    else
    {
        errorMessage->setText("Shipments: deletion successful!");
    }
}

void EditSelectWindow::on_buttonFind_clicked()
{
    editor = new DataEditWindow(ui->lineEdit->text());
    editor->show();
    close();
}
