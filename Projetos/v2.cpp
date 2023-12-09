
#include <iostream>
#include <fstream>
#include <string>

const int MAX_SOCIOS = 100;  // Tamanho máximo do array de sócios

// Estrutura para armazenar informações de sócios
struct Socio {
    int numeroTitulo;
    std::string nomeTitular;
    int numeroDependente1;
    int numeroDependente2;
    bool pagamentoMensalidade;
};

Socio socios[MAX_SOCIOS];  // Array de sócios
int numSocios = 0;         // Número atual de sócios

// Estrutura para armazenar entradas e saídas pela portaria
struct RegistroPortaria {
    int numeroTitulo;
    std::string nomeSocio;
    bool entrada; // true para entrada, false para saída
};

RegistroPortaria registrosPortaria[MAX_SOCIOS];  // Array de registros de portaria
int numRegistrosPortaria = 0;                     // Número atual de registros

// Função para inserir um sócio no array
void inserirSocio() {
    Socio novoSocio;
    std::cout << "Número do título: ";
    std::cin >> novoSocio.numeroTitulo;
    std::cout << "Nome do titular: ";
    std::cin >> novoSocio.nomeTitular;
    std::cout << "Número do dependente 1: ";
    std::cin >> novoSocio.numeroDependente1;
    std::cout << "Número do dependente 2: ";
    std::cin >> novoSocio.numeroDependente2;
    std::cout << "Pagamento da mensalidade (1 para em dia, 0 para inadimplente): ";
    std::cin >> novoSocio.pagamentoMensalidade;

    if (numSocios < MAX_SOCIOS) {
        socios[numSocios++] = novoSocio;
        std::cout << "Sócio inserido com sucesso.\n";
    } else {
        std::cout << "Limite de sócios atingido.\n";
    }
}

// Função para listar todos os sócios
void listarSocios() {
    std::cout << "Lista de sócios:\n";
    for (int i = 0; i < numSocios; ++i) {
        std::cout << "Título: " << socios[i].numeroTitulo << ", Nome: " << socios[i].nomeTitular
                  << ", Dep1: " << socios[i].numeroDependente1 << ", Dep2: " << socios[i].numeroDependente2
                  << ", Pagamento em dia: " << (socios[i].pagamentoMensalidade ? "Sim" : "Não") << "\n";
    }
}

// Função para remover um sócio do array
void removerSocio(int numeroTitulo) {
    for (int i = 0; i < numSocios; ++i) {
        if (socios[i].numeroTitulo == numeroTitulo) {
            // Remove o sócio movendo os elementos seguintes uma posição para trás
            for (int j = i; j < numSocios - 1; ++j) {
                socios[j] = socios[j + 1];
            }
            --numSocios;
            std::cout << "Sócio removido com sucesso.\n";
            return;
        }
    }
    std::cout << "Sócio não encontrado.\n";
}

// Função para carregar dados de sócios a partir de um arquivo .txt
void carregarDadosDeArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return;
    }

    numSocios = 0;  // Reinicia o número atual de sócios

    Socio novoSocio;
    while (arquivo >> novoSocio.numeroTitulo >> novoSocio.nomeTitular >>
           novoSocio.numeroDependente1 >> novoSocio.numeroDependente2 >>
           novoSocio.pagamentoMensalidade) {
        if (numSocios < MAX_SOCIOS) {
            socios[numSocios++] = novoSocio;
        } else {
            std::cout << "Limite de sócios atingido. Alguns dados podem não ter sido carregados.\n";
            break;
        }
    }

    arquivo.close();
}

int main() {
    int escolha;
    std::string nomeArquivo;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Inserir sócio\n";
        std::cout << "2. Listar sócios\n";
        std::cout << "3. Remover sócio\n";
        std::cout << "4. Carregar dados de arquivo\n";
        std::cout << "5. Registrar entrada pela portaria\n";
        std::cout << "6. Registrar saída pela portaria\n";
        std::cout << "7. Gerar relatório de visitas no dia\n";
        std::cout << "8. Gerar relatório de visitas no dia (salvar em arquivo)\n";
        std::cout << "9. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                inserirSocio();
                break;
            case 2:
                listarSocios();
                break;
            case 3:
                int numeroTitulo;
                std::cout << "Número do título do sócio a ser removido: ";
                std::cin >> numeroTitulo;
                removerSocio(numeroTitulo);
                break;
            case 4:
                std::cout << "Digite o nome do arquivo: ";
                std::cin >> nomeArquivo;
                carregarDadosDeArquivo(nomeArquivo);
                break;
            // Restante dos casos...
            case 9:
                std::cout << "Saindo do programa.\n";
                break;
            default:
                std::cout << "Escolha inválida. Tente novamente.\n";
        }
    } while (escolha != 9);

    return 0;
}
