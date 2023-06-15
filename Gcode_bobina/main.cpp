#include "mainwindow.h"
#include <QApplication>
#include "manager_bobina.h"

int main(int argc, char *argv[])
{
    QString local="C:/Users/henri/Downloads/faculdade/7 semestre/PRG/Gcode_bobina/";
    QString nome_arq ="bobinas.txt";
    manager_bobina* Manager_bobina = manager_bobina::getInstance();
    Manager_bobina->carregarDoArquivo(local + nome_arq);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
