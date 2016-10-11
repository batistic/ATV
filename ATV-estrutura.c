/*
 *                  A.T.V. - ASSISTENTE TECNICO VIRTUAL
 *
 *    Software desenvolvido para auxiliar equipes tecnicas de times de futebol de campo
 *
 *  Desenvolvido por:
 *    Edson da Costa Vitor Junior
 *    Guilherme Atihe de Oliveira
 *    Gustavo Batistic Ribeiro
 *    Pedro Henrique Maldonado Truzzi
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*    Estrutura onde os dados de uma partida sao armazenados    */

struct no_ls{
    int id;
    char adversario[100];
    char sigla_adv[3];
    int dia;
    int mes;
    int gols_pro;
    int gols_contra;
    int substituicoes;
    struct no_ls *prox;
};

typedef struct no_ls partida;
partida *jogo; // declarando um vetor que armazena os jogos

/*    Estrutura onde os dados de um jogador sao armazenados    */

typedef struct {
    // Controle
    int controle;
    // Dados pessoais
    char nome[100]; int idade; float altura; float peso; int pe; int uniforme; int posicao[17];
    // Estatisticas em jogo
    float notas[100];         float media_notas;
    int passesC[100];         float media_passesC;          int total_passesC;
    int passesE[100];         float media_passesE;          int total_passesE;
    int finalizacoesC[100];   float media_finalizacoesC;    int total_finalizacoesC;
    int finalizacoesE[100];   float media_finalizacoesE;    int total_finalizacoesE;
    int desarmes[100];        float media_desarmes;         int total_desarmes;
    int perdas[100];          float media_perdas;           int total_perdas;
    int gols[100];            float media_gols;             int total_gols;
    int golsC[100];           float media_golsC;            int total_golsC;
    int faltasC[100];         float media_faltasC;          int total_faltasC;
    int faltasS[100];         float media_faltasS;          int total_faltasS;
    int imped[100];           float media_imped;            int total_imped;
    int assistG[100];         float media_assistG;          int total_assistG;
    int assistF[100];         float media_assistF;          int total_assistF;
    int penaltisC[100];       float media_penaltisC;        int total_penaltisC;
    int penaltisS[100];       float media_penaltisS;        int total_penaltisS;
    int penaltisP[100];       float media_penaltisP;        int total_penaltisP;
    int pos[100];             int pos_mais_usada;
    int jogou[100];           int jogos;
}jogador;

jogador elenco[40]; // declarando um vetor que armazena 40 jogadores

/*    Estrutura onde os dados de um goleiro sao armazenados    */

typedef struct {
    // Controle
    int controle;
    // Dados pessoais
    char nome[100]; int idade; float altura; float peso; int pe; int uniforme;
    // Estatisticas em jogo
    float notas[100];         float media_notas;
    int passesC[100];         float media_passesC;          int total_passesC;
    int passesE[100];         float media_passesE;          int total_passesE;
    int defesas[100];         float media_defesas;          int total_defesas;
    int perdas[100];          float media_perdas;           int total_perdas;
    int golsS[100];           float media_golsS;            int total_golsS;
    int golsC[100];           float media_golsC;            int total_golsC;
    int golsF[100];           float media_golsF;            int total_golsF;
    int faltasC[100];         float media_faltasC;          int total_faltasC;
    int faltasS[100];         float media_faltasS;          int total_faltasS;
    int imped[100];           float media_imped;            int total_imped;
    int assistG[100];         float media_assistG;          int total_assistG;
    int assistF[100];         float media_assistF;          int total_assistF;
    int penaltisC[100];       float media_penaltisC;        int total_penaltisC;
    int penaltisS[100];       float media_penaltisS;        int total_penaltisS;
    int penaltisD[100];       float media_penaltisD;        int total_penaltisD;
    int penaltisP[100];       float media_penaltisP;        int total_penaltisP;
    int jogou[100];           int jogos;
}goleiro;

goleiro goleiros[10]; // declarando um vetor que armazena 10 goleiros

/*    Prototipos das funcoes da lista escadeada simples    */

int Inicializar_LS   (partida **inicio);
int Inserir_LS       (partida **inicio, char adv[], char sgl[], int diaD, int mesD, int golsP, int golsC, int subs, int *n);
int Editar_LS        (partida **inicio, int i, char adv[], char sgl[], int diaD, int mesD, int golsP, int golsC, int subs);
int Listar_LS        (partida *inicio);
int Encontrar_LS     (partida *inicio, int i, int *diaD, int *mesD, int *golsP, int *golsC, char sgl[], char adv[]);

/*    Prototipos das funcoes utilizadas    */

int cadastrar(); //cadastra um novo jogador
int editar(); //edita o cadastro de um jogador
int excluir(); // exclui o cadastro de um jogador
int lista_jogadores(); //lista todos os jogadores do grupo
int lista_jogos(partida **inicio); // lista todos os jogos ocorridos
int estatisticas_jogador(partida **inicio); //exibe as estatísticas de um jogador
int estatisticas_grupo(); //exibe as estatisticas do grupo
int inserir_dados(partida **inicio); //insere os dados de uma partida
int editar_dados(partida **inicio); //edita os dados de uma partida que já ocorreu
float media_jogador(int total, int num_jogador); //calcula a media de um jogador
float media_jogadorN(int num_jogador); //calcula a media de notas de um jogador
float pontuacao(int num_uniforme, int n); //calcula a pontuação do jogador na partida
//int rankingI(int indicador); //exibe o ranking dos jogadores por um indicador //acredito que não será utilizada
//int rankingF(float indicador); //exibe o ranking dos jogadores por um indicador //acredito que não será utilizada
int melhor_escalacao();//exibe a melhor escalação baseado nas melhores notas por posição //todo
int grupo_notas(); //exibe as estatísticas de nota do grupo //todo
int grupo_GeF(); //exibe as estatísticas de gol e finalização do grupo //da pra melhorar
int grupo_PeA();//exibe as estatísticas de passes e assistências do grupo //todo
int grupo_DeP();//exibe as estatísticas de desarme e de perdas de posse de bola do grupo //todo
int grupo_Def();//exibe as estatísticas de defesa do grupo //todo
int grupo_FeP();//exibe as estatísticas de faltas e pênaltis do grupo //todo
int grupo_Imp();//exibe as estatísticas de impedimentos do grupo //todo
int jogador_dados(int num_uniforme);//mostra os dados gerais do jogador
int jogador_GeF(int num_uniforme, partida *inicio);//exibe as estatísticas de gol e finalização do jogador
int goleiro_Gols(int num_uniforme, partida *inicio);//exibe as estatísticas de gols sofridos e convertidos do goleiro
int jogador_PeA(int num_uniforme, partida *inicio);//exibe as estatísticas de passes e assistências do jogador
int jogador_DeP(int num_uniforme, partida *inicio);//exibe as estatísticas de desarmes e de perdas de posse de bola do jogador
int jogador_DeG(int num_uniforme, partida *inicio);//exibe as estatísticas de defesa do jogador
int jogador_FeP(int num_uniforme, partida *inicio);//exibe as estatísticas de faltas e pênaltis do jogador
int jogador_Imp(int num_uniforme, partida *inicio);//exibe as estatísticas de impedimentos do jogador
int jogador_notas(int num_uniforme, partida *inicio);//exibe as estatísticas de notas do jogador

/* Funcao principal */

int main()
{
    int comando;

    jogo = (partida *) malloc(sizeof(partida));
    Inicializar_LS(&jogo);

    int i,j;
    for(i=0;i<40;i++)
    {
        elenco[i].controle=0; // zerando os controles dos jogadores
        elenco[i].uniforme=-1; // zerando os uniformes dos jogadores
        elenco[i].jogos=0;
        for(j=0;j<100;j++) // zerando os jogos dos jogadores
            elenco[i].jogou[j]=0;
        for(j=0;j<17;j++)
            elenco[i].posicao[j]=0; // zerando as posições dos jogadores
        // zerando as medias dos jogadores
        elenco[i].media_assistF=0;
        elenco[i].media_assistG=0;
        elenco[i].media_desarmes=0;
        elenco[i].media_perdas=0;
        elenco[i].media_faltasC=0;
        elenco[i].media_faltasS=0;
        elenco[i].media_gols=0;
        elenco[i].media_golsC=0;
        elenco[i].media_finalizacoesC=0;
        elenco[i].media_finalizacoesE=0;
        elenco[i].media_imped=0;
        elenco[i].media_notas=0;
        elenco[i].media_passesC=0;
        elenco[i].media_passesE=0;
        elenco[i].media_penaltisC=0;
        elenco[i].media_penaltisS=0;
        elenco[i].media_penaltisP=0;
        // zerando o total dos indicadores
        elenco[i].total_assistF=0;
        elenco[i].total_assistG=0;
        elenco[i].total_desarmes=0;
        elenco[i].total_perdas=0;
        elenco[i].total_faltasC=0;
        elenco[i].total_faltasS=0;
        elenco[i].total_gols=0;
        elenco[i].total_golsC=0;
        elenco[i].total_finalizacoesC=0;
        elenco[i].total_finalizacoesE=0;
        elenco[i].total_imped=0;
        elenco[i].total_passesC=0;
        elenco[i].total_passesE=0;
        elenco[i].total_penaltisC=0;
        elenco[i].total_penaltisS=0;
        elenco[i].total_penaltisP=0;
        elenco[i].pos_mais_usada=0;
    }
    for(i=0;i<10;i++)
    {
        goleiros[i].controle=0; // zerando os controles dos goleiros
        goleiros[i].uniforme=-1; // zerando os uniformes dos goleiros
        goleiros[i].jogos=0;
        for(j=0;j<100;j++) // zerando os jogos dos goleiros
            goleiros[i].jogou[j]=0;
        // zerando as medias dos goleiros
        goleiros[i].media_assistF=0;
        goleiros[i].media_assistG=0;
        goleiros[i].media_defesas=0;
        goleiros[i].media_faltasC=0;
        goleiros[i].media_faltasS=0;
        goleiros[i].media_golsC=0;
        goleiros[i].media_golsS=0;
        goleiros[i].media_perdas=0;
        goleiros[i].media_imped=0;
        goleiros[i].media_notas=0;
        goleiros[i].media_passesC=0;
        goleiros[i].media_passesE=0;
        goleiros[i].media_penaltisC=0;
        goleiros[i].media_penaltisS=0;
        goleiros[i].media_penaltisP=0;
        goleiros[i].media_penaltisD=0;
        // zerando o total dos indicadores
        goleiros[i].total_assistF=0;
        goleiros[i].total_assistG=0;
        goleiros[i].total_defesas=0;
        goleiros[i].total_faltasC=0;
        goleiros[i].total_faltasS=0;
        goleiros[i].total_golsC=0;
        goleiros[i].total_golsS=0;
        goleiros[i].total_perdas=0;
        goleiros[i].total_imped=0;
        goleiros[i].total_passesC=0;
        goleiros[i].total_passesE=0;
        goleiros[i].total_penaltisC=0;
        goleiros[i].total_penaltisS=0;
        goleiros[i].total_penaltisP=0;
        goleiros[i].total_penaltisD=0;
    }

    do{
        system("cls");  // limpando a tela
        /* Menu de opções */
        printf("\tA.T.V.\n\n");
        printf("1. Cadastrar jogador.\n");
        printf("2. Editar dados de jogador.\n");
        printf("3. Excluir cadastro de um jogador.\n");
        printf("4. Inserir dados de uma partida.\n");
        printf("5. Editar dados de uma partida.\n");
        printf("6. Ver estatisticas de um jogador.\n");
        printf("7. Ver estatisticas do grupo.\n");
        printf("0. Sair.\n");
        printf("\n-> ");
        scanf("%d",&comando); // leitura da opção

        switch(comando)
        {
            case 1:
                cadastrar(); // entra na função que cadastra jogadores
                break;

            case 2:
                editar(); // entra na função que edita cadastro de jogadores
                break;

            case 3:
                excluir(); // entra na função que exclui cadastro de jogaador
                break;

            case 4:
                inserir_dados(&jogo); // entra na função que cadastra insere dados de uma partida
                break;

            case 5:
                editar_dados(&jogo); // entra na função que cadastra edita dados de uma partida
                break;

            case 6:
                estatisticas_jogador(&jogo); // entra na função que exibe as estatisticas de um jogador
                break;

            case 7:
                estatisticas_grupo(); // entra na função que exibe as estatisticas do grupo
                break;

            case 0:
                system("cls");
                printf("\t\tAte logo!\n\n");  // sai do sistema
                system("PAUSE");
                break;

            default:
                printf("Digite uma opcao valida\n");
        }

    }while(comando!=0);

    return 0;
}

/* Funcao que cadastra um novo jogador */

