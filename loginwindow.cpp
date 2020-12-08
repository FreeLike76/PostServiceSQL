#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    errorMsg = new QMessageBox();
    errorMsg->setText("Error! Connection failed!");
    dbConnected = false;
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={Sql server};SERVER=DESKTOP-06DJAAT;DATABASE=PostOffice;");
    db.setUserName(ui->lineEdit->text());
    db.setPassword(ui->lineEdit_2->text());

    if(db.open())
    {
        dbConnected = true;
        close();
    }
    else
    {
       dbConnected = false;
       errorMsg->show();
    }
}
