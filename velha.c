#include <stdio.h>
#include <string.h>
#include<time.h>
#include <stdlib.h>

char jogo[4][4] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
}; //Linha Coluna  
char p1 = 'X',
     p2 = 'O',
     jX = '1',
     jO = '2';

int rodadas = 0;

void mostrar();
void limparJogo();
char checar();
int aleatorizar();
void getPlayers();
void jogar(int start);

void mostrar(){
    int a = 0,b=0;
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            printf(" %c ", jogo[x][y]);
            a++;
            if(a==3) printf("\n");
            else printf("|");
        }
        a=0;
        b++;
        if(b<3)
            printf("-----------\n");
        else
            printf("\n");
    }
}

void limparJogo(){
    for(int x=0;x<3;x++)
        for(int y=0;y<3;y++)
            jogo[x][y] = ' ';
}

char checar(){
    //Checar linhas
    for(int x=0;x<3;x++)
        if(jogo[x][0] == jogo[x][1] && jogo[x][1] == jogo[x][2] && jogo[x][1] != ' ')
            return jogo[x][0];
    //Checar colunas
    for(int y=0;y<3;y++)
        if(jogo[0][y] == jogo[1][y] && jogo[1][y] == jogo[2][y] && jogo[0][y] != ' ')
            return jogo[0][y];
    //Checar diagonais
    if(jogo[0][0]==jogo[1][1] && jogo[1][1]==jogo[2][2] && jogo[0][0] != ' ')
        return jogo[0][0];
    if(jogo[0][2]==jogo[1][1] && jogo[1][1]==jogo[2][0] && jogo[0][2] != ' ')
        return jogo[0][2];
    
    for(int x=0;x<3;x++)
        for(int y=0;y<3;y++)
            if(jogo[x][y]==' ')
                return 'J'; //Ainda é jogavel!
    return 'V';             //Deu velha! Acabar o jogo!
}

int aleatorizar(){
    srand(time(NULL));
    return (rand()%2) + 1;
}

void getPlayers(){
    printf("Jogador P1: ");
    scanf(" %c", &p1);
    if(p1 == 'X' || p1 == 'x'){
        printf("Jogador P2: O\n\n");
        p1 = 'X';
        p2 = 'O';
        jX = '1';
        jO = '2';
    }else if(p1 == 'O' || p1 == 'o'){
        printf("Jogador P2: X\n\n");
        p1 = 'O';
        p2 = 'X';
        jX = '2';
        jO = '1';
    }else{
        printf("Opcao invalida!\n");
        getPlayers();
    }
}

void jogar(int jogador){
    rodadas++;

    int flag = 0,pos=10;

    int x,y;

    while(flag == 0){
        printf("Escolha P%d:",jogador);
        scanf("%d",&pos);
        if(pos<1 || pos>9) printf ("Posicao invalida!\n");
        else{
            pos--;
            x = pos/3;
            y = pos%3;
            if(jogo[x][y] == ' ')
                if(jogador==1){
                    jogo[x][y] = p1;
                    flag++;
                }
                else if(jogador==2){
                    jogo[x][y] = p2;
                    flag++;
                }
        }
    }
    printf("\n");
    mostrar();
    if(rodadas < 9 && checar()=='J')
        if(jogador==1) jogar(2);
        else jogar(1);
    else{
        switch (checar()){
        case 'X':
            printf("Vencedor: P%c!\n",jX);
            break;
        case 'O':
            printf("Vencedor: P%c!\n",jO);
            break;
        default:
            printf("Deu velha!");
            break;
        }
    }
}

void main(){
    //limparJogo();
    int start = aleatorizar();
    getPlayers();

    printf("Vencedor do Sorteio: P%d comeca!\n",start);
    printf("Escolha as posicoes de acordo com a matriz abaixo:\n");
    mostrar();
    limparJogo();
    jogar(start);
}