int cadastrar()
{
    system("cls");
    int pos,i,n,num_uniforme,j; // variaveis auxiliares
    int erro=1; // variavel para testar se um n. de uniforme ja foi cadastrado
    printf("\tCadastrar jogador.\n\n");
    printf("1. Jogador.\t2. Goleiro.\n0. Voltar\n\n-> ");//solicita que o usuário defina se é goleiro ou não
    while(pos!=1 && pos!=2 && pos!=0){//verifica se entrada é valida (apenas 1 e 2 permitidos)
        scanf("%d",&pos);
        if(pos!=1 && pos!=2 && pos!=0)
            printf("Digite uma opcao valida ->");
    }
    if(pos==0)
        return 0;
    if(pos==1)//caso entrada seja 1) Jogador (que não goleiro)
    {
        for(i=0;i<40;i++)//verifica uma posição livre no vetor de jogadores em ordem crescente
                        // 0 para vazia, 1 para ocupada, se o valor do controle na posição i = 0, grava nesta posição
        {
            if(elenco[i].controle==0)
            {
                n=i;
                break;
            }
        }
        elenco[n].controle=1; // mostra que a posição tem um jogador cadastrado
        //leitura de dados do jogador
        printf("Nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s",elenco[n].nome);
        printf("Idade: ");
        scanf("%d",&elenco[n].idade);
        printf("Altura: ");
        scanf("%f",&elenco[n].altura);
        printf("Peso: ");
        scanf("%f",&elenco[n].peso);
        printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
        scanf("%d",&elenco[n].pe);
        while(erro==1)  // loop para verificar se o numero do uniforme já não pertence a outro jogador
        {
            printf("Numero no uniforme: ");
            scanf("%d",&num_uniforme);
            for(i=0;i<40;i++)   // percorrendo todas as posições de jogador possíveis
            {
                if(i<10)
                {
                    if(num_uniforme==goleiros[i].uniforme)  // verifica se tem um goleiro com esse numero de uniforme
                    {
                        printf("Numero de uniforme ja cadastrado!\n");
                        break;
                    }
                }
                if(num_uniforme==elenco[i].uniforme)  // verifica se tem um jogador com esse numero de uniforme
                {
                    printf("Numero de uniforme ja cadastrado!\n");
                    break;
                }
                if(i==39) // todas as posições percorridas, significa que ninguem tem o mesmo numero de uniforme
                {
                    erro=0;
                    elenco[n].uniforme=num_uniforme;
                }
            }
        }
        printf("Insira as siglas das possiveis posicoes de atuacao (separadas por espaco):\n");
        printf("ZD: Zagueiro Direito,             ZE: Zagueiro Esquerdo,\n");
        printf("ZC: Zagueiro Central,             LDD: Lateral Direito Defensivo,\n");
        printf("LED: Lateral Esquerdo Defensivo,  LDO: Lateral Direito Ofensivo,\n");
        printf("LEO: Lateral Esquerdo Ofensivo,   PV: Primeiro Volante,\n");
        printf("SV: Segundo Volante,              ARM: Armador,\n");
        printf("MD: Meia Direita,                 ME: Meia Esquerda,\n");
        printf("MA: Meia Atacante,                SA: Segundo Atacante,\n");
        printf("PD: Ponta Direita,                PE: Ponta Esquerda,\n");
        printf("CA: Centroavante.\n");
        printf("\n-> ");
        char ch; // variavel para fazer a leitura caractere por caractere
        i=0;   // zerando variavel auxiliar
        setbuf(stdin, NULL);
        do
        {
            ch=getchar(); // lendo caractere por caractere
            if(ch!=' ') // quando o usuario digita espaço ou enter
            {
                if((ch>64 && ch<91) || (ch>96 && ch<123))
                {
                    if(ch=='Z' || ch=='z')
                    {
                        ch=getchar();
                        if(ch=='D' || ch=='d')
                        {
                            elenco[n].posicao[i]=1;
                            i++;
                        }
                        if(ch=='E' || ch=='e')
                        {
                            elenco[n].posicao[i]=2;
                            i++;
                        }
                        if(ch=='C' || ch=='c')
                        {
                            elenco[n].posicao[i]=3;
                            i++;
                        }
                    }
                    if(ch=='L' || ch=='l')
                    {
                        ch=getchar();
                        if(ch=='D' || ch=='d')
                        {
                            ch=getchar();
                            if(ch=='D' || ch=='d')
                            {
                                elenco[n].posicao[i]=4;
                                i++;
                            }
                            if(ch=='O' || ch=='o')
                            {
                                elenco[n].posicao[i]=6;
                                i++;
                            }
                        }
                        if(ch=='E' || ch=='e')
                        {
                            ch=getchar();
                            if(ch=='D' || ch=='d')
                            {
                                elenco[n].posicao[i]=5;
                                i++;
                            }
                            if(ch=='O' || ch=='o')
                            {
                                elenco[n].posicao[i]=7;
                                i++;
                            }
                        }
                    }
                    if(ch=='P' || ch=='p')
                    {
                        ch=getchar();
                        if(ch=='V' || ch=='v')
                        {
                            elenco[n].posicao[i]=8;
                            i++;
                        }
                        if(ch=='D' || ch=='d')
                        {
                            elenco[n].posicao[i]=14;
                            i++;
                        }
                        if(ch=='E' || ch=='e')
                        {
                            elenco[n].posicao[i]=15;
                            i++;
                        }
                    }
                    if(ch=='S' || ch=='s')
                    {
                        ch=getchar();
                        if(ch=='V' || ch=='v')
                        {
                            elenco[n].posicao[i]=9;
                            i++;
                        }
                        if(ch=='A' || ch=='a')
                        {
                            elenco[n].posicao[i]=16;
                            i++;
                        }
                    }
                    if(ch=='A' || ch=='a')
                    {
                        ch=getchar();
                        if(ch=='R' || ch=='r')
                        {
                            ch=getchar();
                            if(ch=='M' || ch=='m')
                            {
                                elenco[n].posicao[i]=10;
                                i++;
                            }
                        }
                    }
                    if(ch=='M' || ch=='m')
                    {
                        ch=getchar();
                        if(ch=='D' || ch=='d')
                        {
                            elenco[n].posicao[i]=11;
                            i++;
                        }
                        if(ch=='E' || ch=='e')
                        {
                            elenco[n].posicao[i]=12;
                            i++;
                        }
                        if(ch=='A' || ch=='a')
                        {
                            elenco[n].posicao[i]=13;
                            i++;
                        }
                    }
                    if(ch=='C' || ch=='c')
                    {
                        ch=getchar();
                        if(ch=='A' || ch=='a')
                        {
                            elenco[n].posicao[i]=17;
                            i++;
                        }
                    }
                }
            }
        }while(ch != '\n'); // caso o usuario de enter, o loop é encerrado
    }
    if(pos==2)//caso entrada seja 2) Goleiro
    {
        for(i=0;i<10;i++)//verifica uma posição livre no vetor de jogadores em ordem crescente
                        // 0 para vazia, 1 para ocupada, se o valor do controle na posição i = 0, grava nesta posição
        {
            if(goleiros[i].controle==0)
            {
                n=i;
                break;
            }
        }
        goleiros[i].controle=1; // mostra que a posição tem um jogador cadastrado
        //leitura de dados do jogador
        printf("Nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s",goleiros[n].nome);
        printf("Idade: ");
        scanf("%d",&goleiros[n].idade);
        printf("Altura: ");
        scanf("%f",&goleiros[n].altura);
        printf("Peso: ");
        scanf("%f",&goleiros[n].peso);
        printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
        scanf("%d",&goleiros[n].pe);
        while(erro==1)  // loop para verificar se o numero do uniforme já não pertence a outro jogador
        {
            printf("Numero no uniforme: ");
            scanf("%d",&num_uniforme);
            for(i=0;i<40;i++)   // percorrendo todas as posições de jogador possíveis
            {
                if(i<10)
                {
                     if(num_uniforme==goleiros[i].uniforme)  // verifica se tem um goleiro com esse numero de uniforme
                     {
                         printf("Numero de uniforme ja cadastrado!\n");
                     }
                }
                if(num_uniforme==elenco[i].uniforme)  // verifica se tem um jogador com esse numero de uniforme
                {
                    printf("Numero de uniforme ja cadastrado!\n");
                }
                else
                    if(i==39) // todas as posições percorridas, significa que ninguem tem o mesmo numero de uniforme
                    {
                        erro=0;
                        goleiros[n].uniforme=num_uniforme;
                    }
            }
        }
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

/* Funcao que edita o cadastro de um jogador */

int editar()
{
    system("cls");
    printf("\tEditar cadastro de jogador.\n\n");
    int n,i,encontrado=0; // variaveis auxiliares
    int num_uniforme=lista_jogadores(); // chama a função que lista todos os jogadores e retorna o numero do uniforme do escolhido pelo usuario
    if(num_uniforme==0)
        return 0;
    for(n=0;n<40;n++) // percorrendo todas os jogadores possíveis
    {
        if(num_uniforme==elenco[n].uniforme)    // verifica a quem o numero de uniforme requerido pertence
        {
            // reescreve os dados
            printf("Nome: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s",elenco[n].nome);
            printf("Idade: ");
            scanf("%d",&elenco[n].idade);
            printf("Altura: ");
            scanf("%f",&elenco[n].altura);
            printf("Peso: ");
            scanf("%f",&elenco[n].peso);
            printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
            scanf("%d",&elenco[n].pe);
            int erro=1;
            while(erro==1) // loop para verificar se o numero do uniforme já não pertence a outro jogador
            {
                printf("Numero no uniforme: ");
                scanf("%d",&num_uniforme);
                if(num_uniforme==elenco[n].uniforme) // verifica se o numero de uniforme foi alterado
                {
                    erro=0; // caso não tenha sido alterado
                }
                else
                {
                    for(i=0;i<40;i++) // percorrendo todas as posições de jogador possíveis
                    {
                        if(i<10)
                        {
                            if(num_uniforme==goleiros[i].uniforme)  // verifica se tem um goleiro com esse numero de uniforme
                            {
                                printf("Numero de uniforme ja cadastrado!\n");
                            }
                        }
                        if(num_uniforme==elenco[i].uniforme)  // verifica se tem um jogador com esse numero de uniforme
                        {
                            printf("Numero de uniforme ja cadastrado!\n");
                        }
                        else
                            if(i==39) // todas as posições percorridas, significa que ninguem tem o mesmo numero de uniforme
                            {
                                erro=0;
                                elenco[n].uniforme=num_uniforme;
                            }
                    }
                }
            }
            printf("Insira as siglas das possiveis posicoes de atuacao (separadas por espaco):\n");
            printf("ZD: Zagueiro Direito,             ZE: Zagueiro Esquerdo,\n");
            printf("ZC: Zagueiro Central,             LDD: Lateral Direito Defensivo,\n");
            printf("LED: Lateral Esquerdo Defensivo,  LDO: Lateral Direito Ofensivo,\n");
            printf("LEO: Lateral Esquerdo Ofensivo,   PV: Primeiro Volante,\n");
            printf("SV: Segundo Volante,              ARM: Armador,\n");
            printf("MD: Meia Direita,                 ME: Meia Esquerda,\n");
            printf("MA: Meia Atacante,                SA: Segundo Atacante,\n");
            printf("PD: Ponta Direita,                PE: Ponta Esquerda,\n");
            printf("CA: Centroavante.\n");
            printf("\n-> ");
            char ch; // variavel para fazer a leitura caractere por caractere
            int j=0;
            i=0;   // variaveis auxiliares
            char p[4]; // string que serao armazenadas as posições do jogador
            setbuf(stdin, NULL);
            do
            {
                ch=getchar(); // lendo caractere por caractere
                if(ch==' ' || ch=='\n') // quando o usuario digita espaço ou enter
                {
                    p[i]='\0'; // tornando a ultima posição da string um caractere nulo
                    i=0;
                    // comparando a string com as posições possiveis, e armazenando por numeros
                    if(strcmp(p,"ZD")==0 || strcmp(p,"zd")==0)
                        elenco[n].posicao[j]=1;
                    if(strcmp(p,"ZE")==0 || strcmp(p,"ze")==0)
                        elenco[n].posicao[j]=2;
                    if(strcmp(p,"ZC")==0 || strcmp(p,"zc")==0)
                        elenco[n].posicao[j]=3;
                    if(strcmp(p,"LDD")==0 || strcmp(p,"ldd")==0)
                        elenco[n].posicao[j]=4;
                    if(strcmp(p,"LED")==0 || strcmp(p,"led")==0)
                        elenco[n].posicao[j]=5;
                    if(strcmp(p,"LDO")==0 || strcmp(p,"ldo")==0)
                        elenco[n].posicao[j]=6;
                    if(strcmp(p,"LEO")==0 || strcmp(p,"leo")==0)
                        elenco[n].posicao[j]=7;
                    if(strcmp(p,"PV")==0 || strcmp(p,"pv")==0)
                        elenco[n].posicao[j]=8;
                    if(strcmp(p,"SV")==0 || strcmp(p,"sv")==0)
                        elenco[n].posicao[j]=9;
                    if(strcmp(p,"ARM")==0 || strcmp(p,"arm")==0)
                        elenco[n].posicao[j]=10;
                    if(strcmp(p,"MD")==0 || strcmp(p,"md")==0)
                        elenco[n].posicao[j]=11;
                    if(strcmp(p,"ME")==0 || strcmp(p,"me")==0)
                        elenco[n].posicao[j]=12;
                    if(strcmp(p,"MA")==0 || strcmp(p,"ma")==0)
                        elenco[n].posicao[j]=13;
                    if(strcmp(p,"PD")==0 || strcmp(p,"pd")==0)
                        elenco[n].posicao[j]=14;
                    if(strcmp(p,"PE")==0 || strcmp(p,"pe")==0)
                        elenco[n].posicao[j]=15;
                    if(strcmp(p,"SA")==0 || strcmp(p,"sa")==0)
                        elenco[n].posicao[j]=16;
                    if(strcmp(p,"CA")==0 || strcmp(p,"ca")==0)
                        elenco[n].posicao[j]=17;
                    j++;
                }
                if((ch>64 && ch<91) || (ch>96 && ch<123))
                {
                    p[i]=ch; // caso seja uma letra maiucula, armazena o caractere na string p
                    i++;
                }
            }while(ch != '\n'); // caso o usuario digite enter, o loop é encerrado

            encontrado++;
            break;
            }
    }
    for(n=0;n<10;n++) // percorrendo todos os goleiros possiveis
    {
        if(encontrado==1)
            break;
        if(num_uniforme==goleiros[n].uniforme) // verificando a quem pertence o uniforme requisitado
        {
            // inserindo dados
            printf("Nome: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s",goleiros[n].nome);
            printf("Idade: ");
            scanf("%d",&goleiros[n].idade);
            printf("Altura: ");
            scanf("%f",&goleiros[n].altura);
            printf("Peso: ");
            scanf("%f",&goleiros[n].peso);
            printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
            scanf("%d",&goleiros[n].pe);
            int erro=1;
            do // loop para verificar se o numero do uniforme já não pertence a outro jogador
            {
                printf("Numero no uniforme: ");
                scanf("%d",&num_uniforme);
                if(num_uniforme==goleiros[n].uniforme) // verificando se o uniforme foi alterado
                {
                    erro=0; // não foi alterado
                }
                else
                {
                    for(i=0;i<40;i++) // percorrendo todos os jogadores possíveis
                    {
                        if(i<10)
                        {
                            if(num_uniforme==goleiros[i].uniforme)  // verifica se tem um goleiro com esse numero de uniforme
                            {
                                printf("Numero de uniforme ja cadastrado!\n");
                            }
                        }
                        if(num_uniforme==elenco[i].uniforme)  // verifica se tem um jogador com esse numero de uniforme
                        {
                            printf("Numero de uniforme ja cadastrado!\n");
                        }
                        else
                            if(i==39) // todas as posições percorridas, significa que ninguem tem o mesmo numero de uniforme
                            {
                                erro=0;
                                goleiros[n].uniforme=num_uniforme;
                            }
                    }
                }
            }while(erro==1);

            break;
        }
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

/* Função que exclui o cadastro de um jogador */

int excluir()
{
    system("cls");
    printf("\tExcluir cadastro de jogador.\n\n");
    int num_uniforme=lista_jogadores(); // pedindo ao usuário qual jogador (por uniforme) ele quer excluir
    if(num_uniforme==0)
        return 0;
    int i,j,encontrado=0; // variaveis auxiliares
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme)  // verifica se tem um goleiro com esse numero de uniforme, se sim, qual
        {
            // zerando todos os dados do goleiro
            goleiros[i].controle=0;
            goleiros[i].uniforme=-1;
            for(j=0;j<100;j++)
                goleiros[i].jogou[j]=0;
            goleiros[i].media_assistF=0;
            goleiros[i].media_assistG=0;
            goleiros[i].media_defesas=0;
            goleiros[i].media_faltasC=0;
            goleiros[i].media_faltasS=0;
            goleiros[i].media_golsC=0;
            goleiros[i].media_golsS=0;
            goleiros[i].media_perdas=0;
            goleiros[i].media_imped=0;
            goleiros[i].media_notas=0;
            goleiros[i].media_passesC=0;
            goleiros[i].media_passesE=0;
            goleiros[i].media_penaltisC=0;
            goleiros[i].media_penaltisS=0;
            goleiros[i].media_penaltisD=0;
            goleiros[i].media_penaltisP=0;
            goleiros[i].total_assistF=0;
            goleiros[i].total_assistG=0;
            goleiros[i].total_defesas=0;
            goleiros[i].total_faltasC=0;
            goleiros[i].total_faltasS=0;
            goleiros[i].total_golsC=0;
            goleiros[i].total_golsS=0;
            goleiros[i].total_perdas=0;
            goleiros[i].total_imped=0;
            goleiros[i].total_passesC=0;
            goleiros[i].total_passesE=0;
            goleiros[i].total_penaltisC=0;
            goleiros[i].total_penaltisS=0;
            goleiros[i].total_penaltisD=0;
            goleiros[i].total_penaltisP=0;
            goleiros[i].jogos=0;

            encontrado++;
            break;
        }
    }
    for(i=0;i<40;i++)
    {
        if(encontrado==1)
            break;
        if(num_uniforme==elenco[i].uniforme)  // verifica se tem um jogador com esse numero de uniforme, se sim, qual
        {
            // zerando todos os dados do jogador
            elenco[i].controle=0;
            elenco[i].uniforme=-1;
            for(j=0;j<17;j++)
                elenco[i].posicao[j]=0;
            for(j=0;j<100;j++)
                elenco[i].jogou[j]=0;
            elenco[i].media_assistF=0;
            elenco[i].media_assistG=0;
            elenco[i].media_desarmes=0;
            elenco[i].media_perdas=0;
            elenco[i].media_faltasC=0;
            elenco[i].media_faltasS=0;
            elenco[i].media_gols=0;
            elenco[i].media_finalizacoesC=0;
            elenco[i].media_finalizacoesE=0;
            elenco[i].media_imped=0;
            elenco[i].media_notas=0;
            elenco[i].media_passesC=0;
            elenco[i].media_passesE=0;
            elenco[i].media_penaltisC=0;
            elenco[i].media_penaltisS=0;
            elenco[i].media_penaltisP=0;
            elenco[i].total_assistF=0;
            elenco[i].total_assistG=0;
            elenco[i].total_desarmes=0;
            elenco[i].total_perdas=0;
            elenco[i].total_faltasC=0;
            elenco[i].total_faltasS=0;
            elenco[i].total_gols=0;
            elenco[i].total_finalizacoesC=0;
            elenco[i].total_finalizacoesE=0;
            elenco[i].total_imped=0;
            elenco[i].total_passesC=0;
            elenco[i].total_passesE=0;
            elenco[i].total_penaltisC=0;
            elenco[i].total_penaltisS=0;
            elenco[i].total_penaltisP=0;
            elenco[i].pos_mais_usada=0;
            elenco[i].jogos=0;

            break;
        }
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

/* Função que insere os dados de uma partida */

int inserir_dados(partida **inicio)
{
    system("cls");
    int i,n,j,num_uniforme,opc; // variaveis auxiliares
    // variaveis dos dados da partida
    int jogo_mes, jogo_dia, jogo_gols_pro, jogo_gols_contra, jogo_substituicoes;
    char jogo_adversario[100], jogo_sigla_adv[3];
    printf("\tInserir dados de uma partida.\n\n");
    // lendo dados
    printf("Mes do jogo: ");
    scanf("%d",&jogo_mes);
    printf("Dia do jogo: ");
    scanf("%d",&jogo_dia);
    printf("Adversario: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s",jogo_adversario);
    printf("Sigla do adversario (tres letras): ");
    scanf("%s",jogo_sigla_adv);
    printf("Gols feitos: ");
    scanf("%d",&jogo_gols_pro);
    printf("Gols sofridos: ");
    scanf("%d",&jogo_gols_contra);
    printf("Substituicoes feitas na partida: ");
    scanf("%d",&jogo_substituicoes);
    Inserir_LS(inicio, jogo_adversario, jogo_sigla_adv, jogo_dia, jogo_mes, jogo_gols_pro, jogo_gols_contra, jogo_substituicoes, &n);
    //for(i=0;i<11+jogo_substituicoes;i++) // loop que percorre todos os jogadores que jogaram a partida
    //apagar depois
    for(i=0;i<2;i++)//apagar depois
    //apagar depois
    {
        int encontrado=0;
        printf("\nPara inserir os dados de um jogador na partida, insira o numero de seu uniforme: ");
        scanf("%d",&num_uniforme);
        if(num_uniforme == -1)
        {
            printf("\tDigite o numero de um jogador cadastrado!\n");
            i--;
        }
        else{
        for(j=0;j<10;j++)
        {
            if(num_uniforme==goleiros[j].uniforme) // verifica se o numero do uniforme é de um goleiro, e de qual
            {
                printf("Deseja inserir os dados do %s?\t1. Sim.\t2. Nao\n",goleiros[j].nome);
                scanf("%d",&opc);
                if(opc==2)
                {
                    i--;
                    break;
                }
                encontrado++;
                goleiros[j].jogos++;
                goleiros[j].jogou[n]=1;
                printf("Insira os dados do %s\n",goleiros[j].nome);
                printf("  Defesas: ");
                scanf("%d",&goleiros[j].defesas[n]);
                goleiros[j].total_defesas+=goleiros[j].defesas[n];
                goleiros[j].media_defesas=media_jogador(goleiros[j].total_defesas,goleiros[j].uniforme);
                printf("  Passes corretos: ");
                scanf("%d",&goleiros[j].passesC[n]);
                goleiros[j].total_passesC+=goleiros[j].passesC[n];
                goleiros[j].media_passesC=media_jogador(goleiros[j].total_passesC,goleiros[j].uniforme);
                printf("  Passes errados: ");
                scanf("%d",&goleiros[j].passesE[n]);
                goleiros[j].total_passesE+=goleiros[j].passesE[n];
                goleiros[j].media_passesE=media_jogador(goleiros[j].total_passesE,goleiros[j].uniforme);
                printf("  Perdas de posse: ");
                scanf("%d",&goleiros[j].perdas[n]);
                goleiros[j].total_perdas+=goleiros[j].perdas[n];
                goleiros[j].media_perdas=media_jogador(goleiros[j].total_perdas,goleiros[j].uniforme);
                printf("  Gols sofridos: ");
                scanf("%d",&goleiros[j].golsS[n]);
                goleiros[j].total_golsS+=goleiros[j].golsS[n];
                goleiros[j].media_golsS=media_jogador(goleiros[j].total_golsS,goleiros[j].uniforme);
                printf("  Gols convertidos: ");
                scanf("%d",&goleiros[j].golsF[n]);
                goleiros[j].total_golsF+=goleiros[j].golsF[n];
                goleiros[j].media_golsF=media_jogador(goleiros[j].total_golsF,goleiros[j].uniforme);
                printf("  Gols contra: ");
                scanf("%d",&goleiros[j].golsC[n]);
                goleiros[j].total_golsC+=goleiros[j].golsC[n];
                goleiros[j].media_golsC=media_jogador(goleiros[j].total_golsC,goleiros[j].uniforme);
                printf("  Faltas cometidas: ");
                scanf("%d",&goleiros[j].faltasC[n]);
                goleiros[j].total_faltasC+=goleiros[j].faltasC[n];
                goleiros[j].media_faltasC=media_jogador(goleiros[j].total_faltasC,goleiros[j].uniforme);
                printf("  Faltas sofridas: ");
                scanf("%d",&goleiros[j].faltasS[n]);
                goleiros[j].total_faltasS+=goleiros[j].faltasS[n];
                goleiros[j].media_faltasS=media_jogador(goleiros[j].total_faltasS,goleiros[j].uniforme);
                printf("  Impedimentos: ");
                scanf("%d",&goleiros[j].imped[n]);
                goleiros[j].total_imped+=goleiros[j].imped[n];
                goleiros[j].media_imped=media_jogador(goleiros[j].total_imped,goleiros[j].uniforme);
                printf("  Assistencias (gol): ");
                scanf("%d",&goleiros[j].assistG[n]);
                goleiros[j].total_assistG+=goleiros[j].assistG[n];
                goleiros[j].media_assistG=media_jogador(goleiros[j].total_assistG,goleiros[j].uniforme);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&goleiros[j].assistF[n]);
                goleiros[j].total_assistF+=goleiros[j].assistF[n];
                goleiros[j].media_assistF=media_jogador(goleiros[j].total_assistF,goleiros[j].uniforme);
                printf("  Penaltis cometidos: ");
                scanf("%d",&goleiros[j].penaltisC[n]);
                goleiros[j].total_penaltisC+=goleiros[j].penaltisC[n];
                goleiros[j].media_penaltisC=media_jogador(goleiros[j].total_penaltisC,goleiros[j].uniforme);
                printf("  Penaltis sofridos: ");
                scanf("%d",&goleiros[j].penaltisS[n]);
                goleiros[j].total_penaltisS+=goleiros[j].penaltisS[n];
                goleiros[j].media_penaltisS=media_jogador(goleiros[j].total_penaltisS,goleiros[j].uniforme);
                printf("  Penaltis defendidos: ");
                scanf("%d",&goleiros[j].penaltisD[n]);
                goleiros[j].total_penaltisD+=goleiros[j].penaltisD[n];
                goleiros[j].media_penaltisD=media_jogador(goleiros[j].total_penaltisD,goleiros[j].uniforme);
                printf("  Penaltis perdidos: ");
                scanf("%d",&goleiros[j].penaltisP[n]);
                goleiros[j].total_penaltisP+=goleiros[j].penaltisP[n];
                goleiros[j].media_penaltisP=media_jogador(goleiros[j].total_penaltisP,goleiros[j].uniforme);

                goleiros[j].notas[n]=pontuacao(goleiros[j].uniforme, n);

                break;
            }
        }
        char pos[4]; // variavel para armazenar a posicao jogada na partida
        for(j=0;j<40;j++)
        {
            if(num_uniforme==elenco[j].uniforme) // verifica se o numero do uniforme é de um jogador, e de qual
            {
                printf("Deseja inserir os dados do %s?\t1. Sim.\t2. Nao\n",elenco[j].nome);
                scanf("%d",&opc);
                if(opc==2)
                {
                    i--;
                    break;
                }
                encontrado++;
                elenco[j].jogos++;
                elenco[j].jogou[n]=1;
                printf("Insira os dados do %s\n",elenco[j].nome);
                printf("  Sigla da posicao inicial na partida: ");
                scanf("%s",&pos);
                if(strcmp(pos,"ZD")==0 || strcmp(pos,"zd")==0)
                    elenco[j].pos[n]=1;
                if(strcmp(pos,"ZE")==0 || strcmp(pos,"ze")==0)
                    elenco[j].pos[n]=2;
                if(strcmp(pos,"ZC")==0 || strcmp(pos,"zc")==0)
                    elenco[j].pos[n]=3;
                if(strcmp(pos,"LDD")==0 || strcmp(pos,"ldd")==0)
                    elenco[j].pos[n]=4;
                if(strcmp(pos,"LED")==0 || strcmp(pos,"led")==0)
                    elenco[j].pos[n]=5;
                if(strcmp(pos,"LDO")==0 || strcmp(pos,"ldo")==0)
                    elenco[j].pos[n]=6;
                if(strcmp(pos,"LEO")==0 || strcmp(pos,"leo")==0)
                    elenco[j].pos[n]=7;
                if(strcmp(pos,"PV")==0 || strcmp(pos,"pv")==0)
                    elenco[j].pos[n]=8;
                if(strcmp(pos,"SV")==0 || strcmp(pos,"sv")==0)
                    elenco[j].pos[n]=9;
                if(strcmp(pos,"ARM")==0 || strcmp(pos,"arm")==0)
                    elenco[j].pos[n]=10;
                if(strcmp(pos,"MD")==0 || strcmp(pos,"md")==0)
                    elenco[j].pos[n]=11;
                if(strcmp(pos,"ME")==0 || strcmp(pos,"me")==0)
                    elenco[j].pos[n]=12;
                if(strcmp(pos,"MA")==0 || strcmp(pos,"ma")==0)
                    elenco[j].pos[n]=13;
                if(strcmp(pos,"PD")==0 || strcmp(pos,"pd")==0)
                    elenco[j].pos[n]=14;
                if(strcmp(pos,"PE")==0 || strcmp(pos,"pe")==0)
                    elenco[j].pos[n]=15;
                if(strcmp(pos,"SA")==0 || strcmp(pos,"sa")==0)
                    elenco[j].pos[n]=16;
                if(strcmp(pos,"CA")==0 || strcmp(pos,"ca")==0)
                    elenco[j].pos[n]=17;
                printf("  Passes corretos: ");
                scanf("%d",&elenco[j].passesC[n]);
                elenco[j].total_passesC+=elenco[j].passesC[n];
                elenco[j].media_passesC=media_jogador(elenco[j].total_passesC,elenco[j].uniforme);
                printf("  Passes errados: ");
                scanf("%d",&elenco[j].passesE[n]);
                elenco[j].total_passesE+=elenco[j].passesE[n];
                elenco[j].media_passesE=media_jogador(elenco[j].total_passesE,elenco[j].uniforme);
                printf("  Finalizacoes corretas: ");
                scanf("%d",&elenco[j].finalizacoesC[n]);
                elenco[j].total_finalizacoesC+=elenco[j].finalizacoesC[n];
                elenco[j].media_finalizacoesC=media_jogador(elenco[j].total_finalizacoesC,elenco[j].uniforme);
                printf("  Finalizacoes erradas: ");
                scanf("%d",&elenco[j].finalizacoesE[n]);
                elenco[j].total_finalizacoesE+=elenco[j].finalizacoesE[n];
                elenco[j].media_finalizacoesE=media_jogador(elenco[j].total_finalizacoesE,elenco[j].uniforme);
                printf("  Desarmes: ");
                scanf("%d",&elenco[j].desarmes[n]);
                elenco[j].total_desarmes+=elenco[j].desarmes[n];
                elenco[j].media_desarmes=media_jogador(elenco[j].total_desarmes,elenco[j].uniforme);
                printf("  Perdas de posse: ");
                scanf("%d",&elenco[j].perdas[n]);
                elenco[j].total_perdas+=elenco[j].perdas[n];
                elenco[j].media_perdas=media_jogador(elenco[j].total_perdas,elenco[j].uniforme);
                printf("  Gols: ");
                scanf("%d",&elenco[j].gols[n]);
                elenco[j].total_gols+=elenco[j].gols[n];
                elenco[j].media_gols=media_jogador(elenco[j].total_gols,elenco[j].uniforme);
                printf("  Gols contra: ");
                scanf("%d",&elenco[j].golsC[n]);
                elenco[j].total_golsC+=elenco[j].golsC[n];
                elenco[j].media_golsC=media_jogador(elenco[j].total_golsC,elenco[j].uniforme);
                printf("  Faltas cometidas: ");
                scanf("%d",&elenco[j].faltasC[n]);
                elenco[j].total_faltasC+=elenco[j].faltasC[n];
                elenco[j].media_faltasC=media_jogador(elenco[j].total_faltasC,elenco[j].uniforme);
                printf("  Faltas sofridas: ");
                scanf("%d",&elenco[j].faltasS[n]);
                elenco[j].total_faltasS+=elenco[j].faltasS[n];
                elenco[j].media_faltasS=media_jogador(elenco[j].total_faltasS,elenco[j].uniforme);
                printf("  Impedimentos: ");
                scanf("%d",&elenco[j].imped[n]);
                elenco[j].total_imped+=elenco[j].imped[n];
                elenco[j].media_imped=media_jogador(elenco[j].total_imped,elenco[j].uniforme);
                printf("  Assistencias (gol): ");
                scanf("%d",&elenco[j].assistG[n]);
                elenco[j].total_assistG+=elenco[j].assistG[n];
                elenco[j].media_assistG=media_jogador(elenco[j].total_assistG,elenco[j].uniforme);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&elenco[j].assistF[n]);
                elenco[j].total_assistF+=elenco[j].assistF[n];
                elenco[j].media_assistF=media_jogador(elenco[j].total_assistF,elenco[j].uniforme);
                printf("  Penaltis cometidos: ");
                scanf("%d",&elenco[j].penaltisC[n]);
                elenco[j].total_penaltisC+=elenco[j].penaltisC[n];
                elenco[j].media_penaltisC=media_jogador(elenco[j].total_penaltisC,elenco[j].uniforme);
                printf("  Penaltis sofridos: ");
                scanf("%d",&elenco[j].penaltisS[n]);
                elenco[j].total_penaltisS+=elenco[j].penaltisS[n];
                elenco[j].media_penaltisS=media_jogador(elenco[j].total_penaltisS,elenco[j].uniforme);
                printf("  Penaltis perdidos: ");
                scanf("%d",&elenco[j].penaltisP[n]);
                elenco[j].total_penaltisP+=elenco[j].penaltisP[n];
                elenco[j].media_penaltisP=media_jogador(elenco[j].total_penaltisP,elenco[j].uniforme);

                elenco[j].notas[n]=pontuacao(elenco[j].uniforme, n);

                break;
            }
            if(j==39 && encontrado==0)
            {
                printf("\tDigite o numero de um jogador cadastrado!\n");
                i--;
            }
        }
        }
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

/* Funcao que edita os dados de uma partida */

int editar_dados(partida **inicio)
{
    system("cls");
    printf("\tEditar dados de uma partida.\n\n");
    int n=lista_jogos(inicio);
    if(n<0)
        return 0;
    int i,j,num_uniforme,opc; // variaveis auxiliares
    // variaveis dos dados da partida
    int jogo_mes, jogo_dia, jogo_gols_pro, jogo_gols_contra, jogo_substituicoes;
    char jogo_adversario[100], jogo_sigla_adv[3];
    // zerando os dados da partida
    for(i=0;i<10;i++)
    {
        if(goleiros[i].jogou[n]==1){
            goleiros[i].jogos--;
            goleiros[i].jogou[n]=0;
            goleiros[i].total_defesas-=goleiros[i].defesas[n];
            goleiros[i].media_defesas=media_jogador(goleiros[i].total_defesas,goleiros[i].uniforme);
            goleiros[i].total_perdas-=goleiros[i].perdas[n];
            goleiros[i].media_perdas=media_jogador(goleiros[i].total_perdas,goleiros[i].uniforme);
            goleiros[i].total_imped-=goleiros[i].imped[n];
            goleiros[i].media_imped=media_jogador(goleiros[i].total_imped,goleiros[i].uniforme);
            goleiros[i].total_assistF-=goleiros[i].assistF[n];
            goleiros[i].media_assistF=media_jogador(goleiros[i].total_assistF,goleiros[i].uniforme);
            goleiros[i].total_assistG-=goleiros[i].assistG[n];
            goleiros[i].media_assistG=media_jogador(goleiros[i].total_assistG,goleiros[i].uniforme);
            goleiros[i].total_passesC-=goleiros[i].passesC[n];
            goleiros[i].media_passesC=media_jogador(goleiros[i].total_passesC,goleiros[i].uniforme);
            goleiros[i].total_passesE-=goleiros[i].passesE[n];
            goleiros[i].media_passesE=media_jogador(goleiros[i].total_passesE,goleiros[i].uniforme);
            goleiros[i].total_golsF-=goleiros[i].golsF[n];
            goleiros[i].media_golsF=media_jogador(goleiros[i].total_golsF,goleiros[i].uniforme);
            goleiros[i].total_golsC-=goleiros[i].golsC[n];
            goleiros[i].media_golsC=media_jogador(goleiros[i].total_golsC,goleiros[i].uniforme);
            goleiros[i].total_golsS-=goleiros[i].golsS[n];
            goleiros[i].media_golsS=media_jogador(goleiros[i].total_golsS,goleiros[i].uniforme);
            goleiros[i].total_faltasC-=goleiros[i].faltasC[n];
            goleiros[i].media_faltasC=media_jogador(goleiros[i].total_faltasC,goleiros[i].uniforme);
            goleiros[i].total_faltasS-=goleiros[i].faltasS[n];
            goleiros[i].media_faltasS=media_jogador(goleiros[i].total_faltasS,goleiros[i].uniforme);
            goleiros[i].total_penaltisC-=goleiros[i].penaltisC[n];
            goleiros[i].media_penaltisC=media_jogador(goleiros[i].total_penaltisC,goleiros[i].uniforme);
            goleiros[i].total_penaltisP-=goleiros[i].penaltisP[n];
            goleiros[i].media_penaltisP=media_jogador(goleiros[i].total_penaltisP,goleiros[i].uniforme);
            goleiros[i].total_penaltisS-=goleiros[i].penaltisS[n];
            goleiros[i].media_penaltisS=media_jogador(goleiros[i].total_penaltisS,goleiros[i].uniforme);
            goleiros[i].media_notas=media_jogadorN(goleiros[i].uniforme);
        }
        goleiros[i].passesC[n]=0;
        goleiros[i].passesE[n]=0;
        goleiros[i].golsC[n]=0;
        goleiros[i].golsS[n]=0;
        goleiros[i].golsF[n]=0;
        goleiros[i].perdas[n]=0;
        goleiros[i].defesas[n]=0;
        goleiros[i].imped[n]=0;
        goleiros[i].assistF[n]=0;
        goleiros[i].assistG[n]=0;
        goleiros[i].faltasC[n]=0;
        goleiros[i].faltasS[n]=0;
        goleiros[i].penaltisC[n]=0;
        goleiros[i].penaltisP[n]=0;
        goleiros[i].penaltisS[n]=0;
        goleiros[i].notas[n]=0;
    }
    for(i=0;i<40;i++)
    {
        if(elenco[i].jogou[n]==1){
            elenco[i].jogos--;
            elenco[i].jogou[n]=0;
            elenco[i].total_passesC-=elenco[i].passesC[n];
            elenco[i].media_passesC=media_jogador(elenco[i].total_passesC,elenco[i].uniforme);
            elenco[i].total_passesE-=elenco[i].passesE[n];
            elenco[i].media_passesE=media_jogador(elenco[i].total_passesE,elenco[i].uniforme);
            elenco[i].total_gols-=elenco[i].gols[n];
            elenco[i].media_gols=media_jogador(elenco[i].total_gols,elenco[i].uniforme);
            elenco[i].total_golsC-=elenco[i].golsC[n];
            elenco[i].media_golsC=media_jogador(elenco[i].total_golsC,elenco[i].uniforme);
            elenco[i].total_finalizacoesC-=elenco[i].finalizacoesC[n];
            elenco[i].media_finalizacoesC=media_jogador(elenco[i].total_finalizacoesC,elenco[i].uniforme);
            elenco[i].total_finalizacoesE-=elenco[i].finalizacoesE[n];
            elenco[i].media_finalizacoesE=media_jogador(elenco[i].total_finalizacoesE,elenco[i].uniforme);
            elenco[i].total_desarmes-=elenco[i].desarmes[n];
            elenco[i].media_desarmes=media_jogador(elenco[i].total_desarmes,elenco[i].uniforme);
            elenco[i].total_perdas-=elenco[i].perdas[n];
            elenco[i].media_perdas=media_jogador(elenco[i].total_perdas,elenco[i].uniforme);
            elenco[i].total_imped-=elenco[i].imped[n];
            elenco[i].media_imped=media_jogador(elenco[i].total_imped,elenco[i].uniforme);
            elenco[i].total_assistF-=elenco[i].assistF[n];
            elenco[i].media_assistF=media_jogador(elenco[i].total_assistF,elenco[i].uniforme);
            elenco[i].total_assistG-=elenco[i].assistG[n];
            elenco[i].media_assistG=media_jogador(elenco[i].total_assistG,elenco[i].uniforme);
            elenco[i].total_faltasC-=elenco[i].faltasC[n];
            elenco[i].media_faltasC=media_jogador(elenco[i].total_faltasC,elenco[i].uniforme);
            elenco[i].total_faltasS-=elenco[i].faltasS[n];
            elenco[i].media_faltasS=media_jogador(elenco[i].total_faltasS,elenco[i].uniforme);
            elenco[i].total_penaltisC-=elenco[i].penaltisC[n];
            elenco[i].media_penaltisC=media_jogador(elenco[i].total_penaltisC,elenco[i].uniforme);
            elenco[i].total_penaltisP-=elenco[i].penaltisP[n];
            elenco[i].media_penaltisP=media_jogador(elenco[i].total_penaltisP,elenco[i].uniforme);
            elenco[i].total_penaltisS-=elenco[i].penaltisS[n];
            elenco[i].media_penaltisS=media_jogador(elenco[i].total_penaltisS,elenco[i].uniforme);
            elenco[i].media_notas=media_jogadorN(elenco[i].uniforme);
        }
        elenco[i].passesC[n]=0;
        elenco[i].passesE[n]=0;
        elenco[i].gols[n]=0;
        elenco[i].golsC[n]=0;
        elenco[i].finalizacoesC[n]=0;
        elenco[i].finalizacoesE[n]=0;
        elenco[i].desarmes[n]=0;
        elenco[i].perdas[n]=0;
        elenco[i].imped[n]=0;
        elenco[i].assistF[n]=0;
        elenco[i].assistG[n]=0;
        elenco[i].faltasC[n]=0;
        elenco[i].faltasS[n]=0;
        elenco[i].penaltisC[n]=0;
        elenco[i].penaltisP[n]=0;
        elenco[i].penaltisS[n]=0;
        elenco[i].notas[n]=0;
        elenco[i].pos[n]=0;
    }
    // atualizando dados da partida
    printf("Mes do jogo: ");
    scanf("%d",&jogo_mes);
    printf("Dia do jogo: ");
    scanf("%d",&jogo_dia);
    printf("Adversario: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s",jogo_adversario);
    printf("Sigla do adversario (tres letras): ");
    scanf("%s",jogo_sigla_adv);
    printf("Gols feitos: ");
    scanf("%d",&jogo_gols_pro);
    printf("Gols sofridos: ");
    scanf("%d",&jogo_gols_contra);
    printf("Substituicoes feitas na partida: ");
    scanf("%d",&jogo_substituicoes);
    Editar_LS(inicio, n, jogo_adversario, jogo_sigla_adv, jogo_dia, jogo_mes, jogo_gols_pro, jogo_gols_contra, jogo_substituicoes);
    //for(i=0;i<11+jogo[n].substituicoes;i++) // loop que percorre todos os jogadores que jogaram a partida
    //apagar depois
    for(i=0;i<3;i++)//apagar depois
    //apagar depois
    {
        int encontrado=0;
        printf("\nPara inserir os dados de um jogador na partida, insira o numero de seu uniforme: ");
        scanf("%d",&num_uniforme);
        if(num_uniforme == -1)
        {
            printf("\tDigite o numero de um jogador cadastrado!\n");
            i--;
        }
        else{
        for(j=0;j<10;j++)
        {
            if(num_uniforme==goleiros[j].uniforme) // verifica se o numero do uniforme é de um goleiro, e de qual
            {
                printf("Deseja inserir os dados do %s?\t1. Sim.\t2. Nao\n",goleiros[j].nome);
                scanf("%d",&opc);
                if(opc==2)
                {
                    i--;
                    break;
                }
                encontrado++;
                goleiros[j].jogos++;
                goleiros[j].jogou[n]=1;
                printf("Insira os dados do %s\n",goleiros[j].nome);
                printf("  Defesas: ");
                scanf("%d",&goleiros[j].defesas[n]);
                goleiros[j].total_defesas+=goleiros[j].defesas[n];
                goleiros[j].media_defesas=media_jogador(goleiros[j].total_defesas,goleiros[j].uniforme);
                printf("  Passes corretos: ");
                scanf("%d",&goleiros[j].passesC[n]);
                goleiros[j].total_passesC+=goleiros[j].passesC[n];
                goleiros[j].media_passesC=media_jogador(goleiros[j].total_passesC,goleiros[j].uniforme);
                printf("  Passes errados: ");
                scanf("%d",&goleiros[j].passesE[n]);
                goleiros[j].total_passesE+=goleiros[j].passesE[n];
                goleiros[j].media_passesE=media_jogador(goleiros[j].total_passesE,goleiros[j].uniforme);
                printf("  Perdas de posse: ");
                scanf("%d",&goleiros[j].perdas[n]);
                goleiros[j].total_perdas+=goleiros[j].perdas[n];
                goleiros[j].media_perdas=media_jogador(goleiros[j].total_perdas,goleiros[j].uniforme);
                printf("  Gols sofridos: ");
                scanf("%d",&goleiros[j].golsS[n]);
                goleiros[j].total_golsS+=goleiros[j].golsS[n];
                goleiros[j].media_golsS=media_jogador(goleiros[j].total_golsS,goleiros[j].uniforme);
                printf("  Gols convertidos: ");
                scanf("%d",&goleiros[j].golsF[n]);
                goleiros[j].total_golsF+=goleiros[j].golsF[n];
                goleiros[j].media_golsF=media_jogador(goleiros[j].total_golsF,goleiros[j].uniforme);
                printf("  Gols contra: ");
                scanf("%d",&goleiros[j].golsC[n]);
                goleiros[j].total_golsC+=goleiros[j].golsC[n];
                goleiros[j].media_golsC=media_jogador(goleiros[j].total_golsC,goleiros[j].uniforme);
                printf("  Faltas cometidas: ");
                scanf("%d",&goleiros[j].faltasC[n]);
                goleiros[j].total_faltasC+=goleiros[j].faltasC[n];
                goleiros[j].media_faltasC=media_jogador(goleiros[j].total_faltasC,goleiros[j].uniforme);
                printf("  Faltas sofridas: ");
                scanf("%d",&goleiros[j].faltasS[n]);
                goleiros[j].total_faltasS+=goleiros[j].faltasS[n];
                goleiros[j].media_faltasS=media_jogador(goleiros[j].total_faltasS,goleiros[j].uniforme);
                printf("  Impedimentos: ");
                scanf("%d",&goleiros[j].imped[n]);
                goleiros[j].total_imped+=goleiros[j].imped[n];
                goleiros[j].media_imped=media_jogador(goleiros[j].total_imped,goleiros[j].uniforme);
                printf("  Assistencias (gol): ");
                scanf("%d",&goleiros[j].assistG[n]);
                goleiros[j].total_assistG+=goleiros[j].assistG[n];
                goleiros[j].media_assistG=media_jogador(goleiros[j].total_assistG,goleiros[j].uniforme);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&goleiros[j].assistF[n]);
                goleiros[j].total_assistF+=goleiros[j].assistF[n];
                goleiros[j].media_assistF=media_jogador(goleiros[j].total_assistF,goleiros[j].uniforme);
                printf("  Penaltis cometidos: ");
                scanf("%d",&goleiros[j].penaltisC[n]);
                goleiros[j].total_penaltisC+=goleiros[j].penaltisC[n];
                goleiros[j].media_penaltisC=media_jogador(goleiros[j].total_penaltisC,goleiros[j].uniforme);
                printf("  Penaltis sofridos: ");
                scanf("%d",&goleiros[j].penaltisS[n]);
                goleiros[j].total_penaltisS+=goleiros[j].penaltisS[n];
                goleiros[j].media_penaltisS=media_jogador(goleiros[j].total_penaltisS,goleiros[j].uniforme);
                printf("  Penaltis defendidos: ");
                scanf("%d",&goleiros[j].penaltisD[n]);
                goleiros[j].total_penaltisD+=goleiros[j].penaltisD[n];
                goleiros[j].media_penaltisD=media_jogador(goleiros[j].total_penaltisD,goleiros[j].uniforme);
                printf("  Penaltis perdidos: ");
                scanf("%d",&goleiros[j].penaltisP[n]);
                goleiros[j].total_penaltisP+=goleiros[j].penaltisP[n];
                goleiros[j].media_penaltisP=media_jogador(goleiros[j].total_penaltisP,goleiros[j].uniforme);

                goleiros[j].notas[n]=pontuacao(goleiros[j].uniforme, n);

                break;
            }
        }
        char pos[4]; // variavel para armazenar a posicao jogada na partida
        for(j=0;j<40;j++)
        {
            if(num_uniforme==elenco[j].uniforme) // verifica se o numero do uniforme é de um jogador, e de qual
            {
                printf("Deseja inserir os dados do %s?\t1. Sim.\t2. Nao\n",elenco[j].nome);
                scanf("%d",&opc);
                if(opc==2)
                {
                    i--;
                    break;
                }
                encontrado++;
                elenco[j].jogos++;
                elenco[j].jogou[n]=1;
                printf("Insira os dados do %s\n",elenco[j].nome);
                printf("  Sigla da posicao inicial na partida: ");
                scanf("%s",&pos);
                if(strcmp(pos,"ZD")==0 || strcmp(pos,"zd")==0)
                    elenco[j].pos[n]=1;
                if(strcmp(pos,"ZE")==0 || strcmp(pos,"ze")==0)
                    elenco[j].pos[n]=2;
                if(strcmp(pos,"ZC")==0 || strcmp(pos,"zc")==0)
                    elenco[j].pos[n]=3;
                if(strcmp(pos,"LDD")==0 || strcmp(pos,"ldd")==0)
                    elenco[j].pos[n]=4;
                if(strcmp(pos,"LED")==0 || strcmp(pos,"led")==0)
                    elenco[j].pos[n]=5;
                if(strcmp(pos,"LDO")==0 || strcmp(pos,"ldo")==0)
                    elenco[j].pos[n]=6;
                if(strcmp(pos,"LEO")==0 || strcmp(pos,"leo")==0)
                    elenco[j].pos[n]=7;
                if(strcmp(pos,"PV")==0 || strcmp(pos,"pv")==0)
                    elenco[j].pos[n]=8;
                if(strcmp(pos,"SV")==0 || strcmp(pos,"sv")==0)
                    elenco[j].pos[n]=9;
                if(strcmp(pos,"ARM")==0 || strcmp(pos,"arm")==0)
                    elenco[j].pos[n]=10;
                if(strcmp(pos,"MD")==0 || strcmp(pos,"md")==0)
                    elenco[j].pos[n]=11;
                if(strcmp(pos,"ME")==0 || strcmp(pos,"me")==0)
                    elenco[j].pos[n]=12;
                if(strcmp(pos,"MA")==0 || strcmp(pos,"ma")==0)
                    elenco[j].pos[n]=13;
                if(strcmp(pos,"PD")==0 || strcmp(pos,"pd")==0)
                    elenco[j].pos[n]=14;
                if(strcmp(pos,"PE")==0 || strcmp(pos,"pe")==0)
                    elenco[j].pos[n]=15;
                if(strcmp(pos,"SA")==0 || strcmp(pos,"sa")==0)
                    elenco[j].pos[n]=16;
                if(strcmp(pos,"CA")==0 || strcmp(pos,"ca")==0)
                    elenco[j].pos[n]=17;
                printf("  Passes corretos: ");
                scanf("%d",&elenco[j].passesC[n]);
                elenco[j].total_passesC+=elenco[j].passesC[n];
                elenco[j].media_passesC=media_jogador(elenco[j].total_passesC,elenco[j].uniforme);
                printf("  Passes errados: ");
                scanf("%d",&elenco[j].passesE[n]);
                elenco[j].total_passesE+=elenco[j].passesE[n];
                elenco[j].media_passesE=media_jogador(elenco[j].total_passesE,elenco[j].uniforme);
                printf("  Finalizacoes corretas: ");
                scanf("%d",&elenco[j].finalizacoesC[n]);
                elenco[j].total_finalizacoesC+=elenco[j].finalizacoesC[n];
                elenco[j].media_finalizacoesC=media_jogador(elenco[j].total_finalizacoesC,elenco[j].uniforme);
                printf("  Finalizacoes erradas: ");
                scanf("%d",&elenco[j].finalizacoesE[n]);
                elenco[j].total_finalizacoesE+=elenco[j].finalizacoesE[n];
                elenco[j].media_finalizacoesE=media_jogador(elenco[j].total_finalizacoesE,elenco[j].uniforme);
                printf("  Desarmes: ");
                scanf("%d",&elenco[j].desarmes[n]);
                elenco[j].total_desarmes+=elenco[j].desarmes[n];
                elenco[j].media_desarmes=media_jogador(elenco[j].total_desarmes,elenco[j].uniforme);
                printf("  Perdas de posse: ");
                scanf("%d",&elenco[j].perdas[n]);
                elenco[j].total_perdas+=elenco[j].perdas[n];
                elenco[j].media_perdas=media_jogador(elenco[j].total_perdas,elenco[j].uniforme);
                printf("  Gols: ");
                scanf("%d",&elenco[j].gols[n]);
                elenco[j].total_gols+=elenco[j].gols[n];
                elenco[j].media_gols=media_jogador(elenco[j].total_gols,elenco[j].uniforme);
                printf("  Gols contra: ");
                scanf("%d",&elenco[j].golsC[n]);
                elenco[j].total_golsC+=elenco[j].golsC[n];
                elenco[j].media_golsC=media_jogador(elenco[j].total_golsC,elenco[j].uniforme);
                printf("  Faltas cometidas: ");
                scanf("%d",&elenco[j].faltasC[n]);
                elenco[j].total_faltasC+=elenco[j].faltasC[n];
                elenco[j].media_faltasC=media_jogador(elenco[j].total_faltasC,elenco[j].uniforme);
                printf("  Faltas sofridas: ");
                scanf("%d",&elenco[j].faltasS[n]);
                elenco[j].total_faltasS+=elenco[j].faltasS[n];
                elenco[j].media_faltasS=media_jogador(elenco[j].total_faltasS,elenco[j].uniforme);
                printf("  Impedimentos: ");
                scanf("%d",&elenco[j].imped[n]);
                elenco[j].total_imped+=elenco[j].imped[n];
                elenco[j].media_imped=media_jogador(elenco[j].total_imped,elenco[j].uniforme);
                printf("  Assistencias (gol): ");
                scanf("%d",&elenco[j].assistG[n]);
                elenco[j].total_assistG+=elenco[j].assistG[n];
                elenco[j].media_assistG=media_jogador(elenco[j].total_assistG,elenco[j].uniforme);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&elenco[j].assistF[n]);
                elenco[j].total_assistF+=elenco[j].assistF[n];
                elenco[j].media_assistF=media_jogador(elenco[j].total_assistF,elenco[j].uniforme);
                printf("  Penaltis cometidos: ");
                scanf("%d",&elenco[j].penaltisC[n]);
                elenco[j].total_penaltisC+=elenco[j].penaltisC[n];
                elenco[j].media_penaltisC=media_jogador(elenco[j].total_penaltisC,elenco[j].uniforme);
                printf("  Penaltis sofridos: ");
                scanf("%d",&elenco[j].penaltisS[n]);
                elenco[j].total_penaltisS+=elenco[j].penaltisS[n];
                elenco[j].media_penaltisS=media_jogador(elenco[j].total_penaltisS,elenco[j].uniforme);
                printf("  Penaltis perdidos: ");
                scanf("%d",&elenco[j].penaltisP[n]);
                elenco[j].total_penaltisP+=elenco[j].penaltisP[n];
                elenco[j].media_penaltisP=media_jogador(elenco[j].total_penaltisP,elenco[j].uniforme);

                elenco[j].notas[n]=pontuacao(elenco[j].uniforme, n);

                break;
            }
            if(j==39 && encontrado==0)
            {
                printf("\tDigite o numero de um jogador cadastrado!\n");
                i--;
            }
        }
        }

    }
    printf("\n");
    system("PAUSE");
    return 0;
}

/* Funcao que exibe as estatisticas de um jogador */

int estatisticas_jogador(partida **inicio)
{
    system("cls");
    printf("\tEstatisticas de um jogador.\n\n");
    int num_uniforme=lista_jogadores(); // pedindo para o usuario escolher um jogador para ver as estatisticas
    if(num_uniforme==0)
        return 0;
    int i,encontrado=0,opc; // variaveis auxiliares
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme) // vendo se o jogador requerido é um goleiro e, se sim, qual
        {
            system("cls");
            printf("\tEstatisticas do %s\n\n",goleiros[i].nome);
            // menu com as opções de estatísticas que podem ser exibidas do goleiro
            printf("1. Dados gerais.\n");
            printf("2. Gols.\n");
            printf("3. Passes e assistencias.\n");
            printf("4. Defesas e gols sofridos.\n");
            printf("5. Faltas e penaltis.\n");
            printf("6. Impedimentos.\n");
            printf("7. Notas.\n");
            printf("0. Voltar.\n");
            printf("\n-> ");
            scanf("%d",&opc);

            switch(opc)
            {
                case 1:
                    jogador_dados(num_uniforme); // chama a função que mostra os dados gerais de um goleiro
                    break;

                case 2:
                    goleiro_Gols(num_uniforme, *inicio); // chama a função que mostra as estatisticas de gols do goleiro
                    break;

                case 3:
                    jogador_PeA(num_uniforme, *inicio); // chama a função que mostra as estatisticas de passes e assistencias do goleiro
                    break;

                case 4:
                    jogador_DeG(num_uniforme, *inicio); // chama a função que mostra as estatisticas de defesas e gols sofridos do goleiro
                    break;

                case 5:
                    jogador_FeP(num_uniforme, *inicio); // chama a função que mostra as estatisticas de faltas e penaltis do goleiro
                    break;

                case 6:
                    jogador_Imp(num_uniforme, *inicio); // chama a função que mostra as estatisticas de impedimentos do goleiro
                    break;

                case 7:
                    jogador_notas(num_uniforme, *inicio); // chama a função que mostra as estatisticas de notas do goleiro
                    break;

                case 0:
                    return 0; // retorna ao menu inicial

                default:
                    printf("Digite uma opcao valida\n");
            }

            break;
            encontrado++; // caso o jogador requerido seja um goleiro, o loop dos jogadores de linha será quebrado
        }
    }
    for(i=0;i<40;i++)
    {
        if(encontrado==1) // caso o jogador requerido foi um goleiro, quebra-se o loop
            break;
        if(num_uniforme==elenco[i].uniforme) // vendo se o jogador requerido é um jogador e, se sim, qual
        {
            system("cls");
            printf("\tEstatisticas do %s\n\n",elenco[i].nome);
            // menu com as opções de estatísticas que podem ser exibidas do jogador
            printf("1. Dados gerais.\n");
            printf("2. Gols e finalizacoes.\n");
            printf("3. Passes e assistencias.\n");
            printf("4. Desarmes e perda de posse.\n");
            printf("5. Faltas e penaltis.\n");
            printf("6. Impedimentos.\n");
            printf("7. Notas.\n");
            printf("0. Voltar.\n");
            printf("\n-> ");
            scanf("%d",&opc);

            switch(opc)
            {
                case 1:
                    jogador_dados(num_uniforme); // chama a função que mostra os dados gerais do jogador
                    break;

                case 2:
                    jogador_GeF(num_uniforme, *inicio); // chama a função que mostra as estatisticas de gols e finalizacoes do jogador
                    break;

                case 3:
                    jogador_PeA(num_uniforme, *inicio); // chama a função que mostra as estatisticas de passes e assistencias do jogador
                    break;

                case 4:
                    jogador_DeP(num_uniforme, *inicio); // chama a função que mostra as estatisticas de desarmes do jogador
                    break;

                case 5:
                    jogador_FeP(num_uniforme, *inicio); // chama a função que mostra as estatisticas de faltas e penaltis do jogador
                    break;

                case 6:
                    jogador_Imp(num_uniforme, *inicio); // chama a função que mostra as estatisticas de impedimentos do jogador
                    break;

                case 7:
                    jogador_notas(num_uniforme, *inicio); // chama a função que mostra as estatisticas de notas do jogador
                    break;

                case 0:
                    return 0; // retorna ao menu inicial

                default:
                    printf("Digite uma opcao valida\n");
            }
            break;
        }
    }

    return 0;
}

