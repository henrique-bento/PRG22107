#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QMainWindow>

namespace Ui {
class EditWindow;
}

class EditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    ~EditWindow();

public slots:
    void receber_Index(int index);

private slots:
    void on_cancelButton_2_clicked();

    void on_editButton_clicked();

private:
    Ui::EditWindow *ui;
};

#endif // EDITWINDOW_H
