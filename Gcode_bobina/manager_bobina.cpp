#include "manager_bobina.h"

manager_bobina* manager_bobina ::instance = nullptr;

 manager_bobina::manager_bobina(){

}
Bobina::Bobina(const QString& nome, int largura, int comprimento, int distancia_bobinax, int distancia_bobinay, int numero_coluna, int numero_linha, int numero_voltas)
    {
        if (nome.isEmpty() || largura == 0 || comprimento == 0 || distancia_bobinax == 0 || distancia_bobinay == 0 || numero_coluna == 0 || numero_linha == 0 || numero_voltas == 0)
        {
            // Lança uma exceção ou lida com o erro de alguma outra forma
           throw std::invalid_argument("Os valores fornecidos são inválidos.");
        }

        this->nome = nome;
        this->largura = largura;
        this->comprimento = comprimento;
        this->num_volta = numero_voltas;
        this->dist_bobix = distancia_bobinax;
        this->dist_bobiy = distancia_bobinay;
        this->num_coluna = numero_coluna;
        this->num_linha = numero_linha;
        this->num_volta = numero_voltas;
};

bool manager_bobina::adicionarBobina(const Bobina& bobina)
    {
        if (encontrarBobinaPorNome(bobina.nome) != nullptr)
        {
            // O nome da bobina já existe
           QMessageBox::about(nullptr,"Bobina NÃO criada", "O nome da bobina já existe!");
            return false;
        }

        bobinas.append(bobina);
        QMessageBox::about(nullptr,"Bobina criada", "Bobina Adicionada com sucesso!");
        return true;
    }