/* Funcao que exibe as estatisticas do grupo */

int estatisticas_grupo()
{
    system("cls");
    printf("\tEstatisticas do Grupo.\n\n");
    printf("1. Notas gerais.\n");
    printf("2. Melhor escalacao.\n");
    printf("3. Gols e finalizacoes.\n");
    printf("4. Passes e assistencias.\n");
    printf("5. Desarmes.\n");
    printf("6. Defesas.\n");
    printf("7. Faltas e penaltis.\n");
    printf("8. Impedimentos.\n");
    printf("0. Voltar.\n");
    printf("\n-> ");
    int opc;
    scanf("%d",&opc);

    switch(opc)
    {
        case 1:
            grupo_notas();
            break;

        case 2:
            melhor_escalacao();
            break;

        case 3:
            grupo_GeF();
            break;

        case 4:
            grupo_PeA();
            break;

        case 5:
            grupo_DeP();
            break;

        case 6:
            grupo_Def();
            break;

        case 7:
            grupo_FeP();
            break;

        case 8:
            grupo_Imp();
            break;

        case 0:
            return 0;
    }

    return 0;
}

/* Funcao que lista todos os jogadores do grupo */

int lista_jogadores()
{
    int i;
    for(i=0;i<10;i++)
    {
        if(goleiros[i].controle==1)
        {
            printf("%d. %s\n",goleiros[i].uniforme,goleiros[i].nome);
        }
    }
    for(i=0;i<40;i++)
    {
        if(elenco[i].controle==1)
        {
            printf("%d. %s\n",elenco[i].uniforme,elenco[i].nome);
        }
    }
    printf("0. Voltar.\n");
    printf("\n-> ");
    int num_uniforme;
    scanf("%d",&num_uniforme);
    return num_uniforme;
}

