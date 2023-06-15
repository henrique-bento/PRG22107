#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "criarwindow.h"
#include "selectwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     SelectWindow janela_select;
private slots:
    void on_criar_page_clicked();

    void on_selec_page_clicked();

private:
    Ui::MainWindow *ui;
    CriarWindow janela_criar;
};
#endif // MAINWINDOW_H
