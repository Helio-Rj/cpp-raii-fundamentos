
// Inclusão das bibliotecas padrão necessárias
#include <iostream> // Para entrada e saída de dados
#include <string>   // Para manipulação de strings


// Classe que simula o controle de um arquivo
class Arquivo {
private:
    std::string nome; // Nome do arquivo
    bool aberto;      // Indica se o arquivo está aberto

public:
    // Construtor: chamado automaticamente ao criar o objeto
    Arquivo(const std::string& nomeArquivo)
        : nome(nomeArquivo), aberto(false)
    {
        std::cout << "[Construtor] Tentando abrir arquivo: " << nome << std::endl;
        aberto = true; // Simula a abertura do arquivo
        std::cout << "[Construtor] Arquivo aberto\n";
    }

    // Método para simular escrita no arquivo
    void escrever() {
        if (aberto) {
            std::cout << "[Metodo] Escrevendo no arquivo: " << nome << std::endl;
        } else {
            std::cout << "[Metodo] ERRO: arquivo fechado\n";
        }
    }

    // Destrutor: chamado automaticamente ao destruir o objeto
    ~Arquivo() {
        std::cout << "[Destrutor] Fechando arquivo: " << nome << std::endl;
        aberto = false; // Simula o fechamento do arquivo
        std::cout << "[Destrutor] Arquivo fechado\n";
    }
};


// Função principal do programa
int main() {
    std::cout << ">> Entrando no main\n";

    // Bloco para escopo do objeto 'arq'
    {
        Arquivo arq("dados.txt"); // Criação do objeto, construtor é chamado
        arq.escrever();            // Chamada do método escrever
    } // Ao sair do bloco, o destrutor é chamado automaticamente

    std::cout << ">> Saindo do main\n";
    return 0;
}
