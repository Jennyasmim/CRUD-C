// PROFESSOR
typedef struct CADASTRAR_DOCENTE {
  char nome[128]; 
  int dia, mes, ano;
  int numero;
  char email[128]; 
  char formacao[128]; 
  char login[128];    
  char senha[20];
} Docente;

// notas
typedef struct NOTAS {
  float portugues;
  float matematica; 
  float ciencias; 
  float geografia;
  float historia;
  float ingles;
  float artes;
} Notas;

//aluno
typedef struct CADASTRAR_DISCENTE {
  char nome[128];
  int dia, mes, ano;
  int numero;
  char email[128];
  char login[128];    
  char senha[20];
} Discente;


//professor
void REGISTRAR_PROF(Docente professor[], int* P);              
void PAGINA_PROF();                  
void CADASTRO_DOCENTE(Docente professor[], int* P);
void SENHA_P(Docente professor[], int P);                        
void DADOS_DO_DOCENTE (int prof, Docente professor[], int P);         
void LISTA_PROF(Docente professor[], int P);                     
void SENHA_APAGAR_PROF(Docente professor[], int* P);              
void APAGAR_PROF(int ex, Docente professor[], int* P);              
void REGISTROS_PROF(Docente professor[], int P);                 
void SAIR(); 



// ALUNO
void REGISTRAR_ALUNO(Discente ALUNO[], int* A);                
void ENTRADA();                        
void PAGINA_ALUNO();                   
void CADASTRO_ALUNO(Discente ALUNO[], int* A);                 
void SENHA_A(Discente ALUNO[], int A);                        
void DADOS_DO_ALUNO (Discente ALUNO[], int A, int alu);  
void TURMA_A(Discente ALUNO[], int A, int Z[]);                        
void SENHA_APAGAR_ALUNO(Discente ALUNO[], int* A, Notas Materia[]);             
void APAGAR_ALUNO(Discente ALUNO[], int* A, Notas Materia[], int ex);  
void REGISTROS_ALU(Discente ALUNO[], int A);                  

// NOTAS
void REGISTRAR_NOTAS(int A, Notas Materia[]);
void IMPRIMIR_NOTAS(int alu, Discente ALUNO[], Notas Materia[]);       
void MENU_MEDIA (int N, Notas Materia[]);             
void CALCULAR_NOTAS();               
void SENHA_CADASTRAR_NOTAS (Docente professor[], int P, Notas Materia[], int A, Discente ALUNO[]);        
void MATERIAS(Docente professor[], int P, Notas Materia[], int A, Discente ALUNO[], int M);                
void PORTUGUES(Notas Materia[], int A, Discente ALUNO[]);                    
void MATEMATICA(Notas Materia[], int A, Discente ALUNO[]);                   
void CIENCIAS(Notas Materia[], int A, Discente ALUNO[]);                     
void HISTORIA(Notas Materia[], int A, Discente ALUNO[]);                     
void GEOGRAFIA(Notas Materia[], int A, Discente ALUNO[]);                    
void INGLES(Notas Materia[], int A, Discente ALUNO[]);                       
void ARTES(Notas Materia[], int A, Discente ALUNO[]);                        
void REGISTROS_NOTAS(Notas Materia[], int A);                   