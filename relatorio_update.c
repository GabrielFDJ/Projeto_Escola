#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 5
#include "relatorio_update.h"
#define ERRO_VALID_NOME 4
#define ERRO_VALID_DATA 5
#define ERRO_VALID_SEXO 6
#define ERRO_VALID_CPF 7
#define ERRO_VALID_SEMESTRE 8
#define ERRO_VALID_CODPROF 10

int contAL = 0, contN = 0, contDT = 0, contCP = 0 , contS = 0, ContMatAlun = 1000,ContMatProf = 1000, ContCodDisciplina = 10000;//contadores globais
int Verific = 0; // auxiliar para verificar as validações
int escolha;// armazena a opcao escolhida no menu

int Menudeopcoes(){
    printf("\n\nOpcoes disponiveis");
    printf("\n0 - Sair");
    printf("\n1 - Menu do Aluno");
    printf("\n2 - Menu do Professor");
    printf("\n3 - Menu da Disciplina");
    printf("\n4 - Menu de Exclusao");
    printf("\n5 - Menu de busca aluno/professor");
    printf("\n\nDigite uma opcao : ");
    scanf(" %d",&escolha);
    getchar();
    system("clear");
    return escolha;
}

void inicializar(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores,Disciplina lista_disciplina[], int qtd_disciplinas){
    int i;
    for(i = 0; i < TAM;i++){
        lista_aluno[i].matricula = -1;
        lista_professor[i].matricula = -1;
        lista_disciplina[i].codigodisc = -1;
    }
}

