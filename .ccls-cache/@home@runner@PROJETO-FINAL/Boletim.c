#include <stdio.h> 
#include <string.h> 
#include <strings.h>
#include <stdlib.h>
#include "geral.h"

#define  LARANJA   "\x1b[33m"
#define  AZUL      "\x1b[34m"
#define  VERMELHO  "\x1b[31m"
#define  VERDE     "\x1b[32m"
#define  RESET     "\x1b[0m"

void REGISTRAR_NOTAS (int A, Notas Materia[]) {
  FILE *NOTAS = fopen ("NOTAS.dat","r");

  if (NOTAS == NULL) {
    printf(" \t --- NENHUMA NOTA REGISTRADA \n");
    return;
  }
  
  int i;
  for (i = 0; i <= 20; i++) {
    if (i == A) {
      break;
    } else if ( i > A) {
      break;
    }

    fscanf(NOTAS ," %f\n", &Materia[i].portugues);
    fscanf(NOTAS ," %f\n", &Materia[i].matematica);
    fscanf(NOTAS ," %f\n", &Materia[i].ciencias);
    fscanf(NOTAS ," %f\n", &Materia[i].geografia);
    fscanf(NOTAS ," %f\n", &Materia[i].historia);
    fscanf(NOTAS ," %f\n", &Materia[i].ingles);
    fscanf(NOTAS ," %f\n\n", &Materia[i].artes);
  }

 fclose(NOTAS);

}

void IMPRIMIR_NOTAS(int alu, Discente ALUNO[], Notas Materia[]){
  int notas = alu;
  printf("\n ALUNO(A): %s\n", ALUNO[notas].nome);
  printf("\n Lingua Portuguesa: %.1f", Materia[notas].portugues );
  printf("\n Matematica: %.1f", Materia[notas].matematica);
  printf("\n Ciencias: %.1f", Materia[notas].ciencias);
  printf("\n Geografia: %.1f", Materia[notas].geografia);
  printf("\n Historia: %.1f ", Materia[notas].historia); 
  printf("\n Ingles: %.1f", Materia[notas].ingles);
  printf("\n Artes: %.1f \n\n", Materia[notas].artes);

  MENU_MEDIA(notas, Materia);
}

void MENU_MEDIA (int N, Notas Materia[]) {
  int numero1 = 0;

  if (Materia[N].portugues == 0.0 || Materia[N].matematica == 0.0 ||Materia[N].ciencias == 0.0 || Materia[N].geografia == 0.0 || Materia[N].historia == 0.0 || Materia[N].ingles == 0.0 || Materia[N].artes == 0.0) {

    printf("\n  *** NOTA(S) AINDA NÃO REGISTRADA(S) NO SISTEMA.\n");
    printf("\nPARA CONTINUAR ESCOLHA UMA OPÇÃO ABAIXO.\n\n");
    printf("\t1 - OBTER MEDIA\n");
    printf("\t2 - MENU PRINCIPAL\n");
    printf("\nOPÇÃO: ");
    scanf(" %d", &numero1);
    system ("clear");

    if (numero1 == 1) {
      CALCULAR_NOTAS();

    } else if ( numero1 == 2 ) {
      return;

    } else {
      printf(VERMELHO "**OPÇÃO INVALIDA\n" RESET);
    }   
  } else {
    printf( VERDE "\tAPROVADO(A)!\n" RESET);
  }
}

void CALCULAR_NOTAS() {
  float teste, prova;  
  int MEDIA = 7;

  printf(" *PARA OBTER UMA MEDIA INFORME SUA NOTA DE TESTE E PROVA.\n");
  printf("\nTESTE: ");
  scanf(" %f", &teste);
  printf("PROVA: ");
  scanf (" %f", &prova);
  system ("clear");

  printf("\nTESTE = %.1f", teste);
  printf("\nPROVA = %.1f", prova);

  float media1 = (teste + prova)/2;
  printf("\nMEDIA: %.1f\n\n", media1);

  if(media1 >= MEDIA){
    printf( VERDE "\tAPROVADO(A)!\n\n" RESET);
  } else { 
    printf( VERMELHO "\tREPROVADO(A)!\n\n" RESET);
  }   

  printf("*ESSA MEDIA É APENAS UMA ESTIMATIVA, NÃO SERA REGISTRADA NO SISTEMA!!!\n\n");
}

