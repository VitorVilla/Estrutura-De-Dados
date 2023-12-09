#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// Estrutura para armazenar informações de sócios
struct Socio {
    int numeroTitulo;
    std::string nomeTitular;
    int numeroDependente1;
    int numeroDependente2;
    bool pagamentoMensalidade;
};

// Lista de sócios do clube
std::vector<Socio> socios;

// Estrutura para armazenar entradas e saídas pela portaria
struct RegistroPortaria {
    int numeroTitulo;
    std::string nomeSocio;
    bool entrada; // true para entrada, false para saída
};

// Lista de entradas e saídas pela portaria
std::vector<RegistroPortaria> registrosPortaria;

// Função para inserir um sócio na lista
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

    socios.push_back(novoSocio);
}

// Função para listar todos os sócios
void listarSocios() {
    std::cout << "Lista de sócios:\n";
    for (const auto& socio : socios) {
        std::cout << "Título: " << socio.numeroTitulo << ", Nome: " << socio.nomeTitular
                  << ", Dep1: " << socio.numeroDependente1 << ", Dep2: " << socio.numeroDependente2
                  << ", Pagamento em dia: " << (socio.pagamentoMensalidade ? "Sim" : "Não") << "\n";
    }
}

// Função para remover um sócio da lista
void removerSocio(int numeroTitulo) {
    auto it = std::remove_if(socios.begin(), socios.end(),
                             [numeroTitulo](const Socio& socio) {
                                 return socio.numeroTitulo == numeroTitulo;
                             });
    socios.erase(it, socios.end());
}

// Função para carregar dados de sócios a partir de um arquivo .txt
void carregarDadosDeArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return;
    }

    socios.clear();  // Limpa a lista existente

    Socio novoSocio;
    while (arquivo >> novoSocio.numeroTitulo >> novoSocio.nomeTitular >>
           novoSocio.numeroDependente1 >> novoSocio.numeroDependente2 >>
           novoSocio.pagamentoMensalidade) {
        socios.push_back(novoSocio);
    }

    arquivo.close();
}

// Função para registrar entrada ou saída pela portaria
void registrarPortaria(bool entrada) {
    int numeroTitulo;
    std::cout << "Número do título do sócio: ";
    std::cin >> numeroTitulo;

    auto it = std::find_if(socios.begin(), socios.end(),
                           [numeroTitulo](const Socio& socio) {
                               return socio.numeroTitulo == numeroTitulo && socio.pagamentoMensalidade;
                           });

    if (it != socios.end()) {
        RegistroPortaria registro;
        registro.numeroTitulo = it->numeroTitulo;
        registro.nomeSocio = it->nomeTitular;
        registro.entrada = entrada;
        registrosPortaria.push_back(registro);
        std::cout << "Registro de " << (entrada ? "entrada" : "saída") << " realizado com sucesso.\n";
    } else {
        std::cout << "Sócio não encontrado ou inadimplente.\n";
    }
}

// Função para gerar um relatório de visitas no dia
void gerarRelatorioVisitas() {
    std::cout << "Relatório de visitas no dia:\n";
    for (const auto& registro : registrosPortaria) {
        std::cout << registro.numeroTitulo << " " << registro.nomeSocio << " "
                  << (registro.entrada ? "E" : "S") << "\n";
    }
}

// Função para gerar um relatório de visitas no dia em um arquivo texto
void gerarRelatorioVisitasEmArquivo(const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao criar o arquivo.\n";
        return;
    }

    arquivo << "Relatório de visitas no dia:\n";
    for (const auto& registro : registrosPortaria) {
        arquivo << registro.numeroTitulo << " " << registro.nomeSocio << " "
                << (registro.entrada ? "E" : "S") << "\n";
    }

    arquivo.close();
    std::cout << "Relatório salvo em " << nomeArquivo << ".\n";
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
            case 5:
                registrarPortaria(true);
                break;
            case 6:
                registrarPortaria(false);
                break;
            case 7:
                gerarRelatorioVisitas();
                break;
            case 8:
                std::cout << "Digite o nome do arquivo para salvar o relatório: ";
                std::cin >> nomeArquivo;
                gerarRelatorioVisitasEmArquivo(nomeArquivo);
                break;
            case 9:
                std::cout << "Saindo do programa.\n";
                break;
            default:
                std::cout << "Escolha inválida. Tente novamente.\n";
        }
    } while (escolha != 9);

    return 0;
}
