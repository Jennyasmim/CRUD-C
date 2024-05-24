#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "geral.h"

#define LARANJA "\x1b[33m"
#define AZUL "\x1b[34m"
#define VERMELHO "\x1b[31m"
#define VERDE "\x1b[32m"
#define RESET "\x1b[0m"

// variáveis globais
Discente ALUNO[20];
Docente professor[20];
Notas Materia[20];
int A = 0; // numeros de alunos
int P = 0; // numeros de professores
int Z[20]; // codigo da lista de alunos

int main() {
	system("clear");
	REGISTRAR_ALUNO(ALUNO, &A);
	REGISTRAR_PROF(professor, &P);
	REGISTRAR_NOTAS(A, Materia);

	printf(LARANJA "\n --- BEM VINDO(A) AO SISTEMA EDUCACIONAL DA ESCOLA "
				   "EQUIPE ---\n\n" RESET);

	while (1) {
		float prova = 0;
    float teste = 0;
		char opcao = 0;
    char opcao1 = 0;
		int codigo = 0;
		int numero2 = 0;

		ENTRADA(); // no arquivo alu.c

		printf("\nOPÇÃO: ");
		scanf(" %d", &numero2);
		system("clear");

		if (numero2 == 1) {
			PAGINA_ALUNO();

			printf("\nOPÇÃO: ");
			scanf(" %c", &opcao1);
			system("clear");

		} else if (numero2 == 2) {
			PAGINA_PROF();

			printf("\nOPÇÃO: ");
			scanf(" %c", &opcao);
			system("clear");

		} else if (numero2 == 0) {
			SAIR();
			break;
		}

		if (opcao == 'E' || opcao == 'e' || opcao1 == 'E' || opcao1 == 'e') {
			continue;

		} else if (
			opcao == 'L' || opcao == 'l' || opcao1 == 'L' || opcao1 == 'l') {
			LISTA_PROF(professor, P);

		} else if (
			opcao == 'S' || opcao == 's' || opcao1 == 'S' || opcao1 == 's') {
			SAIR();
			break;

		} else if (opcao == 'P' || opcao == 'p') {
			CADASTRO_DOCENTE(professor, &P);

		} else if (opcao == 'D' || opcao == 'd') {
			SENHA_P(professor, P);

		} else if (opcao == 'X' || opcao == 'x') {
			SENHA_APAGAR_PROF(professor, &P);

		} else if (opcao == 'N' || opcao == 'n') {
			SENHA_CADASTRAR_NOTAS(professor, P, Materia, A, ALUNO);

		} else if (opcao1 == 'C' || opcao1 == 'c') {
			CADASTRO_ALUNO(ALUNO, &A);

		} else if (opcao1 == 'A' || opcao1 == 'a') {
			SENHA_A(ALUNO, A);

		} else if (opcao1 == 'R' || opcao1 == 'r') {
			SENHA_APAGAR_ALUNO(ALUNO, &A, Materia);

		} else if (opcao1 == 'T' || opcao1 == 't') {
			TURMA_A(ALUNO, A, Z);

			printf("\n OPÇÃO:  ");
			scanf("%d", &codigo);
			system("clear");

			if (codigo == 1001) {
				printf("\n\n ALUNA: Ana Oliveira \n");
				printf("\n Lingua Portuguesa: 8.5");
				printf("\n Matematica: 7.5");
				printf("\n Ciencias: 7.0");
				printf("\n Geografia: 9.0");
				printf("\n Historia: 10.0  ");
				printf("\n Ingles: 9.0");
				printf("\n Artes: 7.0 \n\n");
				printf(VERDE "\tAPROVADO(A)!\n\n" RESET);

			} else if (codigo == 1002) {
				printf("\n\n ALUNA: Barbara Farias \n");
				printf("\n Lingua Portuguesa: 6.5");
				printf("\n Matematica: 7.0");
				printf("\n Ciencias: 6.0");
				printf("\n Geografia: 8.0");
				printf("\n Historia: 7.5");
				printf("\n Ingles: 8.5");
				printf("\n Artes: 10.0 \n\n");
				printf(VERMELHO "\n Reprovado(a)!\n\n" RESET);

			} else if (codigo == 1003) {
				printf("\n\n ALUNO: Cristiano Albuquerque \n");
				printf("\n Lingua Portuguesa: 8.0");
				printf("\n Matematica: 9.0");
				printf("\n Ciencias: 7.5");
				printf("\n Geografia: 7.0");
				printf("\n Historia: 8.5 ");
				printf("\n Ingles: 8.5");
				printf("\n Artes: 10.0 \n\n");
				printf(VERDE "\nAprovado(a)!\n\n" RESET);

			} else if (codigo == 1004) {
				printf("\n\n ALUNA: Emilia Campos\n");
				printf("\n Lingua Portuguesa: 9.0");
				printf("\n Matematica: 7.0");
				printf("\n Ciencias: 7.5");
				printf("\n Geografia: 7.0");
				printf("\n Historia: 8.5");
				printf("\n Ingles: 8.0");
				printf("\n Artes: 7.5 \n\n");
				printf(VERDE "\nAprovado(a)!\n\n" RESET);

			} else if (codigo == 1005) {
				printf("\n \nALUNO: lucas Mendes\n");
				printf("\n Lingua Portuguesa: 7.0");
				printf("\n Matematica: 7.0");
				printf("\n Ciencias: 9.5");
				printf("\n Geografia: 7.5");
				printf("\n Historia: 8.5 ");
				printf("\n Ingles: 8.0");
				printf("\n Artes: 10.0 \n\n");
				printf(VERDE "\nAprovado(a)!\n\n" RESET);

			} else if (codigo == 1006) {
				printf("\n \nALUNO: Matheus Cardoso\n");
				printf("\n Lingua Portuguesa: 6.0");
				printf("\n Matematica: 9.0");
				printf("\n Ciencias: 7.5");
				printf("\n Geografia: 8.0");
				printf("\n Historia: 7.5 ");
				printf("\n Ingles: 7.5");
				printf("\n Artes: 10.0 \n\n");
				printf(VERMELHO "\nReprovado(a)!\n\n" RESET);

			} else if (codigo == 2) {
				continue;

			} else {
				int cont2 = 0;
				int i;
				for (i = 0; i < A; i++) {
					int cont1 = 0;

					if (Z[i] == codigo) {
						cont2 = cont1;
						IMPRIMIR_NOTAS(i, ALUNO, Materia);
						break;
					}
					cont1 = 1;
					cont2 = cont1;
				}
				if (cont2 == 1) {
					printf(VERMELHO "**OPÇÃO INVALIDA\n" RESET);
				}
			}

		} else {
			printf(VERMELHO "**OPÇÃO INVALIDA\n" RESET);
		}

		printf(AZUL "\n\t------ Comando Processado ------\n\n\n" RESET);
	}

	REGISTROS_NOTAS(Materia, A);
	REGISTROS_ALU(ALUNO, A);
	REGISTROS_PROF(professor, P);
	return 0;
}