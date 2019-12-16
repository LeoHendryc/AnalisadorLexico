# AnalisadorLexico
Analisador Léxico em C de uma pseudo-linguagem chamada "Minha Linguagem Normal"

Existem dois arquivos exemplo, siga as instruções do executável.

AVALIAÇÃO AP2 ANALISADOR LÉXICO 
 
Objetivo: Criar um programa em “C” ou em “C++”, que será um analisador léxico, para a linguagem chamada “Minha Linguagem Normal”, este analisador deve ser construído com algumas das técnicas vistas em laboratório, isso inclui usa AFD, Máquina de Turing, AFD de Pilha com Máquina de Turing. Este analisador deve ser capaz de ler um arquivo fonte da nossa linguagem MLN, exemplo “ArquivoFonte1.mln” e “ArquivoFonte2.mln” que são os dois programas escrito na linguagem MLN (texto livre de marcações), estes serão fornecidos pelo professor. Após o analisador ler o arquivo ele deve gerar como saída um arquivo chamado “resultado.txt” que para cada arquivo fonte lido deve possuir um arquivo de resultado correspondente, contendo a(s) mensagen(s) como descrito abaixo: Para validações corretas: Arquivo fonte: ArquivoFonte1.mln analisado corretamente. 
 
Para validações inconsistentes ou erradas: Arquivo fonte: ArquivoFonte1.mln contendo erro(s)                         Palavra XPTO não reconhecida                         Falta de fechamento de código 
 
 
 
 
2 
 
Tabela de palavras válidas para o analisador 
for num > step string < step Operadores Fechamento Operadores Aritiméticos sqrt “ + if ( - else ) * return  { / print } % read Operadores Relacionais Operadores Atribuição to = := 
 
Alfabeto: 
a b d e f g h i j k l m n o p q r s t u v w y x z 0 1 2 3 4 5 6 7 8 9 = < > ( ) { } + - % , ; “ ; [ ] / :        
 
Final de linha (Fita) é representado por “\n” (quebra de linha) 
 
O trabalho será publicado em um repositório GitHub de sua propriedade, e o link do repositório que contém o sistema deve ser postado no Integress. O repositório deve ter todos os fontes e um arquivo README.md que por sua vez deve ter a descrição de como seu analisador funciona, citando o passo a passo para sua execução. 
 
Será avaliado a execução do programa, resultados esperados de saída, metodologia da implementação. 
