#ifndef EDITSELECTWINDOW_H
#define EDITSELECTWINDOW_H

#include <QDialog>

namespace Ui {
class EditSelectWindow;
}

class EditSelectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditSelectWindow(QWidget *parent = nullptr);
    ~EditSelectWindow();

private:
    Ui::EditSelectWindow *ui;
};

#endif // EDITSELECTWINDOW_H
