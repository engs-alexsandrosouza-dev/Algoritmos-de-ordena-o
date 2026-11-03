

#include <iostream> // Inclui a biblioteca de entrada e saída padrão;
using namespace std; // Permite utilizar cout e cin sem escrever std::;


// Função que realiza a ordenação do vetor utilizando Insertion Sort;
void insertionSort(int arr[], int n) {


    int aux = 0, trocas = 0, comparacoes = 0; // Declaração das variáveis auxiliares e contadores;


    for (int i = 1; i < n; i++) { // Percorre o vetor a partir da segunda posição, pois a primeira já é considerada ordenada;


        int j = i; // A variável j recebe a posição do elemento que será inserido na parte ordenada;


        while (j > 0) { // Continua enquanto existir um elemento anterior para comparar;


            comparacoes++; // Incrementa o contador a cada comparação entre dois elementos;


            if (arr[j - 1] <= arr[j]) { // Verifica se os dois elementos já estão na ordem correta;
                break; // Encerra o while, pois o elemento chegou à posição correta;
            }


            aux = arr[j]; // Armazena temporariamente o valor do elemento atual;
            arr[j] = arr[j - 1]; // O elemento atual recebe o valor do elemento anterior;
            arr[j - 1] = aux; // O elemento anterior recebe o valor armazenado em aux;


            trocas++; // Incrementa o contador a cada troca realizada;
            j--; // Decrementa j para verificar o próximo elemento à esquerda;


        } // Fim do while;


    } // Fim do for externo;


    cout << "O numero de comparacoes realizadas foi: " << comparacoes << endl; // Imprime o número de comparações;
    cout << "O numero de trocas realizadas foi: " << trocas << endl; // Imprime o número de trocas;


} // Fim da função insertionSort;


int main() { // Função principal do programa;


    int n; // Variável que armazena o tamanho do vetor;


    cout << "Digite o tamanho do vetor: "; // Solicita ao usuário o tamanho do vetor;
    cin >> n; // Lê o tamanho do vetor digitado pelo usuário;


if (n <= 0) { // Verifica se o tamanho do vetor é menor ou igual a zero;
    cout << "Tamanho invalido!" << endl; // Exibe uma mensagem de erro;
    return 1; // Encerra o programa caso o tamanho seja inválido;
}


    int* arr = new int[n]; // Cria um vetor com alocação dinâmica de memória;


    cout << "Digite os elementos do vetor: "; // Solicita os elementos do vetor;




    for (int i = 0; i < n; i++) { // Percorre todas as posições do vetor;
        cin >> arr[i]; // Armazena os valores digitados pelo usuário;
    } // Fim do for;


    insertionSort(arr, n); // Chama a função de ordenação, passando o vetor e seu tamanho;


    cout << "Vetor ordenado: "; // Exibe a mensagem que identifica o vetor ordenado;


    for (int i = 0; i < n; i++) { // Percorre o vetor após a ordenação;
        cout << arr[i] << " "; // Imprime os elementos em ordem crescente;
    } // Fim do for;


    cout << endl; // Imprime uma quebra de linha;


    delete[] arr; // Libera a memória alocada dinamicamente;
    arr = nullptr; // Define o ponteiro como nulo;


    return 0; // Indica que o programa foi encerrado com sucesso;


} // Fim da função main;