void SENHA_CADASTRAR_NOTAS(Docente professor[], int P, Notas Materia[], int A, Discente ALUNO[]) {
  char L[128] = "prof";
  char S[128] = "1234P";
  printf("- CADASTRAR NOTAS -\n");
  printf("\nLOGIN: ");
  scanf(" %[^\n]", L);
  printf("SENHA: ");
  scanf(" %[^\n]", S);
  system ("clear");
  printf("\n");

  int compaS2, compaL2;
  int i; 

  for (i = 0; i <= P ; i++) {    
    compaL2 = strcmp(L, professor[i].login);    // sctrcmp - comparação 
    compaS2 = strcmp(S, professor[i].senha); 
   
    if (compaS2 == 0 && compaL2 == 0 ) {  
      int prof = i;
      MATERIAS(professor, P, Materia,  A, ALUNO, prof);
      break;
    } 
  }

  if (compaL2 != 0 ||compaS2 != 0) {
    printf( VERMELHO "SENHA OU LOGIN INCORRETOS!\n\n" RESET);
  }
}

void MATERIAS( Docente professor[], int P, Notas Materia[], int A, Discente ALUNO[], int M) {

  int contagem = 0;
  
  if (strcasecmp (professor[M].formacao, "portugues") == 0) {
    
    for (int i = 0; i < A; i++) {
      if (Materia[i].portugues != 0.0 ) {  
        contagem ++; 

      } else if (Materia[i].portugues == 0.0 ) { break; }

      if ( contagem == A ) {
        printf( LARANJA "**NOTAS DE PORTUGUÊS JÁ ESTÃO REGISTRADAS!!\n" RESET);
        return;
      }
    }

    PORTUGUES ( Materia,  A, ALUNO);

  } else if (strcasecmp (professor[M].formacao, "matematica") == 0) {

    for (int i = 0; i < A; i++) {
      if (Materia[i].matematica != 0) { 
        contagem ++; 
      
      }  else if (Materia[i].matematica == 0.0 ) { break; }

      if (contagem == A) {
        printf( LARANJA "**NOTAS DE MATEMÁTICA JÁ ESTÃO REGISTRADAS!!\n" RESET);
        return;
      }
    }

    MATEMATICA(Materia,  A, ALUNO);
       
  } else if (strcasecmp (professor[M].formacao, "ciencias") == 0) {

    for (int i = 0; i < A; i++) {
      if (Materia[i].ciencias != 0) { 
        contagem ++; 
        
      } else if (Materia[i].ciencias == 0.0 ) { break; }

      if (contagem == A) {
        printf( LARANJA "**NOTAS DE CIÊNCIAS JÁ ESTÃO REGISTRADAS!!\n" RESET);
        return;
      }
    }

    CIENCIAS(Materia,  A, ALUNO);

  } else if (strcasecmp (professor[M].formacao, "historia") == 0) {

    for (int i = 0; i < A; i++) {
      if (Materia[i].historia != 0) { 
        contagem ++; 
        
      } else if (Materia[i].historia == 0.0 ) { break; }

      if (contagem == A) {
        printf( LARANJA "**NOTAS DE HISTÓRIA JÁ ESTÃO REGISTRADAS!!\n" RESET);
        return;
      }
    }

    HISTORIA(Materia,  A, ALUNO);

  } else if (strcasecmp (professor[M].formacao, "geografia")== 0) {

    for (int i = 0; i < A; i++) {
      if (Materia[i].geografia != 0) { 
        contagem ++; 
        
      } else if (Materia[i].geografia == 0.0 ) { break; }

      if (contagem == A) {
        printf( LARANJA "**NOTAS DE GEOGRAFIA JÁ ESTÃO REGISTRADAS!!\n" RESET);
        return;
      }
    }

    GEOGRAFIA(Materia,  A, ALUNO);

  } else if (strcasecmp ( professor[M].formacao, "ingles") == 0) {

    for (int i = 0; i < A; i++) {
      if (Materia[i].ingles != 0) { 
        contagem ++; 
        
      } else if (Materia[i].ingles == 0.0 ) { break; }

      if (contagem == A) {
        printf( LARANJA "**NOTAS DE INGLÊS JÁ ESTÃO REGISTRADAS!!\n" RESET);
        return;
      }
    }

    INGLES(Materia,  A, ALUNO);

  } else if (strcasecmp ( professor[M].formacao, "artes") == 0) {

    for (int i = 0; i < A; i++) {
      if (Materia[i].artes != 0) { 
        contagem ++; 
      
      } else if (Materia[i].artes == 0.0 ) { break; }

      if (contagem == A) {
        printf( LARANJA "**NOTAS DE ARTES JÁ ESTÃO REGISTRADAS!!\n" RESET);
        return;
      }
    }

    ARTES(Materia,  A, ALUNO);
  }
  system ("clear");
  printf("\n *OBS: AS NOTAS SERÃO REGISTRADAS NO SISTEMA APENAS SE A SESSÃO FOR ENCERRADA!!\n\n");
}