/* Função que lista todos os jogos já ocorridos */

int lista_jogos(partida **inicio)
{
    int opc; // variaveis auxiliares
    Listar_LS(*inicio);
    printf("0. Voltar.\n");
    printf("\n-> ");
    scanf("%d",&opc);

    return opc-1; // retorna a posição do vetor jogo[] do jogo requerido
}

/* Funcao que calcula a media de um jogador (FUNÇÃO NÃO TESTADA - NÃO TESTAR)*/

float media_jogador(int total, int num_uniforme)
{
    int i; // variaveis auxiliares
    float media; // variavel para armazenar a media requerida
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme) // verificando se o uniforme do requerido pertence a um goleiro, e qual
        {
            media=(float)total/goleiros[i].jogos; // calculando a media desses dados, por partida

            break;
        }
    }
    for(i=0;i<40;i++)
    {
        if(num_uniforme==elenco[i].uniforme) // verificando se o uniforme do requerido pertence a um jogador, e qual
        {
            media=(float)total/elenco[i].jogos;

            break;
        }
    }

    return media;
}

/* Funcao que calcula a media de notas de um jogador (FUNÇÃO NÃO TESTADA - NÃO TESTAR)*/

float media_jogadorN(int num_uniforme)
{
    int i,j; // variaveis auxiliares
    float media,soma; // variavel para armazenar a media requerida
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme) // verificando se o uniforme do requerido pertence a um goleiro, e qual
        {
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                    soma+=goleiros[i].notas[j]; // somando todos os dados pedidos
            }
            media=soma/goleiros[i].jogos; // calculando a media desses dados, por partida

            break;
        }
    }
    for(i=0;i<40;i++)
    {
        if(num_uniforme==elenco[i].uniforme) // verificando se o uniforme do requerido pertence a um jogador, e qual
        {
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                    soma+=elenco[i].notas[j]; // somando todos os dados pedidos
            }
            media=soma/elenco[i].jogos;

            break;
        }
    }

    return media;
}

