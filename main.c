
/* 
 * File:   main.c
 * Author: paulo
 *
 * Created on 21 de Junho de 2016, 14:02
 */

#include <stdio.h>
#include <stdlib.h>


void mergeSort(int *vetor, int inicio, int fim) {

    int i, m, aux, metade, *vetoraux;

    if(inicio == fim) return; //retornasomente quando o vetor não poder ser mais dividido (Ou seja, quando a posição inicial e final forem a mesma);

    /* Apartir daqui ocorre a nomeação da divisão.
     * O metodo mergeSort é chamado recursivamente, um deles fica com a metade (inicio ao meio)
     * e o outro ficacom a outra metade (meio ao fim)*/

    metade = (inicio + fim ) / 2;
    mergeSort(vetor, inicio, metade);
    mergeSort(vetor, metade + 1,fim);

    /* Declara as variaveis i, m, aux(auxiliar) e um vetoraux(vetor auxiliar).
     * i e m armazena os valores das posições de inicio e meio para poder modifica-los dento do vetor auxiliar.
     * O vetor auxiliar guarda os valores de forma ordenada.
     * Ele é determinado a partir da diferença do inicio pelo fim acrescentado de um. Esse tamanho é o mesmo que o vetor já repetido.
        Ex.: se a divisão vetor tiver 4 posições o auxiliar terá 4 também */

    i = inicio;
    m = metade + 1;
    aux = 0;

    vetoraux = malloc (sizeof(int) * (fim-inicio+1)); //aloca espaço referente a porção de vetor em questão.

    while(aux< fim-inicio+1) { // como o auxiliar só pode percorrer dentro do tamanho do vetor, ele verifica a ordem com o mesmo número de repetições em que o vetor auxiliar pode percorrer;

        if (i == metade + 1 ) {
            vetoraux[aux] = vetor[m];
            m++;
        }
        else if (m == fim + 1) {
            vetoraux[aux] = vetor[i];
            i++;
        }
        else if (vetor[i] < vetor[m]) {
            vetoraux[aux] = vetor[i];
            i++;
        }
        else {
            vetoraux[aux] = vetor[m];
            m++;
        }
        aux++;
    }
    for(i = inicio; i <= fim; i++) { // reintroduz os valores dentro das mesmas posições do vetor principal, com base no vetor auxiliar(já ordenado);
        vetor[i] = vetoraux[i - inicio];
    }   
    free(vetoraux);//libera o espaço do vetor auxiliar dentro da chamada do mergeSort em que foi alocado;
}
void imprimirVetor(int *vetor){ // imprime os valores dos vetores;

    for(int i = 0; i< 9; i++){
  
       printf(" %d |",vetor[i]);
    }
}
int main()
{
    printf("== MergeSort == \n");

    int vetor[] = {7,4,3,1,2,8,6,5,0}; //vetor com 9 números;

    printf("\n Before Sort: |");
    
    imprimirVetor(vetor);
            
    mergeSort(vetor,0,8); // chama o método passando o vetor, a posição incial(0) e a posição final(8);
    
    printf("\n After Sort: |");
    
    imprimirVetor(vetor);
    
    return (EXIT_SUCCESS);
}