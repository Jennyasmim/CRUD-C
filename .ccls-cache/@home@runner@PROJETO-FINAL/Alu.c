#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <math.h>
#include "geral.h"

#define  LARANJA   "\x1b[33m"
#define  AZUL      "\x1b[34m"
#define  VERMELHO  "\x1b[31m"
#define  VERDE     "\x1b[32m"
#define  RESET     "\x1b[0m"

void REGISTRAR_ALUNO (Discente ALUNO[], int* A) {

  FILE *aluno1 = fopen ("ALUNOS.dat", "r");  // read 

  if (aluno1 == NULL) {
    printf(" \t --- NENHUM ALUNO CADASTRADO\n");
    return;
  }
  
  fscanf(aluno1,"ALUNOS CADASTRADOS: %d \n", &(*A)); 

  int I;
  for (I = 0; I <= (*A) ; I++) {
    if (I == (*A)) {
      break;
    }
    fscanf(aluno1,"\n%[^\n]\n", ALUNO[I].nome);
    fscanf(aluno1,"%d/%d/%d\n", &ALUNO[I].dia,   &ALUNO[I].mes,  &ALUNO[I].ano);
    fscanf(aluno1,"%d\n", &ALUNO[I].numero);
    fscanf(aluno1,"%[^\n]\n", ALUNO[I].email);
    fscanf(aluno1,"%[^\n]\n", ALUNO[I].login);
    fscanf(aluno1,"%[^\n]\n", ALUNO[I].senha);
  }
  fclose(aluno1);
}

void ENTRADA() {
  printf("\n\t\t\t*** MENU PRINCIPAL *** \n");
  printf("\n* PARA CONTINUAR ESCOLHA UMA OPÇÃO ABAIXO.\n");
  
  printf("\n\t 1 - Página do Aluno\n");  
  printf("\t 2 - Página do Docente\n"); 

  printf("\n\t 0 - SAIR DO PROGRAMA\n");

}

void PAGINA_ALUNO() {
  printf(" PÁGINA DO ALUNO(A):\n\n");
  printf("\t C - CADASTRO DO ALUNO\n ");
  printf("\t T - TURMA 8ª ANO A\n");
  printf("\t A - DADOS DO ALUNO \n ");
  printf("\t L - LISTA DE PROFESSORES\n");
  printf("\t R - EXCLUIR CADASTRO\n\n");

  printf("\t E - VOLTAR AO MENU PRINCIPAL");
  printf("\n \t S - SAIR DO PROGRAMA\n");

} 

void CADASTRO_ALUNO (Discente ALUNO[], int* A) {
  int quant = 20;

  if ((*A) >= quant) {
    printf( VERMELHO "\n** A QUANTIDADE MÁXIMA DE ALUNOS CADASTRADOS FOI ATINGIDA **\n\n" RESET);
    return;
  }
  Discente novo_aluno;
  printf("- CADASTRO DO ALUNO -\n\n");
  printf(" NOME: ");
  scanf(" %[^\n]",  novo_aluno.nome);
  printf(" DATA DE NASCIMENTO(dd/mm/aaaa): ");
  scanf(" %d /  %d /  %d", &novo_aluno.dia, &novo_aluno.mes, &novo_aluno.ano);
  printf(" N° DE CELULAR: ");
  scanf(" %d", &novo_aluno.numero);
  printf(" EMAIL: ");
  scanf(" %[^\n]",  novo_aluno.email);
  printf(" LOGIN: ");
  scanf(" %[^\n]",  novo_aluno.login);
  printf(" SENHA: ");
  scanf(" %[^\n]",  novo_aluno.senha);
  system ("clear");

  printf("\n *OBS: OS DADOS SERÃO REGISTRADOS NO SISTEMA APENAS SE A SESSÃO FOR ENCERRADA!!\n\n");

  
  ALUNO[(*A)] = novo_aluno;
  (*A) = (*A) + 1;
} 

void SENHA_A(Discente ALUNO[], int A) {
 char L[128] = "aluno";
 char S[128] = "1234A";
 printf("- DADOS DO ALUNO -\n");
 printf("\nLOGIN: ");
 scanf(" %[^\n]", L);
 printf("SENHA: ");
 scanf(" %[^\n]", S);
 printf("\n");
 system("clear");

 int compS, compL;
 int i; 

 for (i = 0; i <= A ; i++) {
    compL = strcmp(L, ALUNO[i].login);  // sctrcmp - comparação 
    compS = strcmp(S , ALUNO[i].senha);

    if ( compS == 0 && compL == 0 ) {
      int ALU = i;
      DADOS_DO_ALUNO (ALUNO, A, ALU);
      break;
    }
  } 

  if ( compS != 0 || compL != 0 ) {
    printf( VERMELHO " SENHA OU LOGIN INCORRETOS!\n\n" RESET);
  }
}

