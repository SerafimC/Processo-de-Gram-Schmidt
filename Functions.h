#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#define SPACE 5

//-------Structs---------
typedef struct _vector{
    float vet[SPACE];
    char L;
}vector;

//-------System_Functions

//Função que lerá o arquivo e populará as estruturas de vetores
vector *readArqAndCreate();

//Função que alocará novo ponteiro para uma estrutura de vetor
vector *newVet(float *vect);



