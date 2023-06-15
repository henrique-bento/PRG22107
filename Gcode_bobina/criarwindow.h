#ifndef CRIARWINDOW_H
#define CRIARWINDOW_H

#include <QMainWindow>

namespace Ui {
class CriarWindow;
}

class CriarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CriarWindow(QWidget *parent = nullptr);
    ~CriarWindow();

private slots:


    void on_cancel_criar_clicked();

    void on_Criar_bobina_clicked();

    void on_salvarButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CriarWindow *ui;
};

#endif // CRIARWINDOW_H
