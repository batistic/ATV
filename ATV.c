/*
 *                         A.T.V. - ASSISTENTE TÉCNICO VIRTUAL
 *
 *    Software desenvolvido para auxiliar equipes técnicas de times de futebol de campo
 *
 * Desenvolvido por:
 *   Edson da Costa Vitor Junior
 *   Guilherme Atihe de Oliveira
 *   Gustavo Batistic Ribeiro
 *   Pedro Henrique Maldonado Truzzi
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*    Estrutura onde os dados de um jogador são armazenados    */

typedef struct {
    // Dados pessoais
    char nome[100]; int idade; float altura; float peso; int pe; int uniforme; int posicao[18];
    // Estatísticas em jogo
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

/*    Estrutura onde os dados de um goleiro são armazenados    */

typedef struct {
    // Dados pessoais
    char nome[100]; int idade; float altura; float peso; int pe; int uniforme;
    // Estatísticas em jogo
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

/*    Protótipos das funções utilizadas    */

int cadastrar();
int editar();
int lista_jogadores();
int estatisticas_jogador();
int estatisticas_grupo();
int inserir_estatisticas();
int editar_estatisticas();
float media(float, int);  // função para calcular media
float pontuacao(char *); // função para calcular pontuação do jogador
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

/* Função principal */

int main()
{

    return 0;
}
