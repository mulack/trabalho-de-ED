#include <stdio.h>
#include <stdlib.h>

typedef struct materia{
    int codigo;
    char *nome;
    double mf;
}MAT;


typedef struct aluno{
    int matricula;
    char *nome_alu;
    MAT *materias[];
    struct aluno *esq;
    struct aluno *dir;
}ALU;

ALU* raiz = NULL;

ALU* busca( ALU* aux, int chave){
    if(aux == NULL){
        return NULL; 
    }else if(chave == aux->matricula){
        return aux; 
    }else if(chave < aux->matricula){ 
        if(aux->esq != NULL){
            return busca(chave, aux->esq);
        }else{
            return aux;
        }
    }else{
        if(aux->dir != NULL){
            return busca(chave, aux->dir);
        }else{
            return aux;
        }
    }
}

MAT* add_materias(int chave){
    MAT materias[5];

    for(i=0; i<5; i++) {
        materias[i].nome = NULL;
        materias[i].codigo = 0;
        materias[i].mf = 0.0;
    }

    for(i=0; i<5; i++) {
        printf(" Digite nome da materia: ");
        scanf("%s", &materias[i].nome);
        printf(" Digite o codigo da materia: ");
        scanf("%d", &materias[i].codigo);
        printf(" Digite a media final do aluno nessa materia: ");
        scanf("%f", &materias[i].mf);
    }
    return MAT materias;
}

void add(int chave, char *aluno, Mat *materias){
    ALU* resp = busca(chave, raiz);
    if(resp == NULL || resp->matricula != chave){
        ALU* novo = malloc (sizeof(ALU));
        novo->matricula = chave;
        char *nome_aluno = aluno;
        MAT *materias[] = add_materias(chave);
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(resp == NULL){ 
            raiz = novo;
        }else{
            if(x < resp->chave){
                resp->esq = novo;
            }else{
                resp->dir = novo;
            }
        }
    }else{
        printf("Add invalida. Chave duplicada");
    }
    
}

ALU* remover(ALU *raiz, int chave) {
    ALU *aux;
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } 
    else if(raiz->valor == chave){ 
        if(raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            printf("Elemento removido: %d !\n", chave);
            return NULL;
        }
        else if(raiz->esq != NULL){                
            aux = raiz->esq;
            free(raiz);
            printf("Elemento removido: %d !\n", chave);
            return aux;
        }
        else if(raiz->dir != NULL){
            aux = raiz->dir;
            free(raiz);
            printf("Elemento removido: %d !\n", chave);
            return aux;
        }
        else{
            aux = raiz->esq;
            while(aux->dir != NULL)
                aux = aux->dir;
            raiz->valor = aux->valor;
            aux->valor = chave;
            printf("Elemento trocado: %d !\n", chave);
            raiz->esq = remover(raiz->esq, chave);
            return raiz;
        }
    }
    else {
        if(chave < raiz->valor)
            raiz->esq = remover(raiz->esq, chave);
        else
            raiz->dir = remover(raiz->dir, chave);
        return raiz;
    }
    
}



int main(){
    return 0;
}