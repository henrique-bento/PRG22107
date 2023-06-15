#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manager_bobina.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), janela_select(this), ui(new Ui::MainWindow)
    , janela_criar(this)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_criar_page_clicked()
{
    //janela_criar=new CriarWindow(this);
    janela_criar.show();
}


void MainWindow::on_selec_page_clicked()
{
    //janela_select=new SelectWindow(this);
    manager_bobina* Manager_bobina = manager_bobina::getInstance();
    for (int i = 0; i < Manager_bobina->bobinas.size(); i++)
    {
        janela_select.adicionarItem(Manager_bobina->bobinas[i].nome);
    }
    janela_select.show();
}

