# Projeto de Estrutura de Dados - Controle de Sócios e Portaria de Clube

Este é um projeto da disciplina de "Estrutura de Dados" voltado para alunos com RA ímpar. O objetivo é criar um sistema para gerenciar os sócios de um clube, incluindo funcionalidades como controle de portaria e geração de relatórios.

## Requisitos

1. **Menu Interativo na Função Main (1 ponto):**
    - Implemente um menu interativo que permita ao usuário interagir com o programa. Inclua opções para carregar os sócios do clube, checar a portaria, e outras funcionalidades relevantes.

2. **Estrutura de Dados para Sócios (2 pontos):**
    - Crie uma estrutura que armazene a lista de sócios do clube. Esta estrutura deve incluir os seguintes campos:
        - Número do título (int)
        - Nome do titular (string)
        - Números dos dependentes 1 e 2 (int)
        - Pagamento da mensalidade em dia (booleano)
    - Implemente funções para inserir, listar e remover sócios.

3. **Leitura de Arquivo para Carregar Dados dos Sócios (2 pontos):**
    - Crie uma função que leia um arquivo de texto (.txt) e carregue os dados dos sócios. A estrutura do arquivo é de sua escolha. Utilize a biblioteca fstream do C++.

4. **Controle de Entrada e Saída pela Portaria (3 pontos):**
    - Implemente uma estrutura de dados que registre quais sócios entraram pela portaria no dia.
    - Ao entrar, o sócio deve informar o número da carteirinha. O sistema deve verificar se o sócio está na estrutura da atividade 2 e não está inadimplente.
    - Caso o sócio esteja em dia, registre o número e nome do sócio (ou respectivo dependente). Por exemplo, pai (sócio) e filho (dependente) ao entrarem gerarão duas entradas na estrutura.
    - Ao sair do clube, registre que o sócio não está mais no clube.

5. **Relatório de Visitas no Dia (1 ponto):**
    - Crie uma função para gerar um relatório de visitas no dia. O relatório deve mostrar os sócios presentes no formato abaixo:
    ```plaintext
    10-11-2023
    =========
    01591 Sócio1 E S
    01292 Sócio2 E
    00233 Sócio3 E S
    12594 Sócio4 E
    00233 Sócio3 E S
    ```
    - No exemplo, os sócios com os títulos de números 01292 e 12594 ainda se encontram no clube. Os sócios com os títulos de números 01591 e 00233 entraram e saíram do clube.

6. **Relatório de Visitas no Dia em Arquivo Texto (.txt) (1 ponto):**
    - Crie uma função para gerar um relatório de visitas no dia, mas a saída precisa ocorrer em um arquivo de texto (.txt).

---

**Observação:** Certifique-se de adaptar e testar o código de acordo com as especificações do projeto e os requisitos da disciplina.

