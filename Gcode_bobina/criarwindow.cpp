#include "criarwindow.h"
#include "ui_criarwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "manager_bobina.h"

CriarWindow::CriarWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CriarWindow)
{
    ui->setupUi(this);

}

CriarWindow::~CriarWindow()
{
    delete ui;
}

void CriarWindow::on_cancel_criar_clicked()
{
    this->close();
}


void CriarWindow::on_Criar_bobina_clicked()
{
    QString local="C:/Users/henri/Downloads/faculdade/7 semestre/PRG/Gcode_bobina/";
    QString nome_arq ="bobinas.txt";
    manager_bobina* Manager_bobina = manager_bobina::getInstance();

    try {
        Bobina bobi((ui->nome_bobi->text()),ui->largura->value(),ui->comprimento->value() ,ui->dist_coluna->value(), ui->dist_linha->value(), ui->num_coluna->value(), ui->num_linha->value(), ui->num_volta->value());
        if(Manager_bobina->adicionarBobina(bobi)){
            QMessageBox::StandardButton resposta = QMessageBox::question(this, "Salvar Bobina", "Deseja salvar a nova bobina no arquivo?", QMessageBox::Yes | QMessageBox::No);
            if (resposta == QMessageBox::Yes) {
                // Código para salvar as mudanças
                Manager_bobina->salvar(local + nome_arq);
            }
        }
    } catch (const std::invalid_argument& e) {
        QMessageBox::about(nullptr,"Bobina NÃO criada", "Dados inseridos invalidos!");
    }
}


void CriarWindow::on_salvarButton_clicked()
{
    QString local="C:/Users/henri/Downloads/faculdade/7 semestre/PRG/Gcode_bobina/";
    QString nome_arq ="bobinas.txt";
    manager_bobina* Manager_bobina = manager_bobina::getInstance();
    QMessageBox::StandardButton resposta = QMessageBox::question(this, "Salvar Bobina", "Deseja salvar todas as bobinas no arquivo?", QMessageBox::Yes | QMessageBox::No);
    if (resposta == QMessageBox::Yes) {
        // Código para salvar as mudanças
        Manager_bobina->salvar(local + nome_arq);
    }
}


void CriarWindow::on_pushButton_3_clicked()
{
    manager_bobina* Manager_bobina = manager_bobina::getInstance();
    Manager_bobina->gerarGCodeBobinaQuadrada(ui->largura->value(),ui->comprimento->value(),ui->num_coluna->value(), ui->num_linha->value(), ui->dist_coluna->value(), ui->dist_linha->value(), ui->num_volta->value());
}

