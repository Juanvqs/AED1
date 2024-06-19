#include<stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
/*
  Exemplos de funções para manipular aquivos. Objetivo de aula de hoje é experimentar essas funções 

1 -  Vamos começar fazendo um programa que nome e salário de 5 pessoas para um vetor de pessoas (crie o tipo pessoa) e grave os dados em arquivo 

2 - vamos fazer um programa para mostrar os dados das pessoas que estão guardados em arquivos gerados pelo programa 1

3 - Vamos fazer um programa para dobrar o salario das pessoas, carregando para a memoria 1 pessoa de cada vez, modificando seu salário e reescrevendo os dados no arquivo


*/





/* 

fopen: Abre ou Cria e abre arquivo. 



 Abrir arquivo = preparar para uso por funcoes de leitura e ou escrita.

 fopen aloca uma struct do tipo FILE e retorna um ponteiro para essa struct (FILE*)

 Essa struct carrega diversas informações sobre o arquivo e pode ser usada para qq manipulação do mesmo.

 Após uso, deve fechar com fclose.

fopen(nome, modo)

O primeiro parametro é o nome do arquivo. Pode vir como uma constante, do tipo "~edleno/dados", "dados" e assim por diante. Pode vir como uma string (char *) vetor de char.

O segundo parâmetro (modo)  é uma string que pode ter os seguintes valores (modos de abertura):

 "w": cria arquivo e deixa ele zerado. Abre somente para escrita. Se arquivo já existe ele tem seu conteúdo destruído (fica com 0 bytes)

 "w+": cria arquivo e deixa ele zerado. Abre para leitura e escrita.  Se arquivo já existe ele tem seu conteúdo destruído (fica com 0 bytes)



A adição de um x após o w ou w+ faz o fopen falhar se arquivo já existir. Assim, evita de destruir arquivo que já exista. Normalmente uso o r+ antes do w para verificar se já existe. Vejo pouca utilidade no x....



"a": abre arquivo já existente somente para escrita e move ponteiro para fim do arquivo.  Não deixa sobrepor informacao já escrita no arquivo. Escreve somente no fim do arquivo sempre! Cria arquivo se ele não existir. Abre somente para escrita.

 "a+": Mesmo do anterior, mas pode ler dados do arquivo. Abre arquivo já existente somente para leitura e escrita e move ponteiro para fim do arquivo.  Não deixa sobrepor informacao já escrita no arquivo. Escreve somente no fim do arquivo sempre! Cria arquivo se ele não existir. Abre somente para escrita.

 r: abre arquivo somente para leitura. Não cria arquivo, dando erro se nao existir previamente.

 r+: abre arquivo para leitura e escrita Não cria arquivo, dando erro se nao existir previamente.



pode-se colocar a letra b ao lado das letras acima, mas ela não tem efeito prático. Antigamente havia arquivos texto e binário. Isso caiu em desuso e hoje há apelas arquivos.

*/

/* 
 Descobrindo o tamanho de um arquivo:

a função f_stat obtem diversas informações sobre o estado atual de um arquivo
essas informações são armazenadas em uma variavel do tipo struct stat.
Em particular, pode-se usar o campo st_size para se saber o tamanho de um arquivo
A fstat recebe 2 parametros:

O primeiro, é o arquivo, mas infelizmente usando um formato de descritor diferente (pouco usado), que é um inteiro ao invés de um FILE. Para converter um FILE para o seu descritor inteiro, usa-se a função fileno().

O segundo parametro é o endereco da variavel do tipo struct stat! Segue uma funcao pra descobrir o tamanho de um arquivo

 */


int tamanhoArquivo(FILE *f) {

struct stat buf;
fstat(fileno(f), &buf);
return buf.st_size;
}


/* fseek *****************************

  Movendo o cursor (posicao atual onde a proxima operação de arquivo (leitura ou escrita será realizada.

Faz-se isso em C usando-se fseek. Considere os exemplos abaixo onde k é um valor numérico (pode ser constante ou uma variavel), fp é um FILE * e o terceiro parametro do fseek seleciona o modo.  Há 3 modos de mover:

1 - Mover para o k-ésimo byte a partir do inicio do arquivo

 fseek(fp, k, SEEK_SET);

Ex: fseek(fp, 0, SEEK_SET) vai pro inicio  de arquivo.

2 - Mover para o k-ésimo byte a partir do fim do arquivo (move k bytes contando do final)

   fseek(fp, k, SEEK_END);

Ex: fseek(fp, 0, SEEK_END) vai pro fim de arquivo.

3 - Mover a partir de onde está o cursor

 fseek(fp, k, SEEK_CUR);

Ex. fseek (fp, -3, SEEK_CUR) volta 3 posicoes
    fseek (fp, 3, SEEK_CUR) avança 3 posicoes

*************/