/* Funcao que calcula a pontuacao de um jogador na partida */

float pontuacao(int num_uniforme, int n)
{
    int i;
    float p;
    for(i=0;i<10;i++)
    {
        // caso o jogador seja um goleiro
        if(num_uniforme==goleiros[i].uniforme)
        {
            p=(5*((float)goleiros[i].passesC[n]/((float)goleiros[i].passesC[n]+(float)goleiros[i].passesE[n])));
            p+=(0.5*goleiros[i].defesas[n]);
            if(goleiros[i].defesas[n]%5==0)
                p+=(0.5*((float)goleiros[i].defesas[n]/5)); // ganha um bonus de meio ponto a cada 5 defesas feitas
            p+=(goleiros[i].golsF[n])-(goleiros[i].golsC[n])-(goleiros[i].golsS[n])-(0.5*goleiros[i].perdas[n]);
            p+=(0.3*goleiros[i].faltasS[n])-(0.1*goleiros[i].faltasC[n])-(0.1*goleiros[i].imped[n]);
            p+=(0.5*goleiros[i].assistG[n])+(0.1*goleiros[i].assistF[n])-(0.7*goleiros[i].penaltisC[n]);
            p+=(0.5*goleiros[i].penaltisS[n])+(goleiros[i].penaltisD[n])-(0.5*goleiros[i].penaltisP[n]);
        }
    }
    for(i=0;i<40;i++)
    {
        if(num_uniforme==elenco[i].uniforme)
        {
            // caso o jogador tenha jogado como ZD, ZC, ZC, LDD ou LED
            if(elenco[i].pos[n]>=1 && elenco[i].pos[n]<=5)
            {
                p=(5.25*((float)elenco[i].passesC[n]/((float)elenco[i].passesC[n]+(float)elenco[i].passesE[n])));
                p+=(1.25*((float)elenco[i].finalizacoesC[n]/((float)elenco[i].finalizacoesC[n]+(float)elenco[i].finalizacoesE[n])));
                p+=elenco[i].gols[n]-elenco[i].golsC[n]+(0.4*elenco[i].desarmes[n])-(0.3*elenco[i].perdas[n]);
                p+=(0.1*elenco[i].faltasS[n])-(0.2*elenco[i].faltasC[n])-(0.1*elenco[i].imped[n]);
                p+=(0.5*elenco[i].assistG[n])+(0.1*elenco[i].assistF[n]);
                p+=(0.5*elenco[i].penaltisS[n])-(0.5*elenco[i].penaltisC[n])-(0.5*elenco[i].penaltisP[n]);
            }
            // caso o jogador tenha jogado como LDO, LEO ou PV
            if(elenco[i].pos[n]>=6 && elenco[i].pos[n]<=8)
            {
                p=(4.75*((float)elenco[i].passesC[n]/((float)elenco[i].passesC[n]+(float)elenco[i].passesE[n])));
                p+=(1.75*((float)elenco[i].finalizacoesC[n]/((float)elenco[i].finalizacoesC[n]+(float)elenco[i].finalizacoesE[n])));
                p+=elenco[i].gols[n]-elenco[i].golsC[n]+(0.2*elenco[i].desarmes[n])-(0.3*elenco[i].perdas[n]);
                p+=(0.1*elenco[i].faltasS[n])-(0.1*elenco[i].faltasC[n])-(0.1*elenco[i].imped[n]);
                p+=(0.55*elenco[i].assistG[n])+(0.15*elenco[i].assistF[n]);
                p+=(0.5*elenco[i].penaltisS[n])-(0.5*elenco[i].penaltisC[n])-(0.5*elenco[i].penaltisP[n]);
            }
            // caso o jogador tenha jogado como SV ou ARM
            if(elenco[i].pos[n]==9 || elenco[i].pos[n]==10)
            {
                p=(4.25*((float)elenco[i].passesC[n]/((float)elenco[i].passesC[n]+(float)elenco[i].passesE[n])));
                p+=(2.25*((float)elenco[i].finalizacoesC[n]/((float)elenco[i].finalizacoesC[n]+(float)elenco[i].finalizacoesE[n])));
                p+=elenco[i].gols[n]-elenco[i].golsC[n]+(0.1*elenco[i].desarmes[n])-(0.3*elenco[i].perdas[n]);
                p+=(0.1*elenco[i].faltasS[n])-(0.1*elenco[i].faltasC[n])-(0.1*elenco[i].imped[n]);
                p+=(0.6*elenco[i].assistG[n])+(0.2*elenco[i].assistF[n]);
                p+=(0.5*elenco[i].penaltisS[n])-(0.5*elenco[i].penaltisC[n])-(0.5*elenco[i].penaltisP[n]);
            }
            // caso o jogador tenha jogado como MD, ME, MA, PD, PE ou SA
            if(elenco[i].pos[n]>=11 && elenco[i].pos[n]<=16)
            {
                p=(2*((float)elenco[i].passesC[n]/((float)elenco[i].passesC[n]+(float)elenco[i].passesE[n])));
                p+=(4.25*((float)elenco[i].finalizacoesC[n]/((float)elenco[i].finalizacoesC[n]+(float)elenco[i].finalizacoesE[n])));
                p+=elenco[i].gols[n]-elenco[i].golsC[n]+(0.1*elenco[i].desarmes[n])-(0.2*elenco[i].perdas[n]);
                p+=(0.2*elenco[i].faltasS[n])-(0.1*elenco[i].faltasC[n])-(0.5*elenco[i].imped[n]);
                p+=(0.65*elenco[i].assistG[n])+(0.25*elenco[i].assistF[n]);
                p+=(0.5*elenco[i].penaltisS[n])-(0.6*elenco[i].penaltisC[n])-(0.5*elenco[i].penaltisP[n]);
            }
            // caso o jogador tenha jogado como CA
            if(elenco[i].pos[n]==17)
            {
                p=(1*((float)elenco[i].passesC[n]/((float)elenco[i].passesC[n]+(float)elenco[i].passesE[n])));
                p+=(5.5*((float)elenco[i].finalizacoesC[n]/((float)elenco[i].finalizacoesC[n]+(float)elenco[i].finalizacoesE[n])));
                p+=elenco[i].gols[n]-elenco[i].golsC[n]+(0.1*elenco[i].desarmes[n])-(0.1*elenco[i].perdas[n]);
                p+=(0.3*elenco[i].faltasS[n])-(0.1*elenco[i].faltasC[n])-(0.1*elenco[i].imped[n]);
                p+=(0.5*elenco[i].assistG[n])+(0.1*elenco[i].assistF[n]);
                p+=(0.5*elenco[i].penaltisS[n])-(0.7*elenco[i].penaltisC[n])-(0.5*elenco[i].penaltisP[n]);
            }
        }
    }
    return p;
}

