// Projeto escola
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#define TAM 5
#include "relatorio_update.h"
#define ERRO_VALID_NOME 4
#define ERRO_VALID_DATA 5
#define ERRO_VALID_SEXO 6
#define ERRO_VALID_CPF 7
#define ERRO_VALID_SEMESTRE 8
#define ERRO_VALID_CODPROF 10


int main(void)
{
    
    setlocale(LC_ALL, "portuguese");
    int opcao,retorno,op;
    int fim = 0, saida = 0;
    Aluno lista_aluno[TAM];
    int qtd_alunos = 0;
    Professor lista_professor[TAM];
    int qtd_professores = 0;
    Disciplina lista_disciplina[TAM];
    int qtd_disciplinas = 0;
    Disciplina lista_alundisc[TAM];
    int qtd_alundisc = 0;
    
    inicializar(lista_aluno, qtd_alunos, lista_professor, qtd_professores, lista_disciplina, qtd_disciplinas);
    
    while (!fim){
        
        opcao = Menudeopcoes();
        
        switch (opcao){
            case 0:{ //programa encerrado
                system("clear");
                printf("\nPrograma encerrado");
                fim = 1; break;}
            case 1: { //menu aluno
                saida = 0;
                while (!saida){
                    printf("\n\n*******Menu do Aluno*******");
                    printf("\n0 - Sair do menu do aluno");
                    printf("\n1 - Cadastrar o aluno");
                    printf("\n2 - Listar alunos cadastrados");
                    printf("\n3 - Listar alunos ordenados por sexo/data/nome");
                    printf("\n4 - Listar aniversariantes do mês");
                    printf("\n5 - Listar alunos matriculados em menos de 3 disciplinas");
                    printf("\n6 - Inserir aluno em disciplina");
                    printf("\n7 - Listar aluno(s) de uma disciplina");
                    printf("\n8 - Excluir aluno de uma disciplina");
                    printf("\n Escolha uma opcao : ");
                    scanf("%d",&op);
                    getchar();
                    
                    switch (op){
                        case 0:{ // saida do menu de aluno
                            system("clear");
                            printf("\nRetornando ao menu principal");
                            saida = 1; break;}
                        case 1: { //cadastrar alunos
                            retorno = cadastroalunos_professores(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                            if (retorno == 0){
                                printf("\nCadastro realizado com sucesso\n");
                                sleep(1);
                                system("clear");
                                qtd_alunos++;
                            }
                            else {
                                printf("\nErro ao realizar cadastro do aluno");
                                 if(retorno == ERRO_VALID_NOME)
                                    printf("\nErro de validacao no NOME\n");
                                if(retorno == ERRO_VALID_DATA)
                    	            printf("\nErro de validacao na DATA\n");
                    	        if(retorno == ERRO_VALID_CPF) 
                    	            printf("\nErro de validacao no CPF\n");
                    	        if(retorno == ERRO_VALID_SEXO)
                    	            printf("\nErro de validacao no SEXO\n");
                                break; 
                            }
                            break;
                            }
                            case 2: { // listar alunos
                                if(qtd_alunos > 0){
                                    listaralunos_professores(lista_aluno, qtd_alunos,lista_professor, qtd_professores);}
                                else {
                                    system("clear");
                                    printf("Não existem alunos cadastrados\n");}
                                break;
                            }
                            case 3: { // Listar alunos  / Listar professores por sexo/data/nome
                                if(qtd_alunos > 0 || qtd_professores > 0){
                                    retorno = ordenar_alunprof_SND(lista_aluno, qtd_alunos, lista_professor, qtd_professores);
                                    if(retorno == 1)
                                        printf("\nListagem feita com sucesso");
                                    else {
                                        system("clear");
                                        printf("\nErro ao listagem de alunos/professores");}
                                }
                                else {
                                    system("clear");
                                    printf("\nNão existem alunos cadastrados");}
                                break;    
                            }
                            case 4: { // Listar aniversariantes do mês aluno/professor
                                if(qtd_alunos > 0 || qtd_professores > 0)
                                    aniversarianteMes(lista_aluno, qtd_alunos, lista_professor, qtd_professores);
                                else {
                                    system("clear");
                                    printf("\nNão existem Alunos/Professores cadastrados");}
                                break;
                                
                            }
                            case 5: { // listar alunos matriculados em menos de 3 disciplinas
                                if(qtd_alunos > 0 && qtd_disciplinas > 0)
                                    listar_alunosmat(lista_aluno, qtd_alunos, lista_alundisc, qtd_alundisc);
                                else{
                                    system("clear");
                                    printf("\nNão existem alunos/disciplinas cadastradas");}
                                break;
                            }
                            case 6: {   // inserir aluno em uma disciplina
                                if(qtd_alunos > 0 && qtd_disciplinas > 0){
                                    retorno = inseriralundisc(lista_aluno, qtd_alunos, lista_disciplina, qtd_disciplinas, lista_alundisc, qtd_alundisc);
                                    if(retorno == 3){
                                        printf("\nSucesso ao inserir aluno ");
                                        qtd_alundisc++;break;}
                                    else
                                        printf("\nErro ao inserir aluno");
                                    break;
                                }
                                else{
                                    system("clear");
                                    printf("Não existem alunos ou disciplinas suficientes cadastrados\n");
                                    break;} 
                                
                            }
                            case 7: { // listar alunos cadastrados em uma disciplina
                                if(qtd_alunos > 0 && qtd_disciplinas > 0){
                                    retorno = listardiscalun (lista_aluno, qtd_alunos, lista_disciplina, qtd_disciplinas, lista_alundisc, qtd_alundisc);
                                    if(retorno == 1)
                                        printf("\nSucesso ao mostrar alunos cadastrados disciplina");
                                    else
                                        printf("\nErro ao listar alunos cadastrados em disciplina");
                                    break;}
                                else{
                                    system("clear");
                                    printf("Não existem alunos, disciplinas suficientes cadastrados\n");
                                    break;}  
                            }
                            case 8: {  // exclui aluno de uma disciplina
                                if(qtd_alundisc > 0){
                                retorno = excluir_alundisc(lista_aluno, qtd_alunos, lista_disciplina, qtd_disciplinas, lista_alundisc, qtd_alundisc);
                                if(retorno == 1)
                                    printf("\nExclusão realizado com sucesso");
                                else
                                    printf("\nFalha na exclusão");
                                break;}
                                else {
                                    system("clear");
                                    printf("\nNão existem alunos cadastrados em disciplinas");}
                                break;    
                            }
                            default:{
                                system("clear");
                                printf("\nOpcao invalida");break;}
                            }
                  }
                  break;
            }
            case 2: { // Menu de professor
                saida = 0;
                while (!saida){
                    printf("\n\n*******Menu do Professor*******");
                    printf("\n0 - Sair do menu do Professor");
                    printf("\n1 - Cadastrar o Profesor");
                    printf("\n2 - Listar Professores cadastrados");
                    printf("\n Escolha uma opcao : ");
                    scanf("%d",&op);
                    getchar();
                    
                    switch (op){
                        case 0:{ // saida do menu de professor
                            system("clear");
                            printf("\nRetornando ao menu principal");
                            saida = 1; break;}
                        case 1: {  // cadastrar professores
                            retorno = cadastroalunos_professores(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                            if (retorno == 0){
                                printf("\nCadastro realizado com sucesso\n");
                                sleep(1);
                                system("clear");
                                qtd_professores++;
                                break;
                            } 
                            else{    
                                printf("\nErro ao realizar cadastro do professor");
                                 if(retorno == ERRO_VALID_NOME)
                                    printf("\nErro de validacao no NOME\n");
                                if(retorno == ERRO_VALID_DATA)
                    	            printf("\nErro de validacao na DATA\n");
                    	        if(retorno == ERRO_VALID_CPF) 
                    	            printf("\nErro de validacao no CPF\n");
                    	        if(retorno == ERRO_VALID_SEXO)
                    	            printf("\nErro de validacao no SEXO\n");
                                break;  
                            }            
                        }
                        case 2: { // listar professores
                            if(qtd_professores > 0)
                                listaralunos_professores(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                            else {
                                system("clear");
                                printf("Não existem professores cadastrados\n");}
                            break; 
                        }
                        default:{
                            system("clear");
                            printf("\nOpcao invalida");break;}
                    } 
                }
                break;
            }
            case 3: { // menu disciplina
                saida = 0;
                if(qtd_professores > 0){
                    while (!saida){
                        printf("\n*******Menu de Disciplina*******");
                        printf("\n0 - Sair do menu de Disciplina");
                        printf("\n1 - Cadastrar Disciplina / Inserir prof disciplina");
                        printf("\n2 - Listar Disciplinas sem alunos");
                        printf("\n Escolha uma opcao : ");
                        scanf("%d",&op);
                        getchar();
                        
                        switch (op){
                            case 0:{ // saida do menu de disciplina
                                system("clear");
                                printf("\nRetornando ao menu principal");
                                saida = 1; break;}
                            case 1: { // cadastro de disciplina / inserir prof em disciplina
                                retorno = cadastrodisciplinas (lista_professor,qtd_professores,lista_disciplina, qtd_disciplinas);
                                if (retorno == 0){
                                    printf("Cadastro realizado com sucesso\n");
                                    sleep(1);
                                    system("clear");
                                    qtd_disciplinas++;}
                                 else {
                                    printf("\nERRRO AO REALIZAR CADASTRO PELOS SEGUINTES MOTIVOS : ");
                                    if(retorno == ERRO_VALID_NOME)
                                        printf("\nErro de validacao no NOME");
                                    if(retorno == ERRO_VALID_SEMESTRE)
                        	            printf("\nErro de validacao no SEMESTRE");
                        	        if(retorno = ERRO_VALID_CODPROF ) 
                        	            printf("\nErro de validacao no CODIGO DO PROFESSOR");
                        	        }
                                break;
                            }
                            case 2: { // listar disciplinas
                                if(qtd_disciplinas > 0)
                                    listardisciplinas (lista_disciplina, qtd_disciplinas);
                                else {
                                    system("clear");
                                    printf("Não existem disciplinas cadastrados\n");}
                                break;
                            }
                            default:{
                                system("clear");
                                printf("\nOpcao invalida");break;}
                        }
                    }
                }
                else {
                    system("clear");
                    printf("\nAinda não existem professores cadastrados para vincular a disciplina");}
                break;
            }
            case 4: { // Menu de exclusao
                if(qtd_alunos > 0 || qtd_professores > 0 || qtd_disciplinas > 0)
                    retorno = exclusao_alunprofdisc(lista_aluno, qtd_alunos, lista_professor, qtd_professores, lista_disciplina, qtd_disciplinas);
                if(retorno == 1){
                    system("clear");
                    printf("\nExclusao feita com sucesso");
                    }
                else 
                    printf("\nErro na exclusao");
                break;}
            case 5: { // Menu de busca
                if(qtd_alunos > 0 || qtd_professores > 0)
                    stringbusca(lista_aluno, qtd_alunos, lista_professor, qtd_professores);
                else {
                    system("clear");
                    printf("\nNão existem alunos/professores cadastrados");}
                break;    
            }
            default: {
                system("clear");
                printf("\nOpção Inválida\n");
            }
        }
}
    return 0;
}
