#include <stdio.h>
#include <stdlib.h>

typedef struct materia{
    int codigo;
    char *nome_diciplina;
    double mf;
}MAT;


typedef struct aluno{
    int matricula;
    char *email;
    char *nome;
    long int telefone;
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

MAT* add_materias(int chave){/// uma loucura minha se der certo show se n F
    MAT* novo = malloc (sizeof(MAT));
    novo->matricula = chave;
    char *nome_aluno = aluno;
    MAT *materias[] = add_materias(chave);
    novo->esq = NULL;
    novo->dir = NULL;
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

void add(int chave, char *aluno, char *email, long int tel){ /// passar a matricula do novo aluno, seu nome, email e telefone nessa ordem
    ALU* resp = busca(chave, raiz); 
    if(resp == NULL || resp->matricula != chave){ /// achou onde vai botar ele se ele não tiver matricula repetida
        ALU* novo = malloc (sizeof(ALU));
        novo->matricula = chave;
        novo->email = email;
        novo->nome = aluno;
        novo->telefone = tel;
        novo->materias[] = add_materias(chave);
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(resp == NULL){ /// confere se esta vazio 
            raiz = novo;
        }else{
            if(x < resp->chave){/// se a matricula é menor bota a esquerda
                resp->esq = novo;
            }else{/// se não é menor é maior bota a direita
                resp->dir = novo;
            }
        }
    }else{
        printf("Add invalida. Chave duplicada");
    }
    
}

ALU* remover(ALU *raiz, int chave) { /// passa a raiz, e a matricula do aluno que vai ser removido
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

void modificar(ALU *aux, int matricula){/// passar a raiz e a matricula como parametro
	ALU *AlunoAlterado = busca(aux, marticula); /// pegando no inserido pelo usuario para alteraçao
	char *nome; /// criando variaveis para leitura e usar na atribuiçao na propriedade do aluno
	char *email;
	long int telefone;
	int op = 1;
	while(op !=0){ //// criando simples laço para o usuario escolher a acao

		printf("digite 1 para alterar o nome, ou digite 2 para alterar o email, 3 para alterar telefone ou 0 para finalizar o processo");
		scanf("%d", &op); /// recebendo operaçao
		if(op ==1){
			printf("digite o nome: ");
			scanf("%s", &nome);
			aluno->nome = nome;//// setando valores q o usuario entrou
		}
		else if(op==2){
			printf("digite o email: ");
			scanf("%s", &email);
			aluno->email = email; /// setando valores q o usuario entrou 
			
		}
		else if(op==3){
			printf("digite o telefone: ");
			scanf("%ld", &telefone);
			aluno->telefone = telefone; /// setando valores q o usuario entrou 
			
		}
	}

}



int main(){
    return 0;
}