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

/*    Estrutura onde os dados de um jogador sao armazenados    */

typedef struct {
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

/*    Estrutura onde os dados de um goleiro sao armazenados    */

typedef struct {
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

/*    Prototipos das funcoes utilizadas    */

int cadastrar();
int editar();
int lista_jogadores();
int estatisticas_jogador();
int estatisticas_grupo();
int inserir_estatisticas();
int editar_estatisticas();
float media(float, int);
float pontuacao(char *);
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

    do{
        system("cls");

        printf("\tA.T.V.\n\n");
        printf("1. Cadastrar jogador.\n");
        printf("2. Editar dados de jogador.\n");
        printf("3. Inserir estatisticas de uma partida.\n");
        printf("4. Editar estatisticas de uma partida.\n");
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
                inserir_estatisticas();
                break;

            case 4:
                editar_estatisticas();
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

}

/* Funcao que edita o cadastro de um jogador */

int editar()
{

}

/* Funcao que insere as estatisticas de uma partida */

int inserir_estatisticas()
{

}

/* Funcao que edita as estatisticas de uma partida */

int editar_estatisticas()
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

}

/* Funcao que calcula a media (nao e' certeza ainda) */

float media()
{

}

/* Funcao que calcula a pontuacao de um jogador na partida */

float pontuacao(char *nome)
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