Bobina* manager_bobina::encontrarBobinaPorNome(const QString& nome)
    {
        for (int i = 0; i < bobinas.size(); ++i)
        {
            if (bobinas[i].nome == nome)
            {
                return &bobinas[i];
            }
        }
        return nullptr;
    }

    void manager_bobina::atualizarBobina(const QString& nome, int largura, int comprimento, int distancia_bobinax,int distancia_bobinay, int numero_coluna, int numero_linha, int numeroVoltas)
    {
        Bobina* bobina = encontrarBobinaPorNome(nome);
        if (bobina != nullptr)
        {
            bobina->largura = largura;
            bobina->comprimento = comprimento;
            bobina->dist_bobix = distancia_bobinax;
            bobina->dist_bobiy = distancia_bobinay;
            bobina->num_coluna = numero_coluna;
            bobina->num_linha = numero_linha;
            bobina->num_volta = numeroVoltas;
        }
    }

    bool manager_bobina::salvar(const QString& filePath)
    {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(nullptr,"Arquivo não aberto", "O arquivo não foi aberto!");
            return false;
        }

        QTextStream out(&file);
        for (const Bobina& bobina : bobinas)
        {
            out << bobina.nome << "," << bobina.largura << "," << bobina.comprimento << "," << bobina.dist_bobix << "," << bobina.dist_bobiy << "," << bobina.num_coluna << "," << bobina.num_linha << "," << bobina.num_volta << "\n";
        }

        file.close();
        QMessageBox::about(nullptr,"Bobina salvas", "Bobinas salvas com sucesso no arquivo!");
        return true;
    }

    bool manager_bobina::carregarDoArquivo(const QString& filePath)
    {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
        }

        bobinas.clear();

        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() == 8)
            {
                QString nome = parts[0];
                int largura = parts[1].toInt();
                int comprimento = parts[2].toInt();
                int dist_x = parts[3].toInt();
                int dist_y = parts[4].toInt();
                int num_coluna = parts[5].toInt();
                int num_linha = parts[6].toInt();
                int numeroVoltas = parts[7].toInt();

                Bobina bobina(nome, largura, comprimento,dist_x, dist_y , num_coluna, num_linha, numeroVoltas);
                bobinas.append(bobina);
            }
        }
        file.close();
        return true;
    }
    manager_bobina* manager_bobina::getInstance(){
        if (instance == nullptr)
            instance = new manager_bobina();
        return instance;
    }
    bool manager_bobina::apagarBobina(const QString& nome){
        for (int i = 0; i < bobinas.size(); i++)
        {
            if (bobinas[i].nome == nome)
            {
                bobinas.remove(i);
                QMessageBox::information(nullptr, "Remoção de Bobina", "A bobina foi removida com sucesso.");
                return true; // Bobina removida com sucesso
            }
        }
        QMessageBox::warning(nullptr, "Remoção de Bobina", "A bobina não foi encontrada.");
        return false; // Bobina não encontrada
    }
    void manager_bobina::gerarGCodeBobinaQuadrada(double largura, double comprimento, int num_colunas, int num_linhas, double dist_colunas, double dist_linhas, int num_voltas) {
        if(largura == 0 || comprimento == 0 || num_colunas == 0 || num_linhas == 0 || num_voltas == 0){
             QMessageBox::warning(nullptr, "Valores invalidos", "G-Code não gerado valores invalidos.");
        }
        else{
             QStringList gcode;
             // Configurações iniciais do G-code
             gcode += "G90\n";  // Modo de posicionamento absoluto
             gcode += "G21\n";  // Unidades em milímetros

             double x_inicial = 0;
             double y_inicial = 0;

             for (int linha = 0; linha < num_linhas; linha++) {
                for (int coluna = 0; coluna < num_colunas; coluna++) {
                    double x_final = x_inicial + largura;
                    double y_final = y_inicial + comprimento;

                    // Movimento para o início da bobina
                    gcode += "G1 X" + QString::number(x_inicial) + " Y" + QString::number(y_inicial) + "\n";

                    // Gerar o trajeto da bobina
                    for (int volta = 0; volta < num_voltas; volta++) {
                        // Movimento horizontal
                        gcode += "G1 X" + QString::number(x_final) + " Y" + QString::number(y_inicial) + "\n";
                        gcode += "G1 X" + QString::number(x_final) + " Y" + QString::number(y_final) + "\n";
                        gcode += "G1 X" + QString::number(x_inicial) + " Y" + QString::number(y_final) + "\n";
                        gcode += "G1 X" + QString::number(x_inicial) + " Y" + QString::number(y_inicial) + "\n";

                        // Ajustar a altura para a próxima volta (opcional)
                        if (volta < num_voltas - 1) {
                            gcode += "G1 Z1\n";  // Ajustar a altura (por exemplo, 1 mm)
                        }
                    }

                    // Mover para a próxima coluna
                    x_inicial += largura + dist_colunas;
                }

                // Mover para a próxima linha
                x_inicial = 0;
                y_inicial += comprimento + dist_linhas;
             }

             // Obter a pasta de destino do arquivo usando o QFileDialog
             QString pasta_destino = QFileDialog::getExistingDirectory(nullptr, "Selecionar pasta de destino");

             if (!pasta_destino.isEmpty()) {
                // Obter o nome do arquivo a ser salvo usando o QFileDialog
                QString nome_arquivo = QFileDialog::getSaveFileName(nullptr, "Salvar arquivo", pasta_destino, "Arquivos G-code (*.nc)");

                if (!nome_arquivo.isEmpty()) {
                    // Salvar o G-code no arquivo selecionado
                    QFile arquivo(nome_arquivo);

                    if (arquivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
                        QTextStream out(&arquivo);
                        for (const QString& linha : gcode) {
                            out << linha << "\n";
                        }
                        arquivo.close();
                        QMessageBox::information(nullptr, "Sucesso", "Arquivo " + nome_arquivo + " gerado com sucesso!");
                    } else {
                        QMessageBox::critical(nullptr, "Erro", "Erro ao criar o arquivo " + nome_arquivo);
                    }
                } else {
                    QMessageBox::information(nullptr, "Cancelado", "Operação cancelada pelo usuário.");
                }
             } else {
                QMessageBox::information(nullptr, "Cancelado", "Operação cancelada pelo usuário.");
             }
    }
    }
