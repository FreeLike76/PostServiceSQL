#include "selectwindow.h"
#include "ui_selectwindow.h"

SelectWindow::SelectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectWindow)
{
    ui->setupUi(this);
    selectColumn = ui->selectColumn->currentText();
    selectValue = "";
}

SelectWindow::~SelectWindow()
{
    delete ui;
}

void SelectWindow::on_buttonSelect_clicked()
{
    selectColumn = ui->selectColumn->currentText();
    selectValue = ui->selectValue->text();
    close();
}
