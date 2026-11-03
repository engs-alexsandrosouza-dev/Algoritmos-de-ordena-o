
#include <iostream> // Inclui a biblioteca de entrada e saída;
using namespace std; // Permite utilizar cout e cin;

// Função que junta duas partes do vetor em ordem crescente;
void juntar(int vetor[], int inicio, int meio, int fim, int &comparacoes, int &movimentacoes) {

    int tamanho = fim - inicio + 1; // Calcula o tamanho da parte do vetor;
    int* aux = new int[tamanho]; // Cria um vetor auxiliar para guardar os valores;

    int i = inicio; // Começa na primeira posição da parte esquerda;
    int j = meio + 1; // Começa na primeira posição da parte direita;
    int k = 0; // Controla a posição do vetor auxiliar;

    while (i <= meio && j <= fim) { // Compara os elementos enquanto as duas partes tiverem valores;

        comparacoes++; // Conta uma comparação entre elementos;

        if (vetor[i] <= vetor[j]) { // Verifica se o valor da esquerda é menor ou igual ao da direita;

            aux[k] = vetor[i]; // Guarda o valor da esquerda no vetor auxiliar;
            i++; // Avança uma posição na parte esquerda;

        } else { // Caso o valor da direita seja menor;

            aux[k] = vetor[j]; // Guarda o valor da direita no vetor auxiliar;
            j++; // Avança uma posição na parte direita;

        } // Fim do if;

        k++; // Avança uma posição no vetor auxiliar;

    } // Fim do while;

    while (i <= meio) { // Verifica se sobraram elementos na parte esquerda;

        aux[k] = vetor[i]; // Copia o elemento restante;
        i++; // Avança na parte esquerda;
        k++; // Avança no vetor auxiliar;

    } // Fim do while;

    while (j <= fim) { // Verifica se sobraram elementos na parte direita;

        aux[k] = vetor[j]; // Copia o elemento restante;
        j++; // Avança na parte direita;
        k++; // Avança no vetor auxiliar;

    } // Fim do while;

    for (int x = 0; x < tamanho; x++) { // Percorre o vetor auxiliar;

        vetor[inicio + x] = aux[x]; // Copia os valores ordenados para o vetor original;
        movimentacoes++; // Conta uma movimentação;

    } // Fim do for;

    delete[] aux; // Libera a memória utilizada pelo vetor auxiliar;

} // Fim da função juntar;


// Função que realiza a ordenação utilizando Merge Sort;
void mergeSort(int vetor[], int inicio, int fim, int &comparacoes, int &movimentacoes) {

    if (inicio < fim) { // Verifica se existe mais de um elemento para ordenar;

        int meio = (inicio + fim) / 2; // Calcula o meio do vetor;

        mergeSort(vetor, inicio, meio, comparacoes, movimentacoes); // Divide a parte esquerda;

        mergeSort(vetor, meio + 1, fim, comparacoes, movimentacoes); // Divide a parte direita;

        juntar(vetor, inicio, meio, fim, comparacoes, movimentacoes); // Junta as duas partes ordenadas;

    } // Fim do if;

} // Fim da função mergeSort;


int main() { // Função principal do programa;

    int tamanho; // Variável que armazena o tamanho do vetor;
    int comparacoes = 0, movimentacoes = 0; // Contadores das operações;

    cout << "Digite o tamanho do vetor: "; // Solicita o tamanho do vetor;
    cin >> tamanho; // Lê o tamanho informado;

    if (tamanho <= 0) { // Verifica se o tamanho é válido;
        cout << "Tamanho invalido!" << endl; // Exibe mensagem de erro;
        return 1; // Encerra o programa;
    } // Fim do if;

    int* vetor = new int[tamanho]; // Cria o vetor utilizando alocação dinâmica;

    cout << "Digite os elementos do vetor: "; // Solicita os elementos;

    for (int i = 0; i < tamanho; i++) { // Percorre todas as posições do vetor;

        cin >> vetor[i]; // Armazena o número digitado;

    } // Fim do for;

    mergeSort(vetor, 0, tamanho - 1, comparacoes, movimentacoes); // Chama a função de ordenação;

    cout << "O numero de comparacoes realizadas foi: " << comparacoes << endl; // Exibe as comparações;
    cout << "O numero de movimentacoes realizadas foi: " << movimentacoes << endl; // Exibe as movimentações;
    cout << "O numero de trocas realizadas foi: 0" << endl; // Não existem trocas diretas nesta implementação;

    cout << "Vetor ordenado: "; // Exibe o vetor ordenado;

    for (int i = 0; i < tamanho; i++) { // Percorre o vetor;

        cout << vetor[i] << " "; // Imprime os valores ordenados;

    } // Fim do for;

    cout << endl; // Pula uma linha;

    delete[] vetor; // Libera a memória alocada;
    vetor = nullptr; // Define o ponteiro como nulo;

    return 0; // Finaliza o programa;

} // Fim da função main;
