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
    //MAT *materias[];
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

/*MAT* add_materias(){/// uma loucura minha se der certo show se n F
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
}*/

ALU *add(int matri, char *aluno, char *email, long int tel){ /// passar a matricula do novo aluno, seu nome, email e telefone nessa ordem
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
        else if(raiz->esq != NULL && raiz->dir != NULL){
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
        else if(raiz->esq != NULL){                
            aux = raiz->esq;
            free(raiz);
            printf("Elemento removido: %d !\n\n", chave);
            return aux;
        }
        else{
            aux = raiz->dir;
            free(raiz);
            printf("Elemento removido: %d !\n\n", chave);
            return aux;
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

ALU *modificar(ALU *aux, int chave){/// passar a raiz e a matricula como parametro
	ALU *AlunoAlterado = busca(chave, aux); /// pegando no inserido pelo usuario para alteraçao
	if (AlunoAlterado->matricula == chave){
    	char *nombre; /// criando variaveis para leitura e usar na atribuiçao na propriedade do aluno
	    char *emaill;
	    long int fone;
	    int op = 1;
    	while(op !=0){ //// criando simples laço para o usuario escolher a acao
    		printf(" Digite 1 para alterar o nome\n Digite 2 para alterar o email\n Digite 3 para alterar o telefone\n Digite 0 para finalizar o processo:\n");
    		scanf("%d", &op); /// recebendo operaçao
    		if(op ==1){
		    	printf("digite o nome: ");
		    	scanf("%s", nombre);
		    	AlunoAlterado->nome = nombre;//// setando valores q o usuario entrou
	    	}
    		else if(op==2){
    			printf("digite o email: ");
    			scanf("%s", emaill);
    			AlunoAlterado->email = emaill; /// setando valores q o usuario entrou 
    		}
    		else if(op==3){
    			printf("digite o telefone: ");
    			scanf("%ld", &fone);
    			AlunoAlterado->telefone = fone; /// setando valores q o usuario entrou
        		}
        	}
	}
	else{
	    printf("aluno não cadastrado\n");
	}
}

void buscar_alu(int chave){
    ALU *aux = busca(chave, raiz);
    if (aux->matricula == chave){
        printf("Aluno encontrado, esses são seus dados: \n");
        printf("Matricula: %d \n", aux->matricula);
        printf("Nome: %s \n", aux->nome);
        printf("Email: %s \n", aux->email);
        printf("Telefone :%ld \n\n", aux->telefone);
    }
    else{
        printf("aluno não encontrado \n");
    }
}

void imprimir_arv(ALU *raiz){
    if(raiz){
        imprimir_arv(raiz->esq);
        printf("Dados do aluno: \n");
        printf("Matricula: %d \n", raiz->matricula);
        printf("Nome: %s \n", raiz->nome);
        printf("Email: %s \n", raiz->email);
        printf("Telefone :%ld \n\n", raiz->telefone);
        imprimir_arv(raiz->dir);
    }
}

void main_de_interacao(){
    int op = 1;
    while(op !=0){ ////criando simples laço para o usuario escolher a acao no menu
    	printf("\n Digite 1 para adicionar um aluno\n Digite 2 para modificar dados do aluno\n Digite 3 para remover um aluno\n Digite 4 para buscar um aluno\n Digite 5 para imprimir todos os alunos\n Digite 0 para finalizar o processo:\n");
    	scanf("%d", &op); /// recebendo operaçao
		if(op ==1){
		    int nmatri;//atribuir variavel para nova matricula
    		char nalu[50];//atribuir variavel para novo aluno
    		char nema[30];//atribuir variavel para novo email
    		long int ntel;//atribuir variavel para novo numero de telefone
	    	printf("digite a matricula: ");
	    	scanf("%d", &nmatri);//recolhendo dados do usuario e armazenando nas variaveis
    		printf("digite o nome do aluno: ");
    		scanf("%s", nalu);//recolhendo dados do usuario e armazenando nas variaveis
			printf("digite o email: ");
			scanf("%s", nema);//recolhendo dados do usuario e armazenando nas variaveis
    		printf("digite o numero de telefone: ");
    		scanf("%ld", &ntel);//recolhendo dados do usuario e armazenando nas variaveis
    		add(nmatri, nalu, nema, ntel);//usando os dados fornecidos pelo usuario para executar a função
	   	}
    	else if(op==2){
	        int modmat;//atribui variavel para o aluno a ser modificado
    		printf("digite a matricula do aluno: ");
    		scanf("%d", &modmat);//recolhendo dados do usuario e armazenando na variavel
    		modificar(raiz, modmat);//usando os dados fornecidos pelo usuario para executar a função
    	}
    	else if(op==3){
		       int remmat;//atribui variavel para o aluno a ser modificado
    		printf("digite a matricula do aluno: ");
    		scanf("%d", &remmat);//recolhendo dados do usuario e armazenando na variavel
    		remover(raiz, remmat);//usando os dados fornecidos pelo usuario para executar a função
    	}
    	else if(op==4){
		    int chave;//atribui variavel para o aluno a ser buscado
    		printf("digite a chave do aluno: ");
    		scanf("%d", &chave);//recolhendo dados do usuario e armazenando na variavel
    		buscar_alu(chave);//usando os dados fornecidos pelo usuario para executar a função
    	}
    	else if(op==5){
	        imprimir_arv(raiz);
        }
    } 
}

int main() {
    add(555555, "pedro", "mfmd@gmail.com", 998877664); 
    add(444444, "joao", "fefe@gmail.com", 344343434);
    add(333333, "caio", "caicai@gmail.com", 355554534);
    //add(324388, "felipe", "feh@gmail.com", 235346677); 
    //add(945645, "maria", "mari@gmail.com", 235546586);
    //add(232889, "guilherme", "gui@gmail.com", 124854845);
    //add(221318, "jessica", "jess@gmail.com", 98663135); 
    //add(134355, "ana", "ana@gmail.com", 243558831);
    //add(213854, "julia", "juh@gmail.com", 123155996);   
    //add(153254, "pedro", "pedro@gmail.com", 523689234);
    //printf("%s", materias[0].nome_disciplina);*/
    main_de_interacao();   
    return 0;
}