/* fechando um arquivo

 fclose(fp);

 *********** */

/* Em que posição está o cursor ?


   ftell(fp)

Ex:
fseek(fp,10, SEEK_SET);
printf("%lu", ftell(fp)); // imprime 10 caso o arquivo tenha pelo menos 10 bytes

*********/


/**********************
 gravando valores em um  arquivo

A função fwrite copia bytes da memoria RAM para um arquivo. Se o cursor estiver no fim de arquivo, isso faz o arquivo crescer de tamanho. Se o cursor estiver em outro local, isso causa uma sobre escrita em dados já existentes. Lembre-se que se arquivo for aberto com modo "a" ou "a+", toda escrita será forçada sempre pro fim de arquivo.

 size_t  fwrite(endereco onde estão os dados, tamanho de um registro, numero de itens, fp);

endereco onde estão os dados: endereco que indica onde estao os dados na memoria que serão copiados

tamanho de um registro: fwrite foi feito pra gravar registros (como se fosse um vetor de elementos a ser gravado). 

numero de elementos: quantidade de elementos (registros) a ser gravada (copiada para o arquivo).

fp: descritor do arquivo (FILE*)


Cursor é movido para o ponto logo após onde escreveu os dados.

A função retorna o número de registros efetivamente gravados. Por exemplo, se sistemas de arquivo só tem espaço para 1 regristo e peço pra gravar 5, a funcao ira gravar 1 e retornar 1. Se tiver espaço para 1 registro e meio, vai gravar apenas 1 e retornar 1.



****************************/




/**********************
 lendo valores de um do arquivo

A função fread copia bytes de um arquivo para a memoria RAM. A leitura é feita a partir da posição atual do cursor.

 size_t  fread(endereco para onde vão os dados, tamanho de um registro, numero de itens, fp);

endereco onde vão os dados: endereco que indica para onde os dados serão lidos (copiados para a memoria)

tamanho de um registro: fread foi feito pra ler registros (como se fosse um vetor de elementos a ser lido). 

numero de elementos: quantidade de elementos (registros) a ser lida (copiada do  arquivo para a memoria).

fp: descritor do arquivo (FILE*)

Cursor do arquivo é movido para o ponto logo após onde leu  os dados.

A função retorna o número de registros efetivamente lidos. Assim, pode-se testar o sucesso verificando-se se fread retornou exatamente o valor "numero de elementos".

****************************/


/* ftruncate( fileno(fp), x)

trunca um arquivo para que o mesmo fique com, no máximo, x bytes. Note que, assim como fstat, ela usa descritor numérico, por isso precisa usar fileno().

Se arquivo tem menos que x bytes, ele é preenchido com zeros até completar x bytes.

*/

/* fflush(fp)

   descarrega o buffer de gravação para um arquivo, evitando perdas de dados

*/


/*

1 -  Vamos começar fazendo um programa que nome e salário de 5 pessoas para um vetor de pessoas (crie o tipo pessoa) e grave os dados em arquivo 
*/
typedef struct tipoPessoa {
  char nome[20];
  float salario;
} tipoPessoa;

int main() {
  FILE *fdArq;
  int x;
  int numRegGravados;
  tipoPessoa vet[5];

  for(x = 0; x < 5; x++) {
    printf("Lendo para a posicao %d\n",x);
    printf("Entre com o nome:");
    scanf("%[^\n]%*c",vet[x].nome);
    printf("Entre com o salario:");
    scanf("%f%*c",&vet[x].salario);
  }  
  fdArq = fopen("dados","w");
  if(fdArq == NULL) {
    printf("Não consegui criar o arquivo\n");
    exit(1);
  }

  numRegGravados = fwrite(vet,sizeof(tipoPessoa), 5, fdArq);
  printf("Foram gravados %d registros no arquivo\n", numRegGravados);
  fclose(fdArq);
}