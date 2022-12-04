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

ALU* busca(int x, ALU* aux){
    if(aux == NULL){
        return NULL; //vazia
    }else if(x == aux->matricula){
        return aux; //encontrei :D
    }else if(x<aux->matricula){ //buscar no lado esq
        if(aux->esq != NULL){
            return busca(x, aux->esq);
        }else{//esq esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }else{//buscar no lado dir
        if(aux->dir != NULL){
            return busca(x, aux->dir);
        }else{//dir esta vazia
            return aux; //pai do elemento que não foi encontrado
        }
    }
}

MAT* add_materias(){/// uma loucura minha se der certo show se n F
    MAT* nova = malloc (sizeof(MAT));
    nova->codigo = chave;
    nova->mf = NULL;
    nova->nome_diciplina = NULL;

    MAT materias[5];

    for(i=0; i<5; i++) {
        materias[i].nome_diciplina = NULL;
        materias[i].codigo = 0;
        materias[i].mf = 0.0;
    }

    for(i=0; i<5; i++) {
        printf(" Digite nome da materia: ");
        scanf("%s", &materias[i].nome_diciplina);
        printf(" Digite o codigo da materia: ");
        scanf("%d", &materias[i].codigo);
        printf(" Digite a media final do aluno nessa materia: ");
        scanf("%f", &materias[i].mf);
    }
    return MAT materias;
}

void add(int matri, char *aluno, char *email, long int tel){ /// passar a matricula do novo aluno, seu nome, email e telefone nessa ordem
    ALU* resp = busca(matri, raiz); 
    if(resp == NULL || resp->matricula != matri){ /// achou onde vai botar ele se ele não tiver matricula repetida
        ALU* novo = malloc (sizeof(ALU));
        novo->matricula = matri;
        novo->email = email;
        novo->nome = aluno;
        novo->telefone = tel;
        //novo->materias[] = add_materias();
        novo->esq = NULL;
        novo->dir = NULL;
        
        if(resp == NULL){ /// confere se esta vazio 
            raiz = novo;
            return raiz;
        }else{
            if(matri < resp->matricula){/// se a matricula é menor bota a esquerda
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
        printf("Valor nao encontrado!\n\n");
        return NULL;
    } 
    else if(raiz->matricula == chave){ 
        if(raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            printf("Elemento removido: %d !\n\n", chave);
            return NULL;
        }
        else if(raiz->esq != NULL){                
            aux = raiz->esq;
            free(raiz);
            printf("Elemento removido: %d !\n\n", chave);
            return aux;
        }
        else if(raiz->dir != NULL){
            aux = raiz->dir;
            free(raiz);
            printf("Elemento removido: %d !\n\n", chave);
            return aux;
        }
        else{
            aux = raiz->esq;
            while(aux->dir != NULL){
                aux = aux->dir;
            }
            raiz->matricula = aux->matricula;
            aux->matricula = chave;
            printf("Elemento trocado: %d !\n\n", chave);
            raiz->esq = remover(raiz->esq, chave);
            return raiz;
        }
    }
    else {
        if(chave < raiz->matricula)
            raiz->esq = remover(raiz->esq, chave);
        else
            raiz->dir = remover(raiz->dir, chave);
        return raiz;
    }
}

void modificar(ALU *aux, int chave){/// passar a raiz e a matricula como parametro
	ALU *AlunoAlterado = busca(chave, aux); /// pegando no inserido pelo usuario para alteraçao
	if (AlunoAlterado->matricula == chave){
    	char *nome; /// criando variaveis para leitura e usar na atribuiçao na propriedade do aluno
	    char *email;
	    long int telefone;
	    int op = 1;
    	while(op !=0){ //// criando simples laço para o usuario escolher a acao
    		printf(" Digite 1 para alterar o nome\n Digite 2 para alterar o email\n Digite 3 para alterar o telefone\n Digite 0 para finalizar o processo:\n");
    		scanf("%d", &op); /// recebendo operaçao
    		if(op ==1){
		    	printf("digite o nome: ");
		    	scanf("%s", &nome);
		    	aux->nome = nome;//// setando valores q o usuario entrou
	    	}
    		else if(op==2){
    			printf("digite o email: ");
    			scanf("%s", &email);
    			aux->email = email; /// setando valores q o usuario entrou 
    		}
    		else if(op==3){
    			printf("digite o telefone: ");
    			scanf("%ld", &telefone);
    			aux->telefone = telefone; /// setando valores q o usuario entrou
        		}
        	}
	}
	else{
	    printf("aluno não cadastrado\n");
	}
}

void buscar_alu(ALU *aux, int chave){
    ALU *raiz = busca(aux, chave);
    if (raiz->matricula == chave){
        printf("Aluno encontrado, esses são seus dados: \n");
        printf("Matricula: %d \n", raiz->matricula);
        printf("Nome: %s \n", raiz->nome);
        printf("Email: %s \n", raiz->email);
        printf("Telefone :%ld \n\n", raiz->telefone);
    }
    else{
        printf("aluno não encontrado");
    }
}

void imprimir_arv(ALU *raiz){
    if(raiz){
        printf("Dados do aluno: \n");
        printf("Matricula: %d \n", raiz->matricula);
        printf("Nome: %s \n", raiz->nome);
        printf("Email: %s \n", raiz->email);
        printf("Telefone :%ld \n\n", raiz->telefone);
        imprimir_arv(raiz->esq);
        imprimir_arv(raiz->dir);
    }
}


int main(){
    int main() {
    add(555555, "pedro", "mfmd@gmail.com", 998877664); 
    add(444444, "joao", "fefe@gmail.com", 344343434);
    add(333333, "caio", "caicai@gmail.com", 355554534);
    //modificar(raiz, 555555);
    remover(raiz, 444444);
    imprimir_arv(raiz);
    //buscar_alu(raiz, 333333);
    //printf("%s", materias[0].nome_disciplina);
    return 0;
}
