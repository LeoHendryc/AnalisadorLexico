/*
 L�o Hendryc Viana de Sousa
 Curso de Engenharia da Computa��o
 Mat�ria de Teoria da Computa��o e Compiladores
 Faculdade �rea1 - 2019.2
 Analisador l�xico em C da linguagem .mln
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "al_funcoes.h"



int main() {
    
	FILE *arq;
    int tamanho, i;
	char *fita;
	char nome[40];
	setlocale(LC_ALL, "portuguese-brazilian");
	
	printf("|===============================================|\n");
    printf("|============== ANALISADOR LEXICO ==============|\n");
    printf("|======== MINHA LINGUAGEM NORMAL (.mln) ========|\n");
    printf("|== Digite o nome do arquivo a ser analisado: ==|\n\n");
	
	scanf("%s", &nome); 
	
	arq = fopen(nome, "r");
	if (arq == NULL){	    //testadno se arquivo foi aberto
		printf("\n\n====Arquivo inexistente=====");
		return -1;
	}
	tamanho = tamArquivo(arq);
	fclose(arq);
	
	fita = (char*) malloc(i * sizeof(char));
	
	arq = fopen(nome, "r");
	carregarFita(arq, fita);
	fclose(arq);
	
	for(i=0; i<tamanho; i++)
		printf("%c", fita[i]);
	printf("\nTeste");
	
	analisarFita(fita, tamanho); 
	system("break");
	return 0;
}
