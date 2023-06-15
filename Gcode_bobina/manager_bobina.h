#ifndef MANAGER_BOBINA_H
#define MANAGER_BOBINA_H

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

class Bobina
{
public:
    QString nome;
    int largura;
    int comprimento;
    int dist_bobix;
    int dist_bobiy;
    int num_coluna;
    int num_linha;
    int num_volta;

    Bobina(const QString& nome = "", int largura = 0, int comprimento = 0, int distancia_bobinax = 0, int distancia_bobinay = 0, int numero_coluna = 0, int numero_linha = 0, int numero_voltas = 0);
};

class manager_bobina
{
    static manager_bobina* instance;
    manager_bobina();
public:
    QVector<Bobina> bobinas;
    static manager_bobina* getInstance();
    bool adicionarBobina(const Bobina& bobina);
    Bobina* encontrarBobinaPorNome(const QString& nome);
    void atualizarBobina(const QString& nome, int largura, int comprimento, int distancia_bobinax,int distancia_bobinay, int numero_coluna, int numero_linha, int numeroVoltas);
    bool salvar(const QString& filePath);
    bool carregarDoArquivo(const QString& filePath);
    bool apagarBobina(const QString& nome);
    void gerarGCodeBobinaQuadrada(double largura, double comprimento, int num_colunas, int num_linhas, double dist_colunas, double dist_linhas, int num_voltas);
};

#endif // MANAGER_BOBINA_H