void DADOS_DO_ALUNO( Discente ALUNO[], int A, int alu) {
  printf("-- DADOS DO ALUNO --\n");
  printf("\n  NOME: %s", ALUNO[alu].nome);
  printf("\n  DATA DE NASCISMENTE: %d/%d/%d", ALUNO[alu].dia, ALUNO[alu].mes,  ALUNO[alu].ano);
  printf("\n  N° DE CELULAR: %d",  ALUNO[alu].numero);
  printf("\n  EMAIL: %s", ALUNO[alu].email);
  printf("\n  LOGIN: %s", ALUNO[alu].login);
  printf("\n  SENHA: %s\n\n", ALUNO[alu].senha);
}

void TURMA_A (Discente ALUNO[], int A, int Z[]) {
  printf("\n TURMA 8ª ANO A:\n");
  printf("\n \t1001 - Ana Oliveira");
  printf("\n \t1002 - Barbara Farias");
  printf("\n \t1003 - Cristiano Albuquerque");
  printf("\n \t1004 - Emilia Campos");
  printf("\n \t1005 - lucas Mendes");
  printf("\n \t1006 - Matheus Cardoso\n");

  int x = 1007;
  int I;
  for( I = 0; I <= A; I++) {
    if (I == A) {
      break;
    }
    Z[I] = x++;
  }

  int i;
  for (i = 0; i <= A; i++) {
    if (i == A) {
      break;
    }
    printf("\t%d - %s\n", Z[i], ALUNO[i].nome);
      
  }
  printf("\n\t 2 - MENU PRINCIPAL\n"); 
}

void SENHA_APAGAR_ALUNO (Discente ALUNO[], int* A, Notas Materia[]) {
  char L[128] = "aluno";
  char S[128] = "1234A";
   printf("- APAGAR CADASTRO -\n");
  printf("\nLOGIN: ");
  scanf(" %[^\n]", L);
  printf("SENHA: ");
  scanf(" %[^\n]", S);
  printf("\n");
  system("clear");

  int compS, compL;
  int i; 

  for (i = 0; i <= (*A) ; i++) {

    compL = strcmp(L, ALUNO[i].login);    // sctrcmp - comparação 
    compS = strcmp(S, ALUNO[i].senha);

    if ( compS == 0 && compL == 0 ) {
      int AL = i;

      APAGAR_ALUNO(ALUNO, A, Materia, AL);
      break;
    }
  } 

  if ( compS != 0 || compL != 0 ) {
    printf( VERMELHO "\n SENHA OU LOGIN INCORRETOS!\n\n" RESET);
  }

}

void APAGAR_ALUNO( Discente ALUNO[], int* A, Notas Materia[], int ex) {
  //DADOS
  strcpy(ALUNO[ex].nome, ALUNO[ex + 1].nome ); 
  ALUNO[ex].dia = ALUNO[ex + 1].dia;
  ALUNO[ex].mes = ALUNO[ex + 1].mes;
  ALUNO[ex].ano = ALUNO[ex + 1].ano;
  ALUNO[ex].numero = ALUNO[ex + 1].numero;
  strcpy(ALUNO[ex].email, ALUNO[ex + 1].email);
  strcpy(ALUNO[ex].login, ALUNO[ex + 1].login);
  strcpy(ALUNO[ex].senha, ALUNO[ex + 1].senha);

  // NOTAS
  Materia[ex].portugues = Materia[ex + 1].portugues;
  Materia[ex].matematica = Materia[ex + 1].matematica;
  Materia[ex].ciencias = Materia[ex + 1].ciencias;
  Materia[ex].geografia = Materia[ex + 1].geografia;
  Materia[ex].historia = Materia[ex + 1].historia;
  Materia[ex].ingles = Materia[ex + 1].ingles;
  Materia[ex].artes = Materia[ex + 1].artes;

  (*A) = (*A) - 1;
  printf("\n *OBS: OS DADOS SERÃO APAGADOS DO SISTEMA APENAS SE A SESSÃO FOR ENCERRADA!!\n\n");  
}

void REGISTROS_ALU(Discente ALUNO[], int A ){
  FILE *aluno1 = fopen ("ALUNOS.dat", "w");
  fprintf(aluno1,"ALUNOS CADASTRADOS: %d\n", A);
  
  int I;
  for (I = 0; I <= A ; I++) {
    if (I == A) {
     break;
    }
   
    fprintf(aluno1,"\n%s\n", ALUNO[I].nome);
    fprintf(aluno1,"%d/%d/%d\n", ALUNO[I].dia,   ALUNO[I].mes,  ALUNO[I].ano);
    fprintf(aluno1,"%d\n", ALUNO[I].numero);
    fprintf(aluno1,"%s\n", ALUNO[I].email);
    fprintf(aluno1,"%s\n", ALUNO[I].login);
    fprintf(aluno1,"%s\n", ALUNO[I].senha);

  }
  fclose(aluno1);
}