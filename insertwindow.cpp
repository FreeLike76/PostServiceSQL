#include "insertwindow.h"
#include "ui_insertwindow.h"

InsertWindow::InsertWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertWindow)
{
    ui->setupUi(this);
    errorMsg = new QMessageBox();
}

InsertWindow::~InsertWindow()
{
    delete ui;
}

void InsertWindow::on_pushButton_clicked()
{
    QSqlQuery* insert = new QSqlQuery();
    insert->prepare("insert into InfoLabels([Weight], [Height], [Width], [Length], [Description]) "
                    "values (:weight, :height, :width, :length, :description)");
    insert->bindValue(":weight", ui->inputWeight->text());
    insert->bindValue(":height", ui->inputHeight->text());
    insert->bindValue(":width", ui->inputWidth->text());
    insert->bindValue(":length", ui->inputLength->text());
    insert->bindValue(":description", ui->inputDescription->toPlainText().replace("\n", ", "));
    if(!insert->exec())
    {
        errorMsg->setText("LabelInfo: insert failed");
        errorMsg->show();
    }
    else
    {
        auto labelID = insert->lastInsertId();
        insert->prepare("insert into Shipments(SenderID, ReceiverID, OfficeSenderID, OfficeReceiverID, "
                        "[Status], LabelID, CreationDate) "
                        "values (:sender, :receiver, :Osender, :Oreceiver, 0, :label, getdate())");
        insert->bindValue(":sender", ui->inputSender->text());
        insert->bindValue(":receiver", ui->inputReceiver->text());
        insert->bindValue(":Osender", ui->inputOSender->text());
        insert->bindValue(":Oreceiver", ui->inputOReceiver->text());
        insert->bindValue(":label", labelID.toString());
        if(!insert->exec())
        {
            insert->prepare("delete from InfoLabels where LabelID = " + labelID.toString());
            insert->exec();
            errorMsg->setText("Shipments: insert failed");
            errorMsg->show();
        }
        else
        {
            close();
        }
    }
}
