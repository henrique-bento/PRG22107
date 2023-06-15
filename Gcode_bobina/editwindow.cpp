#include "editwindow.h"
#include "ui_editwindow.h"
#include "manager_bobina.h"

EditWindow::EditWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);
}

EditWindow::~EditWindow()
{
    delete ui;
}

void EditWindow::receber_Index(int index){
    manager_bobina* Manager_bobina = manager_bobina::getInstance();

    ui->nome_bobi->setText(Manager_bobina->bobinas[index].nome);
    ui->largura->setValue(Manager_bobina->bobinas[index].largura);
    ui->comprimento->setValue(Manager_bobina->bobinas[index].comprimento);
    ui->dist_coluna->setValue(Manager_bobina->bobinas[index].dist_bobix);
    ui->dist_linha->setValue(Manager_bobina->bobinas[index].dist_bobiy);
    ui->num_coluna->setValue(Manager_bobina->bobinas[index].num_coluna);
    ui->num_linha->setValue(Manager_bobina->bobinas[index].num_coluna);
    ui->num_volta->setValue(Manager_bobina->bobinas[index].num_volta);
}
void EditWindow::on_cancelButton_2_clicked()
{
    this->close();
}


void EditWindow::on_editButton_clicked()
{
    QString local="C:/Users/henri/Downloads/faculdade/7 semestre/PRG/Gcode_bobina/";
    QString nome_arq ="bobinas.txt";
    manager_bobina* Manager_bobina = manager_bobina::getInstance();
    Manager_bobina->atualizarBobina(ui->nome_bobi->text(), ui->largura->value(), ui->comprimento->value(),
    ui->dist_coluna->value(), ui->dist_linha->value(), ui->num_coluna->value(), ui->num_linha->value(), ui->num_volta->value());
    QMessageBox::StandardButton resposta = QMessageBox::question(this, "Salvar Mudanças", "Deseja salvar as mudanças feitas?", QMessageBox::Yes | QMessageBox::No);
    if (resposta == QMessageBox::Yes) {
    // Código para salvar as mudanças
    Manager_bobina->salvar(local + nome_arq);
    }
}
