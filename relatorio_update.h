#define TAM 5
#include <string.h>

typedef struct cadastroAluno{
    
    int matricula;
    char nome [50];
    char dataNascimento [15];
    char cpf [15];
    char sexo;
    
}Aluno;

typedef struct cadastroProfessor{
    
    int matricula;
    char nome [50];
    char dataNascimento [15];
    char cpf [15];
    char sexo;
    
}Professor;

typedef struct cadastroDisciplinas{
    
    char nome [50];
    int codigodisc;
    int semestre;
    int codigoprof;
    int codalun;
    char nomeprofdisc[50];
    char nomealundisc[50];
    int codalundisc;
    
}Disciplina;

//funcoes de validação de aluno e prof 
int validarNome(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
int validarNascimento(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
int validarCpf(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
int validarSexo(Aluno lista_aluno[], int qtd_alunos,Professor lista_professor[],int qtd_professores);
int geradorMatricula(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores); 
//funcoes de validação de disciplina
int validarNomeDisc(Disciplina lista_disciplina[], int qtd_disciplinas);
int validarSemestre(Disciplina lista_disciplina[], int qtd_disciplinas);
int validarCodProf (Professor lista_professor[], int qtd_professores, Disciplina lista_disciplina[], int qtd_disciplinas);
int geradorCodDisc(Disciplina lista_disciplina[], int qtd_disciplinas);

int Menudeopcoes();

//função de exclusao
int exclusao_alunprofdisc (Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores,Disciplina lista_disciplina[], int qtd_disciplinas);
//função de inicializar os vetores
void inicializar(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores,Disciplina lista_disciplina[], int qtd_disciplinas);
//funcoes aluno/professor
int cadastroalunos_professores (Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
void listaralunos_professores (Aluno lista_aluno[], int qtd_alunos,Professor lista_professor[], int qtd_professores);
//funcoes aluno/disciplina/professor 
int inseriralundisc(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas, Disciplina lista_alundisc[], int qtd_alundisc);
int cadastrodisciplinas (Professor lista_professor[], int qtd_professores, Disciplina lista_disciplina[], int qtd_disciplinas);
void listardisciplinas (Disciplina lista_disciplina[], int qtd_disciplinas);
int listardiscalun (Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas, Disciplina lista_alundisc[], int qtd_alundisc);
int excluir_alundisc(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas,Disciplina lista_alundisc[], int qtd_alundisc);
int ordenar_alunprof_SND(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);//função que lista aluno/prof por sexo,data de nascimento e nome
void aniversarianteMes(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
void listar_alunosmat(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_alundisc[], int qtd_alundisc);
void stringbusca(Aluno lista_aluno[], int qtd_alunos,Professor lista_professor[], int qtd_professores);