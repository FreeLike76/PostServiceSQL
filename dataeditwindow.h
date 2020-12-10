#ifndef DATAEDITWINDOW_H
#define DATAEDITWINDOW_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class DataEditWindow;
}

class DataEditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DataEditWindow(QString id, QWidget *parent = nullptr);
    ~DataEditWindow();
    QSqlTableModel* rowModel;
private:
    Ui::DataEditWindow *ui;
};

#endif // DATAEDITWINDOW_H
