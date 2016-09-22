/*
 *                         A.T.V. - ASSISTENTE TECNICO VIRTUAL
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

/*    Estrutura onde os dados de um jogador sao armazenados    */

typedef struct {
    // Controle
    int controle;
    // Dados pessoais
    char nome[100]; int idade; float altura; float peso; int pe; int uniforme; int posicao[18];
    // Estatisticas em jogo
    float notas[100];         float media_notas;
    int passesC[100];         float media_passesC;
    int passesE[100];         float media_passesE;
    int finalizacoesC[100];   float media_finalizacoesC;
    int finalizacoesE[100];   float media_finalizacoesE;
    int desarmes[100];        float media_desarmes;
    int gols[100];            float media_gols;
    int faltasC[100];         float media_faltasC;
    int faltasS[100];         float media_faltasS;
    int imped[100];           float media_imped;
    int assistG[100];         float media_assistG;
    int assistF[100];         float media_assistF;
    int penaltisC[100];       float media_penaltisC;
    int penaltisS[100];       float media_penaltisS;
    int penaltisP[100];       float media_penaltisP;
}jogador;

jogador elenco[40];

/*    Estrutura onde os dados de um goleiro sao armazenados    */

typedef struct {
    // Controle
    int controle;
    // Dados pessoais
    char nome[100]; int idade; float altura; float peso; int pe; int uniforme;
    // Estatisticas em jogo
    float notas[100];         float media_notas;
    int passesC[100];         float media_passesC;
    int passesE[100];         float media_passesE;
    int defesas[100];         float media_defesas;
    int golsS[100];           float media_golsS;
    int golsC[100];           float media_golsC;
    int faltasC[100];         float media_faltasC;
    int faltasS[100];         float media_faltasS;
    int imped[100];           float media_imped;
    int assistG[100];         float media_assistG;
    int assistF[100];         float media_assistF;
    int penaltisC[100];       float media_penaltisC;
    int penaltisS[100];       float media_penaltisS;
    int penaltisP[100];       float media_penaltisP;
}goleiro;

goleiro goleiros[10];

/*    Prototipos das funcoes utilizadas    */

int cadastrar();
int editar();
int lista_jogadores();
int estatisticas_jogador();
int estatisticas_grupo();
int inserir_dados();
int editar_dados();
float media();
float pontuacao();
int ranking();
int melhor_escalacao();
int grupo_notas();
int grupo_GeF();
int grupo_PeA();
int grupo_Des();
int grupo_Def();
int grupo_FeP();
int grupo_Imp();
int jogador_dados();
int jogador_GeF();
int jogador_PeA();
int jogador_des();
int jogador_def();
int jogador_FeP();
int jogador_imp();
int jogador_notas();

/* Funcao principal */

