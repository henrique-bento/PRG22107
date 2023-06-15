# Introdução

A ideia desse projeto surgiu com a necessidade de gerar arquivos G-code com uma sequência específica de movimento para a fabricação de bobinas onde os programas padrões não atenderam a sequência necessária para executar a confecção correta então foi desenvolvido um software que gera uma sequência de G-code ideal de acordo com as bobinas criadas através de um interface gráfica implementada. 

# Implementação

A implementação desse software foi feita toda com o QT creator em C++ com o paradigma de orientação a objetos, como essa implementação foi feita orientada a objetos Foram definidas duas classes principais: a classe Bobina e a classe Manager Bobina. A classe bobina pode representar apenas uma bobina ou então um conjunto de múltiplas cópias da mesma bobina assim podendo gerar várias bobinas ao mesmo tempo. A classe manager_bobina tem como objetivo principal ser uma interface e gerenciar as bobinas criadas gerando um vetor da classe Bobina e gerenciando as interações com esse vetor e possíveis alterações das bobinas até então desenvolvidas. Com essas duas classes definidas primeiramente na classe Bobina foi definido os parâmetros que representam uma bobina a implementação da Classe bobina é demonstrada abaixo.

```
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
```

Com a classe que representa as bobinas definidas foi implementado a classe que ira gerenciar e fazer uma interface de um vetor da classe bobina e assim poder gerenciar todas elas, todas a bobinas implementadas podem ser salvas em um arquivo de texto a classe manager bobina tem a responsabilidade de criar e adicionar um bobina nova ao vetor, procurar uma bobina pelo seu nome, atualizar as informações de uma bobina, salvar o vetor de bobinas em um arquivo texto, ler as bobinas do arquivo texto e carregar para o vetor, apagar a bobina tanto do vetor como do arquivo e gerar o G-code referente a essa bobina a implementação dessa classe é demonstrada abaixo. Uma coisa utilizada também para poder facilitar o uso dessa classe foi gerar um singleton da mesma onde a classe é iniciada e gerada uma instância e se tem um método que retorna a instância criada e assim pode se acessar os métodos da classe com ela sendo instância uma vez só.

```
class manager_bobina : public Bobina
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
```
Com essas duas classes implementadas basicamente no arquivo main.cpp é feita a leitura do arquivo é carregado os dados para o vetor bobinas, após isso é executada a função MainWindow que traz a interface inicial com dois botões "criar" e "editar" onde você pode acessar a página "criar" e gerar uma bobina do zero e após isso salvar ela no vetor tendo a opção de salvar no arquivo ou não e após isso gerar o código de G-Code referente a bobina. Já apertando em "editar" o usuário vai poder ver as bobinas já criadas e selecionando uma delas pode gerar o G-Code da mesma, Editar seus parâmetros e excluir a bobina do vetor e se desejar do arquivo também. Assim é o funcionamento base da interface implementada para gerar as bobinas desejadas. 
