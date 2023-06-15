#include "selectwindow.h"
#include "ui_selectwindow.h"
#include "manager_bobina.h"
#include "editwindow.h"

SelectWindow::SelectWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SelectWindow), janela_edit(this)
{
    ui->setupUi(this);
    QObject::connect(this, &SelectWindow::open_tela_edit, &janela_edit, &EditWindow::receber_Index);
}

SelectWindow::~SelectWindow()
{
    delete ui;
}

void SelectWindow::on_cancel_button_clicked()
{
    ui->comboBox->clear();
    this->close();
}


void SelectWindow::on_edit_page_clicked()
{
    int currentIndex = ui->comboBox->currentIndex();
    emit open_tela_edit(currentIndex);
    janela_edit.show();
}

void SelectWindow::adicionarItem(const QString& item)
{
    ui->comboBox->addItem(item);
}

void SelectWindow::on_delete_Button_clicked()
{
    QString local="C:/Users/henri/Downloads/faculdade/7 semestre/PRG/Gcode_bobina/";
    QString nome_arq ="bobinas.txt";
    manager_bobina* Manager_bobina = manager_bobina::getInstance();
     int currentIndex = ui->comboBox->currentIndex();

    if(Manager_bobina->apagarBobina(Manager_bobina->bobinas[currentIndex].nome)){
         ui->comboBox->removeItem(currentIndex);
         QMessageBox::StandardButton resposta = QMessageBox::question(this, "Salvar Mudanças", "Deseja salvar as mudanças feitas?", QMessageBox::Yes | QMessageBox::No);
         if (resposta == QMessageBox::Yes) {
          // Código para salvar as mudanças
         Manager_bobina->salvar(local + nome_arq);
         }
    }
}


void SelectWindow::on_gcode_button_clicked()
{
    manager_bobina* Manager_bobina = manager_bobina::getInstance();
    int currentIndex = ui->comboBox->currentIndex();
    Manager_bobina->gerarGCodeBobinaQuadrada( Manager_bobina->bobinas[currentIndex].largura,  Manager_bobina->bobinas[currentIndex].comprimento,  Manager_bobina->bobinas[currentIndex].num_coluna,  Manager_bobina->bobinas[currentIndex].num_linha, Manager_bobina->bobinas[currentIndex].dist_bobiy ,Manager_bobina->bobinas[currentIndex].dist_bobix,  Manager_bobina->bobinas[currentIndex].num_volta);
}

