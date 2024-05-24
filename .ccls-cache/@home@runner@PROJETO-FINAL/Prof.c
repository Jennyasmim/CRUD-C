#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include "geral.h"

#define  LARANJA   "\x1b[33m"
#define  AZUL      "\x1b[34m"
#define  VERMELHO  "\x1b[31m"
#define  VERDE     "\x1b[32m"
#define  RESET     "\x1b[0m"

void REGISTRAR_PROF( Docente professor[], int* P) {
  FILE *prof = fopen ("PROFESSORES.dat", "r");

  if (prof == NULL) {
    printf(" \t --- NENHUM PROFESSOR CADASTRADO\n");
    return;
  }

  fscanf(prof,"PROFESSORES CADASTRADOS: %d\n", &(*P));
  
  int i;
  for (i = 0; i <= (*P) ; i++) {
    if (i == (*P)) {
      break;
    }

    fscanf(prof,"%[^\n]\n",professor[i].nome);
    fscanf(prof,"%d/%d/%d\n",&professor[i].dia, &professor[i].mes, &professor[i].ano);
    fscanf(prof,"%d\n", &professor[i].numero);
    fscanf(prof,"%[^\n]\n",professor[i].formacao);
    fscanf(prof,"%[^\n]\n",professor[i].email);
    fscanf(prof,"%[^\n]\n",professor[i].login);
    fscanf(prof,"%[^\n]\n",professor[i].senha);

  }
  fclose(prof);
}

void PAGINA_PROF() {
  printf(" PÁGINA DO DOCENTE:\n\n");
  printf("\t P - CADASTRO DE DOCENTE\n ");
  printf("\t D - DADOS DE DOCENTE\n ");
  printf("\t N - CADASTRAR NOTAS\n");
  printf("\t L - LISTA DE PROFESSORES\n");
  printf("\t X - EXCLUIR CADASTRO\n\n");

  printf("\t E - VOLTAR AO MENU PRINCIPAL");
  printf("\n \t S - SAIR DO PROGRAMA\n");
  
}

void CADASTRO_DOCENTE(Docente professor[], int* P) {
  int quant = 20;

  if( (*P) >= quant ) {
    printf( VERMELHO "\n** A QUANTIDADE MÁXIMA DE PROFESSORES CADASTRADOS FOI ATINGIDA **\n\n" RESET);
    return;
  }

  Docente novo_educador;
  
  printf("- CADASTRO DE DOCENTE -\n\n");
  printf(" NOME: ");
  scanf(" %[^\n]", novo_educador.nome);
  printf(" DATA DE NASCIMENTO(dd/mm/aaaa): ");
  scanf(" %d /  %d /  %d", &novo_educador.dia, &novo_educador.mes, &novo_educador.ano);
  printf(" N° DE CELULAR: ");
  scanf(" %d", &novo_educador.numero);
  printf(" PROFESSOR(A) DE: ");
  scanf(" %[^\n]", novo_educador.formacao);
  printf(" EMAIL: ");
  scanf(" %[^\n]", novo_educador.email);
  printf(" LOGIN: ");
  scanf(" %[^\n]", novo_educador.login);
  printf(" SENHA: ");
  scanf(" %[^\n]", novo_educador.senha);
  system ("clear");
  
  printf("\n *OBS: OS DADOS SERÃO REGISTRADOS NO SISTEMA APENAS SE A SESSÃO FOR ENCERRADA!!\n\n");

  professor[(*P)] = novo_educador;
  (*P) = (*P) + 1;
} 

void SENHA_P(Docente professor[], int P) {
  char L[128] = "prof";
  char S[128] = "1234P";
  printf("- DADOS DO DOCENTE -\n");
  printf("\nLOGIN: ");
  scanf(" %[^\n]", L);
  printf("SENHA: ");
  scanf(" %[^\n]", S);
  system("clear");
  printf("\n");
 
  int compaS2, compaL2;
  int i; 

  for (i = 0; i <= P ; i++) {
    compaL2 = strcmp(L,  professor[i].login);    // sctrcmp - comparação 
    compaS2 = strcmp(S,  professor[i].senha); 
   
    if ( compaS2 == 0 && compaL2 == 0 ) {
      int D = i;
      DADOS_DO_DOCENTE (D, professor, P);
      break;
    } 
  }

  if ( compaS2 != 0 || compaL2 != 0 ) {
    printf( VERMELHO " SENHA OU LOGIN INCORRETOS!\n\n" RESET);
  }
}