/* Acredito que não serão usadas

/* Funcao que exibe o ranking de jogadores sob um indicador

int rankingI(int indicador)
{

}

/* Funcao que exibe o ranking de jogadores sob um indicador

int rankingF(float indicador)
{

}

*/

/* Funcao que exibe a melhor escalacao baseado nas melhores notas por posicao */

int melhor_escalacao()
{
    system("cls");

    float maiorMedia=0;
    int i,melhor_time[10],formacao[3];

    // calculando o melhor goleiro
    int melhor_goleiro;
    float goleiro_nota=0;
    for(i=0;i<10;i++)
    {
        if(goleiros[i].controle==1)
        {
            if(goleiros[i].media_notas>goleiro_nota)
            {
                melhor_goleiro=goleiros[i].uniforme;
                goleiro_nota=goleiros[i].media_notas;
            }
        }
    }

    // testando as formaçoes: (3-5-2) (4-3-3) (4-4-2)

    int j;
    int zd,ze,zc,ld,le,pv,sv,arm,me,md,ma,pd,pe,sa,ca;

    // (3-5-2)
    for(i=0;i<40;i++)
    {
        for(j=0;j<18;j++)
        {
            if(elenco[i].posicao[j]==1)
            {
                zd=elenco[i].uniforme;
                break;
            }
            else if(elenco[i].posicao[j]==2)
            {
                ze=elenco[i].uniforme;
                break;
            }
            else if(elenco[i].posicao[j]==3)
            {
                zc=elenco[i].uniforme;
                break;
            }
            else if(elenco[i].posicao[j]==8)
            {
                pv=elenco[i].uniforme;
                break;
            }
            else if(elenco[i].posicao[j]==9 || elenco[i].posicao[j]==10)
            {
                sv=elenco[i].uniforme;
                break;
            }
            else if(elenco[i].posicao[j]==11)
            {
                md=elenco[i].uniforme;
                break;
            }
            else if(elenco[i].posicao[j]==12)
            {
                me=elenco[i].uniforme;
                break;
            }
            else if(elenco[i].posicao[j]==13)
            {
                ma=elenco[i].uniforme;
                break;
            }
            else if(elenco[i].posicao[j]==16)
            {
                sa=elenco[i].uniforme;
                break;
            }
            else if(elenco[i].posicao[j]==17)
            {
                ca=elenco[i].uniforme;
                break;
            }
        }
    }

    // (4-3-3)
    //

    // (4-4-2)
    //

    system("pause");
    return 0;
}

/* Funcao que exibe as estatisticas de notas do grupo */

int grupo_notas()
{

}

/* Funcao que exibe as estatisticas de gols e finalizacoes do grupo */