void PORTUGUES(Notas Materia[], int A, Discente ALUNO[]) { 
  printf("\n TURMA 8ª ANO A - NOTAS \n");
  printf("\t\t[PORTUGUES]\n\n");

  int x = 0;    
  int i;
  for ( i = 0; i <= A; i++) {
    x++;
    if (i == A) {
      break;
    }

    if (Materia[i].portugues == 0) {
      printf("\t%d - %s  ", x, ALUNO[i].nome);
      scanf(" %f", &Materia[i].portugues);
      printf("\n");
    } 
  }
}

void MATEMATICA(Notas Materia[], int A, Discente ALUNO[]) { 
  printf("\n TURMA 8ª ANO A - NOTAS \n");
  printf("\t\t[MATEMATICA]\n\n");

  int x = 0;    
  int i;
  for (i = 0; i <= A; i++) {
    x++;
    if (i == A) {
      break;
    }
    
    if (Materia[i].matematica == 0) {
      printf("\t%d - %s  ", x, ALUNO[i].nome);
      scanf(" %f", &Materia[i].matematica);
      printf("\n");
    }
  }
}

void CIENCIAS(Notas Materia[], int A, Discente ALUNO[]) { 
  printf("\n TURMA 8ª ANO A - NOTAS \n");
  printf("\t\t[CIENCIAS]\n\n");

  int x = 0;    
  int i;
  for ( i = 0; i <= A; i++) {
    x++;
    if (i == A) {
      break;
    }
    
    if (Materia[i].ciencias == 0) {
      printf("\t%d - %s  ", x, ALUNO[i].nome);
      scanf(" %f", &Materia[i].ciencias);
      printf("\n");
    }
  }
}

void HISTORIA(Notas Materia[], int A, Discente ALUNO[]) { 
  printf("\n TURMA 8ª ANO A - NOTAS \n");
  printf("\t\t[HISTORIA]\n\n");

  int x = 0;    
  int i;
  for (i = 0; i <= A; i++) {
    x++;
    if (i == A) {
      break;
    }
    
    if (Materia[i].historia == 0) {
      printf("\t%d - %s  ", x, ALUNO[i].nome);
      scanf(" %f", &Materia[i].historia);
      printf("\n");
    }
  }
}

void GEOGRAFIA(Notas Materia[], int A, Discente ALUNO[]) { 
  printf("\n TURMA 8ª ANO A - NOTAS \n");
  printf("\t\t[GEOGRAFIA]\n\n");

  int x = 0;    
  int i;
  for (i = 0; i <= A; i++) {
    x++;
    if (i == A) {
      break;
    }
    
    if (Materia[i].geografia == 0) {
      printf("\t%d - %s  ", x, ALUNO[i].nome);
      scanf(" %f", &Materia[i].geografia);
      printf("\n");
    }
  }
}

void INGLES(Notas Materia[], int A, Discente ALUNO[]) { 
  printf("\n  TURMA 8ª ANO A - NOTAS \n");
  printf("\t\t[INGLES]\n\n");

  int x = 0;    
  int i;
  for ( i = 0; i <= A; i++) {
    x++;
    if (i == A) {
      break;
    }
    
    if (Materia[i].ingles == 0) {
      printf("\t%d - %s  ", x, ALUNO[i].nome);
      scanf(" %f", &Materia[i].ingles);
      printf("\n");
    }  
  }
}

void ARTES(Notas Materia[], int A, Discente ALUNO[]) { 
  printf("\n TURMA 8ª ANO A - NOTAS \n");
  printf("\t\t[ARTES]\n\n");

  int x = 0; 
  int i;   
  for (i = 0; i <= A; i++) {
    x++;
    if (i == A) {
      break;
    }
    
    if (Materia[i].artes == 0) {
      printf("\t%d - %s  ", x, ALUNO[i].nome);
      scanf(" %f", &Materia[i].artes);
      printf("\n");
    }
  }
}

void REGISTROS_NOTAS (Notas Materia[], int A) {
  FILE *NOTAS = fopen ("NOTAS.dat","w");

  int i;
  for ( i = 0; i <= A; i++ ) {
    if (i == A) {
      break;
    }
    fprintf(NOTAS," %.1f\n", Materia[i].portugues);
    fprintf(NOTAS," %.1f\n", Materia[i].matematica);
    fprintf(NOTAS," %.1f\n", Materia[i].ciencias);
    fprintf(NOTAS," %.1f\n", Materia[i].geografia);
    fprintf(NOTAS," %.1f\n", Materia[i].historia);
    fprintf(NOTAS," %.1f\n", Materia[i].ingles);
    fprintf(NOTAS," %.1f\n\n", Materia[i].artes);

  }
  fclose(NOTAS);
} 
