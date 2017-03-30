#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include "Functions.h"
#define SPACE 5

/* Deverá ser a função chamada para popular o vetor
Necessario finalizala. Problema ao retornar o vetor
vector *readArqAndCreate(){
     vector vect[SPACE];
    float vet[SPACE];
    int i = 0, j = 0;
    char url[] = "nero.txt";
    char ch;
    FILE *arq;

    arq = fopen(url, "r");
    if(arq == NULL)
        printf("Não possível abrir o arquivo!\n");
    else
        while((ch = fgetc(arq)) != 'F'){
            if(ch >47 && ch < 58){
                vet[i] = ch - 48; // Convertento To Int          
                i++; 
            }

            if(i == SPACE){
                vect[j] = newVet(vet);
                i = 0;
                j++;
            }
        } 
    
    fclose(arq);  

    return *vect;
}*/ 

vector *newVet(float *vet){
    vector *vect = malloc(1*sizeof(vector));
    int i, j;

    for (i = 0; i < SPACE; i++){
            vect->vet[i] = vet[i];
    }

    return vect;
}
