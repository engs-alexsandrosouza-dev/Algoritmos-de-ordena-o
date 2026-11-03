
#include <iostream> // Inclui a biblioteca de entrada e saída padrão;
using namespace std; // Permite utilizar cout e cin sem escrever std::;

// Função que realiza a ordenação do vetor utilizando Selection Sort;
void selectionSort(int vetor[], int tamanho) {

    int menor = 0, temp = 0, trocas = 0, comparacoes = 0; // Declaração das variáveis auxiliares e contadores;

    for (int i = 0; i < tamanho - 1; i++) { // Percorre o vetor até a penúltima posição;

        menor = i; // Define a posição atual como a posição do menor elemento;

        for (int j = i + 1; j < tamanho; j++) { // Percorre os elementos seguintes para encontrar o menor valor;

            comparacoes++; // Incrementa o contador a cada comparação realizada;

            if (vetor[j] < vetor[menor]) { // Verifica se o elemento atual é menor que o menor encontrado;
                menor = j; // Atualiza a posição do menor elemento;
            } // Fim do if;

        } // Fim do for interno;

        if (menor != i) { // Verifica se o menor elemento está em uma posição diferente da atual;

            temp = vetor[i]; // Armazena temporariamente o valor da posição atual;
            vetor[i] = vetor[menor]; // A posição atual recebe o menor valor encontrado;
            vetor[menor] = temp; // A posição do menor elemento recebe o valor armazenado em temp;

            trocas++; // Incrementa o contador quando uma troca é realizada;

        } // Fim do if;

    } // Fim do for externo;

    cout << "O numero de comparacoes realizadas foi: " << comparacoes << endl; // Imprime o número de comparações;
    cout << "O numero de trocas realizadas foi: " << trocas << endl; // Imprime o número de trocas;

} // Fim da função selectionSort;

int main() { // Função principal do programa;

    int tamanho; // Variável que armazena o tamanho do vetor;

    cout << "Digite o tamanho do vetor: "; // Solicita ao usuário o tamanho do vetor;
    cin >> tamanho; // Lê o tamanho do vetor digitado pelo usuário;

    if (tamanho <= 0) { // Verifica se o tamanho do vetor é menor ou igual a zero;
        cout << "Tamanho invalido!" << endl; // Exibe uma mensagem de erro;
        return 1; // Encerra o programa caso o tamanho seja inválido;
    } // Fim do if;

    int* vetor = new int[tamanho]; // Cria um vetor com alocação dinâmica de memória;

    cout << "Digite os elementos do vetor: "; // Solicita os elementos do vetor;

    for (int i = 0; i < tamanho; i++) { // Percorre todas as posições do vetor;
        cin >> vetor[i]; // Armazena os valores digitados pelo usuário;
    } // Fim do for;

    selectionSort(vetor, tamanho); // Chama a função Selection Sort, passando o vetor e seu tamanho;

    cout << "Vetor ordenado: "; // Exibe a mensagem que identifica o vetor ordenado;

    for (int i = 0; i < tamanho; i++) { // Percorre o vetor após a ordenação;
        cout << vetor[i] << " "; // Imprime os elementos em ordem crescente;
    } // Fim do for;

    cout << endl; // Imprime uma quebra de linha;

    delete[] vetor; // Libera a memória alocada dinamicamente;
    vetor = nullptr; // Define o ponteiro como nulo;

    return 0; // Indica que o programa foi encerrado com sucesso;

} // Fim da função main;