void DADOS_DO_DOCENTE(int d, Docente professor[], int P) {
  printf("-- DADOS DO DOCENTE --\n");
  printf("\n  NOME: %s",professor[d].nome);
  printf("\n  DATA DE NASCISMENTE: %d/%d/%d",professor[d].dia, professor[d].mes, professor[d].ano);
  printf("\n  N° DE CELULAR: %d", professor[d].numero);
  printf("\n  PROFESSOR(A) DE: %s", professor[d].formacao);
  printf("\n  EMAIL: %s",professor[d].email);
  printf("\n  LOGIN: %s",professor[d].login);
  printf("\n  SENHA: %s\n\n", professor[d].senha);

}

void LISTA_PROF(Docente professor[], int P) {
  printf("\nLISTA DE PROFESSORES:\n\n");
  int x = 0;
  int i;
  for (i = 0; i <= P; i++) {
    x++;
    if (i == P) {
      break;
    }
  
    printf("\t%d. %s    --> %s\n", x, professor[i].nome, professor[i].formacao);
  }
  printf("\n\n");
}

void SENHA_APAGAR_PROF (Docente professor[], int* P) {
  char L[128] = "prof";
  char S[128] = "1234P";
  printf("- APAGAR CADASTRO -\n");
  printf("\nLOGIN: ");
  scanf(" %[^\n]", L);
  printf("SENHA: ");
  scanf(" %[^\n]", S);
  system ("clear");
  printf("\n");
  system("clear");

  int compaS2, compaL2;
  int i; 

  for (i = 0; i <= (*P) ; i++) {
    
    compaL2 = strcmp(L, professor[i].login);    // sctrcmp - comparação 
    compaS2 = strcmp(S, professor[i].senha); 
   
    if (compaS2 == 0 && compaL2 == 0 ) {  
      int prof = i;
      APAGAR_PROF(prof, professor, P);
      
      break;
    } 
  }
  
  if ( compaS2 != 0 || compaL2 != 0 ) {
    printf( VERMELHO " SENHA OU LOGIN INCORRETOS!\n\n" RESET);
  }
}

void APAGAR_PROF(int ex, Docente professor[], int* P) {
    
  strcpy(professor[ex].nome, professor[ex + 1].nome);
  professor[ex].dia = professor[ex + 1].dia;
  professor[ex].mes = professor[ex + 1].mes;
  professor[ex].ano = professor[ex + 1].ano;
  professor[ex].numero = professor[ex + 1].numero;
  strcpy(professor[ex].formacao, professor[ex + 1].formacao);
  strcpy(professor[ex].email, professor[ex + 1].email);
  strcpy(professor[ex].login, professor[ex + 1].login);
  strcpy(professor[ex].senha, professor[ex + 1].senha);
  
  (*P) = (*P) - 1;
  printf("\n *OBS: OS DADOS SERÃO APAGADOS DO SISTEMA APENAS SE A SESSÃO FOR ENCERRADA!!\n\n");
}

void REGISTROS_PROF(Docente professor[], int P) {
  FILE *prof = fopen ("PROFESSORES.dat", "w");
  fprintf(prof,"PROFESSORES CADASTRADOS: %d\n", P);

  int i;
  for (i = 0; i <= P ; i++) {
    if (i == P) {
      break;
    }
    fprintf(prof,"\n%s\n",professor[i].nome);
    fprintf(prof,"%d/%d/%d\n",professor[i].dia, professor[i].mes, professor[i].ano);
    fprintf(prof,"%d\n",professor[i].numero);
    fprintf(prof,"%s\n",professor[i].formacao);
    fprintf(prof,"%s\n",professor[i].email);
    fprintf(prof,"%s\n",professor[i].login);
    fprintf(prof,"%s\n",professor[i].senha);
  }
  fclose(prof);

}

void SAIR () {
  printf("\n______________________________________________\n\n\n");
  printf("  \t\t\t  SESSÃO ENCERRADA.\n");
  printf("\n______________________________________________\n\n\n");

}
