
#include <iostream> // Inclui a biblioteca de entrada e saída padrão;
using namespace std; // Permite utilizar cout e cin sem escrever std::;

// Função que organiza os elementos em relação ao pivô;
int particionar(int vetor[], int inicio, int fim, int &comparacoes, int &trocas) {

    int pivo = vetor[fim]; // Define o último elemento do vetor como pivô;
    int i = inicio - 1; // Define a posição inicial dos elementos menores ou iguais ao pivô;
    int temp = 0; // Variável auxiliar utilizada para realizar as trocas;

    for (int j = inicio; j < fim; j++) { // Percorre os elementos entre o início e a posição anterior ao pivô;

        comparacoes++; // Incrementa o contador a cada comparação realizada;

        if (vetor[j] <= pivo) { // Verifica se o elemento atual é menor ou igual ao pivô;

            i++; // Avança a posição destinada aos elementos menores ou iguais ao pivô;

            if (i != j) { // Verifica se os elementos estão em posições diferentes;

                temp = vetor[i]; // Armazena temporariamente o valor da posição i;
                vetor[i] = vetor[j]; // A posição i recebe o valor da posição j;
                vetor[j] = temp; // A posição j recebe o valor armazenado em temp;

                trocas++; // Incrementa o contador quando uma troca é realizada;

            } // Fim do if;

        } // Fim do if;

    } // Fim do for;

    if (i + 1 != fim) { // Verifica se o pivô precisa ser movido para sua posição correta;

        temp = vetor[i + 1]; // Armazena temporariamente o elemento da posição seguinte;
        vetor[i + 1] = vetor[fim]; // Coloca o pivô em sua posição correta;
        vetor[fim] = temp; // Coloca o elemento armazenado na antiga posição do pivô;

        trocas++; // Incrementa o contador quando o pivô é trocado;

    } // Fim do if;

    return i + 1; // Retorna a posição final do pivô;

} // Fim da função particionar;


// Função que realiza a ordenação utilizando Quick Sort;
void quickSort(int vetor[], int inicio, int fim, int &comparacoes, int &trocas) {

    if (inicio < fim) { // Verifica se a parte do vetor possui mais de um elemento;

        int posicaoPivo = particionar(vetor, inicio, fim, comparacoes, trocas); // Organiza os elementos e retorna a posição do pivô;

        quickSort(vetor, inicio, posicaoPivo - 1, comparacoes, trocas); // Ordena a parte esquerda do vetor;

        quickSort(vetor, posicaoPivo + 1, fim, comparacoes, trocas); // Ordena a parte direita do vetor;

    } // Fim do if;

} // Fim da função quickSort;


int main() { // Função principal do programa;

    int tamanho; // Variável que armazena o tamanho do vetor;
    int comparacoes = 0, trocas = 0; // Declaração dos contadores de comparações e trocas;

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

    quickSort(vetor, 0, tamanho - 1, comparacoes, trocas); // Chama a função Quick Sort para ordenar o vetor;

    cout << "O numero de comparacoes realizadas foi: " << comparacoes << endl; // Imprime o número de comparações;
    cout << "O numero de trocas realizadas foi: " << trocas << endl; // Imprime o número de trocas;

    cout << "Vetor ordenado: "; // Exibe a mensagem que identifica o vetor ordenado;

    for (int i = 0; i < tamanho; i++) { // Percorre o vetor após a ordenação;
        cout << vetor[i] << " "; // Imprime os elementos em ordem crescente;
    } // Fim do for;

    cout << endl; // Imprime uma quebra de linha;

    delete[] vetor; // Libera a memória alocada dinamicamente;
    vetor = nullptr; // Define o ponteiro como nulo;

    return 0; // Indica que o programa foi encerrado com sucesso;

} // Fim da função main;
