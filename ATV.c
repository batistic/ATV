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

typedef struct {
    int controle;
    char adversario[100];
    int gols_pro;
    int gols_contra;
    int saldo_gols;
    int substituicoes;
}partida;

partida jogo[100]; // declarando um vetor que armazena 100 jogos

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
    int jogou[100];           int jogos;
}goleiro;

goleiro goleiros[10]; // declarando um vetor que armazena 10 goleiros

/*    Prototipos das funcoes utilizadas    */

int cadastrar(); //cadastra um novo jogador
int editar(); //edita o cadastro de um jogador
int excluir(); // exclui o cadastro de um jogador
int lista_jogadores(); //lista todos os jogadores do grupo
int lista_jogos(); // lista todos os jogos ocorridos
int estatisticas_jogador(); //exibe as estatísticas de um jogador
int estatisticas_grupo(); //exibe as estatisticas do grupo
int inserir_dados(); //insere os dados de uma partida
int editar_dados(); //edita os dados de uma partida que já ocorreu
float media_jogador(int *vet, int num_jogador); //calcula a media de um jogador
float pontuacao(); //calcula a pontuação do jogador na partida
int ranking(); //exibe o ranking dos jogadores por um indicador
int melhor_escalacao();//exibe a melhor escalação baseado nas melhores notas por posição
int grupo_notas(); //exibe as estatísticas de nota do grupo
int grupo_GeF(); //exibe as estatísticas de gol e finalização do grupo
int grupo_PeA();//exibe as estatísticas de passes e assistências do grupo
int grupo_Des();//exibe as estatísticas de desarme do grupo
int grupo_Def();//exibe as estatísticas de defesa do grupo
int grupo_FeP();//exibe as estatísticas de faltas e pênaltis do grupo
int grupo_Imp();//exibe as estatísticas de impedimentos do grupo
int jogador_dados();//mostra os dados gerais do jogador
int jogador_GeF();//exibe as estatísticas de gol e finalização do jogador
int jogador_PeA();//exibe as estatísticas de passes e assistências do jogador
int jogador_Des();//exibe as estatísticas de desarmes do jogador
int jogador_Def();//exibe as estatísticas de defesa do jogador
int jogador_FeP();//exibe as estatísticas de faltas e pênaltis do jogador
int jogador_Imp();//exibe as estatísticas de impedimentos do jogador
int jogador_notas();//exibe as estatísticas de notas do jogador

/* Funcao principal */

