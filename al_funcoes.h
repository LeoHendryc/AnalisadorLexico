#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5000
#define TAMAUX 20

//------------------------------ Definindo o alfabeto e as palavras reservadas ---------------------------
char estados[50][5];
char estadoInicial[5];
char estadoFinal[5];
char alfabetoFita[10];
int contTransacoes, contEstadosFinais, contEstados;

int cabeca_leitura;
int numCadeias;

char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
'=', '<', '>',
'(', ')', '[', ']', '{', '}',  '"', 
'+', '-', '/', '%','*', 
',', ';',
':'};

char caracteres[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char numeros[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char fechamento[] = {'(', ')', '[', ']', '{', '}',  '"'};

char atribuicao[] = {':'};

char relacional[] = {'=', '<', '>'};

char aritimetico[] = {'+', '-', '/', '%', '*'};

char* palavras[] = {"for", "step", "sqrt", "if", "else", "return", "print", "read", "to", "num", "string"};

//-----------------------------------------------------------------------------------------------------------

//	Imprime arquivo no console e retornando um valor inteiro para do tamanho dele
int tamArquivo(FILE *arq){

	char c;
	int i = 0;
	while ((c = fgetc(arq)) != EOF){
        i++;
	}
    printf("\nArquivo lido com sucesso!\n");
    return i;
}

void carregarFita(FILE *arq, char *fita){
	char c;
	int j = -1;
	
	while ((c = fgetc(arq)) != EOF){
		j++;
        fita[j] = c;
	}
	printf("\nFita carregada!\n");
}



int procurarCaracteres(char letra){
	int i;
	for (i = 0; i < 26; i++){
		if(letra == caracteres[i]) return 1;
	}	
	return 0;
}


int procurarNumeros(char letra){
	int i;
	for (i = 0; i < 10; i++){
		if(letra == numeros[i]) return 1;
	}	
	return 0;
}


int procurarFechamento(char letra){
	int i;
	for (i = 0; i < 7; i++){
		if(letra == fechamento[i]) return 1;
	}	
	return 0;
}


int procurarAtribuicao(char letra){
	int i;
	if(letra == atribuicao[0]) return 1;
	return 0;
}


int procurarRelacional(char letra){
	int i;
	for (i = 0; i < 3; i++){
		if(letra == relacional[i]) return 1;
	}	
	return 0;
}


int procurarAritimetico(char letra){
	int i;
	for (i = 0; i < 5; i++){
		if(letra == aritimetico[i]) return 1;
	}	
	return 0;
}

int verificarAlfabeto(char letra){
	int i;
	for (i = 0; i < 54; i++){
		if(letra == alfabeto[i]) return 1;
	}	
	return 0;
}

int verificarPalavra(char *aux) {
	int i=0;
	if(aux == NULL) return 0;
	for(i = 0; i < 11; i++){
		if(strcmp(aux, palavras[i]) == 0) return 1;
	}
	return 0;
}

void reiniciarAuxiliar(char* aux){
	free(aux);
	aux = NULL;
}

void reiniciarVetAux(char *vetAux){
	int i;
	for(i=0; i<TAMAUX; i++){
		vetAux[i] = '\0';
	}
}

void analisarFita(char *fita, int tamanho){
    
	int contAux = 0, cabecote = 0, i;
	char vetAux[TAMAUX];// Variável auxiliar para fazer comparação com as palavras;
	char c;
	int contChaves = 0;
	int contColchetes = 0;
	int parenteses = 0;
	int erro = 0;
	FILE *resultado;
	reiniciarVetAux(&vetAux);
	
	printf("\nVerificando...\n");
	while (cabecote < tamanho){
		c = fita[cabecote];
		//Caracteres
		if(procurarCaracteres(c)){
			if(vetAux[0] == '\0'){
				vetAux[contAux] = c;
				contAux++;
				cabecote++;
				continue;
			}else{
				vetAux[contAux] = c;
				contAux++;
				cabecote++;
				continue;
			}
		}
		//Numeros
		if(procurarNumeros(c)){
			if(vetAux[0] == '\0'){
				if(procurarCaracteres(fita[cabecote + 1])){
					vetAux[contAux] = c;
					contAux++;
					cabecote++;
					continue;
				}
			}else{
				vetAux[contAux] = c;
				contAux++;
				cabecote++;
				continue;
			}
		}
		//Fechamentos
		if(procurarFechamento(c)){
			if(c == '"'){
				cabecote++;
				c = fita[cabecote];
				while(cabecote<tamanho && c != '"'){
					c = fita[cabecote];
					++cabecote;
				}
			}
			if(vetAux[0] == '\0'){
				cabecote++;
			}else{
				if(verificarPalavra(&vetAux)){
					printf("\nEncontrada a palavra: - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
				}else{
					printf("\nPalavra nao valida: - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
				} 
			}
			if(c == '{') contChaves++;
			if(c == '}') contChaves--;
			if(c == '[') contColchetes++;
			if(c == ']') contColchetes--;
			if(c == '(') parenteses++;
			if(c == ')') parenteses--;
			continue;
		}
		//Atribuição
		if(procurarAtribuicao(c)){
			if(vetAux[0] == '\0'){
				
				cabecote++;
				continue;
			}else{
				if(verificarPalavra(&vetAux)){
					printf("\nPalavra válida encontrada: - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
					continue;
				}else{
					printf("\nPalavra não válida: - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
					continue;
				}
			}
		}
		//Relacional
		if(procurarRelacional(c)){
			if(vetAux[0] == '\0'){
				cabecote++;
			}else{
				if(verificarPalavra(&vetAux)){
					printf("\nPalavra válida encontrada: - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
					continue;
				}else{
					printf("\nPalavra nao valida! - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
					continue;
				}
			}
		}
		//Atritimético
		if(procurarAritimetico(c)){
			if(vetAux[0] == '\0'){
				cabecote++;
			}else{
				if(verificarPalavra(&vetAux)){
					printf("\nPalavra válida encontrada: - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
					continue;
				}else{
					printf("\nPalavra nao valida! - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
					continue;
				}
			}
		}
		
		if(c == ' ' || c == '\n'){
			if(vetAux[0] == '\0'){
				cabecote++;
				continue;
			}else{
				if(verificarPalavra(&vetAux)){
					printf("\nPalavra válida encontrada: - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
					continue;
				}else{
					printf("\nPalavra nao valida! - %s", vetAux);
					reiniciarVetAux(&vetAux);
					contAux = 0;
					cabecote++;
					continue;
				}
			}
		}
		
		if(verificarAlfabeto(c) && c != ' ') {
			cabecote++;
			continue;
		}else{
			printf("\nO caracter '%c' não pertence ao alfabeto!", c);
			cabecote++;
			erro++;
			continue;
		}
	}
	
	printf("\n%d", cabecote);
	if(contChaves == 0){
		printf("\nFechamento de chaves OK!");
	}else{
		printf("\nFechamento de chaves faltando!");
	}
	if(contColchetes == 0){
		printf("\nFechamento de cochetes OK!");
	}else{
		printf("\nFechamento de cochetes faltando!");
	}
	if(parenteses == 0){
		printf("\nFechamento de parênteses OK!");
	}else{
		printf("\nFechamento de parênteses faltando!");
	}
	
	resultado = fopen("Resultado.txt", "w");
	printf("\nAnálise léxica do arquivo terminada!\n");
	if(contChaves == 0){
		fprintf(resultado, "\nFechamento de chaves OK!");
	}else{
		fprintf(resultado, "\nFechamento de chaves faltando!");
	}
	if(contColchetes == 0){
		fprintf(resultado, "\nFechamento de colchetes OK!");
	}else{
		printf(resultado, "\nFechamento de colchetes faltando!");
	}
	if(parenteses == 0){
		fprintf(resultado, "\nFechamento de parênteses OK!");
	}else{
		fprintf(resultado, "\nFechamento de parênteses faltando!");
	}
	fprintf(resultado, "\nQuantidade de caracteres invalidos: %d", erro);
	fclose(resultado);
	
	
}
