#include <iostream> //Inclui a biblioteca de entrada e saída padrão;
using namespace std; // Permite que utlizemos o cout e cin sem precisar escrever std::cout e std::cin;

void bubbleSort(int arr[], int n){ // cria um função chamada bubbleSort que recebe um vetor e seu tamanho como parâmetros;
    int aux = 0, trocas = 0, comparacoes = 0; // Declaração de variáveis auxiliares para auxiliar na ordenação e contagem de trocas e comparações;

    for (int i = 0; i < n - 1; i++){ // For externo que percorre o vetor n vezes;
        for (int j = 0; j < n - 1 - i; j ++){ // For interno que percorre o vetor n - 1 - i (pois a cada iteração do for externo, o maior elemento é colocado na última posição);
            comparacoes++; // Incrementa a variável comparacoes a cada comparação realizada;
            if (arr[j] > arr[j+1]){ // Se o elemento atual for maior que o próximo elemento, realiza a troca;
            aux = arr[j]; //A variável aux recebe o valor do elemento atual, se a condição for verdadeira;
            arr[j] = arr[j +1]; // O elemento atual recebe o valor do próximo elemento;
            arr[j+1] = aux; // O próximo elemento recebe o valor da variável aux, que é o valor do elemento atual;
            trocas++; // Incrementa a variável trocas a cada troca realizada;
            } // Fim do if;
        } // Fim do for interno;
    } // Fim do for externo;

    cout << "O numero de comparações realizadas foi: " << comparacoes << endl; // Imprime o número de comparações realizadas;
    cout << "O numero de trocas realizadas foi: " << trocas << endl; // Imprime o número de trocas realizadas;
} // Fim da função bubbleSort;

int main (){ // Função principal do programa;
    int n; //Variavel que armazena o tamanho do vetor;
    
    cout << "Digite o tamanho do vetor: "; // Solicita ao usuário que digite o tamanho do vetor;
    cin >> n; // Lê o tamanho do vetor digitado pelo usuário;

    if(n <= 0){ // Verifica se o tamanho do vetor é menor ou igual a zero;
        cout << "Tamanho do vetor inválido. O programa será encerrado." << endl; // Imprime uma mensagem de erro caso o tamanho do vetor seja inválido;
        return 0; // Retorna 0 para indicar que o programa foi encerrado;
    } // Fim do if;
    
    int* arr = new int[n]; //Cria um vetor com alocação dinâmica de memória, com tamanho digitado pelo usuário;
    cout << "Digite os elementos do vetor: "; // Solicita ao usuário que digite os elementos do vetor;
    for (int i = 0; i < n; i++){ // For que percorre o vetor e armazena os elementos digitados pelo usuário;
        cin >> arr[i]; // Lê os elementos digitados pelo usuário e armazena no vetor;
    } // Fim do for;

    bubbleSort(arr, n); // Chama a função bubbleSort, passando o vetor e seu tamanho como parâmetros;

    cout << "Vetor ordenado: "; // Imprime a mensagem "Vetor ordenado: " para indicar que o vetor será exibido em ordem crescente;
    for (int i = 0; i < n; i++){ // For que percorre o vetor e imprime os elementos em ordem crescente;
        cout << arr[i] << " "; // Imprime os elementos do vetor em ordem crescente, separados por espaço;
    } // Fim do for;

    cout << endl; // Imprime uma quebra de linha para melhorar a formatação da saída;

    delete[] arr; // Libera a memória alocada dinamicamente para o vetor;
    arr = nullptr; // Define o ponteiro arr como nulo para evitar acesso a memória liberada;
    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso;

} // Fim da função main;
