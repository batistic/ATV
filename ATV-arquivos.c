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
#include <conio.h>
#include <windows.h>

/*    Estrutura onde os dados de um cadastro sao armazenados    */

typedef struct registro{
    char nome[100];
    char senha[20];
}cadastro;

/*    Estrutura onde os dados de uma partida sao armazenados    */

struct jogos{
    int id;
    char adversario[100];
    char sigla_adv[3];
    int dia;
    int mes;
    int gols_pro;
    int gols_contra;
    int substituicoes;
};

typedef struct jogos partida;

/*    Estrutura onde os dados de um jogador sao armazenados    */

typedef struct {
    // Dados pessoais
    char nome[100]; int idade; float altura; float peso; int pe; int uniforme; int posicao;
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

/*    Estrutura onde os dados de um goleiro sao armazenados    */

typedef struct {
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

/*    Prototipos das funcoes utilizadas    */

int home(char *time);
int cadastro_time(char *time);
int login(char *time);
int cadastrar(char *time); //cadastra um novo jogador
int editar(char *time); //edita o cadastro de um jogador
int excluir(char *time); // exclui o cadastro de um jogador
int lista_jogadores(char *time); //lista todos os jogadores do grupo
int lista_jogos(char *time); // lista todos os jogos ocorridos
int estatisticas_jogador(char *time); //exibe as estatísticas de um jogador
int estatisticas_grupo(char *time); //exibe as estatisticas do grupo
int inserir_dados(char *time); //insere os dados de uma partida
int editar_dados(char *time); //edita os dados de uma partida que já ocorreu
float media_jogador(int total, int jogos); //calcula a media de um jogador
float media_jogadorN(int num_jogador, char *time); //calcula a media de notas de um jogador
float pontuacao(int num_uniforme, int n, char *time); //calcula a pontuação do jogador na partida
int melhor_escalacao(char *time);//exibe a melhor escalação baseado nas melhores notas por posição
int melhor_escalacao1(char *time);//exibe a melhor escalação com a formacao 3-5-2
int melhor_escalacao2(char *time);//exibe a melhor escalação com a formacao 4-3-3
int melhor_escalacao3(char *time);//exibe a melhor escalação com a formacao 4-4-2
int grupo_notas(); //exibe as estatísticas de nota do grupo
int grupo_GeF(); //exibe as estatísticas de gol e finalização do grupo //da pra melhorar
int grupo_PeA();//exibe as estatísticas de passes e assistências do grupo
int grupo_DeP();//exibe as estatísticas de desarme e de perdas de posse de bola do grupo
int grupo_Def();//exibe as estatísticas de defesa do grupo
int grupo_FeP();//exibe as estatísticas de faltas e pênaltis do grupo
int grupo_Imp();//exibe as estatísticas de impedimentos do grupo
int jogador_dados(int num_uniforme, char *time);//mostra os dados gerais do jogador
int jogador_GeF(int num_uniforme, char *time);//exibe as estatísticas de gol e finalização do jogador
int goleiro_Gols(int num_uniforme, char *time);//exibe as estatísticas de gols sofridos e convertidos do goleiro
int jogador_PeA(int num_uniforme, char *time);//exibe as estatísticas de passes e assistências do jogador
int jogador_DeP(int num_uniforme, char *time);//exibe as estatísticas de desarmes e de perdas de posse de bola do jogador
int jogador_DeG(int num_uniforme, char *time);//exibe as estatísticas de defesa do jogador
int jogador_FeP(int num_uniforme, char *time);//exibe as estatísticas de faltas e pênaltis do jogador
int jogador_Imp(int num_uniforme, char *time);//exibe as estatísticas de impedimentos do jogador
int jogador_notas(int num_uniforme, char *time);//exibe as estatísticas de notas do jogador

/* Funcao principal */

int main()
{
    int comando,erro;
    system("cls");
    char time[100];
    erro = home(time);
    if(erro == 1)
        return 0;

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
                cadastrar(time); // entra na função que cadastra jogadores
                break;

            case 2:
                editar(time); // entra na função que edita cadastro de jogadores
                break;

            case 3:
                excluir(time); // entra na função que exclui cadastro de jogaador
                break;

            case 4:
                inserir_dados(time); // entra na função que cadastra insere dados de uma partida
                break;

            case 5:
                editar_dados(time); // entra na função que cadastra edita dados de uma partida
                break;

            case 6:
                estatisticas_jogador(time); // entra na função que exibe as estatisticas de um jogador
                break;

            case 7:
                estatisticas_grupo(time); // entra na função que exibe as estatisticas do grupo
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

int cadastrar(char *time)
{
    FILE *arqJ;
    FILE *arqG;
    char arqJogadores[120], arqGoleiros[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    system("cls");
    jogador elenco, auxiliarJ;
    goleiro goleiros, auxiliarG;
    arqJ = fopen(arqJogadores,"ab+"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqG = fopen(arqGoleiros,"ab+"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    int pos,n,num_uniforme,j; // variaveis auxiliares
    int erro=1; // variavel para testar se um n. de uniforme ja foi cadastrado
    printf("\tCadastrar jogador.\n\n");
    printf("1. Jogador.\t2. Goleiro.\n0. Voltar\n\n-> ");//solicita que o usuário defina se é goleiro ou não
    while(pos!=1 && pos!=2 && pos!=0){//verifica se entrada é valida (apenas 1 e 2 permitidos)
        scanf("%d",&pos);
        if(pos!=1 && pos!=2 && pos!=0)
            printf("Digite uma opcao valida -> ");
    }
    if(pos==0)
        return 0;
    if(pos==1)//caso entrada seja 1) Jogador (que não goleiro)
    {
        //leitura de dados do jogador
        printf("Nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s",elenco.nome);
        printf("Idade: ");
        scanf("%d",&elenco.idade);
        printf("Altura: ");
        scanf("%f",&elenco.altura);
        printf("Peso: ");
        scanf("%f",&elenco.peso);
        printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
        scanf("%d",&elenco.pe);
        while(erro==1)  // loop para verificar se o numero do uniforme já não pertence a outro jogador
        {
            printf("Numero no uniforme: ");
            scanf("%d",&num_uniforme);
            fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
            while((!feof(arqJ)) && (auxiliarJ.uniforme != num_uniforme)){
                fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
            }
            if(auxiliarJ.uniforme == num_uniforme)
            {
                printf("Numero de uniforme ja cadastrado!\n");
            }
            else
            {
                fread(&auxiliarG, sizeof(goleiro), 1, arqG);
                while((!feof(arqG)) && (auxiliarG.uniforme != num_uniforme)){
                    fread(&auxiliarG, sizeof(goleiro), 1, arqG);
                }
                if(auxiliarG.uniforme == num_uniforme)
                {
                    printf("Numero de uniforme ja cadastrado!\n");
                }
                else
                {
                    elenco.uniforme = num_uniforme;
                    erro = 0;
                }
            }
        }
        printf("Insira a sigla da posicao do jogador:\n");
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
        char p[3];
        scanf("%s",p);
        if(strcmp(p,"ZD")==0 || strcmp(p,"zd")==0)
            elenco.posicao=1;
        if(strcmp(p,"ZE")==0 || strcmp(p,"ze")==0)
            elenco.posicao=2;
        if(strcmp(p,"ZC")==0 || strcmp(p,"zc")==0)
            elenco.posicao=3;
        if(strcmp(p,"LDD")==0 || strcmp(p,"ldd")==0)
            elenco.posicao=4;
        if(strcmp(p,"LED")==0 || strcmp(p,"led")==0)
            elenco.posicao=5;
        if(strcmp(p,"LDO")==0 || strcmp(p,"ldo")==0)
            elenco.posicao=6;
        if(strcmp(p,"LEO")==0 || strcmp(p,"leo")==0)
            elenco.posicao=7;
        if(strcmp(p,"PV")==0 || strcmp(p,"pv")==0)
            elenco.posicao=8;
        if(strcmp(p,"SV")==0 || strcmp(p,"sv")==0)
            elenco.posicao=9;
        if(strcmp(p,"ARM")==0 || strcmp(p,"arm")==0)
            elenco.posicao=10;
        if(strcmp(p,"MD")==0 || strcmp(p,"md")==0)
            elenco.posicao=11;
        if(strcmp(p,"ME")==0 || strcmp(p,"me")==0)
            elenco.posicao=12;
        if(strcmp(p,"MA")==0 || strcmp(p,"ma")==0)
            elenco.posicao=13;
        if(strcmp(p,"PD")==0 || strcmp(p,"pd")==0)
            elenco.posicao=14;
        if(strcmp(p,"PE")==0 || strcmp(p,"pe")==0)
            elenco.posicao=15;
        if(strcmp(p,"SA")==0 || strcmp(p,"sa")==0)
            elenco.posicao=16;
        if(strcmp(p,"CA")==0 || strcmp(p,"ca")==0)
            elenco.posicao=17;

        elenco.jogos=0;
        for(j=0;j<100;j++) // zerando os jogos do jogador
            elenco.jogou[j]=0;
        // zerando as medias do jogador
        elenco.media_assistF=0;
        elenco.media_assistG=0;
        elenco.media_desarmes=0;
        elenco.media_perdas=0;
        elenco.media_faltasC=0;
        elenco.media_faltasS=0;
        elenco.media_gols=0;
        elenco.media_golsC=0;
        elenco.media_finalizacoesC=0;
        elenco.media_finalizacoesE=0;
        elenco.media_imped=0;
        elenco.media_notas=0;
        elenco.media_passesC=0;
        elenco.media_passesE=0;
        elenco.media_penaltisC=0;
        elenco.media_penaltisS=0;
        elenco.media_penaltisP=0;
        // zerando o total dos indicadores
        elenco.total_assistF=0;
        elenco.total_assistG=0;
        elenco.total_desarmes=0;
        elenco.total_perdas=0;
        elenco.total_faltasC=0;
        elenco.total_faltasS=0;
        elenco.total_gols=0;
        elenco.total_golsC=0;
        elenco.total_finalizacoesC=0;
        elenco.total_finalizacoesE=0;
        elenco.total_imped=0;
        elenco.total_passesC=0;
        elenco.total_passesE=0;
        elenco.total_penaltisC=0;
        elenco.total_penaltisS=0;
        elenco.total_penaltisP=0;

        fwrite(&elenco,sizeof(jogador),1,arqJ);
    }
    if(pos==2)//caso entrada seja 2) Goleiro
    {
        //leitura de dados do jogador
        printf("Nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s",goleiros.nome);
        printf("Idade: ");
        scanf("%d",&goleiros.idade);
        printf("Altura: ");
        scanf("%f",&goleiros.altura);
        printf("Peso: ");
        scanf("%f",&goleiros.peso);
        printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
        scanf("%d",&goleiros.pe);
        while(erro==1)  // loop para verificar se o numero do uniforme já não pertence a outro jogador
        {
            printf("Numero no uniforme: ");
            scanf("%d",&num_uniforme);
            fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
            while((!feof(arqJ)) && (auxiliarJ.uniforme != num_uniforme)){
                fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
            }
            if(auxiliarJ.uniforme == num_uniforme)
            {
                printf("Numero de uniforme ja cadastrado!\n");
            }
            else
            {
                fread(&auxiliarG, sizeof(goleiro), 1, arqG);
                while((!feof(arqG)) && (auxiliarG.uniforme != num_uniforme)){
                    fread(&auxiliarG, sizeof(goleiro), 1, arqG);
                }
                if(auxiliarG.uniforme == num_uniforme)
                {
                    printf("Numero de uniforme ja cadastrado!\n");
                }
                else
                {
                    goleiros.uniforme = num_uniforme;
                    erro = 0;
                }
            }
        }

        goleiros.jogos=0;
        for(j=0;j<100;j++) // zerando os jogos dos goleiros
            goleiros.jogou[j]=0;
        // zerando as medias dos goleiros
        goleiros.media_assistF=0;
        goleiros.media_assistG=0;
        goleiros.media_defesas=0;
        goleiros.media_faltasC=0;
        goleiros.media_faltasS=0;
        goleiros.media_golsC=0;
        goleiros.media_golsS=0;
        goleiros.media_perdas=0;
        goleiros.media_imped=0;
        goleiros.media_notas=0;
        goleiros.media_passesC=0;
        goleiros.media_passesE=0;
        goleiros.media_penaltisC=0;
        goleiros.media_penaltisS=0;
        goleiros.media_penaltisP=0;
        goleiros.media_penaltisD=0;
        // zerando o total dos indicadores
        goleiros.total_assistF=0;
        goleiros.total_assistG=0;
        goleiros.total_defesas=0;
        goleiros.total_faltasC=0;
        goleiros.total_faltasS=0;
        goleiros.total_golsC=0;
        goleiros.total_golsS=0;
        goleiros.total_perdas=0;
        goleiros.total_imped=0;
        goleiros.total_passesC=0;
        goleiros.total_passesE=0;
        goleiros.total_penaltisC=0;
        goleiros.total_penaltisS=0;
        goleiros.total_penaltisP=0;
        goleiros.total_penaltisD=0;

        fwrite(&elenco,sizeof(goleiro),1,arqG);
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

/* Funcao que edita o cadastro de um jogador */

int editar(char *time)
{
    system("cls");
    printf("\tEditar cadastro de jogador.\n\n");
    int n,j,erro,novo_uniforme; // variaveis auxiliares
    int num_uniforme=lista_jogadores(time); // chama a função que lista todos os jogadores e retorna o numero do uniforme do escolhido pelo usuario
    if(num_uniforme==0)
        return 0;
    FILE *arqJ;
    FILE *arqG;
    FILE *aux;
    char arqJogadores[120], arqGoleiros[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    jogador elenco, auxiliarJ, auxJ;
    goleiro goleiros, auxiliarG, auxG;
    arqJ = fopen(arqJogadores,"ab+"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqG = fopen(arqGoleiros,"ab+"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    while((!feof(arqJ)) && (auxiliarJ.uniforme != num_uniforme)){
        fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
    }
    if(auxiliarJ.uniforme == num_uniforme)
    {
        elenco.jogos = auxiliarJ.jogos;
        for(j=0;j<100;j++) // zerando os jogos do jogador
            elenco.jogou[j] = auxiliarJ.jogou[j];
        // zerando as medias do jogador
        elenco.media_assistF = auxiliarJ.media_assistF;
        elenco.media_assistG = auxiliarJ.media_assistG;
        elenco.media_desarmes = auxiliarJ.media_desarmes;
        elenco.media_perdas = auxiliarJ.media_perdas;
        elenco.media_faltasC = auxiliarJ.media_faltasC;
        elenco.media_faltasS = auxiliarJ.media_faltasS;
        elenco.media_gols = auxiliarJ.media_gols;
        elenco.media_golsC = auxiliarJ.media_golsC;
        elenco.media_finalizacoesC = auxiliarJ.media_finalizacoesC;
        elenco.media_finalizacoesE = auxiliarJ.media_finalizacoesE;
        elenco.media_imped = auxiliarJ.media_imped;
        elenco.media_notas = auxiliarJ.media_notas;
        elenco.media_passesC = auxiliarJ.media_passesC;
        elenco.media_passesE = auxiliarJ.media_passesE;
        elenco.media_penaltisC = auxiliarJ.media_penaltisC;
        elenco.media_penaltisS = auxiliarJ.media_penaltisS;
        elenco.media_penaltisP = auxiliarJ.media_penaltisP;
        // zerando o total dos indicadores
        elenco.total_assistF = auxiliarJ.total_assistF;
        elenco.total_assistG = auxiliarJ.total_assistG;
        elenco.total_desarmes = auxiliarJ.total_desarmes;
        elenco.total_perdas = auxiliarJ.total_perdas;
        elenco.total_faltasC = auxiliarJ.total_faltasC;
        elenco.total_faltasS = auxiliarJ.total_faltasS;
        elenco.total_gols = auxiliarJ.total_gols;
        elenco.total_golsC = auxiliarJ.total_golsC;
        elenco.total_finalizacoesC = auxiliarJ.total_finalizacoesC;
        elenco.total_finalizacoesE = auxiliarJ.total_finalizacoesE;
        elenco.total_imped = auxiliarJ.total_imped;
        elenco.total_passesC = auxiliarJ.total_passesC;
        elenco.total_passesE = auxiliarJ.total_passesE;
        elenco.total_penaltisC = auxiliarJ.total_penaltisC;
        elenco.total_penaltisS = auxiliarJ.total_penaltisS;
        elenco.total_penaltisP = auxiliarJ.total_penaltisP;

        //leitura de dados do jogador
        printf("Nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s",elenco.nome);
        printf("Idade: ");
        scanf("%d",&elenco.idade);
        printf("Altura: ");
        scanf("%f",&elenco.altura);
        printf("Peso: ");
        scanf("%f",&elenco.peso);
        printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
        scanf("%d",&elenco.pe);
        while(erro==1)  // loop para verificar se o numero do uniforme já não pertence a outro jogador
        {
            printf("Numero no uniforme: ");
            scanf("%d",&novo_uniforme);
            if(novo_uniforme==num_uniforme) // verifica se o numero de uniforme foi alterado
            {
                erro=0; // caso não tenha sido alterado
                break;
            }
            else
            {
                rewind(arqJ);
                fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
                while((!feof(arqJ)) && (auxiliarJ.uniforme != novo_uniforme)){
                    fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
                }
                if(auxiliarJ.uniforme == novo_uniforme)
                {
                    printf("Numero de uniforme ja cadastrado!\n");
                }
                else
                {
                    rewind(arqG);
                    fread(&auxiliarG, sizeof(goleiro), 1, arqG);
                    while((!feof(arqG)) && (auxiliarG.uniforme != novo_uniforme)){
                        fread(&auxiliarG, sizeof(goleiro), 1, arqG);
                    }
                    if(auxiliarG.uniforme == novo_uniforme)
                    {
                        printf("Numero de uniforme ja cadastrado!\n");
                    }
                    else
                    {
                        elenco.uniforme = novo_uniforme;
                        erro = 0;
                    }
                }
            }
        }
        printf("Insira a sigla da posicao do jogador:\n");
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
        char p[3];
        scanf("%s",p);
        if(strcmp(p,"ZD")==0 || strcmp(p,"zd")==0)
            elenco.posicao=1;
        if(strcmp(p,"ZE")==0 || strcmp(p,"ze")==0)
            elenco.posicao=2;
        if(strcmp(p,"ZC")==0 || strcmp(p,"zc")==0)
            elenco.posicao=3;
        if(strcmp(p,"LDD")==0 || strcmp(p,"ldd")==0)
            elenco.posicao=4;
        if(strcmp(p,"LED")==0 || strcmp(p,"led")==0)
            elenco.posicao=5;
        if(strcmp(p,"LDO")==0 || strcmp(p,"ldo")==0)
            elenco.posicao=6;
        if(strcmp(p,"LEO")==0 || strcmp(p,"leo")==0)
            elenco.posicao=7;
        if(strcmp(p,"PV")==0 || strcmp(p,"pv")==0)
            elenco.posicao=8;
        if(strcmp(p,"SV")==0 || strcmp(p,"sv")==0)
            elenco.posicao=9;
        if(strcmp(p,"ARM")==0 || strcmp(p,"arm")==0)
            elenco.posicao=10;
        if(strcmp(p,"MD")==0 || strcmp(p,"md")==0)
            elenco.posicao=11;
        if(strcmp(p,"ME")==0 || strcmp(p,"me")==0)
            elenco.posicao=12;
        if(strcmp(p,"MA")==0 || strcmp(p,"ma")==0)
            elenco.posicao=13;
        if(strcmp(p,"PD")==0 || strcmp(p,"pd")==0)
            elenco.posicao=14;
        if(strcmp(p,"PE")==0 || strcmp(p,"pe")==0)
            elenco.posicao=15;
        if(strcmp(p,"SA")==0 || strcmp(p,"sa")==0)
            elenco.posicao=16;
        if(strcmp(p,"CA")==0 || strcmp(p,"ca")==0)
            elenco.posicao=17;

        char arqAux[120];
        strcpy(arqAux,time);
        strcat(arqAux,"/auxiliar.dat");

        aux = fopen(arqAux,"wb"); if(aux == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }

        rewind(arqJ);
        fread(&auxJ,sizeof(jogador),1,arqJ);
        while(!feof(arqJ)){
            if(auxJ.uniforme != num_uniforme)
                fwrite(&auxJ,sizeof(jogador),1,arqJ);
            else
                fwrite(&elenco,sizeof(jogador),1,arqJ);
            fread(&auxJ,sizeof(jogador),1,arqJ);
        }
        remove(arqJogadores);
        rename(arqAux,arqJogadores);
    }
    else
    {
        rewind(arqG);
        fread(&auxiliarG, sizeof(goleiro), 1, arqG);
        while((!feof(arqG)) && (auxiliarG.uniforme != num_uniforme)){
            fread(&auxiliarG, sizeof(goleiro), 1, arqG);
        }
        if(auxiliarG.uniforme == num_uniforme)
        {
            goleiros.jogos = auxiliarG.jogos;
            for(j=0;j<100;j++) // zerando os jogos do jogador
                goleiros.jogou[j] = auxiliarG.jogou[j];
            // zerando as medias do jogador
            goleiros.media_assistF = auxiliarG.media_assistF;
            goleiros.media_assistG = auxiliarG.media_assistG;
            goleiros.media_defesas = auxiliarG.media_defesas;
            goleiros.media_perdas = auxiliarG.media_perdas;
            goleiros.media_faltasC = auxiliarG.media_faltasC;
            goleiros.media_faltasS = auxiliarG.media_faltasS;
            goleiros.media_golsC = auxiliarG.media_golsC;
            goleiros.media_golsS = auxiliarG.media_golsS;
            goleiros.media_imped = auxiliarG.media_imped;
            goleiros.media_notas = auxiliarG.media_notas;
            goleiros.media_passesC = auxiliarG.media_passesC;
            goleiros.media_passesE = auxiliarG.media_passesE;
            goleiros.media_penaltisC = auxiliarG.media_penaltisC;
            goleiros.media_penaltisS = auxiliarG.media_penaltisS;
            goleiros.media_penaltisP = auxiliarG.media_penaltisP;
            goleiros.media_penaltisD = auxiliarG.media_penaltisD;
            // zerando o total dos indicadores
            goleiros.total_assistF = auxiliarG.total_assistF;
            goleiros.total_assistG = auxiliarG.total_assistG;
            goleiros.total_defesas = auxiliarG.total_defesas;
            goleiros.total_perdas = auxiliarG.total_perdas;
            goleiros.total_faltasC = auxiliarG.total_faltasC;
            goleiros.total_faltasS = auxiliarG.total_faltasS;
            goleiros.total_golsS = auxiliarG.total_golsS;
            goleiros.total_golsC = auxiliarG.total_golsC;
            goleiros.total_imped = auxiliarG.total_imped;
            goleiros.total_passesC = auxiliarG.total_passesC;
            goleiros.total_passesE = auxiliarG.total_passesE;
            goleiros.total_penaltisC = auxiliarG.total_penaltisC;
            goleiros.total_penaltisS = auxiliarG.total_penaltisS;
            goleiros.total_penaltisP = auxiliarG.total_penaltisP;
            goleiros.total_penaltisD = auxiliarG.total_penaltisD;

            //leitura de dados do jogador
            printf("Nome: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s",goleiros.nome);
            printf("Idade: ");
            scanf("%d",&goleiros.idade);
            printf("Altura: ");
            scanf("%f",&goleiros.altura);
            printf("Peso: ");
            scanf("%f",&goleiros.peso);
            printf("Pe' forte (1. Direito / 2. Esquerdo / 3. Ambos): ");
            scanf("%d",&goleiros.pe);
            while(erro==1)  // loop para verificar se o numero do uniforme já não pertence a outro jogador
            {
                printf("Numero no uniforme: ");
                scanf("%d",&novo_uniforme);
                if(novo_uniforme==num_uniforme) // verifica se o numero de uniforme foi alterado
                {
                    erro=0; // caso não tenha sido alterado
                    break;
                }
                else
                {
                    rewind(arqJ);
                    fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
                    while((!feof(arqJ)) && (auxiliarJ.uniforme != novo_uniforme)){
                        fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
                    }
                    if(auxiliarJ.uniforme == novo_uniforme)
                    {
                        printf("Numero de uniforme ja cadastrado!\n");
                    }
                    else
                    {
                        rewind(arqG);
                        fread(&auxiliarG, sizeof(goleiro), 1, arqG);
                        while((!feof(arqG)) && (auxiliarG.uniforme != novo_uniforme)){
                            fread(&auxiliarG, sizeof(goleiro), 1, arqG);
                        }
                        if(auxiliarG.uniforme == novo_uniforme)
                        {
                            printf("Numero de uniforme ja cadastrado!\n");
                        }
                        else
                        {
                            goleiros.uniforme = novo_uniforme;
                            erro = 0;
                        }
                    }
                }
            }

            char arqAux[120];
            strcpy(arqAux,time);
            strcat(arqAux,"/auxiliar.dat");

            aux = fopen(arqAux,"wb"); if(aux == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }

            rewind(arqG);
            fread(&auxG,sizeof(goleiro),1,arqG);
            while(!feof(arqJ)){
                if(auxG.uniforme != num_uniforme)
                    fwrite(&auxG,sizeof(goleiro),1,aux);
                else
                    fwrite(&goleiros,sizeof(goleiro),1,aux);
                fread(&auxG,sizeof(goleiro),1,arqG);
            }
            remove(arqGoleiros);
            rename(arqAux,arqGoleiros);
        }
        else
        {
            printf("Numero de uniforme nao encontrado!\n");
        }
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

/* Função que exclui o cadastro de um jogador */

int excluir(char *time)
{
    system("cls");
    printf("\tExcluir cadastro de jogador.\n\n");
    int n,i,encontrado=0,novo_uniforme; // variaveis auxiliares
    int num_uniforme=lista_jogadores(time); // chama a função que lista todos os jogadores e retorna o numero do uniforme do escolhido pelo usuario
    if(num_uniforme==0)
        return 0;
    FILE *arqJ;
    FILE *arqG;
    FILE *aux;
    char arqJogadores[120], arqGoleiros[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    jogador elenco, auxiliarJ, auxJ;
    goleiro goleiros, auxiliarG, auxG;
    arqJ = fopen(arqJogadores,"ab+"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqG = fopen(arqGoleiros,"ab+"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    while((!feof(arqJ)) && (auxiliarJ.uniforme != num_uniforme)){
        fread(&auxiliarJ, sizeof(jogador), 1, arqJ);
    }
    if(auxiliarJ.uniforme == num_uniforme)
    {
        char arqAux[120];
        strcpy(arqAux,time);
        strcat(arqAux,"/auxiliar.dat");

        aux = fopen(arqAux,"wb"); if(aux == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }

        rewind(arqJ);
        fread(&auxJ,sizeof(jogador),1,arqJ);
        while(!feof(arqJ)){
            if(auxJ.uniforme != num_uniforme)
                fwrite(&auxJ,sizeof(jogador),1,arqJ);
            fread(&auxJ,sizeof(jogador),1,arqJ);
        }
        remove(arqJogadores);
        rename(arqAux,arqJogadores);
    }
    else
    {
        rewind(arqG);
        fread(&auxiliarG, sizeof(goleiro), 1, arqG);
        while((!feof(arqG)) && (auxiliarG.uniforme != num_uniforme)){
            fread(&auxiliarG, sizeof(goleiro), 1, arqG);
        }
        if(auxiliarG.uniforme == num_uniforme)
        {
            char arqAux[120];
            strcpy(arqAux,time);
            strcat(arqAux,"/auxiliar.dat");

            aux = fopen(arqAux,"wb"); if(aux == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }

            rewind(arqG);
            fread(&auxG,sizeof(goleiro),1,arqG);
            while(!feof(arqJ)){
                if(auxG.uniforme != num_uniforme)
                    fwrite(&auxG,sizeof(goleiro),1,aux);
                fread(&auxG,sizeof(goleiro),1,arqG);
            }
            remove(arqGoleiros);
            rename(arqAux,arqGoleiros);
        }
        else
        {
            printf("Numero de uniforme nao encontrado!\n");
        }
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

/* Função que insere os dados de uma partida */

int inserir_dados(char *time)
{
    system("cls");
    FILE *arqJ;
    FILE *arqG;
    FILE *arqP;
    FILE *auxiliar;
    char arqJogadores[120], arqGoleiros[120], arqPartidas[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    strcpy(arqPartidas,time);
    strcat(arqPartidas,"/jogos.dat");
    char arqAuxiliar[120];
    strcpy(arqAuxiliar,time);
    strcat(arqAuxiliar,"/auxiliar.dat");
    auxiliar = fopen(arqAuxiliar,"wb"); if(auxiliar == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqJ = fopen(arqJogadores,"ab+"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqG = fopen(arqGoleiros,"ab+"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqP = fopen(arqPartidas,"ab+"); if(arqP == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    int i,n,j,num_uniforme,opc; // variaveis auxiliares
    // variaveis dos dados da partida
    partida jogo, auxP;
    goleiro goleiros, auxG;
    jogador elenco, auxJ;
    printf("\tInserir dados de uma partida.\n\n");
    // lendo dados
    printf("Mes do jogo: ");
    scanf("%d",&jogo.mes);
    printf("Dia do jogo: ");
    scanf("%d",&jogo.dia);
    printf("Adversario: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s",jogo.adversario);
    printf("Sigla do adversario (tres letras): ");
    scanf("%s",jogo.sigla_adv);
    printf("Gols feitos: ");
    scanf("%d",&jogo.gols_pro);
    printf("Gols sofridos: ");
    scanf("%d",&jogo.gols_contra);
    printf("Substituicoes feitas na partida: ");
    scanf("%d",&jogo.substituicoes);

    fread(&auxP,sizeof(partida),1,arqP);
    int id = 0;
    while(!feof(arqP)){
        fread(&auxP,sizeof(partida),1,arqP);
        id++;
    }
    jogo.id = id + 1;
    n = jogo.id;
    fwrite(&jogo,sizeof(partida),1,arqP);
    for(i=0;i<11+jogo.substituicoes;i++) // loop que percorre todos os jogadores que jogaram a partida
    {
        printf("\nPara inserir os dados de um jogador na partida, insira o numero de seu uniforme: ");
        scanf("%d",&num_uniforme);
        fread(&goleiros,sizeof(goleiro),1,arqG);
        while((!feof(arqG)) && num_uniforme != goleiros.uniforme){
            fread(&goleiros,sizeof(goleiro),1,arqG);
        }
        if(num_uniforme == goleiros.uniforme)
        {
            printf("Deseja inserir os dados do %s?\t1. Sim.\t2. Nao\n",goleiros.nome);
            scanf("%d",&opc);
            if(opc==1)
            {
                goleiros.jogos++;
                goleiros.jogou[n] = 1;
                printf("Insira os dados do %s\n",goleiros.nome);
                printf("  Defesas: ");
                scanf("%d",&goleiros.defesas[n]);
                goleiros.total_defesas+=goleiros.defesas[n];
                goleiros.media_defesas=media_jogador(goleiros.total_defesas,goleiros.jogos);
                printf("  Passes corretos: ");
                scanf("%d",&goleiros.passesC[n]);
                goleiros.total_passesC+=goleiros.passesC[n];
                goleiros.media_passesC=media_jogador(goleiros.total_passesC,goleiros.jogos);
                printf("  Passes errados: ");
                scanf("%d",&goleiros.passesE[n]);
                goleiros.total_passesE+=goleiros.passesE[n];
                goleiros.media_passesE=media_jogador(goleiros.total_passesE,goleiros.jogos);
                printf("  Perdas de posse: ");
                scanf("%d",&goleiros.perdas[n]);
                goleiros.total_perdas+=goleiros.perdas[n];
                goleiros.media_perdas=media_jogador(goleiros.total_perdas,goleiros.jogos);
                printf("  Gols sofridos: ");
                scanf("%d",&goleiros.golsS[n]);
                goleiros.total_golsS+=goleiros.golsS[n];
                goleiros.media_golsS=media_jogador(goleiros.total_golsS,goleiros.jogos);
                printf("  Gols convertidos: ");
                scanf("%d",&goleiros.golsF[n]);
                goleiros.total_golsF+=goleiros.golsF[n];
                goleiros.media_golsF=media_jogador(goleiros.total_golsF,goleiros.jogos);
                printf("  Gols contra: ");
                scanf("%d",&goleiros.golsC[n]);
                goleiros.total_golsC+=goleiros.golsC[n];
                goleiros.media_golsC=media_jogador(goleiros.total_golsC,goleiros.jogos);
                printf("  Faltas cometidas: ");
                scanf("%d",&goleiros.faltasC[n]);
                goleiros.total_faltasC+=goleiros.faltasC[n];
                goleiros.media_faltasC=media_jogador(goleiros.total_faltasC,goleiros.jogos);
                printf("  Faltas sofridas: ");
                scanf("%d",&goleiros.faltasS[n]);
                goleiros.total_faltasS+=goleiros.faltasS[n];
                goleiros.media_faltasS=media_jogador(goleiros.total_faltasS,goleiros.jogos);
                printf("  Impedimentos: ");
                scanf("%d",&goleiros.imped[n]);
                goleiros.total_imped+=goleiros.imped[n];
                goleiros.media_imped=media_jogador(goleiros.total_imped,goleiros.jogos);
                printf("  Assistencias (gol): ");
                scanf("%d",&goleiros.assistG[n]);
                goleiros.total_assistG+=goleiros.assistG[n];
                goleiros.media_assistG=media_jogador(goleiros.total_assistG,goleiros.jogos);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&goleiros.assistF[n]);
                goleiros.total_assistF+=goleiros.assistF[n];
                goleiros.media_assistF=media_jogador(goleiros.total_assistF,goleiros.jogos);
                printf("  Penaltis cometidos: ");
                scanf("%d",&goleiros.penaltisC[n]);
                goleiros.total_penaltisC+=goleiros.penaltisC[n];
                goleiros.media_penaltisC=media_jogador(goleiros.total_penaltisC,goleiros.jogos);
                printf("  Penaltis sofridos: ");
                scanf("%d",&goleiros.penaltisS[n]);
                goleiros.total_penaltisS+=goleiros.penaltisS[n];
                goleiros.media_penaltisS=media_jogador(goleiros.total_penaltisS,goleiros.jogos);
                printf("  Penaltis defendidos: ");
                scanf("%d",&goleiros.penaltisD[n]);
                goleiros.total_penaltisD+=goleiros.penaltisD[n];
                goleiros.media_penaltisD=media_jogador(goleiros.total_penaltisD,goleiros.jogos);
                printf("  Penaltis perdidos: ");
                scanf("%d",&goleiros.penaltisP[n]);
                goleiros.total_penaltisP+=goleiros.penaltisP[n];
                goleiros.media_penaltisP=media_jogador(goleiros.total_penaltisP,goleiros.jogos);

                goleiros.notas[n]=pontuacao(goleiros.uniforme, n, time);
                goleiros.media_notas=media_jogadorN(goleiros.uniforme, time);

                rewind(arqG);
                fread(&auxG,sizeof(goleiro),1,arqG);
                while((!feof(arqG))){
                    if(num_uniforme == auxG.uniforme)
                    {
                        fwrite(&goleiros,sizeof(goleiro),1,auxiliar);
                    }
                    else
                    {
                        fwrite(&auxG,sizeof(goleiro),1,auxiliar);
                    }
                    fread(&auxG,sizeof(goleiro),1,arqG);
                }
                fclose(arqG);
                fclose(auxiliar);
                remove(arqGoleiros);
                rename(arqAuxiliar, arqGoleiros);

                arqG = fopen(arqGoleiros,"ab+"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
                auxiliar = fopen(arqAuxiliar,"rb"); if(auxiliar == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }

            }
            else
            {
                i--;
            }
        }
        else
        {
            fread(&elenco,sizeof(jogador),1,arqJ);
            while((!feof(arqJ)) && num_uniforme != elenco.uniforme){
                fread(&elenco,sizeof(jogador),1,arqJ);
            }
            if(num_uniforme == elenco.uniforme)
            {
                char pos[4];
                printf("Deseja inserir os dados do %s?\t1. Sim.\t2. Nao\n",elenco.nome);
                scanf("%d",&opc);
                if(opc==1)
                {
                    elenco.jogos++;
                    elenco.jogou[n]=1;
                    printf("Insira os dados do %s\n",elenco.nome);
                    printf("  Sigla da posicao inicial na partida: ");
                    scanf("%s",&pos);
                    if(strcmp(pos,"ZD")==0 || strcmp(pos,"zd")==0)
                        elenco.pos[n]=1;
                    if(strcmp(pos,"ZE")==0 || strcmp(pos,"ze")==0)
                        elenco.pos[n]=2;
                    if(strcmp(pos,"ZC")==0 || strcmp(pos,"zc")==0)
                        elenco.pos[n]=3;
                    if(strcmp(pos,"LDD")==0 || strcmp(pos,"ldd")==0)
                        elenco.pos[n]=4;
                    if(strcmp(pos,"LED")==0 || strcmp(pos,"led")==0)
                        elenco.pos[n]=5;
                    if(strcmp(pos,"LDO")==0 || strcmp(pos,"ldo")==0)
                        elenco.pos[n]=6;
                    if(strcmp(pos,"LEO")==0 || strcmp(pos,"leo")==0)
                        elenco.pos[n]=7;
                    if(strcmp(pos,"PV")==0 || strcmp(pos,"pv")==0)
                        elenco.pos[n]=8;
                    if(strcmp(pos,"SV")==0 || strcmp(pos,"sv")==0)
                        elenco.pos[n]=9;
                    if(strcmp(pos,"ARM")==0 || strcmp(pos,"arm")==0)
                        elenco.pos[n]=10;
                    if(strcmp(pos,"MD")==0 || strcmp(pos,"md")==0)
                        elenco.pos[n]=11;
                    if(strcmp(pos,"ME")==0 || strcmp(pos,"me")==0)
                        elenco.pos[n]=12;
                    if(strcmp(pos,"MA")==0 || strcmp(pos,"ma")==0)
                        elenco.pos[n]=13;
                    if(strcmp(pos,"PD")==0 || strcmp(pos,"pd")==0)
                        elenco.pos[n]=14;
                    if(strcmp(pos,"PE")==0 || strcmp(pos,"pe")==0)
                        elenco.pos[n]=15;
                    if(strcmp(pos,"SA")==0 || strcmp(pos,"sa")==0)
                        elenco.pos[n]=16;
                    if(strcmp(pos,"CA")==0 || strcmp(pos,"ca")==0)
                        elenco.pos[n]=17;
                    printf("  Passes corretos: ");
                    scanf("%d",&elenco.passesC[n]);
                    elenco.total_passesC+=elenco.passesC[n];
                    elenco.media_passesC=media_jogador(elenco.total_passesC,elenco.jogos);
                    printf("  Passes errados: ");
                    scanf("%d",&elenco.passesE[n]);
                    elenco.total_passesE+=elenco.passesE[n];
                    elenco.media_passesE=media_jogador(elenco.total_passesE,elenco.jogos);
                    printf("  Finalizacoes corretas: ");
                    scanf("%d",&elenco.finalizacoesC[n]);
                    elenco.total_finalizacoesC+=elenco.finalizacoesC[n];
                    elenco.media_finalizacoesC=media_jogador(elenco.total_finalizacoesC,elenco.jogos);
                    printf("  Finalizacoes erradas: ");
                    scanf("%d",&elenco.finalizacoesE[n]);
                    elenco.total_finalizacoesE+=elenco.finalizacoesE[n];
                    elenco.media_finalizacoesE=media_jogador(elenco.total_finalizacoesE,elenco.jogos);
                    printf("  Desarmes: ");
                    scanf("%d",&elenco.desarmes[n]);
                    elenco.total_desarmes+=elenco.desarmes[n];
                    elenco.media_desarmes=media_jogador(elenco.total_desarmes,elenco.jogos);
                    printf("  Perdas de posse: ");
                    scanf("%d",&elenco.perdas[n]);
                    elenco.total_perdas+=elenco.perdas[n];
                    elenco.media_perdas=media_jogador(elenco.total_perdas,elenco.jogos);
                    printf("  Gols: ");
                    scanf("%d",&elenco.gols[n]);
                    elenco.total_gols+=elenco.gols[n];
                    elenco.media_gols=media_jogador(elenco.total_gols,elenco.jogos);
                    printf("  Gols contra: ");
                    scanf("%d",&elenco.golsC[n]);
                    elenco.total_golsC+=elenco.golsC[n];
                    elenco.media_golsC=media_jogador(elenco.total_golsC,elenco.jogos);
                    printf("  Faltas cometidas: ");
                    scanf("%d",&elenco.faltasC[n]);
                    elenco.total_faltasC+=elenco.faltasC[n];
                    elenco.media_faltasC=media_jogador(elenco.total_faltasC,elenco.jogos);
                    printf("  Faltas sofridas: ");
                    scanf("%d",&elenco.faltasS[n]);
                    elenco.total_faltasS+=elenco.faltasS[n];
                    elenco.media_faltasS=media_jogador(elenco.total_faltasS,elenco.jogos);
                    printf("  Impedimentos: ");
                    scanf("%d",&elenco.imped[n]);
                    elenco.total_imped+=elenco.imped[n];
                    elenco.media_imped=media_jogador(elenco.total_imped,elenco.jogos);
                    printf("  Assistencias (gol): ");
                    scanf("%d",&elenco.assistG[n]);
                    elenco.total_assistG+=elenco.assistG[n];
                    elenco.media_assistG=media_jogador(elenco.total_assistG,elenco.jogos);
                    printf("  Assistencias (finalizacao): ");
                    scanf("%d",&elenco.assistF[n]);
                    elenco.total_assistF+=elenco.assistF[n];
                    elenco.media_assistF=media_jogador(elenco.total_assistF,elenco.jogos);
                    printf("  Penaltis cometidos: ");
                    scanf("%d",&elenco.penaltisC[n]);
                    elenco.total_penaltisC+=elenco.penaltisC[n];
                    elenco.media_penaltisC=media_jogador(elenco.total_penaltisC,elenco.jogos);
                    printf("  Penaltis sofridos: ");
                    scanf("%d",&elenco.penaltisS[n]);
                    elenco.total_penaltisS+=elenco.penaltisS[n];
                    elenco.media_penaltisS=media_jogador(elenco.total_penaltisS,elenco.jogos);
                    printf("  Penaltis perdidos: ");
                    scanf("%d",&elenco.penaltisP[n]);
                    elenco.total_penaltisP+=elenco.penaltisP[n];
                    elenco.media_penaltisP=media_jogador(elenco.total_penaltisP,elenco.jogos);

                    elenco.notas[n]=pontuacao(elenco.uniforme, n, time);
                    elenco.media_notas=media_jogadorN(elenco.uniforme, time);

                    rewind(arqJ);
                    fread(&auxJ,sizeof(jogador),1,arqJ);
                    while((!feof(arqJ))){
                        if(num_uniforme == auxJ.uniforme)
                        {
                            fwrite(&elenco,sizeof(jogador),1,auxiliar);
                        }
                        else
                        {
                            fwrite(&auxJ,sizeof(jogador),1,auxiliar);
                        }
                        fread(&auxJ,sizeof(jogador),1,arqJ);
                    }
                    fclose(arqJ);
                    fclose(auxiliar);
                    remove(arqJogadores);
                    rename(arqAuxiliar, arqJogadores);

                    arqJ = fopen(arqJogadores,"ab+"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
                    auxiliar = fopen(arqAuxiliar,"rb"); if(auxiliar == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
                }
                else
                {
                    i--;
                }
            }
            else
            {
                printf("\tDigite o numero de um jogador cadastrado!\n");
                i--;
            }
        }
    }
    printf("\n");
    fclose(arqJ);
    fclose(arqG);
    fclose(arqP);
    fclose(auxiliar);
    system("PAUSE");
    return 0;
}

/* Funcao que edita os dados de uma partida */

int editar_dados(char *time)
{
    system("cls");
    printf("\tEditar dados de uma partida.\n\n");
    int n=lista_jogos(time);
    if(n<0)
        return 0;
    FILE *arqJ;
    FILE *arqG;
    FILE *arqP;
    FILE *auxiliar;
    char arqJogadores[120], arqGoleiros[120], arqPartidas[120], arqAuxiliar[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    strcpy(arqPartidas,time);
    strcat(arqPartidas,"/jogos.dat");
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqAuxiliar,time);
    strcat(arqAuxiliar,"/auxiliar.dat");
    arqJ = fopen(arqJogadores,"ab+"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqG = fopen(arqGoleiros,"ab+"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqP = fopen(arqPartidas,"ab+"); if(arqP == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    auxiliar = fopen(arqAuxiliar,"wb"); if(auxiliar == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    int i,j,num_uniforme,opc; // variaveis auxiliares
    // variaveis dos dados da partida
    partida jogo, auxP;
    goleiro goleiros, auxG;
    jogador elenco, auxJ;
    // zerando os dados da partida
    fread(&goleiros,sizeof(goleiro),1,arqG);
    while(!feof(arqG)){
        if(goleiros.jogou[n] == 1){
            goleiros.jogos--;
            goleiros.jogou[n]=0;
            goleiros.total_defesas-=goleiros.defesas[n];
            goleiros.media_defesas=media_jogador(goleiros.total_defesas,goleiros.jogos);
            goleiros.total_perdas-=goleiros.perdas[n];
            goleiros.media_perdas=media_jogador(goleiros.total_perdas,goleiros.jogos);
            goleiros.total_imped-=goleiros.imped[n];
            goleiros.media_imped=media_jogador(goleiros.total_imped,goleiros.jogos);
            goleiros.total_assistF-=goleiros.assistF[n];
            goleiros.media_assistF=media_jogador(goleiros.total_assistF,goleiros.jogos);
            goleiros.total_assistG-=goleiros.assistG[n];
            goleiros.media_assistG=media_jogador(goleiros.total_assistG,goleiros.jogos);
            goleiros.total_passesC-=goleiros.passesC[n];
            goleiros.media_passesC=media_jogador(goleiros.total_passesC,goleiros.jogos);
            goleiros.total_passesE-=goleiros.passesE[n];
            goleiros.media_passesE=media_jogador(goleiros.total_passesE,goleiros.jogos);
            goleiros.total_golsF-=goleiros.golsF[n];
            goleiros.media_golsF=media_jogador(goleiros.total_golsF,goleiros.jogos);
            goleiros.total_golsC-=goleiros.golsC[n];
            goleiros.media_golsC=media_jogador(goleiros.total_golsC,goleiros.jogos);
            goleiros.total_golsS-=goleiros.golsS[n];
            goleiros.media_golsS=media_jogador(goleiros.total_golsS,goleiros.jogos);
            goleiros.total_faltasC-=goleiros.faltasC[n];
            goleiros.media_faltasC=media_jogador(goleiros.total_faltasC,goleiros.jogos);
            goleiros.total_faltasS-=goleiros.faltasS[n];
            goleiros.media_faltasS=media_jogador(goleiros.total_faltasS,goleiros.jogos);
            goleiros.total_penaltisC-=goleiros.penaltisC[n];
            goleiros.media_penaltisC=media_jogador(goleiros.total_penaltisC,goleiros.jogos);
            goleiros.total_penaltisP-=goleiros.penaltisP[n];
            goleiros.media_penaltisP=media_jogador(goleiros.total_penaltisP,goleiros.jogos);
            goleiros.total_penaltisS-=goleiros.penaltisS[n];
            goleiros.media_penaltisS=media_jogador(goleiros.total_penaltisS,goleiros.jogos);
            goleiros.total_penaltisD-=goleiros.penaltisD[n];
            goleiros.media_penaltisD=media_jogador(goleiros.total_penaltisD,goleiros.jogos);
            goleiros.media_notas=media_jogadorN(goleiros.uniforme, time);
        }
        goleiros.passesC[n]=0;
        goleiros.passesE[n]=0;
        goleiros.golsC[n]=0;
        goleiros.golsS[n]=0;
        goleiros.golsF[n]=0;
        goleiros.perdas[n]=0;
        goleiros.defesas[n]=0;
        goleiros.imped[n]=0;
        goleiros.assistF[n]=0;
        goleiros.assistG[n]=0;
        goleiros.faltasC[n]=0;
        goleiros.faltasS[n]=0;
        goleiros.penaltisC[n]=0;
        goleiros.penaltisP[n]=0;
        goleiros.penaltisS[n]=0;
        goleiros.notas[n]=0;

        fwrite(&goleiros,sizeof(goleiro),1,auxiliar);
        fread(&goleiros,sizeof(goleiro),1,arqG);
    }
    fclose(auxiliar);
    fclose(arqG);
    remove(arqGoleiros);
    rename(arqAuxiliar,arqGoleiros);

    arqG = fopen(arqGoleiros,"ab+"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    auxiliar = fopen(arqAuxiliar,"wb"); if(auxiliar == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }

    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        if(elenco.jogou[n] == 1){
            elenco.jogos--;
            elenco.jogou[n]=0;
            elenco.total_passesC-=elenco.passesC[n];
            elenco.media_passesC=media_jogador(elenco.total_passesC,elenco.jogos);
            elenco.total_passesE-=elenco.passesE[n];
            elenco.media_passesE=media_jogador(elenco.total_passesE,elenco.jogos);
            elenco.total_gols-=elenco.gols[n];
            elenco.media_gols=media_jogador(elenco.total_gols,elenco.jogos);
            elenco.total_golsC-=elenco.golsC[n];
            elenco.media_golsC=media_jogador(elenco.total_golsC,elenco.jogos);
            elenco.total_finalizacoesC-=elenco.finalizacoesC[n];
            elenco.media_finalizacoesC=media_jogador(elenco.total_finalizacoesC,elenco.jogos);
            elenco.total_finalizacoesE-=elenco.finalizacoesE[n];
            elenco.media_finalizacoesE=media_jogador(elenco.total_finalizacoesE,elenco.jogos);
            elenco.total_desarmes-=elenco.desarmes[n];
            elenco.media_desarmes=media_jogador(elenco.total_desarmes,elenco.jogos);
            elenco.total_perdas-=elenco.perdas[n];
            elenco.media_perdas=media_jogador(elenco.total_perdas,elenco.jogos);
            elenco.total_imped-=elenco.imped[n];
            elenco.media_imped=media_jogador(elenco.total_imped,elenco.jogos);
            elenco.total_assistF-=elenco.assistF[n];
            elenco.media_assistF=media_jogador(elenco.total_assistF,elenco.jogos);
            elenco.total_assistG-=elenco.assistG[n];
            elenco.media_assistG=media_jogador(elenco.total_assistG,elenco.jogos);
            elenco.total_faltasC-=elenco.faltasC[n];
            elenco.media_faltasC=media_jogador(elenco.total_faltasC,elenco.jogos);
            elenco.total_faltasS-=elenco.faltasS[n];
            elenco.media_faltasS=media_jogador(elenco.total_faltasS,elenco.jogos);
            elenco.total_penaltisC-=elenco.penaltisC[n];
            elenco.media_penaltisC=media_jogador(elenco.total_penaltisC,elenco.jogos);
            elenco.total_penaltisP-=elenco.penaltisP[n];
            elenco.media_penaltisP=media_jogador(elenco.total_penaltisP,elenco.jogos);
            elenco.total_penaltisS-=elenco.penaltisS[n];
            elenco.media_penaltisS=media_jogador(elenco.total_penaltisS,elenco.jogos);
            elenco.media_notas=media_jogadorN(elenco.uniforme, time);
        }
        elenco.passesC[n]=0;
        elenco.passesE[n]=0;
        elenco.gols[n]=0;
        elenco.golsC[n]=0;
        elenco.finalizacoesC[n]=0;
        elenco.finalizacoesE[n]=0;
        elenco.desarmes[n]=0;
        elenco.perdas[n]=0;
        elenco.imped[n]=0;
        elenco.assistF[n]=0;
        elenco.assistG[n]=0;
        elenco.faltasC[n]=0;
        elenco.faltasS[n]=0;
        elenco.penaltisC[n]=0;
        elenco.penaltisP[n]=0;
        elenco.penaltisS[n]=0;
        elenco.notas[n]=0;
        elenco.pos[n]=0;

        fwrite(&elenco,sizeof(jogador),1,auxiliar);
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    fclose(auxiliar);
    fclose(arqJ);
    remove(arqJogadores);
    rename(arqAuxiliar,arqJogadores);

    arqJ = fopen(arqJogadores,"ab+"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    auxiliar = fopen(arqAuxiliar,"wb"); if(auxiliar == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }

    // atualizando dados da partida
    printf("Mes do jogo: ");
    scanf("%d",&jogo.mes);
    printf("Dia do jogo: ");
    scanf("%d",&jogo.dia);
    printf("Adversario: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s",jogo.adversario);
    printf("Sigla do adversario (tres letras): ");
    scanf("%s",jogo.sigla_adv);
    printf("Gols feitos: ");
    scanf("%d",&jogo.gols_pro);
    printf("Gols sofridos: ");
    scanf("%d",&jogo.gols_contra);
    printf("Substituicoes feitas na partida: ");
    scanf("%d",&jogo.substituicoes);
    jogo.id = n;

    fread(&auxP,sizeof(partida),1,arqP);
    while(!feof(arqP)){
        if(auxP.id == jogo.id)
        {
            fwrite(&jogo,sizeof(partida),1,auxiliar);
        }
        else
        {
            fwrite(&auxP,sizeof(partida),1,auxiliar);
        }
        fread(&auxP,sizeof(partida),1,arqP);
    }
    fclose(auxiliar);
    fclose(arqP);
    remove(arqPartidas);
    rename(arqAuxiliar,arqPartidas);

    auxiliar = fopen(arqAuxiliar,"wb"); if(auxiliar == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }

    for(i=0;i<11+jogo.substituicoes;i++) // loop que percorre todos os jogadores que jogaram a partida
    {
        printf("\nPara inserir os dados de um jogador na partida, insira o numero de seu uniforme: ");
        scanf("%d",&num_uniforme);
        fread(&goleiros,sizeof(goleiro),1,arqG);
        while((!feof(arqG)) && num_uniforme != goleiros.uniforme){
            fread(&goleiros,sizeof(goleiro),1,arqG);
        }
        if(num_uniforme == goleiros.uniforme)
        {
            printf("Deseja inserir os dados do %s?\t1. Sim.\t2. Nao\n",goleiros.nome);
            scanf("%d",&opc);
            if(opc==1)
            {
                goleiros.jogos++;
                goleiros.jogou[n] = 1;
                printf("Insira os dados do %s\n",goleiros.nome);
                printf("  Defesas: ");
                scanf("%d",&goleiros.defesas[n]);
                goleiros.total_defesas+=goleiros.defesas[n];
                goleiros.media_defesas=media_jogador(goleiros.total_defesas,goleiros.jogos);
                printf("  Passes corretos: ");
                scanf("%d",&goleiros.passesC[n]);
                goleiros.total_passesC+=goleiros.passesC[n];
                goleiros.media_passesC=media_jogador(goleiros.total_passesC,goleiros.jogos);
                printf("  Passes errados: ");
                scanf("%d",&goleiros.passesE[n]);
                goleiros.total_passesE+=goleiros.passesE[n];
                goleiros.media_passesE=media_jogador(goleiros.total_passesE,goleiros.jogos);
                printf("  Perdas de posse: ");
                scanf("%d",&goleiros.perdas[n]);
                goleiros.total_perdas+=goleiros.perdas[n];
                goleiros.media_perdas=media_jogador(goleiros.total_perdas,goleiros.jogos);
                printf("  Gols sofridos: ");
                scanf("%d",&goleiros.golsS[n]);
                goleiros.total_golsS+=goleiros.golsS[n];
                goleiros.media_golsS=media_jogador(goleiros.total_golsS,goleiros.jogos);
                printf("  Gols convertidos: ");
                scanf("%d",&goleiros.golsF[n]);
                goleiros.total_golsF+=goleiros.golsF[n];
                goleiros.media_golsF=media_jogador(goleiros.total_golsF,goleiros.jogos);
                printf("  Gols contra: ");
                scanf("%d",&goleiros.golsC[n]);
                goleiros.total_golsC+=goleiros.golsC[n];
                goleiros.media_golsC=media_jogador(goleiros.total_golsC,goleiros.jogos);
                printf("  Faltas cometidas: ");
                scanf("%d",&goleiros.faltasC[n]);
                goleiros.total_faltasC+=goleiros.faltasC[n];
                goleiros.media_faltasC=media_jogador(goleiros.total_faltasC,goleiros.jogos);
                printf("  Faltas sofridas: ");
                scanf("%d",&goleiros.faltasS[n]);
                goleiros.total_faltasS+=goleiros.faltasS[n];
                goleiros.media_faltasS=media_jogador(goleiros.total_faltasS,goleiros.jogos);
                printf("  Impedimentos: ");
                scanf("%d",&goleiros.imped[n]);
                goleiros.total_imped+=goleiros.imped[n];
                goleiros.media_imped=media_jogador(goleiros.total_imped,goleiros.jogos);
                printf("  Assistencias (gol): ");
                scanf("%d",&goleiros.assistG[n]);
                goleiros.total_assistG+=goleiros.assistG[n];
                goleiros.media_assistG=media_jogador(goleiros.total_assistG,goleiros.jogos);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&goleiros.assistF[n]);
                goleiros.total_assistF+=goleiros.assistF[n];
                goleiros.media_assistF=media_jogador(goleiros.total_assistF,goleiros.jogos);
                printf("  Penaltis cometidos: ");
                scanf("%d",&goleiros.penaltisC[n]);
                goleiros.total_penaltisC+=goleiros.penaltisC[n];
                goleiros.media_penaltisC=media_jogador(goleiros.total_penaltisC,goleiros.jogos);
                printf("  Penaltis sofridos: ");
                scanf("%d",&goleiros.penaltisS[n]);
                goleiros.total_penaltisS+=goleiros.penaltisS[n];
                goleiros.media_penaltisS=media_jogador(goleiros.total_penaltisS,goleiros.jogos);
                printf("  Penaltis defendidos: ");
                scanf("%d",&goleiros.penaltisD[n]);
                goleiros.total_penaltisD+=goleiros.penaltisD[n];
                goleiros.media_penaltisD=media_jogador(goleiros.total_penaltisD,goleiros.jogos);
                printf("  Penaltis perdidos: ");
                scanf("%d",&goleiros.penaltisP[n]);
                goleiros.total_penaltisP+=goleiros.penaltisP[n];
                goleiros.media_penaltisP=media_jogador(goleiros.total_penaltisP,goleiros.jogos);

                goleiros.notas[n]=pontuacao(goleiros.uniforme, n, time);
                goleiros.media_notas=media_jogadorN(goleiros.uniforme, time);

                rewind(arqG);
                fread(&auxG,sizeof(goleiro),1,arqG);
                while((!feof(arqG))){
                    if(num_uniforme == auxG.uniforme)
                    {
                        fwrite(&goleiros,sizeof(goleiro),1,auxiliar);
                    }
                    else
                    {
                        fwrite(&auxG,sizeof(goleiro),1,auxiliar);
                    }
                    fread(&auxG,sizeof(goleiro),1,arqG);
                }
                fclose(arqG);
                fclose(auxiliar);
                remove(arqGoleiros);
                rename(arqAuxiliar, arqGoleiros);

                arqG = fopen(arqGoleiros,"ab+"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
                auxiliar = fopen(arqAuxiliar,"rb"); if(auxiliar == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }

            }
            else
            {
                i--;
            }
        }
        else
        {
            fread(&elenco,sizeof(jogador),1,arqJ);
            while((!feof(arqJ)) && num_uniforme != elenco.uniforme){
                fread(&elenco,sizeof(jogador),1,arqJ);
            }
            if(num_uniforme == elenco.uniforme)
            {
                char pos[4];
                printf("Deseja inserir os dados do %s?\t1. Sim.\t2. Nao\n",elenco.nome);
                scanf("%d",&opc);
                if(opc==1)
                {
                    elenco.jogos++;
                    elenco.jogou[n]=1;
                    printf("Insira os dados do %s\n",elenco.nome);
                    printf("  Sigla da posicao inicial na partida: ");
                    scanf("%s",&pos);
                    if(strcmp(pos,"ZD")==0 || strcmp(pos,"zd")==0)
                        elenco.pos[n]=1;
                    if(strcmp(pos,"ZE")==0 || strcmp(pos,"ze")==0)
                        elenco.pos[n]=2;
                    if(strcmp(pos,"ZC")==0 || strcmp(pos,"zc")==0)
                        elenco.pos[n]=3;
                    if(strcmp(pos,"LDD")==0 || strcmp(pos,"ldd")==0)
                        elenco.pos[n]=4;
                    if(strcmp(pos,"LED")==0 || strcmp(pos,"led")==0)
                        elenco.pos[n]=5;
                    if(strcmp(pos,"LDO")==0 || strcmp(pos,"ldo")==0)
                        elenco.pos[n]=6;
                    if(strcmp(pos,"LEO")==0 || strcmp(pos,"leo")==0)
                        elenco.pos[n]=7;
                    if(strcmp(pos,"PV")==0 || strcmp(pos,"pv")==0)
                        elenco.pos[n]=8;
                    if(strcmp(pos,"SV")==0 || strcmp(pos,"sv")==0)
                        elenco.pos[n]=9;
                    if(strcmp(pos,"ARM")==0 || strcmp(pos,"arm")==0)
                        elenco.pos[n]=10;
                    if(strcmp(pos,"MD")==0 || strcmp(pos,"md")==0)
                        elenco.pos[n]=11;
                    if(strcmp(pos,"ME")==0 || strcmp(pos,"me")==0)
                        elenco.pos[n]=12;
                    if(strcmp(pos,"MA")==0 || strcmp(pos,"ma")==0)
                        elenco.pos[n]=13;
                    if(strcmp(pos,"PD")==0 || strcmp(pos,"pd")==0)
                        elenco.pos[n]=14;
                    if(strcmp(pos,"PE")==0 || strcmp(pos,"pe")==0)
                        elenco.pos[n]=15;
                    if(strcmp(pos,"SA")==0 || strcmp(pos,"sa")==0)
                        elenco.pos[n]=16;
                    if(strcmp(pos,"CA")==0 || strcmp(pos,"ca")==0)
                        elenco.pos[n]=17;
                    printf("  Passes corretos: ");
                    scanf("%d",&elenco.passesC[n]);
                    elenco.total_passesC+=elenco.passesC[n];
                    elenco.media_passesC=media_jogador(elenco.total_passesC,elenco.jogos);
                    printf("  Passes errados: ");
                    scanf("%d",&elenco.passesE[n]);
                    elenco.total_passesE+=elenco.passesE[n];
                    elenco.media_passesE=media_jogador(elenco.total_passesE,elenco.jogos);
                    printf("  Finalizacoes corretas: ");
                    scanf("%d",&elenco.finalizacoesC[n]);
                    elenco.total_finalizacoesC+=elenco.finalizacoesC[n];
                    elenco.media_finalizacoesC=media_jogador(elenco.total_finalizacoesC,elenco.jogos);
                    printf("  Finalizacoes erradas: ");
                    scanf("%d",&elenco.finalizacoesE[n]);
                    elenco.total_finalizacoesE+=elenco.finalizacoesE[n];
                    elenco.media_finalizacoesE=media_jogador(elenco.total_finalizacoesE,elenco.jogos);
                    printf("  Desarmes: ");
                    scanf("%d",&elenco.desarmes[n]);
                    elenco.total_desarmes+=elenco.desarmes[n];
                    elenco.media_desarmes=media_jogador(elenco.total_desarmes,elenco.jogos);
                    printf("  Perdas de posse: ");
                    scanf("%d",&elenco.perdas[n]);
                    elenco.total_perdas+=elenco.perdas[n];
                    elenco.media_perdas=media_jogador(elenco.total_perdas,elenco.jogos);
                    printf("  Gols: ");
                    scanf("%d",&elenco.gols[n]);
                    elenco.total_gols+=elenco.gols[n];
                    elenco.media_gols=media_jogador(elenco.total_gols,elenco.jogos);
                    printf("  Gols contra: ");
                    scanf("%d",&elenco.golsC[n]);
                    elenco.total_golsC+=elenco.golsC[n];
                    elenco.media_golsC=media_jogador(elenco.total_golsC,elenco.jogos);
                    printf("  Faltas cometidas: ");
                    scanf("%d",&elenco.faltasC[n]);
                    elenco.total_faltasC+=elenco.faltasC[n];
                    elenco.media_faltasC=media_jogador(elenco.total_faltasC,elenco.jogos);
                    printf("  Faltas sofridas: ");
                    scanf("%d",&elenco.faltasS[n]);
                    elenco.total_faltasS+=elenco.faltasS[n];
                    elenco.media_faltasS=media_jogador(elenco.total_faltasS,elenco.jogos);
                    printf("  Impedimentos: ");
                    scanf("%d",&elenco.imped[n]);
                    elenco.total_imped+=elenco.imped[n];
                    elenco.media_imped=media_jogador(elenco.total_imped,elenco.jogos);
                    printf("  Assistencias (gol): ");
                    scanf("%d",&elenco.assistG[n]);
                    elenco.total_assistG+=elenco.assistG[n];
                    elenco.media_assistG=media_jogador(elenco.total_assistG,elenco.jogos);
                    printf("  Assistencias (finalizacao): ");
                    scanf("%d",&elenco.assistF[n]);
                    elenco.total_assistF+=elenco.assistF[n];
                    elenco.media_assistF=media_jogador(elenco.total_assistF,elenco.jogos);
                    printf("  Penaltis cometidos: ");
                    scanf("%d",&elenco.penaltisC[n]);
                    elenco.total_penaltisC+=elenco.penaltisC[n];
                    elenco.media_penaltisC=media_jogador(elenco.total_penaltisC,elenco.jogos);
                    printf("  Penaltis sofridos: ");
                    scanf("%d",&elenco.penaltisS[n]);
                    elenco.total_penaltisS+=elenco.penaltisS[n];
                    elenco.media_penaltisS=media_jogador(elenco.total_penaltisS,elenco.jogos);
                    printf("  Penaltis perdidos: ");
                    scanf("%d",&elenco.penaltisP[n]);
                    elenco.total_penaltisP+=elenco.penaltisP[n];
                    elenco.media_penaltisP=media_jogador(elenco.total_penaltisP,elenco.jogos);

                    elenco.notas[n]=pontuacao(elenco.uniforme, n, time);
                    elenco.media_notas=media_jogadorN(elenco.uniforme, time);

                    rewind(arqJ);
                    fread(&auxJ,sizeof(jogador),1,arqJ);
                    while((!feof(arqJ))){
                        if(num_uniforme == auxJ.uniforme)
                        {
                            fwrite(&elenco,sizeof(jogador),1,auxiliar);
                        }
                        else
                        {
                            fwrite(&auxJ,sizeof(jogador),1,auxiliar);
                        }
                        fread(&auxJ,sizeof(jogador),1,arqJ);
                    }
                    fclose(arqJ);
                    fclose(auxiliar);
                    remove(arqJogadores);
                    rename(arqAuxiliar, arqJogadores);

                    arqJ = fopen(arqJogadores,"ab+"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
                    auxiliar = fopen(arqAuxiliar,"rb"); if(auxiliar == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
                }
                else
                {
                    i--;
                }
            }
            else
            {
                printf("\tDigite o numero de um jogador cadastrado!\n");
                i--;
            }
        }
    }
    printf("\n");
    fclose(arqJ);
    fclose(arqG);
    fclose(auxiliar);
    system("PAUSE");
    return 0;
}

/* Funcao que exibe as estatisticas de um jogador */

int estatisticas_jogador(char *time)
{
    system("cls");
    printf("\tEstatisticas de um jogador.\n\n");
    int num_uniforme=lista_jogadores(time); // pedindo para o usuario escolher um jogador para ver as estatisticas
    if(num_uniforme==0)
        return 0;
    FILE *arqJ;
    FILE *arqG;
    char arqJogadores[120], arqGoleiros[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    arqJ = fopen(arqJogadores,"rb"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqG = fopen(arqGoleiros,"rb"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    jogador elenco;
    goleiro goleiros;
    int opc; // variavel auxiliar
    fread(&goleiros,sizeof(goleiro),1,arqG);
    while((!feof(arqG)) && num_uniforme != goleiros.uniforme){
        fread(&goleiros,sizeof(goleiro),1,arqG);
    }
    if(num_uniforme == goleiros.uniforme)
    {
        system("cls");
        printf("\tEstatisticas do %s\n\n",goleiros.nome);
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
                jogador_dados(num_uniforme, time); // chama a função que mostra os dados gerais de um goleiro
                break;

            case 2:
                goleiro_Gols(num_uniforme, time); // chama a função que mostra as estatisticas de gols do goleiro
                break;

            case 3:
                jogador_PeA(num_uniforme, time); // chama a função que mostra as estatisticas de passes e assistencias do goleiro
                break;

            case 4:
                jogador_DeG(num_uniforme, time); // chama a função que mostra as estatisticas de defesas e gols sofridos do goleiro
                break;

            case 5:
                jogador_FeP(num_uniforme, time); // chama a função que mostra as estatisticas de faltas e penaltis do goleiro
                break;

            case 6:
                jogador_Imp(num_uniforme, time); // chama a função que mostra as estatisticas de impedimentos do goleiro
                break;

            case 7:
                jogador_notas(num_uniforme, time); // chama a função que mostra as estatisticas de notas do goleiro
                break;

            case 0:
                return 0; // retorna ao menu inicial

            default:
                printf("Opcao invalida!\n");
        }
    }
    else
    {
        fread(&elenco,sizeof(jogador),1,arqJ);
        while((!feof(arqJ)) && num_uniforme != elenco.uniforme){
            fread(&elenco,sizeof(jogador),1,arqJ);
        }
        if(num_uniforme == elenco.uniforme)
        {
            system("cls");
            printf("\tEstatisticas do %s\n\n",elenco.nome);
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
                    jogador_dados(num_uniforme, time); // chama a função que mostra os dados gerais do jogador
                    break;

                case 2:
                    jogador_GeF(num_uniforme, time); // chama a função que mostra as estatisticas de gols e finalizacoes do jogador
                    break;

                case 3:
                    jogador_PeA(num_uniforme, time); // chama a função que mostra as estatisticas de passes e assistencias do jogador
                    break;

                case 4:
                    jogador_DeP(num_uniforme, time); // chama a função que mostra as estatisticas de desarmes do jogador
                    break;

                case 5:
                    jogador_FeP(num_uniforme, time); // chama a função que mostra as estatisticas de faltas e penaltis do jogador
                    break;

                case 6:
                    jogador_Imp(num_uniforme, time); // chama a função que mostra as estatisticas de impedimentos do jogador
                    break;

                case 7:
                    jogador_notas(num_uniforme, time); // chama a função que mostra as estatisticas de notas do jogador
                    break;

                case 0:
                    return 0; // retorna ao menu inicial

                default:
                    printf("Opcao invalida!\n");
            }
        }
        else
        {
            printf("Numero de uniforme nao encontrado!\n");
            system("pause");
        }
    }

    return 0;
}

/* Funcao que exibe as estatisticas do grupo */

int estatisticas_grupo(char *time)
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
            melhor_escalacao(time);
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

int lista_jogadores(char *time)
{
    FILE *arqJ;
    FILE *arqG;
    char arqJogadores[120], arqGoleiros[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    jogador elenco, auxiliarJ;
    goleiro goleiros, auxiliarG;
    arqJ = fopen(arqJogadores,"rb"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqG = fopen(arqGoleiros,"rb"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    fread(&auxiliarG,sizeof(goleiro),1,arqG);
    while((!feof(arqG))){
        printf("%d. %s",auxiliarG.uniforme,auxiliarG.nome);
        fread(&auxiliarG,sizeof(goleiro),1,arqG);
    }
    fread(&auxiliarJ,sizeof(jogador),1,arqJ);
    while((!feof(arqJ))){
        printf("%d. %s",auxiliarJ.uniforme,auxiliarJ.nome);
        fread(&auxiliarJ,sizeof(jogador),1,arqJ);
    }
    printf("0. Voltar.\n");
    printf("\n-> ");
    fclose(arqJ);
    fclose(arqG);
    int num_uniforme;
    scanf("%d",&num_uniforme);
    return num_uniforme;
}

/* Função que lista todos os jogos já ocorridos */

int lista_jogos(char *time)
{
    int opc; // variaveis auxiliares
    FILE *arqP;
    char arqPartida[120];
    strcpy(arqPartida,time);
    strcat(arqPartida,"/jogos.dat");
    partida jogo;
    arqP = fopen(arqPartida,"rb"); if(arqP == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    fread(&jogo,sizeof(partida),1,arqP);
    while(!feof(arqP)){
        printf("%d. %d x %d %s",jogo.id + 1, jogo.gols_pro,jogo.gols_contra,jogo.adversario);
        fread(&jogo,sizeof(partida),1,arqP);
    }
    fclose(arqP);
    printf("0. Voltar.\n");
    printf("\n-> ");
    scanf("%d",&opc);

    return opc-1; // retorna a posição do vetor jogo[] do jogo requerido
}

/* Funcao que calcula a media de um jogador */

float media_jogador(int total, int jogos)
{
    float media; // variavel para armazenar a media requerida

    media = (float)total/jogos;

    return media;
}

/* Funcao que calcula a media de notas de um jogador */

float media_jogadorN(int num_uniforme, char *time)
{
    int i; // variaveis auxiliares
    float media,soma=0; // variavel para armazenar a media requerida
    FILE *arqJ;
    FILE *arqG;
    char arqJogadores[120], arqGoleiros[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    arqJ = fopen(arqJogadores,"rb"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqG = fopen(arqGoleiros,"rb"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    jogador elenco;
    goleiro goleiros;

    fread(&goleiros,sizeof(goleiro),1,arqG);
    while((!feof(arqG)) && num_uniforme != goleiros.uniforme){
        fread(&goleiros,sizeof(goleiro),1,arqG);
    }
    if(num_uniforme == goleiros.uniforme)
    {
        for(i=0;i<100;i++)
        {
            if(goleiros.jogou[i]==1)
                soma+=goleiros.notas[i]; // somando todos os dados pedidos
        }
        media=soma/goleiros.jogos; // calculando a media desses dados, por partida
    }
    else
    {
        fread(&elenco,sizeof(jogador),1,arqJ);
        while((!feof(arqJ)) && num_uniforme != elenco.uniforme){
            fread(&elenco,sizeof(jogador),1,arqJ);
        }
        if(num_uniforme == elenco.uniforme)
        {
            for(i=0;i<100;i++)
            {
                if(elenco.jogou[i]==1)
                    soma+=elenco.notas[i]; // somando todos os dados pedidos
            }
            media=soma/elenco.jogos; // calculando a media desses dados, por partida
        }
        else
        {
            printf("Numero de uniforme nao encontrado!\n");
            system("pause");
        }
    }
    fclose(arqJ);
    fclose(arqG);

    return media;
}

/* Funcao que calcula a pontuacao de um jogador na partida */

float pontuacao(int num_uniforme, int n, char *time)
{
    float p;

    FILE *arqJ;
    FILE *arqG;
    FILE *auxiliar;
    char arqJogadores[120], arqGoleiros[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    arqJ = fopen(arqJogadores,"ab+"); if(arqJ == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    arqG = fopen(arqGoleiros,"ab+"); if(arqG == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    goleiro goleiros;
    jogador elenco;

    fread(&goleiros,sizeof(goleiro),1,arqG);
    while((!feof(arqG)) && num_uniforme != goleiros.uniforme){
        fread(&goleiros,sizeof(goleiro),1,arqG);
    }
    if(num_uniforme == goleiros.uniforme)
    {
        if(goleiros.passesC[n]+goleiros.passesE[n] == 0){
            p=5*(0.5);
        }
        else{
            p=(5*((float)goleiros.passesC[n]/((float)goleiros.passesC[n]+(float)goleiros.passesE[n])));
        }
        p+=(0.5*goleiros.defesas[n]);
        if(goleiros.defesas[n]%5==0)
            p+=(0.5*((float)goleiros.defesas[n]/5)); // ganha um bonus de meio ponto a cada 5 defesas feitas
        p+=(goleiros.golsF[n])-(goleiros.golsC[n])-(goleiros.golsS[n])-(0.5*goleiros.perdas[n]);
        p+=(0.3*goleiros.faltasS[n])-(0.1*goleiros.faltasC[n])-(0.1*goleiros.imped[n]);
        p+=(0.5*goleiros.assistG[n])+(0.1*goleiros.assistF[n])-(0.7*goleiros.penaltisC[n]);
        p+=(0.5*goleiros.penaltisS[n])+(goleiros.penaltisD[n])-(0.5*goleiros.penaltisP[n]);
    }
    else
    {
        fread(&elenco,sizeof(jogador),1,arqJ);
        while((!feof(arqJ)) && num_uniforme != elenco.uniforme){
            fread(&elenco,sizeof(jogador),1,arqJ);
        }
        if(num_uniforme == elenco.uniforme)
        {
            if(elenco.pos[n]>=1 && elenco.pos[n]<=5)
            {
                if(elenco.passesC[n]+elenco.passesE[n] == 0){
                    p=5.25*(0.5);
                }
                else{
                    p=(5.25*((float)elenco.passesC[n]/((float)elenco.passesC[n]+(float)elenco.passesE[n])));
                }
                if(elenco.finalizacoesC[n]+elenco.finalizacoesE[n] == 0){
                    p+=1.25*(0.5);
                }
                else{
                    p+=(1.25*((float)elenco.finalizacoesC[n]/((float)elenco.finalizacoesC[n]+(float)elenco.finalizacoesE[n])));
                }
                p+=elenco.gols[n]-elenco.golsC[n]+(0.4*elenco.desarmes[n])-(0.3*elenco.perdas[n]);
                p+=(0.1*elenco.faltasS[n])-(0.2*elenco.faltasC[n])-(0.1*elenco.imped[n]);
                p+=(0.5*elenco.assistG[n])+(0.1*elenco.assistF[n]);
                p+=(0.5*elenco.penaltisS[n])-(0.5*elenco.penaltisC[n])-(0.5*elenco.penaltisP[n]);
            }
            // caso o jogador tenha jogado como LDO, LEO ou PV
            if(elenco.pos[n]>=6 && elenco.pos[n]<=8)
            {
                if(elenco.passesC[n]+elenco.passesE[n] == 0){
                    p=4.75*(0.5);
                }
                else{
                    p=(4.75*((float)elenco.passesC[n]/((float)elenco.passesC[n]+(float)elenco.passesE[n])));
                }
                if(elenco.finalizacoesC[n]+elenco.finalizacoesE[n] == 0){
                    p+=1.75*(0.5);
                }
                else{
                    p+=(1.75*((float)elenco.finalizacoesC[n]/((float)elenco.finalizacoesC[n]+(float)elenco.finalizacoesE[n])));
                }
                p+=elenco.gols[n]-elenco.golsC[n]+(0.2*elenco.desarmes[n])-(0.3*elenco.perdas[n]);
                p+=(0.1*elenco.faltasS[n])-(0.1*elenco.faltasC[n])-(0.1*elenco.imped[n]);
                p+=(0.55*elenco.assistG[n])+(0.15*elenco.assistF[n]);
                p+=(0.5*elenco.penaltisS[n])-(0.5*elenco.penaltisC[n])-(0.5*elenco.penaltisP[n]);
            }
            // caso o jogador tenha jogado como SV ou ARM
            if(elenco.pos[n]==9 || elenco.pos[n]==10)
            {
                if(elenco.passesC[n]+elenco.passesE[n] == 0){
                    p=4.25*(0.5);
                }
                else{
                    p=(4.25*((float)elenco.passesC[n]/((float)elenco.passesC[n]+(float)elenco.passesE[n])));
                }
                if(elenco.finalizacoesC[n]+elenco.finalizacoesE[n] == 0){
                    p+=2.25*(0.5);
                }
                else{
                    p+=(2.25*((float)elenco.finalizacoesC[n]/((float)elenco.finalizacoesC[n]+(float)elenco.finalizacoesE[n])));
                }
                p+=elenco.gols[n]-elenco.golsC[n]+(0.1*elenco.desarmes[n])-(0.3*elenco.perdas[n]);
                p+=(0.1*elenco.faltasS[n])-(0.1*elenco.faltasC[n])-(0.1*elenco.imped[n]);
                p+=(0.6*elenco.assistG[n])+(0.2*elenco.assistF[n]);
                p+=(0.5*elenco.penaltisS[n])-(0.5*elenco.penaltisC[n])-(0.5*elenco.penaltisP[n]);
            }
            // caso o jogador tenha jogado como MD, ME, MA, PD, PE ou SA
            if(elenco.pos[n]>=11 && elenco.pos[n]<=16)
            {
                if(elenco.passesC[n]+elenco.passesE[n] == 0){
                    p=2*(0.5);
                }
                else{
                    p=(2*((float)elenco.passesC[n]/((float)elenco.passesC[n]+(float)elenco.passesE[n])));
                }
                if(elenco.finalizacoesC[n]+elenco.finalizacoesE[n] == 0){
                    p+=4.25*(0.5);
                }
                else{
                    p+=(4.25*((float)elenco.finalizacoesC[n]/((float)elenco.finalizacoesC[n]+(float)elenco.finalizacoesE[n])));
                }
                p+=elenco.gols[n]-elenco.golsC[n]+(0.1*elenco.desarmes[n])-(0.2*elenco.perdas[n]);
                p+=(0.2*elenco.faltasS[n])-(0.1*elenco.faltasC[n])-(0.5*elenco.imped[n]);
                p+=(0.65*elenco.assistG[n])+(0.25*elenco.assistF[n]);
                p+=(0.5*elenco.penaltisS[n])-(0.6*elenco.penaltisC[n])-(0.5*elenco.penaltisP[n]);
            }
            // caso o jogador tenha jogado como CA
            if(elenco.pos[n]==17)
            {
                if(elenco.passesC[n]+elenco.passesE[n] == 0){
                    p=1*(0.5);
                }
                else{
                    p=(1*((float)elenco.passesC[n]/((float)elenco.passesC[n]+(float)elenco.passesE[n])));
                }
                if(elenco.finalizacoesC[n]+elenco.finalizacoesE[n] == 0){
                    p+=5.5*(0.5);
                }
                else{
                    p+=(5.5*((float)elenco.finalizacoesC[n]/((float)elenco.finalizacoesC[n]+(float)elenco.finalizacoesE[n])));
                }
                p+=elenco.gols[n]-elenco.golsC[n]+(0.1*elenco.desarmes[n])-(0.1*elenco.perdas[n]);
                p+=(0.3*elenco.faltasS[n])-(0.1*elenco.faltasC[n])-(0.1*elenco.imped[n]);
                p+=(0.5*elenco.assistG[n])+(0.1*elenco.assistF[n]);
                p+=(0.5*elenco.penaltisS[n])-(0.7*elenco.penaltisC[n])-(0.5*elenco.penaltisP[n]);
            }
        }
        else
        {
            printf("Numero de uniforme nao encontrado!\n");
            system("pause");
        }
    }
    fclose(arqJ);
    fclose(arqG);

    if(p<0) {  p = 0;  }
    if(p>10){  p = 10; }

    return p;
}

/* Funcao que exibe a melhor escalacao baseado nas melhores notas por posicao */

int melhor_escalacao(char *time)
{
    system("cls");
    printf("\tEscolha uma formacao para saber a melhor escalacao:\n")
    printf("1. 3-5-2\n");
    printf("2. 4-3-3\n");
    printf("3. 4-4-2\n");
    printf("0. Voltar\n");
    printf("\n-> ");
    int opc;
    scanf("%d",&opc);
    switch(opc)
    {
        case 1: melhor_escalacao1(time);
                break;
        case 2: melhor_escalacao2(time);
                break;
        case 3: melhor_escalacao3(time);
                break;
        case 0: break;
        default: printf("Opcao invalida\n");
    }

    return 0;
}

/*      3 - 5 - 2     */
int melhor_escalacao1(char *time)
{
    system("cls");

    FILE *arqJ;
    FILE *arqG;
    char arqJogadores[120], arqGoleiros[120];
    strcpy(arqJogadores,time);
    strcat(arqJogadores,"/jogadores.dat");
    strcpy(arqGoleiros,time);
    strcat(arqGoleiros,"/goleiros.dat");
    arqJ = fopen(arqJogadores,"ab+");
    arqG = fopen(arqGoleiros,"ab+");
    goleiro goleiros;
    jogadores elenco;

    int i,j,melhor_time[10],contador=0;
    float media=0.0;

    // calculando o melhor goleiro
    int melhor_goleiro;
    float goleiro_nota=0;

    fread(&goleiros,sizeof(goleiro),1,arqG);
    while(!feof(arqG)){
        if(goleiros.media_notas>goleiro_nota)
        {
            melhor_goleiro=goleiros.uniforme;
            goleiro_nota=goleiros.media_notas;
        }
        fread(&goleiros,sizeof(goleiro),1,arqG);
    }
    media += goleiro_nota;
    rewind(arqG);

    /*    ZAGUEIROS    */

    float Nz[3],menorNota=11;
    int Uz[3], indice;
    for(i=0;i<3;i++)
    {
        Nz[i]=-1;
    }
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        if(elenco.posicao == 1 || elenco.posicao == 2 || elenco.posicao == 3)
        {
            if(contador == 3)
            {
                if(elenco.media_notas>menorNota)
                {
                    Nz[indice] = elenco.media_notas;
                    Uz[indice] = elenco.uniforme;
                }
            }
            else
            {
                for(j=0;j<3;j++)
                {
                    if(Nz[j]==-1)
                    {
                        Nz[j] = elenco.media_notas;
                        Uz[j] = elenco.uniforme;
                        contador++;
                        break;
                    }
                }
            }
            for(j=0;j<3;j++)
            {
                if(Nz[j]<menorNota && Nz[j] > 0)
                {
                    menorNota = Nz[j];
                    indice = j;
                }
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[0]=Uz[0];
    melhor_time[1]=Uz[1];
    melhor_time[2]=Uz[2];

    media += Nz[0];
    media += Nz[1];
    media += Nz[2];

    rewind(arqJ);

    /*      PRIMEIROS VOLANTES     */
    float Npv=-1;
    int Upv;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        if(elenco.posicao == 8)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Npv)
                {
                    Npv = elenco.media_notas;
                    Upv = elenco.uniforme;
                }
            }
            if(Npv==-1)
            {
                Npv = elenco.media_notas;
                Upv = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[3]=Upv;
    rewind(arqJ);

    /*      SEGUNDOS VOLANTES ou ARMADOR    */
    float Nsv=-1;
    int Usv;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        if(elenco.posicao == 9 || elenco.posicao == 10)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Nsv)
                {
                    Nsv = elenco.media_notas;
                    Usv = elenco.uniforme;
                }
            }
            if(Nsv==-1)
            {
                Nsv = elenco.media_notas;
                Usv = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[4]=Usv;

    media += Nsv;

    rewind(arqJ);

    /*      MEIAS DIREITAS ou PONTAS DIREITAS    */
    float Nmd=-1;
    int Umd;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        if(elenco.posicao == 11 || elenco.posicao == 14)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Nmd)
                {
                    Nmd = elenco.media_notas;
                    Umd = elenco.uniforme;
                }
            }
            if(Nmd==-1)
            {
                Nmd = elenco.media_notas;
                Umd = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[5]=Umd;

    media += Nmd;

    rewind(arqJ);

    /*      MEIAS ESQUERDAS ou PONTAS ESQUERDAS    */
    float Nme=-1;
    int Ume;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        if(elenco.posicao == 12 || elenco.posicao == 15)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Nme)
                {
                    Nme = elenco.media_notas;
                    Ume = elenco.uniforme;
                }
            }
            if(Nme==-1)
            {
                Nme = elenco.media_notas;
                Ume = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[6]=Ume;

    media += Nme;

    rewind(arqJ);

    /*      MEIAS ATACANTES    */
    float Nma=-1;
    int Uma;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        if(elenco.posicao == 13)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Nma)
                {
                    Nma = elenco.media_notas;
                    Uma = elenco.uniforme;
                }
            }
            if(Nma==-1)
            {
                Nma = elenco.media_notas;
                Uma = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[7]=Uma;

    media += Nma;

    rewind(arqJ);

    /*  ATACANTES  */
    float Na[2];
    menorNota=11;
    int Ua[2];
    for(i=0;i<2;i++)
    {
        Na[i]=-1;
    }
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        if(elenco.posicao == 16 || elenco.posicao == 17)
        {
            if(contador == 2)
            {
                if(elenco.media_notas>menorNota)
                {
                    Na[indice] = elenco.media_notas;
                    Ua[indice] = elenco.uniforme;
                }
            }
            for(j=0;j<2;j++)
            {
                if(Na[j]==-1)
                {
                    Na[j] = elenco.media_notas;
                    Ua[j] = elenco.uniforme;
                    contador++;
                    break;
                }
            }
            for(j=0;j<2;j++)
            {
                if(Na[j]<menorNota && Na[j] > 0)
                {
                    menorNota = Na[j];
                    indice = j;
                }
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[8]=Ua[0];
    melhor_time[9]=Ua[1];

    media += Na[0];
    media += Na[1];

    rewind(arqJ);

    media = media / 11;

    /* IMPRIMINDO */

    printf(" _______________________\n|\t\t\t|\n");
    if(melhor_time[9] < 10)
        printf("|\t0%d    ",melhor_time[9]);
    else
        printf("|\t%d    ",melhor_time[9]);
    if(melhor_time[8] < 10)
        printf("0%d\t|\n|\t\t\t|\n",melhor_time[8]);
    else
        printf("%d\t|\n|\t\t\t|\n",melhor_time[8]);
    if(melhor_time[7] < 10)
        printf("|\t   0%d   \t|\n|\t\t\t|\n",melhor_time[7]);
    else
        printf("|\t   %d   \t|\n|\t\t\t|\n",melhor_time[7]);
    if(melhor_time[6] < 10)
        printf("|  0%d\t",melhor_time[6]);
    else
        printf("|  %d\t",melhor_time[6]);
    if(melhor_time[5] < 10)
        printf("\t    0%d  |\n|\t\t\t|\n",melhor_time[5]);
    else
        printf("\t    %d  |\n|\t\t\t|\n",melhor_time[5]);
    if(melhor_time[4] < 10)
        printf("|       0%d\t\t|\n",melhor_time[4]);
    else
        printf("|       %d\t\t|\n",melhor_time[4]);
    if(melhor_time[3] < 10)
        printf("|\t     0%d\t\t|\n|\t\t\t|\n",melhor_time[3]);
    else
        printf("|\t     %d\t\t|\n|\t\t\t|\n",melhor_time[3]);
    if(melhor_time[2] < 10)
        printf("|    0%d\t\t",melhor_time[2]);
    else
        printf("|    %d\t\t",melhor_time[2]);
    if(melhor_time[1] < 10)
        printf("0%d\t|\n|\t\t\t|\n",melhor_time[1]);
    else
        printf("%d\t|\n|\t\t\t|\n",melhor_time[1]);
    if(melhor_time[0] < 10)
        printf("|\t   0%d   \t|\n|\t\t\t|\n",melhor_time[0]);
    else
        printf("|\t   %d   \t|\n|\t\t\t|\n",melhor_time[0]);
    if(melhor_goleiro < 10)
        printf("|\t\t\t|\n|\t   0%d\t\t|\n|\t\t\t|\n",melhor_goleiro);
    else
        printf("|\t\t\t|\n|\t   %d\t\t|\n|\t\t\t|\n",melhor_goleiro);
    printf("|_______________________|\n");

    fread(&goleiros,sizeof(goleiro),1,arqG);
    while((!feof(arqG)) && goleiros.uniforme != melhor_goleiro){
        if(goleiros.uniforme != melhor_goleiro)
        {
            printf("\nGoleiro:          %s.\n", goleiros.uniforme);
        }
        fread(&goleiros,sizeof(goleiro),1,arqG);
    }
    fclose(arqG);

    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        for(i=0;i<10;i++)
        {
            if(elenco.uniforme == melhor_time[i])
            {
                if(i==0)
                    printf("Zagueiros:        %s,",elenco.uniforme);
                if(i==1)
                    printf(" %s,",elenco.uniforme);
                if(i==2)
                    printf(" %s.\n",elenco.uniforme);
                if(i==3)
                    printf("Primeiro volante: %s.\n",elenco.uniforme);
                if(i==4)
                    printf("Segundo volante:  %s.\n",elenco.uniforme);
                if(i==5)
                    printf("Meia direita:     %s.\n",elenco.uniforme);
                if(i==6)
                    printf("Meia esquerda:    %s.\n",elenco.uniforme);
                if(i==7)
                    printf("Meia atacante:    %s.\n",elenco.uniforme);
                if(i==8)
                    printf("Atacantes:        %s,",elenco.uniforme);
                if(i==9)
                    printf(" %s.\n",elenco.uniforme);
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    fclose(arqJ);

    printf("\nMedia de notas da escalacao: %.3f\n\n",media);

    system("pause");
    return 0;
}

/*      4 - 3 - 3     */
int melhor_escalacao2(char *time)
{
    system("cls");

    int i,j,melhor_time[10],contador=0;
    float media = 0.0;

    // calculando o melhor goleiro
    int melhor_goleiro;
    float goleiro_nota=0;

    fread(&goleiros,sizeof(goleiro),1,arqG);
    while(!feof(arqG)){
        if(goleiros.media_notas>goleiro_nota)
        {
            melhor_goleiro=goleiros.uniforme;
            goleiro_nota=goleiros.media_notas;
        }
        fread(&goleiros,sizeof(goleiro),1,arqG);
    }
    rewind(arqG);

    media += goleiro_nota;

    /*  ZAGUEIROS  */
    float Nz[2],menorNota=11;
    int Uz[2], indice;
    for(i=0;i<2;i++)
    {
        Nz[i]=-1;
    }
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arJ)){
        if(elenco.posicao == 1 || elenco.posicao == 2 || elenco.posicao == 3)
        {
            if(contador == 2)
            {
                if(elenco.media_notas>menorNota)
                {
                    Nz[indice] = elenco.media_notas;
                    Uz[indice] = elenco.uniforme;
                }
            }
            else
            {
                for(j=0;j<2;j++)
                {
                    if(Nz[j]==-1)
                    {
                        Nz[j] = elenco.media_notas;
                        Uz[j] = elenco.uniforme;
                        contador++;
                        break;
                    }
                }
            }
            for(j=0;j<2;j++)
            {
                if(Nz[j]<menorNota && Nz[j] > 0)
                {
                    menorNota = Nz[j];
                    indice = j;
                }
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[0]=Uz[0];
    melhor_time[1]=Uz[1];

    media += Nz[0];
    media += Nz[1];

    rewind(arqJ);

    /* LATERAIS DIREITOS */
    float Nld=-1;
    int Uld;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arJ)){
        if(elenco.posicao == 4 || elenco.posicao == 6)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Nld)
                {
                    Nld = elenco.media_notas;
                    Uld = elenco.uniforme;
                }
            }
            if(Nld==-1)
            {
                Nld = elenco.media_notas;
                Uld = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[2]=Uld;

    media += Nld;

    rewind(arqJ);

    /* LATERAIS ESQUERDOS */
    float Nle=-1;
    int Ule;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arJ)){
        if(elenco.posicao == 5 || elenco.posicao == 7)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Nle)
                {
                    Nle = elenco.media_notas;
                    Ule = elenco.uniforme;
                }
            }
            if(Nle==-1)
            {
                Nle = elenco.media_notas;
                Ule = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[3]=Ule;

    media += Nle;

    rewind(arqJ);

    /*      PRIMEIROS VOLANTES     */
    float Npv=-1;
    int Upv;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arJ)){
        if(elenco.posicao == 8)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Npv)
                {
                    Npv = elenco.media_notas;
                    Upv = elenco.uniforme;
                }
            }
            if(Npv==-1)
            {
                Npv = elenco.media_notas;
                Upv = elenco.uniforme;
                contador++;
                break;
            }
        }
    }
    melhor_time[4]=Upv;

    media += Npv;

    rewind(arqJ);

    /*      MEIAS DIREITAS      */
    float Nmd=-1;
    int Umd;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arJ)){
        if(elenco.posicao == 11 || elenco.posicao == 13)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Nmd)
                {
                    Nmd = elenco.media_notas;
                    Umd = elenco.uniforme;
                }
            }
            if(Nmd==-1)
            {
                Nmd = elenco.media_notas;
                Umd = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[5]=Umd;

    media += Nmd;

    rewind(arqJ);

    /*      MEIAS ESQUERDAS    */
    float Nme=-1;
    int Ume;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arJ)){
        if(elenco.posicao == 12 || elenco.posicao == 13)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Nme)
                {
                    Nme = elenco.media_notas;
                    Ume = elenco.uniforme;
                }
            }
            if(Nme==-1)
            {
                Nme = elenco.media_notas;
                Ume = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[6]=Ume;

    media += Nme;

    rewind(arqJ);

    /*      PONTAS DIREITAS      */
    float Npd=-1;
    int Upd;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arJ)){
        if(elenco.posicao == 14)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Npd)
                {
                    Npd = elenco.media_notas;
                    Upd = elenco.uniforme;
                }
            }
            if(Npd==-1)
            {
                Npd = elenco.media_notas;
                Upd = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[7]=Upd;

    media += Npd;

    rewind(arqJ);

    /*      PONTAS ESQUERDAS      */
    float Npe=-1;
    int Upe;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arJ)){
        if(elenco.posicao == 15)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Npe)
                {
                    Npe = elenco.media_notas;
                    Upe = elenco.uniforme;
                }
            }
            if(Npe==-1)
            {
                Npe = elenco.media_notas;
                Upe = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[8]=Upe;

    media += Npe;

    rewind(arqJ);

    /*      ATACANTES      */
    float Na=-1;
    int Ua;
    contador = 0;
    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arJ)){
        if(elenco.posicao == 16 || elenco.posicao == 17)
        {
            if(contador == 1)
            {
                if(elenco.media_notas>Na)
                {
                    Na = elenco.media_notas;
                    Ua = elenco.uniforme;
                }
            }
            if(Na==-1)
            {
                Na = elenco.media_notas;
                Ua = elenco.uniforme;
                contador++;
                break;
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    melhor_time[9]=Ua;

    media += Na;

    rewind(arqJ);

    media = media / 11;

    /* IMPRIMINDO */
    printf(" _______________________\n|\t\t\t|\n");
    if(melhor_time[9] < 10)
        printf("|\t   0%d   \t|\n|\t\t\t|\n",melhor_time[9]);
    else
        printf("|\t   %d   \t|\n|\t\t\t|\n",melhor_time[9]);
    if(melhor_time[8] < 10)
        printf("|  0%d\t",melhor_time[8]);
    else
        printf("|  %d\t",melhor_time[8]);
    if(melhor_time[7] < 10)
        printf("\t    0%d  |\n|\t\t\t|\n",melhor_time[7]);
    else
        printf("\t    %d  |\n|\t\t\t|\n",melhor_time[7]);
    if(melhor_time[6] < 10)
        printf("|\t0%d",melhor_time[6]);
    else
        printf("|\t%d",melhor_time[6]);
    if(melhor_time[5] < 10)
        printf("    0%d\t|\n|\t\t\t|\n",melhor_time[5]);
    else
        printf("    %d\t|\n|\t\t\t|\n",melhor_time[5]);
    if(melhor_time[4] < 10)
        printf("|\t   0%d   \t|\n|\t\t\t|\n",melhor_time[4]);
    else
        printf("|\t   %d   \t|\n|\t\t\t|\n",melhor_time[4]);
    if(melhor_time[3] < 10)
        printf("|  0%d\t",melhor_time[3]);
    else
        printf("|  %d\t",melhor_time[3]);
    if(melhor_time[2] < 10)
        printf("\t    0%d  |\n",melhor_time[2]);
    else
        printf("\t    %d  |\n",melhor_time[2]);
    if(melhor_time[1] < 10)
        printf("|\t0%d\t",melhor_time[1]);
    else
        printf("|\t%d\t",melhor_time[1]);
    if(melhor_time[0] < 10)
        printf("0%d\t|\n|\t\t\t|\n",melhor_time[0]);
    else
        printf("%d\t|\n|\t\t\t|\n",melhor_time[0]);
    if(melhor_goleiro < 10)
        printf("|\t\t\t|\n|\t   0%d\t\t|\n|\t\t\t|\n",melhor_goleiro);
    else
        printf("|\t\t\t|\n|\t   %d\t\t|\n|\t\t\t|\n",melhor_goleiro);
    printf("|_______________________|\n");

    fread(&goleiros,sizeof(goleiro),1,arqG);
    while((!feof(arqG)) && goleiros.uniforme != melhor_goleiro){
        if(goleiros.uniforme != melhor_goleiro)
        {
            printf("\nGoleiro:          %s.\n", goleiros.uniforme);
        }
        fread(&goleiros,sizeof(goleiro),1,arqG);
    }
    fclose(arqG);

    fread(&elenco,sizeof(jogador),1,arqJ);
    while(!feof(arqJ)){
        for(i=0;i<10;i++)
        {
            if(elenco.uniforme == melhor_time[i])
            {
                if(i==0)
                    printf("Zagueiros:        %s,",elenco.uniforme);
                if(i==1)
                    printf(" %s.\n",elenco.uniforme);
                if(i==2)
                    printf("Lateral direito:  %s.\n",elenco.uniforme);
                if(i==3)
                    printf("Lateral esquerdo: %s.\n",elenco.uniforme);
                if(i==4)
                    printf("Primeiro volante: %s.\n",elenco.uniforme);
                if(i==5)
                    printf("Meia direita:     %s.\n",elenco.uniforme);
                if(i==6)
                    printf("Meia esquerda:    %s.\n",elenco.uniforme);
                if(i==7)
                    printf("Ponta direita:    %s.\n",elenco.uniforme);
                if(i==8)
                    printf("Ponta esquerda:   %s.\n",elenco.uniforme);
                if(i==9)
                    printf("Atacante:         %s.\n",elenco.uniforme);
            }
        }
        fread(&elenco,sizeof(jogador),1,arqJ);
    }
    fclose(arqJ);

    printf("\nMedia de notas da escalacao: %.3f\n\n",media);

    system("pause");
    return 0;
}

/*      4 - 4 - 2     */
int melhor_escalacao3(char *time)
{
    system("cls");
    int i,j,melhor_time[10],contador=0;
    float media = 0.0;

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
    /* ZAGUEIROS */
    float Nz[2],menorNota=11;
    int Uz[2], indice;
    for(i=0;i<2;i++)
    {
        Nz[i]=-1;
    }
    // percorrendo todos os jogadores
    for(i=0;i<40;i++)
    {
        if(elenco[i].controle==1)
        {
            if(elenco[i].posicao == 1 || elenco[i].posicao == 2 || elenco[i].posicao == 3)
            {
                if(contador == 3)
                {
                    if(elenco[i].media_notas>menorNota)
                    {
                        Nz[indice] = elenco[i].media_notas;
                        Uz[indice] = elenco[i].uniforme;
                    }
                }
                for(j=0;j<2;j++)
                {
                    if(Nz[j]==-1)
                    {
                        Nz[j] = elenco[i].media_notas;
                        Uz[j] = elenco[i].uniforme;
                        contador++;
                        break;
                    }
                }
                for(j=0;j<2;j++)
                {
                    if(Nz[j]<menorNota && Nz[j] > 0)
                    {
                        menorNota = Nz[j];
                        indice = j;
                    }
                }
            }
        }
    }
    melhor_time[0]=Uz[0];
    melhor_time[1]=Uz[1];
    /* LATERAIS DIREITOS */
    float Nld=-1;
    int Uld;
    contador = 0;
    for(i=0;i<40;i++)
    {
        if(elenco[i].controle==1)
        {
            if(elenco[i].posicao == 4 || elenco[i].posicao == 6)
            {
                if(contador == 1)
                {
                    if(elenco[i].media_notas>Nld)
                    {
                        Nld = elenco[i].media_notas;
                        Uld = elenco[i].uniforme;
                    }
                }
                if(Nld==-1)
                {
                    Nld = elenco[i].media_notas;
                    Uld = elenco[i].uniforme;
                    contador++;
                    break;
                }
            }
        }
    }
    melhor_time[2]=Uld;
    /* LATERAIS ESQUERDOS */
    float Nle=-1;
    int Ule;
    contador = 0;
    for(i=0;i<40;i++)
    {
        if(elenco[i].controle==1)
        {
            if(elenco[i].posicao == 5 || elenco[i].posicao == 7)
            {
                if(contador == 1)
                {
                    if(elenco[i].media_notas>Nle)
                    {
                        Nle = elenco[i].media_notas;
                        Ule = elenco[i].uniforme;
                    }
                }
                if(Nle==-1)
                {
                    Nle = elenco[i].media_notas;
                    Ule = elenco[i].uniforme;
                    contador++;
                    break;
                }
            }
        }
    }
    melhor_time[3]=Ule;
    /* PRIMEIROS VOLANTES */
    float Npv=-1;
    int Upv;
    contador = 0;
    for(i=0;i<40;i++)
    {
        if(elenco[i].controle==1)
        {
            if(elenco[i].posicao == 8)
            {
                if(contador == 1)
                {
                    if(elenco[i].media_notas>Npv)
                    {
                        Npv = elenco[i].media_notas;
                        Upv = elenco[i].uniforme;
                    }
                }
                if(Npv==-1)
                {
                    Npv = elenco[i].media_notas;
                    Upv = elenco[i].uniforme;
                    contador++;
                    break;
                }
            }
        }
    }
    melhor_time[4]=Upv;
    /* SEGUNDOS VOLANTES */
    float Nsv=-1;
    int Usv;
    contador = 0;
    for(i=0;i<40;i++)
    {
        if(elenco[i].controle==1)
        {
            if(elenco[i].posicao == 9 || elenco[i].posicao == 10)
            {
                if(contador == 1)
                {
                    if(elenco[i].media_notas>Nsv)
                    {
                        Nsv = elenco[i].media_notas;
                        Usv = elenco[i].uniforme;
                    }
                }
                if(Nsv==-1)
                {
                    Nsv = elenco[i].media_notas;
                    Usv = elenco[i].uniforme;
                    contador++;
                    break;
                }
            }
        }
    }
    melhor_time[5]=Usv;
    /* MEIA DIREITA */
    float Nmd=-1;
    int Umd;
    contador = 0;
    for(i=0;i<40;i++)
    {
        if(elenco[i].controle==1)
        {
            if(elenco[i].posicao == 11 || elenco[i].posicao == 14)
            {
                if(contador == 1)
                {
                    if(elenco[i].media_notas>Nmd)
                    {
                        Nmd = elenco[i].media_notas;
                        Umd = elenco[i].uniforme;
                    }
                }
                if(Nmd==-1)
                {
                    Nmd = elenco[i].media_notas;
                    Umd = elenco[i].uniforme;
                    contador++;
                    break;
                }
            }
        }
    }
    melhor_time[6]=Umd;
    /* MEIA ESQUERDA */
    float Nme=-1;
    int Ume;
    contador = 0;
    for(i=0;i<40;i++)
    {
        if(elenco[i].controle==1)
        {
            if(elenco[i].posicao == 12 || elenco[i].posicao == 15)
            {
                if(contador == 1)
                {
                    if(elenco[i].media_notas>Nme)
                    {
                        Nme = elenco[i].media_notas;
                        Ume = elenco[i].uniforme;
                    }
                }
                if(Nme==-1)
                {
                    Nme = elenco[i].media_notas;
                    Ume = elenco[i].uniforme;
                    contador++;
                    break;
                }
            }
        }
    }
    melhor_time[7]=Ume;
    /* ATACANTES */
    float Na[2];
    menorNota=11;
    int Ua[2];
    for(i=0;i<2;i++)
    {
        Na[i]=-1;
    }
    // percorrendo todos os jogadores
    for(i=0;i<40;i++)
    {
        if(elenco[i].controle==1)
        {
            if(elenco[i].posicao == 16 || elenco[i].posicao == 17)
            {
                if(contador == 2)
                {
                    if(elenco[i].media_notas>menorNota)
                    {
                        Na[indice] = elenco[i].media_notas;
                        Ua[indice] = elenco[i].uniforme;
                    }
                }
                for(j=0;j<2;j++)
                {
                    if(Na[j]==-1)
                    {
                        Na[j] = elenco[i].media_notas;
                        Ua[j] = elenco[i].uniforme;
                        contador++;
                        break;
                    }
                }
                for(j=0;j<2;j++)
                {
                    if(Na[j]<menorNota && Na[j] > 0)
                    {
                        menorNota = Na[j];
                        indice = j;
                    }
                }
            }
        }
    }
    melhor_time[8]=Ua[0];
    melhor_time[9]=Ua[1];
    /* IMPRIMINDO */
    for(i=0;i<10;i++)
    {
        if(goleiros[i].uniforme == melhor_goleiro)
        {
            printf("Goleiro:          %s.\n", goleiros[i].uniforme);
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<40;j++)
        {
            if(elenco[j].uniforme == melhor_time[i])
            {
                if(i==0)
                    printf("Zagueiros:        %s,",elenco[i].uniforme);
                if(i==1)
                    printf(" %s.\n",elenco[i].uniforme);
                if(i==2)
                    printf("Lateral direito:  %s.\n",elenco[i].uniforme);
                if(i==3)
                    printf("Lateral esquerdo: %s.\n",elenco[i].uniforme);
                if(i==4)
                    printf("Primeiro volante: %s.\n",elenco[i].uniforme);
                if(i==5)
                    printf("Segundo volante:  %s.\n",elenco[i].uniforme);
                if(i==6)
                    printf("Meia direita:     %s.\n",elenco[i].uniforme);
                if(i==7)
                    printf("Meia esquerda:    %s.\n",elenco[i].uniforme);
                if(i==8)
                    printf("Atacantes:        %s,",elenco[i].uniforme);
                if(i==9)
                    printf(" %s.\n",elenco[i].uniforme);
            }
        }
    }
    system("pause");
    return 0;
}

/* Funcao que exibe as estatisticas de notas do grupo */

int grupo_notas()
{
  system("cls");
  printf("\tEstatisticas de notas do grupo\n\n");

  /*                             N O T A S                                          */
  /*obtendo a quantidade de jogadores que já jogaram */
  int i = 0, j = 0;
  for (i =0; i <40; i++){
    if(elenco[i].controle == 1){
      j = j+1;
    }
  }
  for(i = 0; i <10; i++){
    if(goleiros[i].controle == 1){
      j = j+1;
    }
  }
  /*criando um vetor (novoNotas[]) apenas com as notas, este vetor é genérico e serve apenas para manipulação (terá seus valores
  alterados ao longo do código)*/
  int l = 0, m = -1, novoUniforme[j];
  float  novoNotas[j];
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoNotas[m] = elenco[l].media_notas;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  for(l = 0; l < 10; l++){
    if(goleiros[l].controle == 1){
      m++;
      novoNotas[m] = goleiros[l].media_notas;
      novoUniforme[m] = goleiros[l].uniforme;
    }
  }
  /*os valores obtidos em novoGols[] será agora ordenado de forma decrescente no vetor rankGols[]*/
  int k = 0, guardaindice, rankUniforme[j];
  float rankNotas[j], maisNotas = 0.0;
  printf("Media de notas por jogador na temporada:\n\n");

  while(k < j){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoGols[]*/
  for(l = 0; l <= m; l ++){
    if(novoNotas[l] >= maisNotas){
      maisNotas = novoNotas[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankNotas[k] = maisNotas;
  maisNotas=0;
  novoNotas[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  int x = 0;
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: %.3f\n",elenco[l].nome, elenco[l].media_notas);
        break;
      }
      if(l < 10){
        if(rankUniforme[x] == goleiros[l].uniforme){
          printf("%s: %.3f\n", goleiros[l].nome, goleiros[l].media_notas);
          break;
        }
      }
    }
  }
  printf("\n");
  system("pause");
  return 0;
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

  /*                             D E F E S A S                                          */
  /*obtendo a quantidade de jogadores que já jogaram */
  int i = 0, j = 0, f = 0;
    //f = f+1;

  for(i = 0; i <10; i++){
    if(goleiros[i].controle == 1){
      j = j+1;
    }
  }
  /*criando um vetor (novoGols[]) apenas com os gols, este vetor é genérico e serve apenas para manipulação (terá seus valores
  alterados ao longo do código)*/
  int novoDefesas[j], l = 0, m = -1, novoUniforme[j];
  /*for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoDefesas[m] = elenco[l].total_defesas;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }*/
  for(l = 0; l < 10; l++){
    if(goleiros[l].controle == 1){
      m++;
      novoDefesas[m] = goleiros[l].total_defesas;
      novoUniforme[m] = goleiros[l].uniforme;
    }
  }
  /*os valores obtidos em novoGols[] será agora ordenado de forma decrescente no vetor rankGols[]*/
  int k = 0, maisDefesas = 0, guardaindice, rankDefesas[j], rankUniforme[j];
  printf("Defesas por goleiro na temporada:\n\n");

  while(k < j){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoGols[]*/
  for(l = 0; l <= m; l ++){
    if(novoDefesas[l] >= maisDefesas){
      maisDefesas = novoDefesas[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankDefesas[k] = maisDefesas;
  maisDefesas=0;
  novoDefesas[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  int x = 0;
  for(x = 0; x < k; x++){
    for(l = 0; l < 10; l++){
        if(rankUniforme[x] == goleiros[l].uniforme){
          printf("%s: %d\n", goleiros[l].nome, rankDefesas[x]);
          break;
        }
    }
  }

      system("pause");
      return 0;
    }

/* Funcao que exibe as estatisticas de faltas e penaltis do grupo */

int grupo_FeP()
{
  system("cls");
  /*                   F A L T A S                                  */

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
  int novoFaltas[j], l = 0, m = -1, novoUniforme[j];
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoFaltas[m] = elenco[l].total_faltasC;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  for(l = 0; l < 10; l++){
    if(goleiros[l].controle == 1){
      m++;
      novoFaltas[m] = goleiros[l].total_faltasC;
      novoUniforme[m] = goleiros[l].uniforme;
    }
  }
  /*os valores obtidos em novoGols[] será agora ordenado de forma decrescente no vetor rankGols[]*/
  int k = 0, maisFaltas = 0, guardaindice, rankFaltas[j], rankUniforme[j];
  printf("Faltas por jogador na temporada:\n\n");

  while(k < j){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoGols[]*/
  for(l = 0; l <= m; l ++){
    if(novoFaltas[l] >= maisFaltas){
      maisFaltas = novoFaltas[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankFaltas[k] = maisFaltas;
  maisFaltas=0;
  novoFaltas[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  int x = 0;
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: Faltas cometidas: %d   Faltas sofridas: %d\n",elenco[l].nome, rankFaltas[x], elenco[l].total_faltasS);
        break;
      }
      if(l < 10){
        if(rankUniforme[x] == goleiros[l].uniforme){
          printf("%s: Faltas cometidas: %d   Faltas sofridas: \n", goleiros[l].nome, rankFaltas[x], goleiros[l].total_faltasS);
          break;
        }
      }
    }
  }


  /*                   P Ê N A L T I S                                  */

  /*Quantidade de jogadores que já jogaram = 'j'
  Criando um vetor (novoFinalizacoes[]) apenas com as finalizações corretas, este vetor é genérico e serve apenas para
  manipulação (terá seus valores alterados ao longo do código) */
  int novoPenaltisC[f];
  l = 0;
  m = -1;
  for(l = 0; l < 40; l++){
    if(elenco[l].controle == 1){
      m++;
      novoPenaltisC[m] = elenco[l].total_penaltisC;
      novoUniforme[m] = elenco[l].uniforme;
    }
  }
  /*os valores obtidos em novoFinalizacoes[] será agora ordenado de forma decrescente no vetor rankFinalizacoes[]*/
  int  maisPenaltisC = 0, rankPenaltisC[f];
  k = 0;
  printf("\n\nPenaltis por jogador na temporada:\n\n");

  while(k < f){
    /*descobrindo o maior número do vetor e guardando seu índice original referente ao vetor novoGols[]*/
  for(l = 0; l <= m; l ++){
    if(novoPenaltisC[l] >= maisPenaltisC){
      maisPenaltisC = novoPenaltisC[l];
      guardaindice = l;
    }
  }
  /*salvando o maior valor em outra variável e zerando para que no próximo laço ele não seja contabilizado*/
  rankPenaltisC[k] = maisPenaltisC;
  maisPenaltisC=0;
  novoPenaltisC[guardaindice] = -1;
  rankUniforme[k] = novoUniforme[guardaindice];
  k++;
  }
  for(x = 0; x < k; x++){
    for(l = 0; l < 40; l++){
      if(rankUniforme[x] == elenco[l].uniforme){
        printf("%s: Penal. cometidos: %d     Penal. perdidos: %d     Penal. sofridos: %d \n",elenco[l].nome, elenco[l].total_penaltisC,elenco[l].total_penaltisP, elenco[l].total_penaltisS);
        break;
      }
      }
    }
  printf("\n\n");
  system("pause");
  return 0;


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

int jogador_dados(int num_uniforme, char *time)
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
            printf("Posicao do jogador:");
            if(elenco[i].posicao==1){
                printf(" zagueiro direito.");
            }
            if(elenco[i].posicao==2){
                printf(" zagueiro esquerdo.");
            }
            if(elenco[i].posicao==3){
                printf(" zagueiro central.");
            }
            if(elenco[i].posicao==4){
                printf(" lateral direito defensivo.");
            }
            if(elenco[i].posicao==5){
                printf(" lateral esquerdo defensivo.");
            }
            if(elenco[i].posicao==6){
                printf(" lateral direito ofensivo.");
            }
            if(elenco[i].posicao==7){
                printf(" lateral esquerdo ofensivo.");
            }
            if(elenco[i].posicao==8){
                printf(" primeiro volante.");
            }
            if(elenco[i].posicao==9){
                printf(" segundo volante.");
            }
            if(elenco[i].posicao==10){
                printf(" armador.");
            }
            if(elenco[i].posicao==11){
                printf(" meia direita.");
            }
            if(elenco[i].posicao==12){
                printf(" meia esquerda.");
            }
            if(elenco[i].posicao==13){
                printf(" meia atacante.");
            }
            if(elenco[i].posicao==14){
                printf(" ponta direita.");
            }
            if(elenco[i].posicao==15){
                printf(" ponta esquerda.");
            }
            if(elenco[i].posicao==16){
                printf(" segundo atacante.");
            }
            if(elenco[i].posicao==17){
                printf(" centroavante.");
            }
            printf("\n");
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

int jogador_GeF(int num_uniforme, char *time)
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

int goleiro_Gols(int num_uniforme, char *time)
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

int jogador_PeA(int num_uniforme, char *time)
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

int jogador_DeP(int num_uniforme, char *time)
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

int jogador_DeG(int num_uniforme, char *time)
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

int jogador_FeP(int num_uniforme, char *time)
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

int jogador_Imp(int num_uniforme, char *time)
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

int jogador_notas(int num_uniforme, char *time)
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
            printf("Media de nota por partida: %.2f\n",elenco[i].media_notas);
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

int home(char *time)
{
    int comando;
    printf("1. Login\n");
    printf("2. Cadastro\n");
    printf("0. Sair\n");
    printf("\n-> ");
    scanf("%d",&comando);

    switch(comando)
    {
        case 1: login(time);
                break;

        case 2: cadastro_time(time);
                break;

        case 0: return 1;

        default: printf("Digite uma opcao valida\n");
    }
    return 0;
}

int cadastro_time(char *time)
{
    system("cls");
    cadastro times;
    FILE *arq;
    arq = fopen("cadastros.dat","ab"); if(arq == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    printf("\t\t  Cadastro de um time\n");
    printf("\t\t(para voltar, digite 0)\n\n");
    do{
        printf("Nome do time: ");
        scanf("%[^\n]s",time);
        if(strcmp(time,"0") == 1)
        {
            home(time);
            return 0;
        }
        fread(&times,sizeof(cadastro),1,arq);
        while ((!feof(arq)) && (strcmp(times.nome,time))){
            fread(&times,sizeof(cadastro),1,arq);
        }
        if(strcmp(times.nome,time) == 0)
        {
            printf("Time já cadastrado!\n");
            rewind(arq);
        }
        else
        {
            char senha[20];
            strcpy(times.nome,time);
            printf("Senha (max. 20 caracteres): ");
            scanf("%s",senha);
            strcpy(times.senha,senha);
            fwrite(&times,sizeof(cadastro),1,arq);
            break;
        }
    }while(strcmp(time,"0"));
    fclose(arq);

    CreateDirectoryA(times.nome, NULL);
    char arquivo[120];

    strcpy(arquivo,times.nome);
    strcat(arquivo,"/jogadores.dat");
    arq = fopen(arquivo,"wb"); if(arq == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    fclose(arq);

    strcpy(arquivo,times.nome);
    strcat(arquivo,"/goleiros.dat");
    arq = fopen(arquivo,"wb"); if(arq == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    fclose(arq);

    strcpy(arquivo,times.nome);
    strcat(arquivo,"/jogos.dat");
    arq = fopen(arquivo,"wb"); if(arq == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    fclose(arq);

    system("pause");
    return 0;
}

int login(char *time)
{
    system("cls");
    FILE *arq;
    arq = fopen("cadastros.dat","rb"); if(arq == NULL){    printf("Erro na abertura do arquivo!\n"); return 1;    }
    printf("\t\t         Login\n");
    printf("\t\t(para voltar, digite 0)\n\n");
    do{
        printf("Nome do time: ");
        scanf("%[^\n]s",time);
        if(strcmp(time,"0") == 0)
            home(time);
        fread(&times,sizeof(cadastro),1,arq);
        while ((!feof(arq)) && (strcmp(times.nome,time))){
            fread(&times,sizeof(cadastro),1,arq);
        }
        if((strcmp(times.nome,time))
        {
            printf("\tTime nao cadastrado!\n");
        }
    }while(strcmp(time,"0"));
    char senha[20],ch;
    int n;
    do
    {
        printf("Senha: ");
        for(n=0;n<20;n++)
        {
            ch = getch();
            printf ("*");
            if(ch==13)
            {
                senha[n]='\0';
                break;
            }
            else
            {
                senha[n]=ch;
            }
        }
        printf("\nSenha incorreta!\n");
    }while(strcmp(times.senha,senha));
    return 0;
}