int main()
{
    int comando;

    int i;
    for(i=0;i<40;i++)
    {
        elenco[i].controle=0;
        elenco[i].uniforme=0;
    }
    for(i=0;i<10;i++)
    {
        goleiros[i].controle=0;
        goleiros[i].uniforme=0;
    }

    do{
        system("cls");

        printf("\tA.T.V.\n\n");
        printf("1. Cadastrar jogador.\n");
        printf("2. Editar dados de jogador.\n");
        printf("3. Inserir dados de uma partida.\n");
        printf("4. Editar dados de uma partida.\n");
        printf("5. Ver estatisticas de um jogador.\n");
        printf("6. Ver estatisticas do grupo.\n");
        printf("0. Sair.\n");
        printf("-> ");
        scanf("%d",&comando);

        switch(comando)
        {
            case 1:
                cadastrar();
                break;

            case 2:
                editar();
                break;

            case 3:
                inserir_dados();
                break;

            case 4:
                editar_dados();
                break;

            case 5:
                estatisticas_jogador();
                break;

            case 6:
                estatisticas_grupo();
                break;

            case 0:
                system("cls");
                printf("\t\tAte logo!\n");
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
    printf("\tCadastrar jogador.\n\n");
    printf("1. Jogador.\t2. Goleiro.\n->");
    int pos,i,n,num_uniforme;
    while(pos!=1 || pos!=2){
        scanf("%d",&pos);
        if(pos!=1 || pos!=2)
            printf("Digite uma opcao valida ->");
    }
    if(pos==1)
    {
        for(i=0;i<40;i++)
        {
            if(elenco[i].controle==0)
            {
                n=i;
                break;
            }
        }
        elenco[n].controle=1;
        printf("Nome: ");
        setbuf(stdin, NULL);
        fgets(elenco[n].nome,100,stdin);
        printf("Idade: ");
        scanf("%d",&elenco[n].idade);
        printf("Altura: ");
        scanf("%f",&elenco[n].altura);
        printf("Peso: ");
        scanf("%f",&elenco[n].peso);
        printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
        scanf("%d",&elenco[n].pe);
        int erro=1;
        do
        {
            printf("Numero no uniforme: ");
            scanf("%d",&elenco[n].uniforme);
            for(i=0;i<40;i++)
            {
                if(elenco[n].uniforme==elenco[i].uniforme || elenco[n].uniforme==goleiros[i].uniforme)
                {
                    printf("Numero de uniforme ja cadastrado!\n");
                }
                else
                    if(i==40)
                        erro=0;
            }
        }while(erro==1);
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
        printf("-> ");
        char ch;
        int j=0;
        i=0;
        char p[4];
        do
        {
            ch=getchar();
            if(ch==' ' || ch=='\n')
            {
                p[i]='\0';
                i=0;
                if(strcmp(p,"ZD")==0)
                    elenco[n].posicao[j]=1;
                if(strcmp(p,"ZE")==0)
                    elenco[n].posicao[j]=2;
                if(strcmp(p,"ZC")==0)
                    elenco[n].posicao[j]=3;
                if(strcmp(p,"LDD")==0)
                    elenco[n].posicao[j]=4;
                if(strcmp(p,"LED")==0)
                    elenco[n].posicao[j]=5;
                if(strcmp(p,"LDO")==0)
                    elenco[n].posicao[j]=6;
                if(strcmp(p,"LEO")==0)
                    elenco[n].posicao[j]=7;
                if(strcmp(p,"PV")==0)
                    elenco[n].posicao[j]=8;
                if(strcmp(p,"SV")==0)
                    elenco[n].posicao[j]=9;
                if(strcmp(p,"ARM")==0)
                    elenco[n].posicao[j]=10;
                if(strcmp(p,"MD")==0)
                    elenco[n].posicao[j]=11;
                if(strcmp(p,"ME")==0)
                    elenco[n].posicao[j]=12;
                if(strcmp(p,"MA")==0)
                    elenco[n].posicao[j]=13;
                if(strcmp(p,"SE")==0)
                    elenco[n].posicao[j]=14;
                if(strcmp(p,"PD")==0)
                    elenco[n].posicao[j]=15;
                if(strcmp(p,"PE")==0)
                    elenco[n].posicao[j]=16;
                if(strcmp(p,"SA")==0)
                    elenco[n].posicao[j]=17;
                if(strcmp(p,"CA")==0)
                    elenco[n].posicao[j]=18;
                j++;
            }
            if(ch>64 && ch<91)
            {
                p[i]=ch;
                i++;
            }
        }while(ch != '\n');
    }
    if(pos==2)
    {
        for(i=0;i<40;i++)
        {
            if(goleiros[i].controle==0)
                break;
        }
        printf("Nome: ");
        setbuf(stdin, NULL);
        fgets(goleiros[n].nome,100,stdin);
        printf("Idade: ");
        scanf("%d",&goleiros[n].idade);
        printf("Altura: ");
        scanf("%f",&goleiros[n].altura);
        printf("Peso: ");
        scanf("%f",&goleiros[n].peso);
        printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
        scanf("%d",&goleiros[n].pe);
        printf("Numero no uniforme: ");
        scanf("%d",&goleiros[n].uniforme);
    }
    system("PAUSE");
    return 0;
}

/* Funcao que edita o cadastro de um jogador */

int editar()
{
    system("cls");
    int n,i;
    int num_uniforme=lista_jogadores();
    for(n=0;n<40;n++)
    {
        if(num_uniforme==elenco[n].uniforme)
        {
            printf("Nome: ");
            setbuf(stdin, NULL);
            fgets(elenco[n].nome,100,stdin);
            printf("Idade: ");
            scanf("%d",&elenco[n].idade);
            printf("Altura: ");
            scanf("%f",&elenco[n].altura);
            printf("Peso: ");
            scanf("%f",&elenco[n].peso);
            printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
            scanf("%d",&elenco[n].pe);
            int erro=1;
            do
            {
                printf("Numero no uniforme: ");
                scanf("%d",&num_uniforme);
                if(num_uniforme==elenco[n].uniforme)
                {
                    erro=0;
                }
                else
                {
                    for(i=0;i<40;i++)
                    {
                        if(num_uniforme==elenco[i].uniforme || num_uniforme==goleiros[i].uniforme)
                        {
                            printf("Numero de uniforme ja cadastrado!\n");
                        }
                        else
                            if(i==40)
                            {
                                erro=0;
                                elenco[n].uniforme=num_uniforme;
                            }
                    }
                }
            }while(erro==1);
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
            printf("-> ");
            char ch;
            int j=0;
            i=0;
            char p[4];
            do
            {
                ch=getchar();
                if(ch==' ' || ch=='\n')
                {
                    p[i]='\0';
                    i=0;
                    if(strcmp(p,"ZD")==0)
                        elenco[n].posicao[j]=1;
                    if(strcmp(p,"ZE")==0)
                        elenco[n].posicao[j]=2;
                    if(strcmp(p,"ZC")==0)
                        elenco[n].posicao[j]=3;
                    if(strcmp(p,"LDD")==0)
                        elenco[n].posicao[j]=4;
                    if(strcmp(p,"LED")==0)
                        elenco[n].posicao[j]=5;
                    if(strcmp(p,"LDO")==0)
                        elenco[n].posicao[j]=6;
                    if(strcmp(p,"LEO")==0)
                        elenco[n].posicao[j]=7;
                    if(strcmp(p,"PV")==0)
                        elenco[n].posicao[j]=8;
                    if(strcmp(p,"SV")==0)
                        elenco[n].posicao[j]=9;
                    if(strcmp(p,"ARM")==0)
                        elenco[n].posicao[j]=10;
                    if(strcmp(p,"MD")==0)
                        elenco[n].posicao[j]=11;
                    if(strcmp(p,"ME")==0)
                        elenco[n].posicao[j]=12;
                    if(strcmp(p,"MA")==0)
                        elenco[n].posicao[j]=13;
                    if(strcmp(p,"SE")==0)
                        elenco[n].posicao[j]=14;
                    if(strcmp(p,"PD")==0)
                        elenco[n].posicao[j]=15;
                    if(strcmp(p,"PE")==0)
                        elenco[n].posicao[j]=16;
                    if(strcmp(p,"SA")==0)
                        elenco[n].posicao[j]=17;
                    if(strcmp(p,"CA")==0)
                        elenco[n].posicao[j]=18;
                    j++;
                }
                if(ch>64 && ch<91)
                {
                    p[i]=ch;
                    i++;
                }
            }while(ch != '\n');
            }
    }
    for(n=0;n<10;n++)
    {
        if(num_uniforme==goleiros[n].uniforme)
        {
            printf("Nome: ");
            setbuf(stdin, NULL);
            fgets(goleiros[n].nome,100,stdin);
            printf("Idade: ");
            scanf("%d",&goleiros[n].idade);
            printf("Altura: ");
            scanf("%f",&goleiros[n].altura);
            printf("Peso: ");
            scanf("%f",&goleiros[n].peso);
            printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
            scanf("%d",&goleiros[n].pe);
            int erro=1;
            do
            {
                printf("Numero no uniforme: ");
                scanf("%d",&num_uniforme);
                if(num_uniforme==goleiros[n].uniforme)
                {
                    erro=0;
                }
                else
                {
                    for(i=0;i<40;i++)
                    {
                        if(num_uniforme==elenco[i].uniforme || num_uniforme==goleiros[i].uniforme)
                        {
                            printf("Numero de uniforme ja cadastrado!\n");
                        }
                        else
                            if(i==40)
                            {
                                erro=0;
                                goleiros[n].uniforme=num_uniforme;
                            }
                    }
                }
            }while(erro==1);
        }
    }
    system("PAUSE");
    return 0;
}

/* Funcao que insere os dados de uma partida */

int inserir_dados()
{
    system("cls");
    printf("\tInserir estatisticas de uma partida.\n\n");
    printf("Adversario: /\n");
    printf("Gols feitos: /\n");
    printf("Gols sofridos: /\n");
    printf("Substituicoes feitas na partida: /\n");
    printf("\nGoleiro\n");
    printf("  Nome: /\n");
    printf("  Defesas: /\n");
    printf("  Passes corretos: /\n");
    printf("  Passes errados: /\n");
    printf("  Gols sofridos: /\n");
    printf("  Gols convertidos: /\n");
    printf("  Faltas cometidas: /\n");
    printf("  Faltas sofridas: /\n");
    printf("  Impedimentos: /\n");
    printf("  Assistencias (gol): /\n");
    printf("  Assistencias (finalizacao): /\n");
    printf("  Penaltis cometidos: /\n");
    printf("  Penaltis sofridos: /\n");
    printf("  Penaltis perdidos: /\n");
    printf("\nJogador 1\n");
    printf("  Nome: /\n");
    printf("  Sigla da posicao na partida: /\n");
    printf("  Passes corretos: /\n");
    printf("  Passes errados: /\n");
    printf("  Finalizacoes corretas: /\n");
    printf("  Finalizacoes erradas: /\n");
    printf("  Desarmes: /\n");
    printf("  Gols: /\n");
    printf("  Faltas cometidas: /\n");
    printf("  Faltas sofridas: /\n");
    printf("  Impedimentos: /\n");
    printf("  Assistencias (gol): /\n");
    printf("  Assistencias (finalizacao): /\n");
    printf("  Penaltis cometidos: /\n");
    printf("  Penaltis sofridos: /\n");
    printf("  Penaltis perdidos: /\n");
    printf("\n\t(...)\n");
    printf("\nJogador N\n");
    printf("  Nome: /\n");
    printf("  Sigla da posicao na partida: /\n");
    printf("  Passes corretos: /\n");
    printf("  Passes errados: /\n");
    printf("  Finalizacoes corretas: /\n");
    printf("  Finalizacoes erradas: /\n");
    printf("  Desarmes: /\n");
    printf("  Gols: /\n");
    printf("  Faltas cometidas: /\n");
    printf("  Faltas sofridas: /\n");
    printf("  Impedimentos: /\n");
    printf("  Assistencias (gol): /\n");
    printf("  Assistencias (finalizacao): /\n");
    printf("  Penaltis cometidos: /\n");
    printf("  Penaltis sofridos: /\n");
    printf("  Penaltis perdidos: /\n");
    system("pause");
    return 0;
}

/* Funcao que edita as estatisticas de uma partida */

int editar_dados()
{

}

/* Funcao que exibe as estatisticas de um jogador */

int estatisticas_jogador()
{

}

/* Funcao que exibe as estatisticas do grupo */

int estatisticas_grupo()
{

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
    printf("-> ");
    int num_uniforme;
    scanf("%d",&num_uniforme);
    return num_uniforme;
}

/* Funcao que calcula a media (nao e' certeza ainda) */

float media()
{

}

/* Funcao que calcula a pontuacao de um jogador na partida */

float pontuacao()
{

}

/* Funcao que exibe o ranking de jogadores sob um indicador */

int ranking(int indicador)
{

}

/* Funcao que exibe a melhor escalacao baseado nas melhores notas por posicao */

int melhor_escalacao()
{

}

/* Funcao que exibe as estatisticas de notas do grupo */

int grupo_notas()
{

}

/* Funcao que exibe as estatisticas de gols e finalizacoes do grupo */

int grupo_GeF()
{

}

/* Funcao que exibe as estatisticas de passes e assistencias do grupo */

int grupo_PeA()
{

}

/* Funcao que exibe as estatisticas de desarmes e defesas do grupo */

int grupo_DeD()
{

}

/* Funcao que exibe as estatisticas de faltas e penaltis do grupo */

int grupo_FeP()
{

}

/* Funcao que exibe as estatisticas de impedimentos do grupo */

int grupo_imp()
{

}

/* Funcao que exibe os dados gerais de um jogador */

int jogador_dados()
{

}

/* Funcao que exibe as estatisticas de gols e finalizacoes de um jogador */

int jogador_GeF()
{

}

/* Funcao que exibe as estatisticas de passes e assistencias de um jogador */

int jogador_PeA()
{

}

/* Funcao que  exibe as estatisticas de desarmes de um jogador*/

int jogador_des()
{

}

/* Funcao que exibe as estatisticas de defesas de um jogador */

int jogador_def()
{

}

/* Funcao que exibe as estatisticas de faltas e penaltis de um jogador */

int jogador_FeP()
{

}

/* Funcao que exibe as estatisticas de impedimentos de um jogador */

int jogador_imp()
{

}

/* Funcao que exibe as estatisticas de notas de um jogador */

int jogador_notas()
{

}
