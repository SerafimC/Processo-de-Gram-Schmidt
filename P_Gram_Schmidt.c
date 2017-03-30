#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Functions.h"
#define SPACE 5
//#include "Tests.h"

vector *proj(vector *v, vector *u);
vector *vetSubVet(vector *v, vector *u);
void normalizar(vector *vet);
//-------Método Principal
void main(){
    vector *vect[SPACE];
    vector *proju[SPACE*2];
    float vet[SPACE];
    int i = 0, j = 0;
    char url[] = "nero.txt";
    char ch, vch[16];
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

    printf("\n Vetores de entrada (Separados por virgula)\n"); 

    for(i = 0; i < SPACE; i++){
        for(j = 0; j < SPACE; j++){
            printf("%f,", vect[i]->vet[j]);
        }
        printf("\n\n");
    }

    //------PROCESSO DE ORTOGONALIZACAO----------------------------
    proju[0] = vect[0];//u1

    proju[1] = proj(vect[1], proju[0]);//v2 em u1
    proju[1] = vetSubVet(vect[1], proju[1]);//u2

    proju[2] = proj(vect[2], proju[0]);//v3 em u1
    proju[3] = proj(vect[2], proju[1]);//v3 em u2
    proju[4] = vetSubVet(proju[2], proju[3]);
    proju[2] = vetSubVet(vect[2], proju[4]);//u3

    proju[3] = proj(vect[3], proju[0]);//v4 em u1
    proju[4] = proj(vect[3], proju[1]);//v4 em u2
    proju[5] = proj(vect[3], proju[2]);//v4 em u3
    proju[6] = vetSubVet(proju[3], proju[4]);
    proju[4] = vetSubVet(proju[6], proju[5]);
    proju[3] = vetSubVet(vect[3], proju[4]);//u4

    proju[4] = proj(vect[4], proju[0]);//v5 em u1
    proju[5] = proj(vect[4], proju[1]);//v5 em u2
    proju[6] = proj(vect[4], proju[2]);//v5 em u3
    proju[7] = proj(vect[4], proju[3]);//v5 em u4
    proju[8] = vetSubVet(proju[4], proju[5]);
    proju[4] = vetSubVet(proju[8], proju[6]);
    proju[5] = vetSubVet(proju[4], proju[7]);
    proju[4] = vetSubVet(vect[4], proju[5]);//u5
    //-------------------------------------------------------------

    //-------------normalização dos vetores ortogonalizados--------
    normalizar(proju[0]);
    normalizar(proju[1]);
    normalizar(proju[2]);
    normalizar(proju[3]);
    normalizar(proju[4]);
    //-------------------------------------------------------------
    
    arq = fopen(url, "a+");
    if(arq == NULL)
        printf("Não foi possivel abrir o arquivo!\n");
    else{
        fprintf(arq, "   ORTONORMALIZADOS\n");
        for(i = 0; i < SPACE; i++){
            fprintf(arq, "(");
            for(j = 0; j < SPACE; j++){
                fprintf(arq, " %.4f ,", (proju[i]->vet[j]));
            }
            fprintf(arq, ")\n");
    }

    }


    for(i = 0; i < SPACE; i++){
        printf("Vetor ortonormalizado %i\n", i);
        for(j = 0; j < SPACE; j++){
            printf("%f,", proju[i]->vet[j]);
             printf("\n");
        }
        printf("------------------------------------------\n");
    }

}

//void verificaLi()

vector *proj(vector *v, vector *u){
    int i;
    float proj;
    vector *vet = malloc(1*sizeof(vector));

    proj = ((v->vet[0]*u->vet[0]) + (v->vet[1]*u->vet[1]) + (v->vet[2]*u->vet[2]) + (v->vet[3]*u->vet[3]) + (v->vet[4]*u->vet[4]));
    proj = (proj / ((u->vet[0]*u->vet[0]) + (u->vet[1]*u->vet[1]) + (u->vet[2]*u->vet[2]) + (u->vet[3]*u->vet[3]) + (u->vet[4]*u->vet[4])));

   
    for(i = 0; i < SPACE; i++){
        vet->vet[i] = (proj * u->vet[i]);
    }

    return vet;
}

vector *vetSubVet(vector *v, vector *u){
    int i;
    vector *vet = malloc(1*sizeof(vector));

    for(i = 0; i < SPACE; i++){
        vet->vet[i] = v->vet[i] - u->vet[i];
    }

    return vet;

}

void normalizar(vector *vet){
    int i;
    double norma = sqrt(((vet->vet[0]*vet->vet[0]) + (vet->vet[1]*vet->vet[1]) + (vet->vet[2]*vet->vet[2]) + (vet->vet[3]*vet->vet[3]) + (vet->vet[4]*vet->vet[4])));

    for(i = 0; i < SPACE; i++){
        
        vet->vet[i] = (vet->vet[i] / norma);
    }
}