#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define v 0       // vazio
#define p 1       // parede
#define s 2       // saída
#define comida 3  // comida

int pontos=0, linha=1, coluna=1;

int mapa[13][13] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,3,1,0,0,0,1},
    {1,0,0,1,0,1,1,0,1,0,1,0,1},
    {1,0,1,1,0,1,0,0,1,0,1,0,1},
    {1,0,1,3,0,1,0,1,1,0,1,0,1},
    {1,0,0,0,0,1,0,3,1,0,1,0,1}, // mapa generico 
    {1,0,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,1,3,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,1,3,0,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,0,1},
    {1,3,0,0,0,3,1,3,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,2,1,1}
};

void monta_mapa(){
    int l, c;
    for(l=0; l<13; l++){
        for(c=0; c<13; c++){
            if(l==linha && c==coluna) printf(":)");
            else{
                if(mapa[l][c]==v) printf("  ");                      // espaço vazio
                if(mapa[l][c]==s) printf("##");                      // saída
                if(mapa[l][c]==p) printf("%c%c",219,219);           // parede (██)
                if(mapa[l][c]==comida) printf("**");                // comida
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

int main(){
    int key, saiu=0;

    monta_mapa();
    while(saiu==0){
        key = getch();
        if(key=='w' || key=='W'){
            linha--;
            if(mapa[linha][coluna]==p) linha++;
            if(mapa[linha][coluna]==comida){
                pontos++;
                mapa[linha][coluna] = v;
            }
        }
        if(key=='a' || key=='A'){
            coluna--;
            if(mapa[linha][coluna]==p) coluna++;
            if(mapa[linha][coluna]==comida){
                pontos++;
                mapa[linha][coluna] = v;
            }
        }
        if(key=='s' || key=='S'){
            linha++;
            if(mapa[linha][coluna]==p) linha--;
            if(mapa[linha][coluna]==comida){
                pontos++;
                mapa[linha][coluna] = v;
            }
        }
        if(key=='d' || key=='D'){
            coluna++;
            if(mapa[linha][coluna]==p) coluna--;
            if(mapa[linha][coluna]==comida){
                pontos++;
                mapa[linha][coluna] = v;
            }
        }
        if(mapa[linha][coluna]==s) saiu++;
        system("cls");
        monta_mapa();
    }
    system("cls");
    printf("Você conseguiu sair do labirinto! Você fez %d pontos.\n", pontos);
    system("pause");
}
