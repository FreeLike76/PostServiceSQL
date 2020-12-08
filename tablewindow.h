#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QWidget>
#include <QSqlQueryModel>

namespace Ui {
class TableWindow;
}

class TableWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TableWindow(QString table, QWidget *parent = nullptr);
    ~TableWindow();

private:
    Ui::TableWindow *ui;
};

#endif // TABLEWINDOW_H