int main()
{
    int comando;

    int i,j;
    for(i=0;i<100;i++)
    {
        jogo[i].controle=0; // zerando os controles dos jogos
    }
    for(i=0;i<40;i++)
    {
        elenco[i].controle=0; // zerando os controles dos jogadores
        elenco[i].uniforme=0; // zerando os uniformes dos jogadores
        elenco[i].jogos=0;
        for(j=0;j<100;j++) // zerando os jogos dos jogadores
            elenco[i].jogou[j]=0;
        for(j=0;j<18;j++)
            elenco[i].posicao[j]=0; // zerando as posições dos jogadores
        // zerando as medias dos jogadores
        elenco[i].media_assistF=0;
        elenco[i].media_assistG=0;
        elenco[i].media_desarmes=0;
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
        elenco[i].pos_mais_usada=0;
    }
    for(i=0;i<10;i++)
    {
        goleiros[i].controle=0; // zerando os controles dos goleiros
        goleiros[i].uniforme=0; // zerando os uniformes dos goleiros
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
        goleiros[i].media_imped=0;
        goleiros[i].media_notas=0;
        goleiros[i].media_passesC=0;
        goleiros[i].media_passesE=0;
        goleiros[i].media_penaltisC=0;
        goleiros[i].media_penaltisS=0;
        goleiros[i].media_penaltisP=0;
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
        printf("-> ");
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
                inserir_dados(); // entra na função que cadastra insere dados de uma partida
                break;

            case 5:
                editar_dados(); // entra na função que cadastra edita dados de uma partida
                break;

            case 6:
                estatisticas_jogador(); // entra na função que exibe as estatisticas de um jogador
                break;

            case 7:
                estatisticas_grupo(); // entra na função que exibe as estatisticas do grupo
                break;

            case 0:
                system("cls");
                printf("\t\tAte logo!\n");  // sai do sistema
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
    printf("1. Jogador.\t2. Goleiro.\n->");//solicita que o usuário defina se é goleiro ou não
    while(pos!=1 && pos!=2){//verifica se entrada é valida (apenas 1 e 2 permitidos)
        scanf("%d",&pos);
        if(pos!=1 && pos!=2)
            printf("Digite uma opcao valida ->");
    }
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
        fgets(elenco[n].nome,100,stdin);
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
        printf("-> ");
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
                p[i]=ch; // caso seja uma letra maiucula, armazena o caractere na string p
                i++;
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
        fgets(goleiros[n].nome,100,stdin);
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
    for(n=0;n<40;n++) // percorrendo todas os jogadores possíveis
    {
        if(num_uniforme==elenco[n].uniforme)    // verifica a quem o numero de uniforme requerido pertence
        {
            // reescreve os dados
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
            printf("-> ");
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
    system("PAUSE");
    return 0;
}

/* Função que exclui o cadastro de um jogador */

int excluir()
{
    system("cls");
    printf("\tExcluir cadastro de jogador.\n\n");
    int num_jogador=lista_jogadores(); // pedindo ao usuário qual jogador (por uniforme) ele quer excluir
    int i,j,encontrado=0; // variaveis auxiliares
    for(i=0;i<10;i++)
    {
        if(num_jogador==goleiros[i].uniforme)  // verifica se tem um goleiro com esse numero de uniforme, se sim, qual
        {
            // zerando todos os dados do goleiro
            goleiros[i].controle=0;
            goleiros[i].uniforme=0;
            for(j=0;j<100;j++)
                goleiros[i].jogou[j]=0;
            goleiros[i].media_assistF=0;
            goleiros[i].media_assistG=0;
            goleiros[i].media_defesas=0;
            goleiros[i].media_faltasC=0;
            goleiros[i].media_faltasS=0;
            goleiros[i].media_golsC=0;
            goleiros[i].media_golsS=0;
            goleiros[i].media_imped=0;
            goleiros[i].media_notas=0;
            goleiros[i].media_passesC=0;
            goleiros[i].media_passesE=0;
            goleiros[i].media_penaltisC=0;
            goleiros[i].media_penaltisS=0;
            goleiros[i].media_penaltisP=0;
            goleiros[i].jogos=0;

            encontrado++;
            break;
        }
    }
    for(i=0;i<40;i++)
    {
        if(encontrado==1)
            break;
        if(num_jogador==elenco[i].uniforme)  // verifica se tem um jogador com esse numero de uniforme, se sim, qual
        {
            // zerando todos os dados do jogador
            elenco[i].controle=0;
            elenco[i].uniforme=0;
            for(j=0;j<18;j++)
                elenco[i].posicao[j]=0;
            for(j=0;j<100;j++)
                elenco[i].jogou[j]=0;
            elenco[i].media_assistF=0;
            elenco[i].media_assistG=0;
            elenco[i].media_desarmes=0;
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
            elenco[i].pos_mais_usada=0;
            elenco[i].jogos=0;

            break;
        }
    }
    system("PAUSE");
    return 0;
}

/* Função que insere os dados de uma partida */

int inserir_dados()
{
    system("cls");
    int n,i,j,num_uniforme; // variaveis auxiliares
    for(i=0;i<100;i++) // percorre todos os jogos possiveis, para verificar um espaço vazio
    {
        if(jogo[i].controle==0)
        {
            n=i;
            break;
        }
    }
    printf("\tInserir dados de uma partida.\n\n");
    // inserindo dados
    printf("Adversario: ");
    setbuf(stdin, NULL);
    fgets(jogo[n].adversario,100,stdin);
    printf("Gols feitos: ");
    scanf("%d",&jogo[n].gols_pro);
    printf("Gols sofridos: ");
    scanf("%d",&jogo[n].gols_contra);
    jogo[n].saldo_gols=jogo[n].gols_pro-jogo[n].gols_contra;
    printf("Substituicoes feitas na partida: ");
    scanf("%d",&jogo[n].substituicoes);
    for(i=0;i<11+jogo[n].substituicoes;i++) // loop que percorre todos os jogadores que jogaram a partida
    {
        printf("Insira o numero do uniforme do jogador: ");
        scanf("%d",&num_uniforme);
        for(j=0;j<10;j++)
        {
            if(num_uniforme==goleiros[j].uniforme) // verifica se o numero do uniforme é de um goleiro, e de qual
            {
                goleiros[j].jogos++;
                goleiros[j].jogou[n]=1;
                printf("%s:\n",goleiros[j].nome[n]);
                printf("  Defesas: ");
                scanf("%d",&goleiros[j].defesas[n]);
                goleiros[j].media_defesas=media_jogador(goleiros[j].defesas,goleiros[j].uniforme);
                printf("  Passes corretos: ");
                scanf("%d",&goleiros[j].passesC[n]);
                goleiros[j].media_passesC=media_jogador(goleiros[j].passesC,goleiros[j].uniforme);
                printf("  Passes errados: ");
                scanf("%d",&goleiros[j].passesE[n]);
                goleiros[j].media_passesE=media_jogador(goleiros[j].passesE,goleiros[j].uniforme);
                printf("  Gols sofridos: ");
                scanf("%d",&goleiros[j].golsS[n]);
                goleiros[j].media_golsS=media_jogador(goleiros[j].golsS,goleiros[j].uniforme);
                printf("  Gols convertidos: ");
                scanf("%d",&goleiros[j].golsC[n]);
                goleiros[j].media_golsC=media_jogador(goleiros[j].golsC,goleiros[j].uniforme);
                printf("  Faltas cometidas: ");
                scanf("%d",&goleiros[j].faltasC[n]);
                goleiros[j].media_faltasC=media_jogador(goleiros[j].faltasC,goleiros[j].uniforme);
                printf("  Faltas sofridas: ");
                scanf("%d",&goleiros[j].faltasS[n]);
                goleiros[j].media_faltasS=media_jogador(goleiros[j].faltasS,goleiros[j].uniforme);
                printf("  Impedimentos: ");
                scanf("%d",&goleiros[j].imped[n]);
                goleiros[j].media_imped=media_jogador(goleiros[j].imped,goleiros[j].uniforme);
                printf("  Assistencias (gol): ");
                scanf("%d",&goleiros[j].assistG[n]);
                goleiros[j].media_assistG=media_jogador(goleiros[j].assistG,goleiros[j].uniforme);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&goleiros[j].assistF[n]);
                goleiros[j].media_assistF=media_jogador(goleiros[j].assistF,goleiros[j].uniforme);
                printf("  Penaltis cometidos: ");
                scanf("%d",&goleiros[j].penaltisC[n]);
                goleiros[j].media_penaltisC=media_jogador(goleiros[j].penaltisC,goleiros[j].uniforme);
                printf("  Penaltis sofridos: ");
                scanf("%d",&goleiros[j].penaltisS[n]);
                goleiros[j].media_penaltisS=media_jogador(goleiros[j].penaltisS,goleiros[j].uniforme);
                printf("  Penaltis perdidos: ");
                scanf("%d",&goleiros[j].penaltisP[n]);
                goleiros[j].media_penaltisP=media_jogador(goleiros[j].penaltisP,goleiros[j].uniforme);
            }
        }
        char pos[4]; // variavel para armazenar a posicao jogada na partida
        for(j=0;j<40;j++)
        {
            if(num_uniforme==elenco[j].uniforme) // verifica se o numero do uniforme é de um jogador, e de qual
            {
                elenco[j].jogos++;
                elenco[j].jogou[n]=1;
                printf("%s:\n",elenco[j].nome);
                printf("  Sigla da posicao inicial na partida: ");
                scanf("%s",&pos);
                if(strcmp(pos,"ZD")==0)
                    elenco[j].posicao[n]=1;
                if(strcmp(pos,"ZE")==0)
                    elenco[j].posicao[n]=2;
                if(strcmp(pos,"ZC")==0)
                    elenco[j].posicao[n]=3;
                if(strcmp(pos,"LDD")==0)
                    elenco[j].posicao[n]=4;
                if(strcmp(pos,"LED")==0)
                    elenco[j].posicao[n]=5;
                if(strcmp(pos,"LDO")==0)
                    elenco[j].posicao[n]=6;
                if(strcmp(pos,"LEO")==0)
                    elenco[j].posicao[n]=7;
                if(strcmp(pos,"PV")==0)
                    elenco[j].posicao[n]=8;
                if(strcmp(pos,"SV")==0)
                    elenco[j].posicao[n]=9;
                if(strcmp(pos,"ARM")==0)
                    elenco[j].posicao[n]=10;
                if(strcmp(pos,"MD")==0)
                    elenco[j].posicao[n]=11;
                if(strcmp(pos,"ME")==0)
                    elenco[j].posicao[n]=12;
                if(strcmp(pos,"MA")==0)
                    elenco[j].posicao[n]=13;
                if(strcmp(pos,"SE")==0)
                    elenco[j].posicao[n]=14;
                if(strcmp(pos,"PD")==0)
                    elenco[j].posicao[n]=15;
                if(strcmp(pos,"PE")==0)
                    elenco[j].posicao[n]=16;
                if(strcmp(pos,"SA")==0)
                    elenco[j].posicao[n]=17;
                if(strcmp(pos,"CA")==0)
                    elenco[j].posicao[n]=18;
                printf("  Passes corretos: ");
                scanf("%d",&elenco[j].passesC[n]);
                elenco[j].media_passesC=media_jogador(&elenco[j].passesC,elenco[j].uniforme);
                printf("  Passes errados: ");
                scanf("%d",&elenco[j].passesE[n]);
                elenco[j].media_passesE=media_jogador(&elenco[j].passesE,elenco[j].uniforme);
                printf("  Finalizacoes corretas: ");
                scanf("%d",&elenco[j].finalizacoesC[n]);
                elenco[j].media_finalizacoesC=media_jogador(&elenco[j].finalizacoesC,elenco[j].uniforme);
                printf("  Finalizacoes erradas: ");
                scanf("%d",&elenco[j].finalizacoesE[n]);
                elenco[j].media_finalizacoesE=media_jogador(&elenco[j].finalizacoesE,elenco[j].uniforme);
                printf("  Desarmes: ");
                scanf("%d",&elenco[j].desarmes[n]);
                elenco[j].media_desarmes=media_jogador(&elenco[j].desarmes,elenco[j].uniforme);
                printf("  Gols: ");
                scanf("%d",&elenco[j].gols[n]);
                elenco[j].media_gols=media_jogador(&elenco[j].gols,elenco[j].uniforme);
                printf("  Faltas cometidas: ");
                scanf("%d",&elenco[j].faltasC[n]);
                elenco[j].media_faltasC=media_jogador(&elenco[j].faltasC,elenco[j].uniforme);
                printf("  Faltas sofridas: ");
                scanf("%d",&elenco[j].faltasS[n]);
                elenco[j].media_faltasS=media_jogador(&elenco[j].faltasS,elenco[j].uniforme);
                printf("  Impedimentos: ");
                scanf("%d",&elenco[j].imped[n]);
                elenco[j].media_imped=media_jogador(&elenco[j].imped,elenco[j].uniforme);
                printf("  Assistencias (gol): ");
                scanf("%d",&elenco[j].assistG[n]);
                elenco[j].media_assistG=media_jogador(&elenco[j].assistG,elenco[j].uniforme);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&elenco[j].assistF[n]);
                elenco[j].media_assistF=media_jogador(&elenco[j].assistF,elenco[j].uniforme);
                printf("  Penaltis cometidos: ");
                scanf("%d",&elenco[j].penaltisC[n]);
                elenco[j].media_penaltisC=media_jogador(&elenco[j].penaltisC,elenco[j].uniforme);
                printf("  Penaltis sofridos: ");
                scanf("%d",&elenco[j].penaltisS[n]);
                elenco[j].media_penaltisS=media_jogador(&elenco[j].penaltisS,elenco[j].uniforme);
                printf("  Penaltis perdidos: ");
                scanf("%d",&elenco[j].penaltisP[n]);
                elenco[j].media_penaltisP=media_jogador(&elenco[j].penaltisP,elenco[j].uniforme);
            }
        }
    }
    system("pause");
    return 0;
}

/* Funcao que edita os dados de uma partida */

int editar_dados()
{
    system("cls");
    printf("\tEditar dados de uma partida.\n\n");
    int n=lista_jogos();
    int i,j,num_uniforme; // variaveis auxiliares
    // zerando os dados da partida
    for(i=0;i<10;i++)
    {
        if(goleiros[i].jogou[n]==1){
            goleiros[i].jogos--;
            goleiros[i].jogou[n]=0;
            goleiros[i].media_defesas=media_jogador(goleiros[i].defesas,goleiros[i].uniforme);
            goleiros[i].media_imped=media_jogador(goleiros[i].imped,goleiros[i].uniforme);
            goleiros[i].media_assistF=media_jogador(goleiros[i].assistF,goleiros[i].uniforme);
            goleiros[i].media_assistG=media_jogador(goleiros[i].assistG,goleiros[i].uniforme);
            goleiros[i].media_passesC=media_jogador(goleiros[i].passesC,goleiros[i].uniforme);
            goleiros[i].media_passesE=media_jogador(goleiros[i].passesE,goleiros[i].uniforme);
            goleiros[i].media_golsC=media_jogador(goleiros[i].golsC,goleiros[i].uniforme);
            goleiros[i].media_golsS=media_jogador(goleiros[i].golsS,goleiros[i].uniforme);
            goleiros[i].media_faltasC=media_jogador(goleiros[i].faltasC,goleiros[i].uniforme);
            goleiros[i].media_faltasS=media_jogador(goleiros[i].faltasS,goleiros[i].uniforme);
            goleiros[i].media_penaltisC=media_jogador(goleiros[i].penaltisC,goleiros[i].uniforme);
            goleiros[i].media_penaltisP=media_jogador(goleiros[i].penaltisP,goleiros[i].uniforme);
            goleiros[i].media_penaltisS=media_jogador(goleiros[i].penaltisS,goleiros[i].uniforme);
            goleiros[i].media_notas=media_jogador(goleiros[i].notas,goleiros[i].uniforme);
        }
        goleiros[i].passesC[n]=0;
        goleiros[i].passesE[n]=0;
        goleiros[i].golsC[n]=0;
        goleiros[i].golsS[n]=0;
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
            elenco[i].media_passesC=media_jogador(elenco[i].passesC,elenco[i].uniforme);
            elenco[i].media_passesE=media_jogador(elenco[i].passesE,elenco[i].uniforme);
            elenco[i].media_gols=media_jogador(elenco[i].gols,elenco[i].uniforme);
            elenco[i].media_finalizacoesC=media_jogador(elenco[i].finalizacoesC,elenco[i].uniforme);
            elenco[i].media_finalizacoesE=media_jogador(elenco[i].finalizacoesE,elenco[i].uniforme);
            elenco[i].media_desarmes=media_jogador(elenco[i].desarmes,elenco[i].uniforme);
            elenco[i].media_imped=media_jogador(elenco[i].imped,elenco[i].uniforme);
            elenco[i].media_assistF=media_jogador(elenco[i].assistF,elenco[i].uniforme);
            elenco[i].media_assistG=media_jogador(elenco[i].assistG,elenco[i].uniforme);
            elenco[i].media_faltasC=media_jogador(elenco[i].faltasC,elenco[i].uniforme);
            elenco[i].media_faltasS=media_jogador(elenco[i].faltasS,elenco[i].uniforme);
            elenco[i].media_penaltisC=media_jogador(elenco[i].penaltisC,elenco[i].uniforme);
            elenco[i].media_penaltisP=media_jogador(elenco[i].penaltisP,elenco[i].uniforme);
            elenco[i].media_penaltisS=media_jogador(elenco[i].penaltisS,elenco[i].uniforme);
            elenco[i].media_notas=media_jogador(elenco[i].notas,elenco[i].uniforme);
        }
        elenco[i].passesC[n]=0;
        elenco[i].passesE[n]=0;
        elenco[i].gols[n]=0;
        elenco[i].finalizacoesC[n]=0;
        elenco[i].finalizacoesE[n]=0;
        elenco[i].desarmes[n]=0;
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
    printf("Adversario: ");
    setbuf(stdin, NULL);
    fgets(jogo[n].adversario,100,stdin);
    printf("Gols feitos: ");
    scanf("%d",&jogo[n].gols_pro);
    printf("Gols sofridos: ");
    scanf("%d",&jogo[n].gols_contra);
    jogo[n].saldo_gols=jogo[n].gols_pro-jogo[n].gols_contra;
    printf("Substituicoes feitas na partida: ");
    scanf("%d",&jogo[n].substituicoes);
    for(i=0;i<11+jogo[n].substituicoes;i++) // loop que percorre todos os jogadores que jogaram a partida
    {
        printf("Insira o numero do uniforme do jogador: ");
        scanf("%d",&num_uniforme);
        for(j=0;j<10;j++)
        {
            if(num_uniforme==goleiros[j].uniforme) // verifica se o numero do uniforme é de um goleiro, e de qual
            {
                goleiros[j].jogos++;
                goleiros[j].jogou[n]=1;
                printf("%s:\n",goleiros[j].nome[n]);
                printf("  Defesas: ");
                scanf("%d",&goleiros[j].defesas[n]);
                printf("  Passes corretos: ");
                scanf("%d",&goleiros[j].passesC[n]);
                printf("  Passes errados: ");
                scanf("%d",&goleiros[j].passesE[n]);
                printf("  Gols sofridos: ");
                scanf("%d",&goleiros[j].golsS[n]);
                printf("  Gols convertidos: ");
                scanf("%d",&goleiros[j].golsC[n]);
                printf("  Faltas cometidas: ");
                scanf("%d",&goleiros[j].faltasC[n]);
                printf("  Faltas sofridas: ");
                scanf("%d",&goleiros[j].faltasS[n]);
                printf("  Impedimentos: ");
                scanf("%d",&goleiros[j].imped[n]);
                printf("  Assistencias (gol): ");
                scanf("%d",&goleiros[j].assistG[n]);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&goleiros[j].assistF[n]);
                printf("  Penaltis cometidos: ");
                scanf("%d",&goleiros[j].penaltisC[n]);
                printf("  Penaltis sofridos: ");
                scanf("%d",&goleiros[j].penaltisS[n]);
                printf("  Penaltis perdidos: ");
                scanf("%d",&goleiros[j].penaltisP[n]);
            }
        }
        char pos[4]; // variavel para armazenar a posicao jogada na partida
        for(j=0;j<40;j++)
        {
            if(num_uniforme==elenco[j].uniforme) // verifica se o numero do uniforme é de um jogador, e de qual
            {
                elenco[j].jogos++;
                elenco[j].jogou[n]=1;
                printf("%s:\n",elenco[j].nome);
                printf("  Sigla da posicao inicial na partida: ");
                scanf("%s",&pos);
                if(strcmp(pos,"ZD")==0)
                    elenco[j].posicao[n]=1;
                if(strcmp(pos,"ZE")==0)
                    elenco[j].posicao[n]=2;
                if(strcmp(pos,"ZC")==0)
                    elenco[j].posicao[n]=3;
                if(strcmp(pos,"LDD")==0)
                    elenco[j].posicao[n]=4;
                if(strcmp(pos,"LED")==0)
                    elenco[j].posicao[n]=5;
                if(strcmp(pos,"LDO")==0)
                    elenco[j].posicao[n]=6;
                if(strcmp(pos,"LEO")==0)
                    elenco[j].posicao[n]=7;
                if(strcmp(pos,"PV")==0)
                    elenco[j].posicao[n]=8;
                if(strcmp(pos,"SV")==0)
                    elenco[j].posicao[n]=9;
                if(strcmp(pos,"ARM")==0)
                    elenco[j].posicao[n]=10;
                if(strcmp(pos,"MD")==0)
                    elenco[j].posicao[n]=11;
                if(strcmp(pos,"ME")==0)
                    elenco[j].posicao[n]=12;
                if(strcmp(pos,"MA")==0)
                    elenco[j].posicao[n]=13;
                if(strcmp(pos,"SE")==0)
                    elenco[j].posicao[n]=14;
                if(strcmp(pos,"PD")==0)
                    elenco[j].posicao[n]=15;
                if(strcmp(pos,"PE")==0)
                    elenco[j].posicao[n]=16;
                if(strcmp(pos,"SA")==0)
                    elenco[j].posicao[n]=17;
                if(strcmp(pos,"CA")==0)
                    elenco[j].posicao[n]=18;
                printf("  Passes corretos: ");
                scanf("%d",&elenco[j].passesC[n]);
                printf("  Passes errados: ");
                scanf("%d",&elenco[j].passesE[n]);
                printf("  Finalizacoes corretas: ");
                scanf("%d",&elenco[j].finalizacoesC[n]);
                printf("  Finalizacoes erradas: ");
                scanf("%d",&elenco[j].finalizacoesE[n]);
                printf("  Desarmes: ");
                scanf("%d",&elenco[j].desarmes[n]);
                printf("  Gols: ");
                scanf("%d",&elenco[j].gols[n]);
                printf("  Faltas cometidas: ");
                scanf("%d",&elenco[j].faltasC[n]);
                printf("  Faltas sofridas: ");
                scanf("%d",&elenco[j].faltasS[n]);
                printf("  Impedimentos: ");
                scanf("%d",&elenco[j].imped[n]);
                printf("  Assistencias (gol): ");
                scanf("%d",&elenco[j].assistG[n]);
                printf("  Assistencias (finalizacao): ");
                scanf("%d",&elenco[j].assistF[n]);
                printf("  Penaltis cometidos: ");
                scanf("%d",&elenco[j].penaltisC[n]);
                printf("  Penaltis sofridos: ");
                scanf("%d",&elenco[j].penaltisS[n]);
                printf("  Penaltis perdidos: ");
                scanf("%d",&elenco[j].penaltisP[n]);
            }
        }
    }
    system("PAUSE");
    return 0;
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

/* Função que lista todos os jogos já ocorridos */

int lista_jogos()
{
    int i,opc; // variaveis auxiliares
    for(i=0;i<100;i++)
    {
        if(jogo[i].controle==1)
        {
            printf("%d.  %d x %d %s.\n",i+1,jogo[i].gols_pro,jogo[i].gols_contra,jogo[i].adversario); // imprimindo todas as opções de jogos
        }
    }
    printf("-> ");
    scanf("%d",&opc);

    return opc-1; // retorna a posição do vetor jogo[] do jogo requerido
}

/* Funcao que calcula a media de um jogador (FUNÇÃO NÃO TESTADA - NÃO TESTAR)*/

float media_jogador(int *vet, int num_jogador)
{
    int i,j,soma; // variaveis auxiliares
    float media; // variavel para armazenar a media requerida
    for(i=0;i<10;i++)
    {
        if(num_jogador==goleiros[i].uniforme) // verificando se o uniforme do requerido pertence a um goleiro, e qual
        {
            for(j=0;j<100;j++)
            {
                if(goleiros[i].jogou[j]==1)
                    soma+=vet[j]; // somando todos os dados pedidos
            }
            media=(float)soma/goleiros[i].jogos; // calculando a media desses dados, por partida

            break;
        }
    }
    for(i=0;i<40;i++)
    {
        if(num_jogador==elenco[i].uniforme) // verificando se o uniforme do requerido pertence a um jogador, e qual
        {
            for(j=0;j<100;j++)
            {
                if(elenco[i].jogou[j]==1)
                    soma+=vet[j]; // somando todos os dados pedidos
            }
            media=(float)soma/elenco[i].jogos;

            break;
        }
    }

    return media;
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

/* Funcao que exibe as estatisticas de desarmes do grupo */

int grupo_Des()
{

}

/* Funcao que exibe as estatisticas de defesas do grupo */

int grupo_Def()
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

int jogador_Des()
{

}

/* Funcao que exibe as estatisticas de defesas de um jogador */

int jogador_Def()
{

}

/* Funcao que exibe as estatisticas de faltas e penaltis de um jogador */

int jogador_FeP()
{

}

/* Funcao que exibe as estatisticas de impedimentos de um jogador */

int jogador_Imp()
{

}

/* Funcao que exibe as estatisticas de notas de um jogador */

int jogador_notas()
{

}
