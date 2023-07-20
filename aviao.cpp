#include <iostream>
#include <string>
#include <vector>

class PassagemAviao {
public:
    PassagemAviao(const std::string& origem, const std::string& destino, const std::string& data, const std::string& hora, double preco)
        : origem(origem), destino(destino), data(data), hora(hora), preco(preco) {}

    void exibirDetalhes() const {
        std::cout << "Origem: " << origem << std::endl;
        std::cout << "Destino: " << destino << std::endl;
        std::cout << "Data: " << data << std::endl;
        std::cout << "Hora: " << hora << std::endl;
        std::cout << "Preço: $" << preco << std::endl;
        std::cout << std::endl;
    }

private:
    std::string origem;
    std::string destino;
    std::string data;
    std::string hora;
    double preco;
};

class SistemaPassagens {
public:
    void adicionarPassagem(const PassagemAviao& passagem) {
        passagens.push_back(passagem);
    }

    void exibirPassagens() const {
        for (const auto& passagem : passagens) {
            passagem.exibirDetalhes();
        }
    }

private:
    std::vector<PassagemAviao> passagens;
};

int main() {
    SistemaPassagens sistema;

    // Exemplo de criação de passagens e adição ao sistema
    sistema.adicionarPassagem(PassagemAviao("São Paulo", "Rio de Janeiro", "08/08/2023", "08:00", 250.0));
    sistema.adicionarPassagem(PassagemAviao("Rio de Janeiro", "São Paulo", "08/18/2023", "10:30", 220.0));
    sistema.adicionarPassagem(PassagemAviao("New York", "London", "09/10/2023", "14:15", 800.0));

    // Exibir todas as passagens disponíveis
    sistema.exibirPassagens();

    return 0;
}