int grupo_GeF()
{
  system("cls");
  printf("\tEstatisticas de gols e finalizacoes do grupo\n\n");

  /*                             G O L S                                          */
  /*obtendo a quantidade de jogadores que já jogaram */
  int i = 0, j = 0, f = 0;
  for (i =0; i <40; i++){

  if(elenco[i].controle == 1){
    j = j +1;
    f = f+1;
    }
  }
  for(i = 0; i <10; i++){
    if(goleiros[i].controle == 1){
      j = j+1;
    }
  }
  /*criando um vetor (novoGols[]) apenas com os gols, este vetor é genérico e serve apenas para manipulação (terá seus valores
  alterados ao longo do código)*/
  int novoGols[j], l = 0, m = -1, novoUniforme[j];
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoGols[m] = elenco[l].total_gols;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  for(l = 0; l < 10; l++){
    if(goleiros[l].controle == 1){
      m++;
      novoGols[m] = goleiros[l].total_golsF;
      novoUniforme[m] = goleiros[l].uniforme;
    }
  }
  /*os valores obtidos em novoGols[] será agora ordenado de forma decrescente no vetor rankGols[]*/
  int k = 0, maisGols = 0, guardaindice, rankGols[j], rankUniforme[j];
  printf("Gols por jogador na temporada:\n\n");

  while(k < j){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoGols[]*/
  for(l = 0; l <= m; l ++){
    if(novoGols[l] >= maisGols){
      maisGols = novoGols[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankGols[k] = maisGols;
  maisGols=0;
  novoGols[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  int x = 0;
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: %d\n",elenco[l].nome, rankGols[x]);
        break;
      }
      if(l < 10){
        if(rankUniforme[x] == goleiros[l].uniforme){
          printf("%s: %d\n", goleiros[l].nome, rankGols[x]);
          break;
        }
      }
    }
  }


  /*                   F I N A L I Z A Ç Õ E S                                  */

  /*Quantidade de jogadores que já jogaram = 'j'
  Criando um vetor (novoFinalizacoes[]) apenas com as finalizações corretas, este vetor é genérico e serve apenas para
  manipulação (terá seus valores alterados ao longo do código) */
  int novoFinalizacoes[f];
  l = 0;
  m = -1;
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoFinalizacoes[m] = elenco[l].total_finalizacoesC;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  /*os valores obtidos em novoFinalizacoes[] será agora ordenado de forma decrescente no vetor rankFinalizacoes[]*/
  int  maisFinalizacoes = 0, rankFinalizacoes[f];
  k = 0;
  printf("\n\nFinalizacoes por jogador na temporada:\n\n");

  while(k < f){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoGols[]*/
  for(l = 0; l <= m; l ++){
    if(novoFinalizacoes[l] >= maisFinalizacoes){
      maisFinalizacoes = novoFinalizacoes[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankFinalizacoes[k] = maisFinalizacoes;
  maisFinalizacoes=0;
  novoFinalizacoes[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: Total: %d     Acertos: %d     Aproveitamento: %.2f%%\n",elenco[l].nome, elenco[l].total_finalizacoesC + elenco[l].total_finalizacoesE,100*((float)elenco[l].total_finalizacoesC)/((float)elenco[l].total_finalizacoesC + (float)elenco[l].total_finalizacoesE)),rankFinalizacoes[x];
        break;
      }
      }
    }
  printf("\n\n");
  system("pause");
  return 0;

}

/* Funcao que exibe as estatisticas de passes e assistencias do grupo */

int grupo_PeA()
{
  system("cls");
  printf("\tEstatisticas de gols e finalizacoes do grupo\n\n");

  /*                             P A S S E S                                          */
  /*obtendo a quantidade de jogadores que já jogaram */
  int i = 0, j = 0, f = 0;
  for (i =0; i <40; i++){

  if(elenco[i].controle == 1){
    j = j +1;
    f = f+1;
    }
  }
  for(i = 0; i <10; i++){
    if(goleiros[i].controle == 1){
      j = j+1;
    }
  }
  /*criando um vetor (novoPasses[]) apenas com os gols, este vetor é genérico e serve apenas para manipulação (terá seus valores
  alterados ao longo do código)*/
  int novoPasses[j], l = 0, m = -1, novoUniforme[j];
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoPasses[m] = elenco[l].total_passesC;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  for(l = 0; l < 10; l++){
    if(goleiros[l].controle == 1){
      m++;
      novoPasses[m] = goleiros[l].total_passesC;
      novoUniforme[m] = goleiros[l].uniforme;
    }
  }
  /*os valores obtidos em novoPasses[] será agora ordenado de forma decrescente no vetor rankPasses[]*/
  int k = 0, maisPasses = 0, guardaindice, rankPasses[j], rankUniforme[j];
  printf("Passes certos por jogador na temporada:\n\n");

  while(k < j){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoPasses[]*/
  for(l = 0; l <= m; l ++){
    if(novoPasses[l] >= maisPasses){
      maisPasses = novoPasses[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankPasses[k] = maisPasses;
  maisPasses=0;
  novoPasses[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  int x = 0;
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: %d\n",elenco[l].nome, rankPasses[x]);
        break;
      }
      if(l < 10){
        if(rankUniforme[x] == goleiros[l].uniforme){
          printf("%s: %d\n", goleiros[l].nome, rankPasses[x]);
          break;
        }
      }
    }
  }


  /*                   A S S I S T Ê N C I A S                                  */

  /*Quantidade de jogadores que já jogaram = 'j'
  Criando um vetor (novoAssistencias[]) apenas com as finalizações corretas, este vetor é genérico e serve apenas para
  manipulação (terá seus valores alterados ao longo do código) */
  int novoAssistencias[f];
  l = 0;
  m = -1;
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoAssistencias[m] = elenco[l].total_assistG;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  /*os valores obtidos em novoAssistencias[] será agora ordenado de forma decrescente no vetor rankAssistencias[]*/
  int  maisAssistencias = 0, rankAssistencias[f];
  k = 0;
  printf("\n\nAssistencias por jogador na temporada:\n\n");

  while(k < f){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoAssistencias[]*/
  for(l = 0; l <= m; l ++){
    if(novoAssistencias[l] >= maisAssistencias){
      maisAssistencias = novoAssistencias[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankAssistencias[k] = maisAssistencias;
  maisAssistencias=0;
  novoAssistencias[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: Total: %d     Assist. Gol: %d     Assist. Finalizacao: %d\n",elenco[l].nome,elenco[l].total_assistG + elenco[l].total_assistF, elenco[l].total_assistG, elenco[l].total_assistF);
        break;
      }
      }
    }
  printf("\n\n");
  system("pause");
  return 0;


}

/* Funcao que exibe as estatisticas de desarmes e de perdas de posse de bola do grupo */

int grupo_DeP()
{
  system("cls");

      /*                        D E S A R M E S                                  */
      /*obtendo a quantidade de jogadores que já jogaram */
  int i = 0, j = 0;
  for (i =0; i <40; i++){

  if(elenco[i].controle == 1){
    j = j +1;
    }
  }
  /*criando um vetor (novoDesarmes[]) apenas com os desarmes, este vetor é genérico e serve apenas para manipulação (terá seus valores
  alterados ao longo do código)*/
  int novoDesarmes[j], l = 0, m = -1, novoUniforme[j];
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoDesarmes[m] = elenco[l].total_desarmes;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  /*os valores obtidos em novoDesarmes[] será agora ordenado de forma decrescente no vetor rankDesarmes[]*/
  int k = 0, maisDesarmes = 0, guardaindice, rankDesarmes[j], rankUniforme[j];
  printf("Desarmes e perdas de posse por jogador na temporada:\n\n");

  while(k < j){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoGols[]*/
  for(l = 0; l <= m; l ++){
    if(novoDesarmes[l] >= maisDesarmes){
      maisDesarmes = novoDesarmes[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankDesarmes[k] = maisDesarmes;
  maisDesarmes=0;
  novoDesarmes[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  int x = 0;
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: Desarmes: %d     Perdas de posse: %d\n",elenco[l].nome, elenco[l].total_desarmes, elenco[l].total_perdas);
        break;
      }
    }
  }
  printf("\n");
  system("pause");
  return 0;
}

/* Funcao que exibe as estatisticas de defesas do grupo */

int grupo_Def()
{

  /*                             G O L S                                          */
  /*obtendo a quantidade de jogadores que já jogaram */
  int i = 0, j = 0, f = 0;
  for (i =0; i <40; i++){

  if(elenco[i].controle == 1){
    j = j +1;
    f = f+1;
    }
  }
  for(i = 0; i <10; i++){
    if(goleiros[i].controle == 1){
      j = j+1;
    }
  }
  /*criando um vetor (novoGols[]) apenas com os gols, este vetor é genérico e serve apenas para manipulação (terá seus valores
  alterados ao longo do código)*/
  int novoGols[j], l = 0, m = -1, novoUniforme[j];
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoGols[m] = elenco[l].total_gols;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  for(l = 0; l < 10; l++){
    if(goleiros[l].controle == 1){
      m++;
      novoGols[m] = goleiros[l].total_golsF;
      novoUniforme[m] = goleiros[l].uniforme;
    }
  }
  /*os valores obtidos em novoGols[] será agora ordenado de forma decrescente no vetor rankGols[]*/
  int k = 0, maisGols = 0, guardaindice, rankGols[j], rankUniforme[j];
  printf("Gols por jogador na temporada:\n\n");

  while(k < j){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoGols[]*/
  for(l = 0; l <= m; l ++){
    if(novoGols[l] >= maisGols){
      maisGols = novoGols[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankGols[k] = maisGols;
  maisGols=0;
  novoGols[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  int x = 0;
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: %d\n",elenco[l].nome, rankGols[x]);
        break;
      }
      if(l < 10){
        if(rankUniforme[x] == goleiros[l].uniforme){
          printf("%s: %d\n", goleiros[l].nome, rankGols[x]);
          break;
        }
      }
    }
  }


}

/* Funcao que exibe as estatisticas de faltas e penaltis do grupo */

int grupo_FeP()
{

}

/* Funcao que exibe as estatisticas de impedimentos do grupo */

int grupo_Imp()
{
    system("cls");

      /*                   I M P E D I M E N T O S                 */
      /*obtendo a quantidade de jogadores que já jogaram */
  int i = 0, j = 0;
  for (i =0; i <40; i++){

  if(elenco[i].controle == 1){
    j = j +1;
    }
  }
  /*criando um vetor (novoImpedimentos[]) apenas com os desarmes, este vetor é genérico e serve apenas para manipulação (terá seus valores
  alterados ao longo do código)*/
  int novoImpedimentos[j], l = 0, m = -1, novoUniforme[j];
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoImpedimentos[m] = elenco[l].total_imped;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  /*os valores obtidos em novoImpedimentos[] será agora ordenado de forma decrescente no vetor rankImpedimentos[]*/
  int k = 0, maisImpedimentos = 0, guardaindice, rankImpedimentos[j], rankUniforme[j];
  printf("Impedimentos por jogador na temporada:\n\n");

  while(k < j){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoGols[]*/
  for(l = 0; l <= m; l ++){
    if(novoImpedimentos[l] >= maisImpedimentos){
      maisImpedimentos = novoImpedimentos[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankImpedimentos[k] = maisImpedimentos;
  maisImpedimentos=0;
  novoImpedimentos[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  int x = 0;
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: %d\n",elenco[l].nome, elenco[l].total_imped);
        break;
      }
    }
  }
  printf("\n");
  system("pause");
  return 0;
}

/* Funcao que exibe os dados gerais de um jogador */

int jogador_dados(int num_uniforme)
{
    system("cls");

    int i,j,encontrado=0;
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme)
        {
            printf("\tDados gerais do %s\n\n",goleiros[i].nome);
            printf("Posicao: goleiro.\n");
            printf("Jogos: %d.\nUniforme: %d.\n",goleiros[i].jogos,goleiros[i].uniforme);
            printf("Idade: %d anos.\n",goleiros[i].idade);
            printf("Altura: %.2f metros.\nPeso: %.2f quilos.\n",goleiros[i].altura,goleiros[i].peso);
            if(goleiros[i].pe==1)
                printf("Destro.\n");
            if(goleiros[i].pe==2)
                printf("Canhoto.\n");
            if(goleiros[i].pe==3)
                printf("Ambidestro.\n");
            encontrado++;
            break;
        }
    }
    for(i=0;i<40;i++)
    {
        if(encontrado==1)
            break;
        if(num_uniforme==elenco[i].uniforme)
        {
            int virgula=0;
            printf("\tDados gerais do %s\n\n",elenco[i].nome);
            printf("Posicoes jogadas:");
            for(j=0;j<17;j++)
            {
                if(elenco[i].posicao[j]==1){
                    if(virgula>0)
                        printf(",");
                    printf(" zagueiro direito");
                    virgula++;
                }
                if(elenco[i].posicao[j]==2){
                    if(virgula>0)
                        printf(",");
                    printf(" zagueiro esquerdo");
                    virgula++;
                }
                if(elenco[i].posicao[j]==3){
                    if(virgula>0)
                        printf(",");
                    printf(" zagueiro central");
                    virgula++;
                }
                if(elenco[i].posicao[j]==4){
                    if(virgula>0)
                        printf(",");
                    printf(" lateral direito defensivo");
                    virgula++;
                }
                if(elenco[i].posicao[j]==5){
                    if(virgula>0)
                        printf(",");
                    printf(" lateral esquerdo defensivo");
                    virgula++;
                }
                if(elenco[i].posicao[j]==6){
                    if(virgula>0)
                        printf(",");
                    printf(" lateral direito ofensivo");
                    virgula++;
                }
                if(elenco[i].posicao[j]==7){
                    if(virgula>0)
                        printf(",");
                    printf(" lateral esquerdo ofensivo");
                    virgula++;
                }
                if(elenco[i].posicao[j]==8){
                    if(virgula>0)
                        printf(",");
                    printf(" primeiro volante");
                    virgula++;
                }
                if(elenco[i].posicao[j]==9){
                    if(virgula>0)
                        printf(",");
                    printf(" segundo volante");
                    virgula++;
                }
                if(elenco[i].posicao[j]==10){
                    if(virgula>0)
                        printf(",");
                    printf(" armador");
                    virgula++;
                }
                if(elenco[i].posicao[j]==11){
                    if(virgula>0)
                        printf(",");
                    printf(" meia direita");
                    virgula++;
                }
                if(elenco[i].posicao[j]==12){
                    if(virgula>0)
                        printf(",");
                    printf(" meia esquerda");
                    virgula++;
                }
                if(elenco[i].posicao[j]==13){
                    if(virgula>0)
                        printf(",");
                    printf(" meia atacante");
                    virgula++;
                }
                if(elenco[i].posicao[j]==14){
                    if(virgula>0)
                        printf(",");
                    printf(" ponta direita");
                    virgula++;
                }
                if(elenco[i].posicao[j]==15){
                    if(virgula>0)
                        printf(",");
                    printf(" ponta esquerda");
                    virgula++;
                }
                if(elenco[i].posicao[j]==16){
                    if(virgula>0)
                        printf(",");
                    printf(" segundo atacante");
                    virgula++;
                }
                if(elenco[i].posicao[j]==17){
                    if(virgula>0)
                        printf(",");
                    printf(" centroavante");
                    virgula++;
                }
            }
            printf(".\n");
            printf("Jogos: %d.\nUniforme: %d.\n",elenco[i].jogos,elenco[i].uniforme);
            printf("Idade: %d anos.\n",elenco[i].idade);
            printf("Altura: %.2f metros.\nPeso: %.2f quilos.\n",elenco[i].altura,elenco[i].peso);
            if(elenco[i].pe==1)
                printf("Destro.\n");
            if(elenco[i].pe==2)
                printf("Canhoto.\n");
            if(elenco[i].pe==3)
                printf("Ambidestro.\n");
            break;
        }
    }

    printf("\n");
    system("PAUSE");
    return 0;
}

/* Funcao que exibe as estatisticas de gols e finalizacoes de um jogador */

int jogador_GeF(int num_uniforme, partida *inicio)
{
    system("cls");
    int i,j,k;
    int diaD, mesD, golsP, golsC;
    char sgl[3], adv[100];
    for(i=0;i<40;i++)
    {
        if(num_uniforme==elenco[i].uniforme)
        {
            printf("\tEstatisticas de gols e finalizacoes do %s\n\n",elenco[i].nome);

            printf("Gols na temporada: %d\n",elenco[i].total_gols);
            printf("Media de gols por partida: %.2f\n",elenco[i].media_gols);
            printf("Gols por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].gols[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].gols[j]);
                }
            }

            printf("\nFinalizacoes corretas na temporada: %d\n",elenco[i].total_finalizacoesC);
            printf("Media de finalizacoes corretas por partida: %.2f\n",elenco[i].media_finalizacoesC);
            printf("Finalizacoes corretas por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].finalizacoesC[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].finalizacoesC[j]);
                }
            }

            printf("\nTotal de finalizacoes na temporada: %d\n",elenco[i].total_finalizacoesC+elenco[i].total_finalizacoesE);
            printf("Media de finalizacoes por partida: %.2f\n",elenco[i].media_finalizacoesC+elenco[i].total_finalizacoesE);
            printf("Total de finalizacoes por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<(elenco[i].finalizacoesC[j]+elenco[i].finalizacoesE[j]);k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].finalizacoesC[j]+elenco[i].finalizacoesE[j]);
                }
            }

            printf("\nAproveitamento de gols (gols por finalizacoes corretas): %.2f%%\n\n",(100*((float)elenco[i].total_gols/(float)elenco[i].total_finalizacoesC)));
            printf("Aproveitamento de finalizacoes (finalizacoes corretas pelo total de finalizacoes): %.2f%%\n\n\n",(100*((float)elenco[i].total_finalizacoesC/((float)elenco[i].total_finalizacoesC+(float)elenco[i].total_finalizacoesE))));


            break;
        }
    }
    system("PAUSE");
    return 0;
}

/* Funcao que exibe as estatisticas de gols de um goleiro */

int goleiro_Gols(int num_uniforme, partida *inicio)
{
    system("cls");

    int i,j,k;
    int diaD, mesD, golsP, golsC;
    char sgl[3], adv[100];
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme)
        {
            printf("\tEstatisticas de gols do goleiro %s\n\n", goleiros[i].nome);
            printf("Gols na temporada: %d\n", goleiros[i].total_golsF);
            printf("Media de gols por partida: %.2f\n",goleiros[i].media_golsF);
            printf("Gols por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].golsF[j];k++)
                        printf("* ");
                    printf("(%d)\n\n\n",goleiros[i].golsF[j]);
                }
            }
        }
    }
    system("PAUSE");
    return 0;
}

/* Funcao que exibe as estatisticas de passes e assistencias de um jogador */

int jogador_PeA(int num_uniforme, partida *inicio)
{
    system("cls");

    int i,j,k;
    int diaD, mesD, golsP, golsC;
    char sgl[3], adv[100];
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme)
        {
            printf("\tEstatisticas de passes e assistencias do %s\n\n", goleiros[i].nome);
            printf("Passes certos na temporada: %d\n", goleiros[i].total_passesC);
            printf("Media de passes certos por partida: %.2f\n", goleiros[i].media_passesC);
            printf("Passes certos por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].passesC[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",goleiros[i].passesC[j]);
                }
            }
            printf("\nTotal de passes na temporada: %d\n", goleiros[i].total_passesC+goleiros[i].total_passesE);
            printf("Media de passes totais por partida: %.2f\n",media_jogador(goleiros[i].total_passesC+goleiros[i].total_passesE, goleiros[i].uniforme));
            printf("Total de passes por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].passesC[j]+goleiros[i].passesE[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",goleiros[i].passesC[j]+goleiros[i].passesE[j]);
                }
            }
            printf("\nAssistencias para gols na temporada: %d\n", goleiros[i].total_assistG);
            printf("Media de assistencias para gols por partida: %.2f\n", goleiros[i].media_assistG);
            printf("Assistencias para gols por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].assistG[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",goleiros[i].assistG[j]);
                }
            }
            printf("\nAssistencias para finalizacoes na temporada: %d\n", goleiros[i].total_assistF);
            printf("Media de assistencias para finalizacoes por partida: %.2f\n", goleiros[i].media_assistF);
            printf("Assistencias para finalizacoes por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].assistF[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",goleiros[i].assistF[j]);
                }
            }
            printf("\nAproveitamento de passes (passes certos pelo total): %.2f%%\n\n",(100*((float)goleiros[i].total_passesC/((float)goleiros[i].total_passesC+(float)goleiros[i].total_passesE))));
            printf("Aproveitamento de assistencias (assistencias para gol pelo total): %.2f%%\n\n\n",(100*((float)goleiros[i].total_assistG/((float)goleiros[i].total_assistG+(float)goleiros[i].total_assistF))));
        }
    }
    for(i=0;i<40;i++){
        if(num_uniforme==elenco[i].uniforme){
            printf("\tEstatisticas de passes e assistencia do %s\n\n", elenco[i].nome);
            printf("\nPasses certos na temporada: %d\n", elenco[i].total_passesC);
            printf("Media de passes certos por partida: %.2f\n", elenco[i].media_passesC);
            printf("Passes certos por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].passesC[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].passesC[j]);
                }
            }
            printf("\nTotal de passes na temporada: %d\n", elenco[i].total_passesC+elenco[i].total_passesE);
            printf("Media de passes totais por partida: %.2f\n",media_jogador(elenco[i].total_passesC+elenco[i].total_passesE, elenco[i].uniforme));
            printf("Total de passes por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].passesC[j]+elenco[i].passesE[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].passesC[j]+elenco[i].passesE[j]);
                }
            }
            printf("\nAssistencias para gols na temporada: %d\n", elenco[i].total_assistG);
            printf("Media de assistencias para gols por partida: %.2f\n", elenco[i].media_assistG);
            printf("Assistencias para gols por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].assistG[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].assistG[j]);
                }
            }
            printf("\nAssistencias para finalizacoes na temporada: %d\n", elenco[i].total_assistF);
            printf("Media de assistencias para finalizacoes por partida: %.2f\n", elenco[i].media_assistF);
            printf("Assistencias para finalizacoes por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].assistF[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].assistF[j]);
                }
            }
            printf("\nAproveitamento de passes (passes certos pelo total): %.2f%%\n\n",(100*((float)elenco[i].total_passesC/((float)elenco[i].total_passesC+(float)elenco[i].total_passesE))));
            printf("Aproveitamento de assistencias (assistencias para gol pelo total): %.2f%%\n\n\n",(100*((float)elenco[i].total_assistG/((float)elenco[i].total_assistG+(float)elenco[i].total_assistF))));
        }
    }

    system("PAUSE");
    return 0;
}

/* Funcao que  exibe as estatisticas de desarmes e de perdas de posse de bola de um jogador*/

