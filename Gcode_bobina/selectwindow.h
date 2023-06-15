#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H

#include <QMainWindow>
#include "editwindow.h"

namespace Ui {
class SelectWindow;
}

class SelectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SelectWindow(QWidget *parent = nullptr);
    ~SelectWindow();
    void adicionarItem(const QString& item);

signals:
    void open_tela_edit(int index);

private slots:

    void on_cancel_button_clicked();

    void on_edit_page_clicked();

    void on_delete_Button_clicked();

    void on_gcode_button_clicked();

private:
    Ui::SelectWindow *ui;
    EditWindow janela_edit;
};

#endif // SELECTWINDOW_H
