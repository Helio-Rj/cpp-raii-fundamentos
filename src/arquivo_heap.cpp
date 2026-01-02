
// Inclusão das bibliotecas necessárias
#include <iostream>
#include <string>

// Classe que simula a manipulação de um arquivo
class Arquivo {

private:
    std::string nome; // Nome do arquivo
    bool aberto;       // Indica se o arquivo está aberto


public:
    // Construtor: abre o arquivo
    Arquivo(const std::string& nomeArquivo)
        : nome(nomeArquivo), aberto(false)
    {
        std::cout << "[Construtor] Abrindo arquivo: " << nome << std::endl;
        aberto = true;
    }


    // Método para simular escrita no arquivo
    void escrever() {
        if (aberto) {
            std::cout << "[Metodo] Escrevendo no arquivo: " << nome << std::endl;
        }
    }

    // Destrutor: fecha o arquivo
    ~Arquivo() {
        std::cout << "[Destrutor] Fechando arquivo: " << nome << std::endl;
        aberto = false;
    }
};


int main() {
    std::cout << ">> Entrando no main\n";

    // Cria um objeto Arquivo na heap
    Arquivo* arq = new Arquivo("heap.txt");
    arq->escrever();

    delete arq;   // ← COMENTE esta linha primeiro
    // Se esta linha permanecer comentada, haverá vazamento de memória (o destrutor não será chamado)

    std::cout << ">> Saindo do main\n";
    return 0;
}