int cadastroalunos_professores(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){ // funcao que recebe o cadastro de alunos e professores
    //variaveis para modificar o aluno e professor
    system("clear");
    int aux = 0, fim = 0, opcao = 0, ant = 0, i, op, saida = 0, atualiz = 0;
    //cadastro alunos
    Verific = 0;
    int retorno = 0;
    if(escolha == 1){
        
        printf("\n******* Bem vindo a central de cadastro de alunos *******\n");
        printf("Matricula sera gerada automaticamente caso os dados estiverem corretos\n");
        
        printf("\nDigite o nome: ");
        fgets(lista_aluno[qtd_alunos].nome, 50, stdin);
        retorno = validarNome(lista_aluno, qtd_alunos, lista_professor, qtd_professores);
        if(retorno == ERRO_VALID_NOME) 
            return ERRO_VALID_NOME;
        
        printf("Digite o sexo: ");
        scanf(" %c",&lista_aluno[qtd_alunos].sexo);
        getchar();
        retorno = validarSexo(lista_aluno, qtd_alunos, lista_professor,  qtd_professores);
        if(retorno == ERRO_VALID_SEXO) 
            return ERRO_VALID_SEXO;
        
        printf("Digite a data de nascimento no formato ' 08/06/2001 ' : ");
        fgets(lista_aluno[qtd_alunos].dataNascimento, 15,stdin);
        size_t ln = strlen(lista_aluno[qtd_alunos].dataNascimento) - 1; 
        if (lista_aluno[qtd_alunos].dataNascimento[ln] == '\n')
            lista_aluno[qtd_alunos].dataNascimento[ln] = '\0';
        retorno = validarNascimento(lista_aluno, qtd_alunos, lista_professor,  qtd_professores);
        if(retorno == ERRO_VALID_DATA) 
            return ERRO_VALID_DATA;
        
        printf("Digite o CPF: ");
        fgets(lista_aluno[qtd_alunos].cpf, 15,stdin);
        ln = strlen(lista_aluno[qtd_alunos].cpf) - 1; 
        if (lista_aluno[qtd_alunos].cpf[ln] == '\n')
            lista_aluno[qtd_alunos].cpf[ln] = '\0';
        retorno = validarCpf(lista_aluno, qtd_alunos, lista_professor,  qtd_professores);
        if(retorno == ERRO_VALID_CPF) 
            return ERRO_VALID_CPF;
        
        if(Verific == 0){
            geradorMatricula(lista_aluno, qtd_alunos, lista_professor,  qtd_professores);
            
            printf("\nDigite 1 se deseja acessar o menu de modificação do aluno , caso contrario digite outro numero : ");
            scanf("%d",&aux);
            getchar();
            
            if(aux == 1){
                while(!fim){
                
                    printf("\n*******Menu de modificação principal*******");
                    printf("\n Digite 0 para sair do menu de modificação");
                    printf("\n Digite 1 se deseja alterar o cadastro do aluno");
                    printf("\n Digite 2 se deseja excluir o aluno atual");
                    printf("\n Escolha uma opcao : ");
                    scanf("%d",&opcao);
                    getchar();
            
                    switch (opcao){
                            case 0: {
                                printf("\nSaida do menu modificação retornando ao menu de opções\n");
                                return 0;fim = 1; break;}
                            case 1: {
                                while (!saida){
                                    printf("\n*******Menu de modificação secundário*******");
                                    printf("\n Digite 0 para sair do menu de modificação");
                                    printf("\n Digite 1 se deseja alterar o nome do aluno");
                                    printf("\n Digite 2 se deseja alterar o sexo do aluno");
                                    printf("\n Digite 3 se deseja alterar a data de nascimento do aluno");
                                    printf("\n Digite 4 se deseja alterar o cpf do aluno");
                                    printf("\n Escolha uma opcao : ");
                                    scanf("%d",&op);
                                    getchar();
                                    switch (op){
                                        case 0:
                                        {
                                            printf("\nSaida do menu modificação secundário retornando ao menu principal\n");
                                            saida = 1; break;
                                        }
                                        case 1:
                                        {
                                            while(!atualiz){
                                                printf("\nDigite o nome: ");
                                                fgets(lista_aluno[qtd_alunos].nome, 50, stdin);
                                                retorno = validarNome(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                                                if(retorno == ERRO_VALID_NOME)
                                                    printf("\nErro ao validar o nome");
                                                else
                                                    return 0;
                                                    
                                            }
                                        }
                                        case 2:
                                        {
                                            while(!atualiz){
                                                printf("\nDigite o sexo: ");
                                                scanf(" %c",&lista_aluno[qtd_alunos].sexo);
                                                getchar();
                                                retorno = validarSexo(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                                                if(retorno == ERRO_VALID_SEXO) 
                                                    printf("\nErro ao validar o Sexo");
                                                else    
                                                    return 0;
                                            }
                                        }
                                        case 3:
                                        {
                                            while(!atualiz){
                                            printf("\nDigite a data de nascimento no formato ' 08/06/2000 ' : ");
                                            fgets(lista_aluno[qtd_alunos].dataNascimento, 15,stdin);
                                            size_t ln = strlen(lista_aluno[qtd_alunos].dataNascimento) - 1; 
                                            if (lista_aluno[qtd_alunos].dataNascimento[ln] == '\n')
                                                lista_aluno[qtd_alunos].dataNascimento[ln] = '\0';
                                            retorno = validarNascimento(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                                            if(retorno == ERRO_VALID_DATA) 
                                                printf("\nErro ao validar o Data, tente novamente");
                                            else    
                                                return 0; 
                                            }
                                        }
                                        case 4: 
                                        {
                                            while(!atualiz){
                                                printf("\nDigite o CPF: ");
                                                fgets(lista_aluno[qtd_alunos].cpf, 15,stdin);
                                                retorno = validarCpf(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                                                if(retorno == ERRO_VALID_CPF) 
                                                    printf("\nErro ao validar o Cpf, tente novamente");
                                                else    
                                                    return 0; 
                                            }   
                                        }
                                        default :{ 
                                            printf("\nOpcao invalida, retornando ao menu de modificação secundario");
                                            atualiz = 1; break;
                                        }
                                            
                                    }
                                }
                            }
                                
                            case 2: {
                                for(i=0;i<50;i++)
                                    lista_aluno[qtd_alunos].nome[i] = -1;
                                for(i=0;i<15;i++){
                                    lista_aluno[qtd_alunos].dataNascimento[i] = -1;
                                    lista_aluno[qtd_alunos].cpf[i] = -1;}
                                lista_aluno[qtd_alunos].sexo = -1; 
                                printf("\nAluno atual excluido \n");
                                return 1;
                            }    
                        }    
                        
                    }}
            else
                return 0;}
        else 
            return 1;
        
    }
    //cadastrar professores    
    else {
        
        printf("\n******* Bem vindo a central de cadastro de professores *******\n");
        printf("Matricula sera gerada automaticamente caso os dados estiverem corretos\n");
        
        printf("\nDigite o nome: ");
        fgets(lista_professor[qtd_professores].nome, 50, stdin);
        retorno = validarNome(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
        if(retorno == ERRO_VALID_NOME) 
            return ERRO_VALID_NOME;
            
        printf("Digite o sexo: ");
        scanf(" %c",&lista_professor[qtd_professores].sexo);
        getchar();
        retorno = validarSexo(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
        if(retorno == ERRO_VALID_SEXO) 
            return ERRO_VALID_SEXO;
        
        printf("Digite a data de nascimento no formato ' 08/06/2000 ' : ");
        fgets(lista_professor[qtd_professores].dataNascimento, 15,stdin);
        size_t ln = strlen(lista_professor[qtd_professores].dataNascimento) - 1; 
        if (lista_professor[qtd_professores].dataNascimento[ln] == '\n')
            lista_professor[qtd_professores].dataNascimento[ln] = '\0';
        retorno = validarNascimento(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
        if(retorno == ERRO_VALID_DATA) 
            return ERRO_VALID_DATA;
        
        printf("Digite o CPF: ");
        fgets(lista_professor[qtd_professores].cpf, 15,stdin);
        retorno = validarCpf(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
        if(retorno == ERRO_VALID_CPF) 
            return ERRO_VALID_CPF;
        
        if(Verific == 0){
            geradorMatricula(lista_aluno, qtd_alunos, lista_professor, qtd_professores);
            
            printf("\nDigite 1 se deseja acessar o menu de modificação do Professor , caso contrario digite outro numero : ");
            scanf("%d",&aux);
            getchar();
            
            if(aux == 1){
                while(!fim){
                
                    printf("\n*******Menu de modificação principal*******");
                    printf("\n Digite 0 para sair do menu de modificação");
                    printf("\n Digite 1 se deseja alterar o cadastro do professor");
                    printf("\n Digite 2 se deseja excluir o professor atual");
                    printf("\n Escolha uma opcao : ");
                    scanf("%d",&opcao);
                    getchar();
            
                    switch (opcao){
                            case 0: {
                                printf("\nSaida do menu modificação retornando ao menu de opções\n");
                                return 0;}
                            case 1: {
                                while (!saida){
                                    printf("\n*******Menu de modificação secundário*******");
                                    printf("\n Digite 0 para sair do menu de modificação");
                                    printf("\n Digite 1 se deseja alterar o nome do professor");
                                    printf("\n Digite 2 se deseja alterar o sexo do professor");
                                    printf("\n Digite 3 se deseja alterar a data de nascimento do professor");
                                    printf("\n Digite 4 se deseja alterar o cpf do professor");
                                    printf("\n Escolha uma opcao : ");
                                    scanf("%d",&op);
                                    getchar();
                                    switch (op){
                                        case 0:
                                        {
                                            printf("\nSaida do menu modificação secundário retornando ao menu principal\n");
                                            saida = 1; break;
                                        }
                                        case 1:
                                        {
                                            while(!atualiz){
                                                printf("\nDigite o nome: ");
                                                fgets(lista_professor[qtd_professores].nome, 50, stdin);
                                                retorno = validarNome(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                                                if(retorno == ERRO_VALID_NOME)
                                                    printf("\nErro ao validar o nome");
                                                else
                                                    return 0; 
                                                  
                                            }
                                        }
                                        case 2:
                                        {
                                            while(!atualiz){
                                                printf("\nDigite o sexo: ");
                                                scanf(" %c",&lista_professor[qtd_professores].sexo);
                                                getchar();
                                                retorno = validarSexo(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                                                if(retorno == ERRO_VALID_SEXO) 
                                                    printf("\nErro ao validar o Sexo");
                                                else    
                                                    return 0;
                                            }
                                        }
                                        case 3:
                                        {
                                            while(!atualiz){
                                            printf("\nDigite a data de nascimento no formato ' 08/06/2000 ' : ");
                                            fgets(lista_professor[qtd_professores].dataNascimento, 15,stdin);
                                            size_t ln = strlen(lista_professor[qtd_professores].dataNascimento) - 1; 
                                            if (lista_professor[qtd_professores].dataNascimento[ln] == '\n')
                                                lista_professor[qtd_professores].dataNascimento[ln] = '\0';
                                            retorno = validarNascimento(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                                            if(retorno == ERRO_VALID_DATA) 
                                                printf("\nErro ao validar o Data, tente novamente");
                                            else    
                                                return 0;  
                                            }    
                                        }
                                        case 4: 
                                        {
                                            while(!atualiz){
                                                printf("\nDigite o CPF: ");
                                                fgets(lista_professor[qtd_professores].cpf, 15,stdin);
                                                retorno = validarCpf(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                                                if(retorno == ERRO_VALID_CPF) 
                                                    printf("\nErro ao validar o Cpf, tente novamente");
                                                else    
                                                    return 0;
                                            }        
                                        }
                                        default :{ 
                                            printf("\nOpcao invalida, retornando ao menu de modificação secundario");
                                            atualiz = 1; break;
                                        }
                                            
                                    }
                                }
                            }
                    
                            case 2: {
                                for(i=0;i<50;i++)
                                    lista_professor[qtd_professores].nome[i] = -1;
                                for(i=0;i<15;i++){
                                    lista_professor[qtd_professores].dataNascimento[i] = -1;
                                    lista_professor[qtd_professores].cpf[i] = -1;}
                                lista_professor[qtd_professores].sexo = -1; 
                                printf("\nProfessor atual excluido");
                                return 1;
                            }    
                    }    
                }
            }
            else
                return 0;}
        
    }
}

int cadastrodisciplinas(Professor lista_professor [], int qtd_professores , Disciplina lista_disciplina[], int qtd_disciplinas){
        system("clear");
        int retorno = 0;
        Verific = 0;
        int i,aux;
        int fim = 0,saida = 0;
        int opcao, op, atualiz;
    
        printf("\n******* Bem vindo a central de cadastro de disciplinas *******\n");
        printf("O codigo da disciplina sera gerado automaticamente caso os dados estiverem corretos\n");
        
        printf("Digite o nome: ");
        fgets(lista_disciplina[qtd_disciplinas].nome, 50, stdin);
        retorno = validarNomeDisc(lista_disciplina, qtd_disciplinas);
        if(retorno == ERRO_VALID_NOME) 
            return ERRO_VALID_NOME;
        
        printf("Digite o semestre no formato de um dígito '1': ");
        scanf("%d",&lista_disciplina[qtd_disciplinas].semestre);
        getchar();
        retorno = validarSemestre(lista_disciplina, qtd_disciplinas);
        if(retorno == ERRO_VALID_SEMESTRE) 
            return ERRO_VALID_SEMESTRE;
        
        printf("Digite o codigo do professor da disciplina no formato '1000': ");
        scanf("%d",&lista_disciplina[qtd_disciplinas].codigoprof);
        getchar();
        retorno = validarCodProf(lista_professor, qtd_professores, lista_disciplina, qtd_disciplinas);
        if(retorno == ERRO_VALID_CODPROF) 
            return ERRO_VALID_CODPROF;
        
        if(Verific == 0){
            geradorCodDisc(lista_disciplina, qtd_disciplinas);
            
            printf("\nDigite 1 se deseja acessar o menu de modificação da disciplina , caso contrario digite outro numero : ");
            scanf("%d",&aux);
            getchar();
            
            if(aux == 1){
                while(!fim){
                
                    printf("\n*******Menu de modificação principal*******");
                    printf("\n Digite 0 para sair do menu de modificação");
                    printf("\n Digite 1 se deseja alterar o cadastro da disciplina");
                    printf("\n Digite 2 se deseja excluir a disciplina atual");
                    printf("\n Escolha uma opcao : ");
                    scanf("%d",&opcao);
                    getchar();
            
                    switch (opcao){
                            case 0: {
                                printf("\nSaida do menu modificação retornando ao menu principal\n");
                                return 0; break;}
                            case 1: {
                                while (!saida){
                                    printf("\n*******Menu de modificação secundário*******");
                                    printf("\n Digite 0 para sair do menu de modificação");
                                    printf("\n Digite 1 se deseja alterar o nome da disciplina");
                                    printf("\n Digite 2 se deseja alterar o semestre da disciplina");
                                    printf("\n Digite 3 se deseja alterar o codigo do professor da disciplina");
                                    printf("\n Escolha uma opcao : ");
                                    scanf("%d",&op);
                                    getchar();
                                    switch (op){
                                        case 0:
                                        {
                                            printf("\nSaida do menu modificação secundário retornando ao menu principal\n");
                                            saida = 1; break;
                                        }
                                        case 1:
                                        {
                                            while(!atualiz){
                                                fgets(lista_disciplina[qtd_disciplinas].nome, 50, stdin);
                                                retorno = validarNomeDisc(lista_disciplina, qtd_disciplinas);
                                                if(retorno == ERRO_VALID_NOME) 
                                                    printf("\nErro ao validar o nome, tente novamente");
                                                else
                                                    return 0;
                                                    
                                            }
                                        }
                                        case 2:
                                        {
                                            while(!atualiz){
                                                printf("\nDigite o semestre no formato de um dígito '1': ");
                                                scanf("%d",&lista_disciplina[qtd_disciplinas].semestre);
                                                getchar();
                                                retorno = validarSemestre(lista_disciplina, qtd_disciplinas);
                                                if(retorno == ERRO_VALID_SEMESTRE)
                                                    printf("\nErro ao validar o Semestre, tente novamente");
                                                else    
                                                    return 0;
                                            }
                                        }
                                        case 3:
                                        {
                                            while(!atualiz){
                                                printf("\nDigite o codigo do professor da disciplina no formato '1000': ");
                                                scanf("%d",&lista_disciplina[qtd_disciplinas].codigoprof);
                                                getchar();
                                                retorno = validarCodProf(lista_professor, qtd_professores, lista_disciplina, qtd_disciplinas);
                                                if(retorno == ERRO_VALID_CODPROF)  
                                                    printf("\nErro ao validar codigo do professor, tente novamente");
                                                else    
                                                    return 0; 
                                            }
                                        }
                                        default :{ 
                                            printf("\nOpcao invalida, retornando ao menu de modificação secundario");
                                            atualiz = 1; break;
                                        }
                                            
                                    }
                                }
                            }
                                
                            case 2: {
                                for(i=0;i<50;i++)
                                    lista_disciplina[qtd_disciplinas].nome[i] = -1;
                                lista_disciplina[qtd_disciplinas].semestre = -1;
                                lista_disciplina[qtd_disciplinas].codigoprof = -1;
                                printf("\nDisciplina atual excluido \n");
                                return 1;
                            }    
                        }    
                        
                    }}
            else        
                return 0;}
        else 
            return 1;
}

int inseriralundisc(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas, Disciplina lista_alundisc[], int qtd_alundisc){
        system("clear");
        Verific = 0;
        int i, cont = 0;
        
        if(qtd_alundisc == 0){
        int x;
        for(x = 0; x < TAM; x++)
            lista_alundisc[x].codalundisc = -1;} //inicializando o vetor
            
        printf("\n Digite a matricula do aluno que deseja inserir na disciplina : ");
        scanf("%d", &lista_alundisc[qtd_alundisc].codalun);
        
        printf("\n Digite o codigo da disciplina : ");
        scanf("%d", &lista_alundisc[qtd_alundisc].codalundisc);
        
        for(i=0;i<qtd_alunos;i++){
            if(lista_aluno[i].matricula == lista_alundisc[qtd_alundisc].codalun){
                strcpy(lista_alundisc[qtd_alundisc].nomealundisc,lista_aluno[i].nome);
                cont++;}    
        }
        
        for(i=0;i<qtd_disciplinas;i++){
            if(lista_disciplina[i].codigodisc == lista_alundisc[qtd_alundisc].codalundisc)
                cont++;} 
                
        if(cont == 2)
            return 3;
        return 0;       
}

void listar_alunosmat(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_alundisc[], int qtd_alundisc){
    system("clear");    
    int i,j,x;
    int codalun;
    int cont = 0;
    
    for(i = 0; i < qtd_alundisc; i++){
        cont = 0;
        codalun = lista_alundisc[i].codalun; 
        for(j = 0; j < qtd_alundisc; i++){
            if(codalun = lista_alundisc[j].codalun)
                cont++;
        }
        if(cont < 3)
            printf("\nAluno %d : %s",i,lista_alundisc[j].nomealundisc);
    }
}

int exclusao_alunprofdisc (Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores,Disciplina lista_disciplina[], int qtd_disciplinas){
    int i,j,x, y = 0;
    int opcao;
    int fim = 0;
    int cod;
    
    while(!fim){
        
        printf("\n*******Menu de exclusao*******");
        printf("\n0 - Sair do menu de exclusao e retornar ao menu principal");
        printf("\n1 - Para excluir um aluno");
        printf("\n2 - Para excluir um professor");
        printf("\n3 - Para excluir uma disciplina");
        printf("\nDigite uma opcao : ");
        scanf("%d",&opcao);
        getchar();
        system("clear");
        
        switch(opcao){
            case 0: {
                printf("\nSaida do menu exclusao retornando ao menu de opções\n");
                    return 2;}
            case 1: {
                
                printf("\nDigite o codigo do aluno que deseja excluir : ");
                scanf("%d",&cod);
                
                for(i = 0 ; i < TAM; i++){
                        if (lista_aluno[i].matricula == cod){
                                if(qtd_alunos == 1){
                                    for(x = 0 ; x < 50; x++)
                                        lista_aluno[i].nome[x] = -1; // zerando nome de aluno 
                                    for(x = 0 ; x < 15; x++){ 
                                        lista_aluno[i].dataNascimento[x] = -1; // zerando dataNascimento
                                        lista_aluno[i].cpf[x] = -1;} // zerando cpf
                                    lista_aluno[i].sexo = -1;    // zerando sexo
                                    qtd_alunos--;
                                    return 1;
                                }    
                                else{
                                    for(y = i; y < TAM ;y++){
                                        if(lista_aluno[y+1].matricula == -1){ 
                                            for(x = 0 ; x < 50; x++) 
                                                lista_aluno[y].nome[x] = -1; // zerando nome de aluno
                                            for(x = 0 ; x < 15; x++){
                                                lista_aluno[y].dataNascimento[x] = -1;  // zerando dataNascimento
                                                lista_aluno[y].cpf[x] = -1;}  // zerando cpf
                                            lista_aluno[y].sexo = -1;   // zerando sexo
                                            lista_aluno[y].matricula = -1;  // zerando matricula
                                            qtd_alunos--;
                                            return 1;}
                                        else { // shift trocando o atual pelo proximo elemento
                                            for(x = 0 ; x < 50; x++)
                                                lista_aluno[y].nome[x] = lista_aluno[y+1].nome[x];
                                            for(x = 0 ; x < 15; x++){    
                                            lista_aluno[y].dataNascimento[x] = lista_aluno[y+1].dataNascimento[x]; 
                                            lista_aluno[y].cpf[x] = lista_aluno[y+1].cpf[x];} 
                                            lista_aluno[y].sexo = lista_aluno[y+1].sexo;
                                            lista_aluno[y].matricula = lista_aluno[y+1].matricula;
                                        }
                                    }
                                   
                                    }    
                                }        
                            }
                    
            break;    
            }
            case 2: {
                
                printf("\nDigite o codigo do professor que deseja excluir : ");
                scanf("%d",&cod);
                
                for(i = 0 ; i < TAM; i++){
                        if (lista_professor[i].matricula == cod){
                                if(qtd_professores == 1){
                                    for(x = 0 ; x < 50; x++)
                                        lista_professor[i].nome[x] = -1; // zerando nome de aluno 
                                    for(x = 0 ; x < 15; x++){ 
                                        lista_professor[i].dataNascimento[x] = -1; // zerando dataNascimento
                                        lista_professor[i].cpf[x] = -1;} // zerando cpf
                                    lista_professor[i].sexo = -1;    // zerando sexo
                                    qtd_professores--;
                                    return 1;
                                }    
                                else{
                                    for(y = i; y < TAM ;y++){
                                        if(lista_professor[y+1].matricula == -1){
                                            for(x = 0 ; x < 50; x++)
                                                lista_professor[y].nome[x] = -1;
                                            for(x = 0 ; x < 15; x++){
                                                lista_professor[y].dataNascimento[x] = -1; // zerando dataNascimento
                                                lista_professor[y].cpf[x] = -1;} // zerando cpf
                                            lista_professor[y].sexo = -1;  // zerando sexo
                                            lista_professor[y].matricula = -1;
                                            qtd_professores--;
                                            return 1;}
                                        else { // shift trocando o atual pelo proximo elemento
                                            for(x = 0 ; x < 50; x++)
                                                lista_professor[y].nome[x] = lista_professor[y+1].nome[x];
                                            for(x = 0 ; x < 15; x++){    
                                                lista_professor[y].dataNascimento[x] = lista_professor[y+1].dataNascimento[x]; // zerando dataNascimento
                                                lista_professor[y].cpf[x] = lista_professor[y+1].cpf[x];} // zerando cpf
                                            lista_professor[y].sexo = lista_professor[y+1].sexo;
                                            lista_professor[y].matricula = lista_professor[y+1].matricula;
                                        }
                                    }
                                   
                                    }    
                                }        
                            }
            break;
            }
            case 3 : {
                
                printf("\nDigite o codigo da disciplina que deseja excluir : ");
                scanf("%d",&cod);
                
                for(i = 0 ; i < TAM; i++){
                        if (lista_disciplina[i].codigodisc == cod){
                                if(qtd_disciplinas == 1){
                                    for(x = 0 ; x < 50; x++)
                                        lista_disciplina[i].nome[x] = -1; // zerando nome da disciplina
                                    lista_disciplina[i].semestre = -1; // zerando semestre
                                    lista_disciplina[i].codigoprof = -1; // zerando codigoprof
                                    lista_disciplina[i].codigodisc = -1;    // zerando codigodisc
                                    qtd_disciplinas--;
                                    return 1;
                                }    
                                else{
                                    for(y = i; y < TAM ;y++){
                                        if(lista_disciplina[y+1].codigodisc == -1){
                                            for(x = 0 ; x < 50; x++)
                                                lista_disciplina[i].nome[x] = -1; // zerando nome da disciplina
                                            lista_disciplina[i].semestre = -1; // zerando semestre
                                            lista_disciplina[i].codigoprof = -1; // zerando codigoprof
                                            lista_disciplina[i].codigodisc = -1;    // zerando zerando codigodisc
                                            qtd_disciplinas--;
                                            return 1;
                                        }
                                        else {
                                            for(x = 0 ; x < 50; x++) // shift trocando o atual pelo proximo elemento
                                                lista_disciplina[y].nome[x] = lista_disciplina[y+1].nome[x];
                                            lista_disciplina[y].semestre =  lista_disciplina[y+1].semestre; 
                                            lista_disciplina[y].codigoprof = lista_disciplina[y+1].codigoprof; 
                                            lista_disciplina[y].codigodisc = lista_disciplina[y+1].codigodisc;
                                        }
                                    }
                                   
                                    }    
                                }        
                            }
            break;
            }
            default: 
                printf("\nOpcao invalida");
        }
    }
    return 0;
}    

int excluir_alundisc(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas, Disciplina lista_alundisc[], int qtd_alundisc){
    system("clear");
    int i, j, x, y,k;
    int matalunex;
    int coddiscex;
    int cont = 0;
    
    printf("\nDigite a matricula do aluno que deseja excluir ");
    scanf("%d", &matalunex);
    
    printf("\nDigite o codigo da disciplina ");
    scanf("%d", &coddiscex);
    
    for(i = 0 ; i < qtd_disciplinas; i++){
        for(j = 0 ; j < qtd_alundisc; j++){
            if (lista_disciplina[i].codigodisc == coddiscex){
                if(lista_alundisc[j].codalun == matalunex){
                    if(qtd_alundisc == 1){
                        for(x = 0 ; x < 50; x++)
                            lista_alundisc[j].nomealundisc[x] = 0; // zerando nome de aluno guardado na disciplina
                        lista_alundisc[j].codalundisc = -1; // zerando codigo do aluno cadastrado na discipllina
                        qtd_alundisc--; // decrementando contador de quantidade de alunos cadastrados em uma disciplina
                        return 1;
                    }
                    else{
                        for(y = j; y < TAM ;y++){
                            if(lista_alundisc[y+1].codalundisc == -1){
                                for(x = 0 ; x < 50; x++)
                                    lista_alundisc[y].nomealundisc[x] = lista_alundisc[y+1].nomealundisc[x];
                                lista_alundisc[y].codalundisc = lista_alundisc[y+1].codalundisc;
                                qtd_alundisc--;
                                return 1;}
                            for(x = 0 ; x < 50; x++)
                                    lista_alundisc[y].nomealundisc[x] = lista_alundisc[y+1].nomealundisc[x];
                                lista_alundisc[y].codalundisc = lista_alundisc[y+1].codalundisc;
                        }    
                    }        
                }
        }}
    }
    return 0;
}

int validarSemestre(Disciplina lista_disciplina[], int qtd_disciplinas){
    
    if(lista_disciplina[qtd_disciplinas].semestre <= 0  || lista_disciplina[qtd_disciplinas].semestre > 2){
        Verific++;
        return ERRO_VALID_SEMESTRE;
    }
    
    return 0;

}

int validarCodProf(Professor lista_professor[], int qtd_professores, Disciplina lista_disciplina[], int qtd_disciplinas){
    int i, cont = 0;
    
    if(lista_disciplina[qtd_disciplinas].codigoprof <= 1000 || lista_disciplina[qtd_disciplinas].codigoprof > 1999){
        Verific++;
        return ERRO_VALID_CODPROF;
    }
    
    for(i=0;i<qtd_professores;i++){
        if(lista_professor[i].matricula == lista_disciplina[qtd_disciplinas].codigoprof){
            strcpy(lista_disciplina[qtd_disciplinas].nomeprofdisc,lista_professor[i].nome);
            cont++;}
    }
    
    if(cont == 0){
        Verific++;
        return ERRO_VALID_CODPROF;
    }
    return 0;    
}

int validarNome(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    if(escolha == 1){
        int i;
        int tamanho;
        tamanho = strlen(lista_aluno[qtd_alunos].nome);
        if(tamanho > 50){
            Verific++;
            return ERRO_VALID_NOME;
        }
        return 0;
    }
    else{
        int i;
        int tamanho;
        tamanho = strlen(lista_professor[qtd_professores].nome);
        if(tamanho > 50){
            Verific++;
            return ERRO_VALID_NOME;
        }
        return 0;
    }
}

int validarNomeDisc(Disciplina lista_disciplina[], int qtd_disciplinas){
        int i;
        int tamanho;
        tamanho = strlen(lista_disciplina[qtd_disciplinas].nome);
        if(tamanho > 50){
            Verific++;
            return ERRO_VALID_NOME;
        }
        return 0;
}

int validarNascimento(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    contDT = 0;
    if(escolha == 1){
        int i;
        int dia,mes,ano,bissexto = 0;
        int tamanho;
        tamanho = strlen(lista_aluno[qtd_alunos].dataNascimento);
        if(tamanho != 10){ // se o tamanho do nome esta correto
            Verific++;
            return ERRO_VALID_DATA;
        }   
        else{
            for(i=0;i<10;i++){
                if(i == 2 || i == 5){ 
                    if(lista_aluno[qtd_alunos].dataNascimento[2] != '/' || lista_aluno[qtd_alunos].dataNascimento[5] != '/') // verifica se a posicao das barras tem realmente barras
                        contDT++;}
                else {
                    if((lista_aluno[qtd_alunos].dataNascimento[i]-'0') < 0) // verifica se contem algo que não seja numeros nas outras posicoes
                        contDT++;}
            }
        }
        //calculo do dia
        dia = (lista_aluno[qtd_alunos].dataNascimento[0]-'0') * 10;
        dia += lista_aluno[qtd_alunos].dataNascimento[1]-'0';
        //calculo do mes
        mes = (lista_aluno[qtd_alunos].dataNascimento[3]-'0') * 10;
        mes += lista_aluno[qtd_alunos].dataNascimento[4]-'0';
        //calculo do ano 
        ano = (lista_aluno[qtd_alunos].dataNascimento[6]-'0') * 1000;
        ano += (lista_aluno[qtd_alunos].dataNascimento[7]-'0') * 100;
        ano += (lista_aluno[qtd_alunos].dataNascimento[8]-'0') * 10;
        ano += lista_aluno[qtd_alunos].dataNascimento[9]-'0';
        
        // verifica se o dia é entre 1 e 31.
        if(dia < 1  || dia > 31)
            contDT = 1;
        
        // verifica se o mês é entre 1 e 12    
        if(mes < 1 || mes > 12)
            contDT = 1;
        
        // verifica se o ano esta no intervalo entre 1900 e 2100
        if(ano < 1900 || ano > 2100)
            contDT = 1;
        
        // verifica se mês for 04, 06, 09 ou 11, dia pode ser no máximo 30;
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
            if(dia > 30)
                contDT = 1;
        
        //calculo do ano bissexto
        if(ano % 4 == 0 && ano % 100 != 0)
            bissexto = 1;
        if(ano % 4 == 0 && ano % 400 == 0 && ano % 100 == 0)
            bissexto = 1;   
        
        if(bissexto) { // verifica se ano for bissexto e mês for 02, dia pode ser no máximo 29.
            if(mes == 2)
                if(dia > 29)
                    contDT = 1;
                }
        
        else { // verifica se mês for 02, dia pode ser no máximo 28;
            if(mes == 2)
                if(dia > 28)
                    contDT = 1;
            }
        if(contDT == 1){
            Verific++;
            return ERRO_VALID_DATA;}
        return 0;
    }
    else{
        int i;
        int tamanho;
        int dia,mes,ano,bissexto = 0;
        tamanho = strlen(lista_professor[qtd_professores].dataNascimento);
        if(tamanho != 10){ // se o tamanho do nome esta correto
            Verific++;
            return ERRO_VALID_DATA;
        }
        else{
            for(i=0;i<10;i++){
                if(i == 2 || i == 5){ 
                    if(lista_professor[qtd_professores].dataNascimento[2] != '/' || lista_professor[qtd_professores].dataNascimento[5] != '/') // verifica se a posicao das barras tem realmente barras
                        contDT = 1;}
                else {
                    if((lista_professor[qtd_professores].dataNascimento[i]-'0') < 0) // verifica se contem algo que não seja numeros nas outras posicoes
                        contDT = 1;}
            }
        }
        
        //calculo do dia
        dia = (lista_professor[qtd_professores].dataNascimento[0]-'0') * 10;
        dia += lista_professor[qtd_professores].dataNascimento[1]-'0';
        //calculo do mes
        mes = (lista_professor[qtd_professores].dataNascimento[3]-'0') * 10;
        mes += lista_professor[qtd_professores].dataNascimento[4]-'0';
        //calculo do ano 
        ano = (lista_professor[qtd_professores].dataNascimento[6]-'0') * 1000;
        ano += (lista_professor[qtd_professores].dataNascimento[7]-'0') * 100;
        ano += (lista_professor[qtd_professores].dataNascimento[8]-'0') * 10;
        ano += lista_professor[qtd_professores].dataNascimento[9]-'0';
        
        // verifica se o dia é entre 1 e 31.
        if(dia < 1  || dia > 31)
            contDT = 1;
        
        // verifica se o mês é entre 1 e 12    
        if(mes < 1 || mes > 12)
            contDT = 1;
        
        // verifica se o ano esta no intervalo entre 1900 e 2100
        if(ano < 1900 || ano > 2100)
            contDT = 1;
        
        // verifica se mês for 04, 06, 09 ou 11, dia pode ser no máximo 30;
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
            if(dia > 30)
                contDT = 1;
        
        //calculo do ano bissexto
        if(ano % 4 == 0 && ano % 100 != 0)
            bissexto = 1;
        if(ano % 4 == 0 && ano % 400 == 0 && ano % 100 == 0)
            bissexto = 1;   
        
        if(bissexto) { // verifica se ano for bissexto e mês for 02, dia pode ser no máximo 29.
            if(mes == 2)
                if(dia > 29)
                    contDT = 1;
                }
        
        else { // verifica se mês for 02, dia pode ser no máximo 28;
            if(mes == 2)
                if(dia > 28)
                    contDT = 1;
            }
            
        if(contDT == 1){
            Verific++;
            return ERRO_VALID_DATA;
        }
        return 0;
    }
}

int validarCpf(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    contCP = 0;
    if(escolha == 1 ){
        int i;
        int tamanho;
        int valid1, soma1 = 0, aux1 = 10;
        int valid2, soma2 = 0, aux2 = 11;
        char dg1,dg2;
        
        tamanho = strlen(lista_aluno[qtd_alunos].cpf);
        
        if(tamanho != 14){ // verifica se o tamanho do cpf esta correto
            Verific++;
            return ERRO_VALID_CPF;
        }
        else{
            for(i=0;i<14;i++){
               if (i == 3 || i == 7 ||i == 11){ 
                    if(lista_aluno[qtd_alunos].cpf[3] != '.' || lista_aluno[qtd_alunos].cpf[7] != '.')
                        contCP = 1;
                    if(lista_aluno[qtd_alunos].cpf[11] != '-')
                        contCP = 1;}
                else{
                    if ((lista_aluno[qtd_alunos].cpf[i]-'0') < 0 )
                        contCP = 1;}
                        
            }}
        
        for(i=0;i<11;i++){ // validação do primeiro digito
                if((lista_aluno[qtd_alunos].cpf [i]) != '.'){
                    soma1 += (lista_aluno[qtd_alunos].cpf[i]-'0') * aux1;
                    aux1 = aux1 - 1;}
        }  
       
        dg1 = lista_aluno[qtd_alunos].cpf[12]-'0'; // capturando o primero digito verificador
        valid1 = (soma1 * 10) % 11;
        
        
        if(valid1 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
            valid1 = 0;
        
        if(valid1 != dg1) // verificando se o primeiro digito verificador é igual ao valid1 , primeira etapa de verificação concluida
            contCP = 1;
            
        for(i=0;i<13;i++){ // validação do segundo digito
                if(lista_aluno[qtd_alunos].cpf [i]-'0' >= 0 && lista_aluno[qtd_alunos].cpf [i]-'0' < 10){
                    soma2 += (lista_aluno[qtd_alunos].cpf[i]-'0') * aux2;
                    aux2 = aux2 - 1;} 
        }   
       
        dg2 = lista_aluno[qtd_alunos].cpf[13]-'0'; // capturando o segundo digito verificador
        valid2 = (soma2 * 10) % 11;
        
        if(valid2 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
            valid2 = 0;
            
        if(valid2 != dg2) // verificando se o segundo digito verificador é igual ao valid2 , segunda etapa de verificação concluida
            contCP = 1;
        
        if(contCP == 1){
            Verific++;
            return ERRO_VALID_CPF;
        }
        return 0;
    }
    else {
        int i;
        int tamanho;
        int valid1, soma1 = 0, aux1 = 10;
        int valid2, soma2 = 0, aux2 = 11;
        char dg1,dg2;
        
        tamanho = strlen(lista_professor[qtd_professores].cpf);
        if(tamanho != 14){ // verifica se o tamanho do cpf esta correto
            Verific++;
            return ERRO_VALID_CPF;
        }
        else{
            for(i=0;i<14;i++){
               if (i == 3 || i == 7 ||i == 11){ 
                    if(lista_professor[qtd_professores].cpf[3] != '.' || lista_professor[qtd_professores].cpf[7] != '.')
                        contCP = 1;
                    if(lista_professor[qtd_professores].cpf[11] != '-')
                        contCP = 1;}
                else{
                    if ((lista_professor[qtd_professores].cpf[i]-'0') < 0 )
                        contCP = 1;}
                        
            }}
          
        for(i=0;i<11;i++){ // validação do primeiro digito
                if((lista_professor[qtd_professores].cpf [i]) != '.'){
                    soma1 += (lista_professor[qtd_professores].cpf[i]-'0') * aux1;
                    aux1 = aux1 - 1;}
        }  
        
        dg1 = lista_professor[qtd_professores].cpf[12]-'0'; // capturando o primero digito verificador
        valid1 = (soma1 * 10) % 11;
        
        if(valid1 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
            valid1 = 0;
        
        if(valid1 != dg1) // verificando se o primeiro digito verificador é igual ao valid1 , primeira etapa de verificação concluida
            contCP = 1;
            
        for(i=0;i<13;i++){ // validação do segundo digito
                if(lista_professor[qtd_professores].cpf [i]-'0' >= 0 && lista_professor[qtd_professores].cpf [i]-'0' < 10){
                    soma2 += (lista_professor[qtd_professores].cpf[i]-'0') * aux2;
                    aux2 = aux2 - 1;} 
        }   
        
        dg2 = lista_professor[qtd_professores].cpf[13]-'0'; // capturando o segundo digito verificador
        valid2 = (soma2 * 10) % 11;
        
        if(valid2 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
            valid2 = 0;
            
        if(valid2 != dg2) // verificando se o segundo digito verificador é igual ao valid2 , segunda etapa de verificação concluida
            contCP = 1;
        
        if(contCP == 1){
            Verific++;
            return ERRO_VALID_CPF;}
        return 0;
    }
}

int validarSexo(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    contS = 0 ;
    if(escolha == 1){
        
        if(lista_aluno[qtd_alunos].sexo == 'M' || lista_aluno[qtd_alunos].sexo == 'F' || lista_aluno[qtd_alunos].sexo == 'm' || lista_aluno[qtd_alunos].sexo == 'f' || lista_aluno[qtd_alunos].sexo == 'o' || lista_aluno[qtd_alunos].sexo == 'O')
            contS = 0;
        else
            contS = 1;
        
        if(contS == 1){
            Verific++;
            return ERRO_VALID_SEXO;}
        return 0;  
    }
    else {
        if(lista_professor[qtd_professores].sexo == 'M' || lista_professor[qtd_professores].sexo == 'F' || lista_professor[qtd_professores].sexo == 'm' || lista_professor[qtd_professores].sexo == 'f' || lista_professor[qtd_professores].sexo == 'o' || lista_professor[qtd_professores].sexo == 'O')
            contS = 0;
        else
            contS = 1;
        
        if(contS == 1){
            Verific++;
            return ERRO_VALID_SEXO;
        }
        return 0;  
    }
}

int geradorMatricula(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    int i;
    if(escolha == 1){
        ContMatAlun++;
        lista_aluno[qtd_alunos].matricula = ContMatAlun;
        getchar();
    }
    else{
        ContMatProf++;
        lista_professor[qtd_professores].matricula = ContMatProf;
        getchar();
    }    
        
    return 0;    
}

int geradorCodDisc(Disciplina lista_disciplina[], int qtd_disciplinas){
    ContCodDisciplina++;
    lista_disciplina[qtd_disciplinas].codigodisc = ContCodDisciplina;
    return 0;
}

void listaralunos_professores(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
        int i;
        system("clear");
        if(escolha == 1){
            printf("\n****** Alunos Cadastrados ******#\n");
            for (i = 0; i < qtd_alunos; i++){
                printf("-----\n");
                printf("Matrícula: %d\n", lista_aluno[i].matricula);
                printf("Nome: %s", lista_aluno[i].nome);
                printf("Sexo: %c\n", lista_aluno[i].sexo);
                printf("Data Nascimento: %s\n", lista_aluno[i].dataNascimento);
                printf("CPF: %s\n", lista_aluno[i].cpf);
        }
        printf("-----");
        }
        else{
            printf("\n****** Professores Cadastrados ******#\n");
            for (i = 0; i < qtd_professores; i++){
                printf("-----\n");
                printf("Matrícula: %d\n", lista_professor[i].matricula);
                printf("Nome: %s", lista_professor[i].nome);
                printf("Sexo: %c\n", lista_professor[i].sexo);
                printf("Data Nascimento: %s\n", lista_professor[i].dataNascimento);
                printf("CPF: %s\n", lista_professor[i].cpf);
            }
            printf("-----");
            }
    }
    
void stringbusca(Aluno lista_aluno[], int qtd_alunos,Professor lista_professor[], int qtd_professores){
    system("clear");
    int op;
    int i,j,x;
    char busca[10];
    int mesal[qtd_alunos];
    int mespr[qtd_alunos];
    int cont = 0 , contl = 0, aux = 0;
    int tamanho;
    
    printf("\nDigite 1 se deseja consultar os Alunos e 2 para os Professores : ");
    scanf("%d",&op);
    getchar();
    
    if(op == 1 && qtd_alunos > 0){
        
        printf("\nDigite ao menos 3 caracteres para buscar Aluno(s) : ");
        scanf("%s",busca);
        
        tamanho = strlen(busca);
        printf("\ntamanho : %d",tamanho);
        cont++;
        
            if(tamanho >= 3){
                for(i = 0; i < tamanho; i++){
                    if(i == 0)
                        j = 0;
                    else
                        j = i + 1;
                    for(; j < qtd_alunos; j++){
                        contl = 0;
                        for(x = 0 ; x < qtd_alunos; x++){
                            if(busca[i] == lista_aluno[j].nome[x] && contl == 0){
                                printf("\nAluno : %s",lista_aluno[j].nome);
                                contl++;}
                        }
                    }
                }
            }
    }
    if(op == 2 && qtd_professores > 0){
        
        printf("\nDigite ao menos 3 caracteres para buscar Professor(es) : ");
        scanf("%s",busca);
        
        tamanho = strlen(busca);
        cont++;
        
        printf("\n*******Busca Professor*********\n");
            if(tamanho >= 3){
                for(i = 0; i < tamanho; i++){
                    if(i == 0)
                        j = 0;
                    else
                        j = i + 1;
                    for(; j < qtd_professores; j++){
                        contl = 0;
                        for(x = 0 ; x < qtd_professores; x++){
                            if(busca[i] == lista_professor[j].nome[x] && contl == 0){
                                printf("\nProfessor : %s",lista_professor[j].nome);
                                printf("-----");
                                contl++;}
                        }
                    }
                }
            }
    }
    
    if(cont == 0)
        printf("\nOpção inválida");
    
}

int ordenar_alunprof_SND(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    system("clear");
    int op = 0, fim = 0, opcao = 0;
    int i, j, x, menor,cont = 0;
    
    char copianomes[qtd_alunos][50], auxcopiA[qtd_alunos][50], auxcopiP[qtd_professores][50];
    char aux[qtd_alunos];
    
    char copiadatas[qtd_alunos][15];
    char auxCP[qtd_alunos][15];
    int dia[qtd_alunos], mes[qtd_alunos], ano[qtd_alunos];
    int auxdata;
    
    printf("\nDigite 1 para acessar o menu de listagem de Aluno");
    printf("\nDigite 2 para acessar o menu de listagem de Professor\n");
    printf("\nDigite uma opcao : ");
    scanf("%d",&op);
    getchar();
    
    if(op == 1 && qtd_alunos > 0){
        while(!fim){
            
            printf("\n*******Menu de Listagem de aluno*******");
            printf("\n Digite 0 para sair do menu de listagem");
            printf("\n Digite 1 para ordenar alunos pelo sexo");
            printf("\n Digite 2 para ordenar alunos pelo nome");
            printf("\n Digite 3 para ordenar alunos pela data de nascimento");
            printf("\n Escolha uma opcao : ");
            scanf("%d",&opcao);
            getchar(); 
            
            switch(opcao){
            case 0:{ 
                printf("\nSaindo do menu de listagem voltando para o Menu Principal");
                return 0; break;}
            case 1: {
                cont = 0;
                for(i=0;i<qtd_alunos;i++){
                    if(i == 0)
                        printf("\n****** Aluno(s) do sexo Masculino ******");
                    if(lista_aluno[i].sexo == 'M' || lista_aluno[i].sexo == 'm'){
                        printf("\nNome do aluno : %s",lista_aluno[i].nome);
                        printf("-----");
                        cont++;
                    }
                }
                if(cont == 0)
                    printf("\n   Não existem alunos do sexo Masculino");
                cont = 0;    
                for(i=0;i<qtd_alunos;i++){
                    if(i == 0)
                        printf("\n****** Aluno(s) do sexo Feminino ******");
                    if(lista_aluno[i].sexo == 'F' || lista_aluno[i].sexo == 'f'){
                        printf("\nNome do aluno : %s",lista_aluno[i].nome);
                        printf("-----");
                        cont++;
                    }
                }
                if(cont == 0)
                    printf("\n   Não existem alunos do sexo Feminino");
                fim = 1; return 1; break;
                }
            case 2: {
                for(j = 0; j < qtd_alunos;j++)
                    for(i = 0; i<50;i++)
                        copianomes[j][i] =  lista_aluno[j].nome[i];
                
                for(i = 0; i < qtd_alunos - 1; i++){
                    
                x = 0;
                menor = i;
                for(j = i + 1; j < qtd_alunos; j++)
                {
                    x = 0;
                    while(copianomes[menor][x] == copianomes[j][x])
                    {
                            x++;
                    } 
                    if(copianomes[menor][x] > copianomes[j][x])
                        menor = j;
                    
                }
                if(menor != i){
                    strcpy(aux, copianomes[menor]);
                    strcpy(copianomes[menor], copianomes[i]);
                    strcpy(copianomes[i], aux);
                }
            }
                printf("\n****** Aluno(s) Ordenados por nome ******\n");
                for(i = 0; i < qtd_alunos; i++){
                    printf("\nNome do aluno %d: %s", i + 1,copianomes[i]);
                    printf("-----");}
                fim = 1 ; return 1; break;   
            }
            
            case 3: {
                for(j = 0; j < qtd_alunos;j++)
                    for(i = 0; i<15;i++)
                        copiadatas[j][i] =  lista_aluno[j].dataNascimento[i];
                
                if(qtd_alunos == 1){
                    for(i = 0; i<15;i++){
                        printf("\nAluno %d = %s", i + 1, copiadatas[i]);
                        return 1;break;} 
                }
                
                for(j = 0; j < qtd_alunos;j++)
                        for(i = 0; i<50;i++)
                            copianomes[j][i] =  lista_aluno[j].nome[i];
                
                for(i = 0; i < qtd_alunos; i++){
                    //calculo do dia
                    dia[i] = (copiadatas[i][0]-'0') * 10;
                    dia[i]+= copiadatas[i][1]-'0';
                    //calculo do mes
                    mes[i] = (copiadatas[i][3]-'0') * 10;
                    mes[i] += copiadatas[i][4]-'0';
                    //calculo do ano 
                    ano[i] = (copiadatas[i][6]-'0') * 1000;
                    ano[i] += (copiadatas[i][7]-'0') * 100;
                    ano[i] += (copiadatas[i][8]-'0') * 10;
                    ano[i] += copiadatas[i][9]-'0';
                    
                }
                
                for(i = 0; i < qtd_alunos; i++){
                    for(j = i + 1; j < qtd_alunos; j++){
                        if(ano[i] > ano[j])
                            {
                                auxdata = ano[i];
                                ano[i] = ano[j];
                                ano[j] = auxdata;
                                
                                auxdata = mes[i];
                                mes[i] = mes[j];
                                mes[j] = auxdata;
                                
                                auxdata = dia[i];
                                dia[i] = dia[j];
                                dia[j] = auxdata;
                                
                                for(x = 0; x < 50; x++)
                                {
                                    auxcopiA[i][x] = copianomes[i][x];
                                    copianomes[i][x] = copianomes[j][x];
                                    copianomes[j][x] = auxcopiA[i][x];
                                }
                                
                                i = 0;
                            }
                        if(ano[i] == ano[j]){
                            if(mes[i] > mes[j])
                            {
                                auxdata = ano[i];
                                ano[i] = ano[j];
                                ano[j] = auxdata;
                                
                                auxdata = mes[i];
                                mes[i] = mes[j];
                                mes[j] = auxdata;
                                
                                auxdata = dia[i];
                                dia[i] = dia[j];
                                dia[j] = auxdata;
                                
                                for(x = 0; x < 50; x++)
                                {
                                    auxcopiA[i][x] = copianomes[i][x];
                                    copianomes[i][x] = copianomes[j][x];
                                    copianomes[j][x] = auxcopiA[i][x];
                                }
                                
                                i = 0;
                            }
                        }
                        if(mes[i] == mes[j]){
                            if(dia[i] > dia[j])
                            {
                                auxdata = ano[i];
                                ano[i] = ano[j];
                                ano[j] = auxdata;
                                
                                auxdata = mes[i];
                                mes[i] = mes[j];
                                mes[j] = auxdata;
                                
                                auxdata = dia[i];
                                dia[i] = dia[j];
                                dia[j] = auxdata;
                                
                                for(x = 0; x < 50; x++)
                                {
                                    auxcopiA[i][x] = copianomes[i][x];
                                    copianomes[i][x] = copianomes[j][x];
                                    copianomes[j][x] = auxcopiA[i][x];
                                }
                                
                                i = 0;
                            }
                        }    
                    }
                }
                    
                    printf("\n****** Aluno(s) Ordenados por data de nascimento do mais velho para o mais novo ******\n"); 
                    for(i = 0; i < qtd_alunos; i++){
                        printf("\nAluno %d : %s  Data = %d/%d/%d ", i + 1, copianomes[i], dia[i], mes[i], ano[i]);
                        printf("-----");
                    }
                    fim = 1; return 1; break; 
            }
            
            default: {
                printf("\nOpcao inválida retornando ao menu de listagem");}
            }
        } 
                    
    }
    
		fim = 0;
		if(op == 2 && qtd_professores > 0){
			while(!fim){
            
            printf("\n*******Menu de Listagem de professores*******");
            printf("\n Digite 0 para sair do menu de listagem");
            printf("\n Digite 1 para ordenar alunos pelo sexo");
            printf("\n Digite 2 para ordenar alunos pelo nome");
            printf("\n Digite 3 para ordenar alunos pela data de nascimento");
            printf("\n Escolha uma opcao : ");
            scanf("%d",&opcao);
            getchar(); 
            
            switch(opcao){
            case 0:{ 
                printf("\nSaindo do menu de listagem voltando para o Menu Principal");
                return 0; break;}
            case 1: { 
                for(i=0;i<qtd_professores;i++){
                    if(i == 0)
                        printf("\n****** Professor(es) do sexo Masculino ******\n");
                    if(lista_professor[i].sexo == 'M' || lista_professor[i].sexo == 'm'){
                        printf("\nNome do professor : %s",lista_professor[i].nome);
                        printf("-----");}
                }
                for(i=0;i<qtd_professores;i++){
                    if(i == 0)
                        printf("\n****** Professor(es) do sexo Feminino ******\n");
                    if(lista_professor[i].sexo == 'F' || lista_professor[i].sexo == 'f'){
                        printf("\nNome do professor : %s",lista_professor[i].nome);
                        printf("-----");}
                }
                fim = 1; return 1; break;
                }
            case 2: {
                for(i = 0; i < qtd_professores - 1; i++){
                    
                    x = 0;
                    menor = i;
                    for(j = i + 1; j < qtd_professores; j++)
                {
                    x = 0;
                    while(lista_professor[menor].nome[x] == lista_professor[j].nome[x])
                    {
                            x++;
                    } 
                    if(lista_professor[menor].nome[x] > lista_professor[j].nome[x])
                        menor = j;
                    
                }
                if(menor != i){
                    strcpy(aux, lista_professor[menor].nome);
                    strcpy(lista_professor[menor].nome, lista_professor[i].nome);
                    strcpy(lista_professor[i].nome, aux);
                }
                }
                printf("\n****** Professor(es) Ordenado(s) por nome ******\n");
                for(i = 0; i < qtd_professores; i++){
                    printf("\nNome do professor %d: %s", i + 1,lista_professor[i].nome);
                    printf("-----");}
                return 1; break;   
            }
            
            case 3: {
                for(j = 0; j < qtd_professores;j++)
                    for(i = 0; i<15;i++)
                        copiadatas[j][i] =  lista_professor[j].dataNascimento[i];
                
                if(qtd_professores == 1){
                    for(i = 0; i<15;i++){
                        printf("\nProfessor %d = %s", i + 1, copiadatas[i]);
                        return 1;break;} 
                }
                
                for(j = 0; j < qtd_professores;j++)
                    for(i = 0; i<50;i++)
                        copianomes[j][i] =  lista_professor[j].nome[i];
                        
                for(i = 0; i < qtd_professores; i++){
                    //calculo do dia
                    dia[i] = (copiadatas[i][0]-'0') * 10;
                    dia[i]+= copiadatas[i][1]-'0';
                    //calculo do mes
                    mes[i] = (copiadatas[i][3]-'0') * 10;
                    mes[i] += copiadatas[i][4]-'0';
                    //calculo do ano 
                    ano[i] = (copiadatas[i][6]-'0') * 1000;
                    ano[i] += (copiadatas[i][7]-'0') * 100;
                    ano[i] += (copiadatas[i][8]-'0') * 10;
                    ano[i] += copiadatas[i][9]-'0';
                    
                }
                
                for(i = 0; i < qtd_professores; i++){
                    for(j = i + 1; j < qtd_professores ; j++){
                        if(ano[i] > ano[j])
                            {
                                auxdata = ano[i];
                                ano[i] = ano[j];
                                ano[j] = auxdata;
                                
                                auxdata = mes[i];
                                mes[i] = mes[j];
                                mes[j] = auxdata;
                                
                                auxdata = dia[i];
                                dia[i] = dia[j];
                                dia[j] = auxdata;
                                
                                for(x = 0; x < 50; x++)
                                {
                                    auxcopiP[i][x] = copianomes[i][x];
                                    copianomes[i][x] = copianomes[j][x];
                                    copianomes[j][x] = auxcopiP[i][x];
                                }
                                
                                i = 0;
                            }
                        if(ano[i] == ano[j]){
                            if(mes[i] > mes[j])
                            {
                                auxdata = ano[i];
                                ano[i] = ano[j];
                                ano[j] = auxdata;
                                
                                auxdata = mes[i];
                                mes[i] = mes[j];
                                mes[j] = auxdata;
                                
                                auxdata = dia[i];
                                dia[i] = dia[j];
                                dia[j] = auxdata;
                                
                                for(x = 0; x < 50; x++)
                                {
                                    auxcopiP[i][x] = copianomes[i][x];
                                    copianomes[i][x] = copianomes[j][x];
                                    copianomes[j][x] = auxcopiP[i][x];
                                }
                                
                                i = 0;
                            }
                        }
                        if(mes[i] == mes[j]){
                            if(dia[i] > dia[j])
                            {
                                auxdata = ano[i];
                                ano[i] = ano[j];
                                ano[j] = auxdata;
                                
                                auxdata = mes[i];
                                mes[i] = mes[j];
                                mes[j] = auxdata;
                                
                                auxdata = dia[i];
                                dia[i] = dia[j];
                                dia[j] = auxdata;
                                
                                for(x = 0; x < 50; x++)
                                {
                                    auxcopiP[i][x] = copianomes[i][x];
                                    copianomes[i][x] = copianomes[j][x];
                                    copianomes[j][x] = auxcopiP[i][x];
                                }
                                
                                i = 0;
                            }
                        }    
                        }
                    }    
                    printf("\n****** Professor(s) Ordenado(s) por data de nascimento ******\n"); 
                    for(i = 0; i<qtd_professores;i++){
                        printf("\nProfessor %d : %s Data : %d/%d/%d",i + 1, copianomes[i], dia[i] , mes[i] , ano[i]);
                        printf("\n-----");
                    }
                fim = 1; return 1; break;
                }   
            default: {
                printf("\nOpcao inválida retornando ao menu de listagem");}
            }
        } 
                
        }
            printf("\nOpção inválida retornando ao Menu principal");
		return 0;
    
}        
    
void aniversarianteMes(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    system("clear");
    int op;
    int i;
    int mesal[qtd_alunos], opmes;
    int mespr[qtd_alunos];
    int cont = 0 ;
    
    printf("\nDigite 1 se deseja consultar os Alunos e 2 para os Professores : ");
    scanf("%d",&op);
    getchar();
    
    if(op == 1 && qtd_alunos > 0){
        cont++;
        for(i = 0; i < qtd_alunos; i++){
        //calculo do mes
        mesal[i] = (lista_aluno[i].dataNascimento[3]-'0') * 10;
        mesal[i] += lista_aluno[i].dataNascimento[4]-'0';
        }
        
        printf("\nDigite o mes que deseja pesquisar : ");
        scanf("%d",&opmes);
        
        for(i = 0; i < qtd_alunos; i++){
             if(opmes == mesal[i])
                printf("\nAluno %d : %s", i + 1,lista_aluno[i].nome);
        }
    }
    
    if(op == 2 && qtd_professores > 0){
        cont++;
        for(i = 0; i < qtd_professores; i++){
        //calculo do mes
        mespr[i] = (lista_professor[i].dataNascimento[3]-'0') * 10;
        mespr[i] += lista_professor[i].dataNascimento[4]-'0';
        }
        
        printf("\nDigite o mes que deseja pesquisar : ");
        scanf("%d",&opmes);
        
        for(i = 0; i < qtd_professores; i++){
             if(opmes == mespr[i])
                printf("\nProfessor %d : %s", i + 1,lista_professor[i].nome);
        }
    }
    
    if(cont == 0)
        printf("\nOpção inválida");
}	

void listardisciplinas(Disciplina lista_disciplina[], int qtd_disciplinas){
    system("clear");
    printf("\n****** Disciplinas Cadastradas ******#\n");
            int i;
        for (i = 0; i < qtd_disciplinas; i++){
            printf("-----\n");
            printf("Nome da disciplina: %s", lista_disciplina[i].nome);
            printf("Codigo da disciplina: %d\n", lista_disciplina[i].codigodisc);
            printf("Semestre: %d\n", lista_disciplina[i].semestre);
            printf("Codigo do professor: %d\n", lista_disciplina[i].codigoprof);
            printf("Nome do professor: %s\n", lista_disciplina[i].nomeprofdisc);
        }
       
}    

int listardiscalun(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas,Disciplina lista_alundisc[], int qtd_alundisc){
        system("clear");
        int coddisc = 0;
        int i,j;
        int conti = 0;
        int contj = 0;
        
        printf("\nDigite qual o codigo da disciplina que deseja pesquisar : ");
        scanf("%d",&coddisc);
        
        for (i = 0; i < qtd_disciplinas; i++){
            if(coddisc == lista_disciplina[i].codigodisc){
            printf("-----\n");
            printf("Nome da disciplina: %s", lista_disciplina[i].nome);
            printf("Codigo da disciplina: %d\n", lista_disciplina[i].codigodisc);
            printf("Semestre: %d\n", lista_disciplina[i].semestre);
            printf("Codigo do professor: %d\n", lista_disciplina[i].codigoprof);
            printf("Nome do professor: %s\n", lista_disciplina[i].nomeprofdisc);
            conti++;    
            }
            
            for (j = 0; j < qtd_alundisc; j++){
                if(lista_disciplina[i].codigodisc == lista_alundisc[j].codalundisc){
                    if(contj == 0){
                        printf("\n****** Aluno(s) Cadastrados na disciplina : %s ******#\n",lista_disciplina[i].nome);
                        printf("Nome do Aluno: %s", lista_alundisc[j].nomealundisc);
                        printf("-----\n");
                        contj++;}
                    else{
                        printf("Nome do Aluno: %s", lista_alundisc[j].nomealundisc);
                        printf("-----\n");}
                }
            }
            if(conti == 0){
                printf("\nNão existe disciplina com esse codigo");
                return 0;}
            if(contj == 0){
                printf("\nNão existem alunos cadastrados nessa disciplina");
                return 0;}
            
            return 1;    
            
        }
}