int jogador_DeP(int num_uniforme, partida *inicio)
{
    system("cls");

    int i,j,k;
    int diaD, mesD, golsP, golsC;
    char sgl[3], adv[100];
    for(i=0;i<40;i++)
    {
        if(num_uniforme==elenco[i].uniforme)
        {
            printf("\tEstatisticas de desarmes e perdas de posse do %s\n\n", elenco[i].nome);
            printf("Desarmes na temporada: %d\n", elenco[i].total_desarmes);
            printf("Media de desarmes por partida: %.2f\n",elenco[i].media_desarmes);
            printf("Desarmes por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].desarmes[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].desarmes[j]);
                }
            }
            printf("\nPerdas de posse na temporada: %d\n", elenco[i].total_perdas);
            printf("Media de perdas de posse por partida: %.2f\n",elenco[i].media_perdas);
            printf("Perdas de posse por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].perdas[j];k++)
                        printf("* ");
                    printf("(%d)\n\n\n",elenco[i].perdas[j]);
                }
            }
        }
    }
    system("PAUSE");
    return 0;
}

/* Funcao que exibe as estatisticas de defesas e de gols sofridos de um goleiro */

int jogador_DeG(int num_uniforme, partida *inicio)
{
    system("cls");

    int i,j,k;
    int diaD, mesD, golsP, golsC;
    char sgl[3], adv[100];
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme)
        {
            printf("\tEstatisticas de defesas e gols sofridos do goleiro %s\n\n", goleiros[i].nome);
            printf("Defesas na temporada: %d\n", goleiros[i].total_defesas);
            printf("Media de defesas por partida: %.2f\n",goleiros[i].media_defesas);
            printf("Defesas por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].defesas[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",goleiros[i].defesas[j]);
                }
            }
            printf("\nGols sofridos na temporada: %d\n", goleiros[i].total_golsS);
            printf("Media de gols sofridos por partida: %.2f\n",goleiros[i].media_golsS);
            printf("Gols sofridos por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].golsS[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",goleiros[i].golsS[j]);
                }
            }
            printf("\nAproveitamento de defesas (defesas pelo total de chutes recebidos): %.2f%%\n\n\n",100*((float)goleiros[i].total_defesas/((float)goleiros[i].total_defesas+(float)goleiros[i].total_golsS)));
        }
    }
    system("PAUSE");
    return 0;
}

/* Funcao que exibe as estatisticas de faltas e penaltis de um jogador */

int jogador_FeP(int num_uniforme, partida *inicio)
{
    system("cls");

    int i,j,k;
    int diaD, mesD, golsP, golsC;
    char sgl[3], adv[100];
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme)
        {
            printf("\tEstatisticas de faltas e penaltis do %s\n\n", goleiros[i].nome);
            printf("Faltas cometidas na temporada: %d\n", goleiros[i].total_faltasC);
            printf("Media de faltas cometidas por partida: %.2f\n", goleiros[i].media_faltasC);
            printf("Faltas cometidas por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].faltasC[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",goleiros[i].faltasC[j]);
                }
            }
            printf("\nFaltas sofridas na temporada: %d\n", goleiros[i].total_faltasS);
            printf("Media de faltas sofridas por partida: %.2f\n",goleiros[i].media_faltasS);
            printf("Faltas sofridas por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].faltasS[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",goleiros[i].faltasS[j]);
                }
            }
            printf("\nPenaltis cometidos na temporada: %d\n", goleiros[i].total_penaltisC);
            if(goleiros[i].total_penaltisC>0)
            {
                printf("Media de penaltis cometidos por partida: %.2f\n", goleiros[i].media_penaltisC);
                printf("Penaltis cometidos por partida:\n\n");
                for(j=0;j<100;j++)
                {
                    if(goleiros[i].jogou[j]==1)
                    {
                        Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                        printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                        for(k=0;k<goleiros[i].penaltisC[j];k++)
                            printf("* ");
                        printf("(%d)\n\n",goleiros[i].penaltisC[j]);
                    }
                }
            }
            if(goleiros[i].total_penaltisC==0)
                printf("\n");
            printf("\nPenaltis sofridos na temporada: %d\n", goleiros[i].total_penaltisS);
            if(goleiros[i].total_penaltisS>0)
            {
                printf("Media de penaltis sofridos por partida: %.2f\n", goleiros[i].media_penaltisS);
                printf("Penaltis sofridos por partida:\n\n");
                for(j=0;j<100;j++)
                {
                    if(goleiros[i].jogou[j]==1)
                    {
                        Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                        printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                        for(k=0;k<goleiros[i].penaltisS[j];k++)
                            printf("* ");
                        printf("(%d)\n\n",goleiros[i].penaltisS[j]);
                    }
                }
            }
            if(goleiros[i].total_penaltisS==0)
                printf("\n");
            printf("\nPenaltis defendidos na temporada: %d\n", goleiros[i].total_penaltisD);
            if(goleiros[i].total_penaltisD>0)
            {
                printf("Media de penaltis defendidos por partida: %.2f\n", goleiros[i].media_penaltisD);
                printf("Penaltis defendidos por partida:\n\n");
                for(j=0;j<100;j++)
                {
                    if(goleiros[i].jogou[j]==1)
                    {
                        Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                        printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                        for(k=0;k<goleiros[i].penaltisD[j];k++)
                            printf("* ");
                        printf("(%d)\n\n",goleiros[i].penaltisD[j]);
                    }
                }
            }
            if(goleiros[i].total_penaltisD==0)
                printf("\n");
            printf("\nPenaltis perdidos na temporada: %d\n", goleiros[i].total_penaltisP);
            if(goleiros[i].total_penaltisP>0)
            {
                printf("Media de penaltis perdidos por partida: %.2f\n", goleiros[i].media_penaltisP);
                printf("Penaltis perdidos por partida:\n\n");
                for(j=0;j<100;j++)
                {
                    if(goleiros[i].jogou[j]==1)
                    {
                        Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                        printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                        for(k=0;k<goleiros[i].penaltisP[j];k++)
                            printf("* ");
                        printf("(%d)\n\n\n",goleiros[i].penaltisP[j]);
                    }
                }
            }
            if(goleiros[i].total_penaltisP==0)
                printf("\n\n");
        }
    }
    for(i=0;i<40;i++)
    {
        if(num_uniforme==elenco[i].uniforme)
        {
            printf("\tEstatisticas de faltas e penaltis do %s\n\n", elenco[i].nome);
            printf("Faltas cometidas na temporada: %d\n", elenco[i].total_faltasC);
            printf("Media de faltas cometidas por partida: %.2f\n", elenco[i].media_faltasC);
            printf("Faltas cometidas por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].faltasC[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].faltasC[j]);
                }
            }
            printf("\nFaltas sofridas na temporada: %d\n", elenco[i].total_faltasS);
            printf("Media de faltas sofridas por partida: %.2f\n",elenco[i].media_faltasS);
            printf("Faltas sofridas por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].faltasS[j];k++)
                        printf("* ");
                    printf("(%d)\n\n",elenco[i].faltasS[j]);
                }
            }
            printf("\nPenaltis cometidos na temporada: %d\n", elenco[i].total_penaltisC);
            if(elenco[i].total_penaltisC>0)
            {
                printf("Media de penaltis cometidos por partida: %.2f\n", elenco[i].media_penaltisC);
                printf("Penaltis cometidos por partida:\n\n");
                for(j=0;j<100;j++)
                {
                    if(elenco[i].jogou[j]==1)
                    {
                        Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                        printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                        for(k=0;k<elenco[i].penaltisC[j];k++)
                            printf("* ");
                        printf("(%d)\n\n",elenco[i].penaltisC[j]);
                    }
                }
            }
            if(elenco[i].total_penaltisC==0)
                printf("\n");
            printf("\nPenaltis sofridos na temporada: %d\n", elenco[i].total_penaltisS);
            if(elenco[i].total_penaltisS>0)
            {
                printf("Media de penaltis sofridos por partida: %.2f\n", elenco[i].media_penaltisS);
                printf("Penaltis sofridos por partida:\n\n");
                for(j=0;j<100;j++)
                {
                    if(elenco[i].jogou[j]==1)
                    {
                        Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                        printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                        for(k=0;k<elenco[i].penaltisS[j];k++)
                            printf("* ");
                        printf("(%d)\n\n",elenco[i].penaltisS[j]);
                    }
                }
            }
            if(elenco[i].total_penaltisS==0)
                printf("\n");
            printf("\nPenaltis perdidos na temporada: %d\n", elenco[i].total_penaltisP);
            if(elenco[i].total_penaltisP>0)
            {
                printf("Media de penaltis perdidos por partida: %.2f\n", elenco[i].media_penaltisP);
                printf("Penaltis perdidos por partida:\n\n");
                for(j=0;j<100;j++)
                {
                    if(elenco[i].jogou[j]==1)
                    {
                        Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                        printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                        for(k=0;k<elenco[i].penaltisP[j];k++)
                            printf("* ");
                        printf("(%d)\n\n\n",elenco[i].penaltisP[j]);
                    }
                }
            }
            if(elenco[i].total_penaltisP==0)
                printf("\n\n");
        }
    }

    system("PAUSE");
    return 0;
}

/* Funcao que exibe as estatisticas de impedimentos de um jogador */

int jogador_Imp(int num_uniforme, partida *inicio)
{
    system("cls");

    int i,j,k;
    int diaD, mesD, golsP, golsC;
    char sgl[3], adv[100];
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme)
        {
            printf("\tEstatisticas de impedimentos do goleiro %s\n\n", goleiros[i].nome);
            printf("Impedimentos na temporada: %d\n", goleiros[i].total_imped);
            printf("Media de impedimentos por partida: %.2f\n",goleiros[i].media_imped);
            printf("Impedimentos por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<goleiros[i].imped[j];k++)
                        printf("* ");
                    printf("(%d)\n\n\n",goleiros[i].imped[j]);
                }
            }
        }
    }

    for(i=0;i<40;i++)
    {
        if(num_uniforme==elenco[i].uniforme)
        {
            printf("\tEstatisticas de impedimentos do %s\n\n", elenco[i].nome);
            printf("Impedimentos na temporada: %d\n", elenco[i].total_imped);
            printf("Media de impedimentos por partida: %.2f\n",elenco[i].media_imped);
            printf("Impedimentos por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<elenco[i].imped[j];k++)
                        printf("* ");
                    printf("(%d)\n\n\n",elenco[i].imped[j]);
                }
            }
        }
    }

    system("PAUSE");
    return 0;
}

/* Funcao que exibe as estatisticas de notas de um jogador */

int jogador_notas(int num_uniforme, partida *inicio)
{
    system("cls");

    int i,j,k,jogoMaiorNota;
    float maiorNota=0;
    int diaD, mesD, golsP, golsC;
    char sgl[3], adv[100];
    for(i=0;i<10;i++)
    {
        if(num_uniforme==goleiros[i].uniforme)
        {
            printf("\tEstatisticas de notas do goleiro %s\n\n", goleiros[i].nome);
            //printf("Impedimentos na temporada: %d\n", goleiros[i].total_n);
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    if(goleiros[i].notas[j]>maiorNota)
                    {
                        maiorNota=goleiros[i].notas[j];
                        jogoMaiorNota=j;
                    }
                }
            }
            printf("Maior nota na temporada: %.2f (%d/%d. %d x %d %s)\n",maiorNota,jogo[jogoMaiorNota].dia,jogo[jogoMaiorNota].mes,jogo[jogoMaiorNota].gols_pro,jogo[jogoMaiorNota].gols_contra,jogo[jogoMaiorNota].sigla_adv);
            printf("Media de nota por partida: %.2f\n",goleiros[i].media_notas);
            printf("Nota por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<(int)goleiros[i].notas[j];k++)
                        printf("* ");
                    printf("(%.2f)\n\n\n",goleiros[i].notas[j]);
                }
            }
        }
    }

    for(i=0;i<40;i++)
    {
        if(num_uniforme==elenco[i].uniforme)
        {
            printf("\tEstatisticas de notas do %s\n\n", elenco[i].nome);
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    if(elenco[i].notas[j]>maiorNota)
                    {
                        maiorNota=elenco[i].notas[j];
                        jogoMaiorNota=j;
                    }
                }
            }
            Encontrar_LS (inicio, jogoMaiorNota, &diaD, &mesD, &golsP, &golsC, sgl, adv);
            printf("Maior nota na temporada: %.2f (%d/%d. %d x %d %c%c%c)\n",maiorNota,diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
            //printf("Media de nota por partida: %.2f\n",elenco[i].media_notas);
            printf("Nota por partida:\n\n");
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                {
                    Encontrar_LS (inicio, j, &diaD, &mesD, &golsP, &golsC, sgl, adv);
                    printf("%d/%d. %d x %d %c%c%c: ",diaD,mesD,golsP,golsC,sgl[0],sgl[1],sgl[2]);
                    for(k=0;k<(int)elenco[i].notas[j];k++)
                        printf("* ");
                    printf("(%.2f)\n\n\n",elenco[i].notas[j]);
                }
            }
        }
    }

    system("PAUSE");
    return 0;
}

/*    Funcoes da lista esncadeada simples    */

int Inicializar_LS (partida **inicio)
{
    *inicio = NULL;
    return 0;
}

int Inserir_LS (partida **inicio, char adv[], char sgl[], int diaD, int mesD, int golsP, int golsC, int subs, int *n)
{
    partida *percorre, *no_novo;
    no_novo = (partida *) malloc(sizeof(partida));
    strcpy(no_novo -> adversario, adv);
    strcpy(no_novo -> sigla_adv, sgl);
    no_novo -> dia = diaD;
    no_novo -> mes = mesD;
    no_novo -> gols_pro = golsP;
    no_novo -> gols_contra = golsC;
    no_novo -> substituicoes = subs;
    no_novo -> prox = NULL;
    if(*inicio == NULL)
	{
	    no_novo -> id = 0;
	    *n = 0;
	    *inicio = no_novo;
	}
    else
    {
        int i=1;
        percorre = *inicio;
        while(percorre -> prox != NULL)
        {
            i++;
            percorre = percorre -> prox;
        }
        *n = i;
        no_novo -> id = i;
        percorre -> prox = no_novo;
    }
    return 0;
}

int Editar_LS (partida **inicio, int i, char adv[], char sgl[], int diaD, int mesD, int golsP, int golsC, int subs)
{
    partida *percorre, *no_novo, *aux;
    no_novo = (partida *) malloc(sizeof(partida));
    strcpy(no_novo -> adversario, adv);
    strcpy(no_novo -> sigla_adv, sgl);
    no_novo -> dia = diaD;
    no_novo -> mes = mesD;
    no_novo -> gols_pro = golsP;
    no_novo -> gols_contra = golsC;
    no_novo -> substituicoes = subs;
    percorre = *inicio;
    while(percorre->id != i)
    {
        aux = percorre;
        percorre = percorre -> prox;
    }
    no_novo -> id = i;
    no_novo -> prox = percorre -> prox;
    aux -> prox = no_novo;
    free(percorre);
    return 0;
}

int Listar_LS (partida *inicio)
{
    if(inicio==NULL)
        return 1;

    printf(" Jogos:\n\n");
    while(inicio != NULL)
    {
        printf("%d. %d x %d %s\n", (inicio->id)+1, inicio->gols_pro, inicio->gols_contra, inicio->adversario);
        inicio = inicio -> prox;
    }
    return 0;
}

int Encontrar_LS (partida *inicio, int i, int *diaD, int *mesD, int *golsP, int *golsC, char sgl[], char adv[])
{
    partida *percorre;
    percorre = inicio;
    while(percorre->id != i)
    {
        percorre = percorre->prox;
    }
    *diaD = percorre->dia;
    *mesD = percorre->mes;
    *golsP = percorre->gols_pro;
    *golsC = percorre->gols_contra;
    strcpy(adv, percorre->adversario);
    sgl[0] = percorre->sigla_adv[0];
    sgl[1] = percorre->sigla_adv[1];
    sgl[2] = percorre->sigla_adv[2];

    printf("\n\n%c\n\n\n",sgl[3]);

    return 0;
}
