#include "editselectwindow.h"
#include "ui_editselectwindow.h"

EditSelectWindow::EditSelectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSelectWindow)
{
    ui->setupUi(this);
}

EditSelectWindow::~EditSelectWindow()
{
    delete ui;
}
