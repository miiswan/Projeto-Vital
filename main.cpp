#include "Stopwatch.hpp" //biblioteca pro cronometro
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define v 0       // vazio
#define p 1       // parede
#define s 2       // saída
#define comida 3  // comida

int pontos=0, linha=1, coluna=1;
using namespace std;

// Função protótipo para jogar
void jogar();

int mapa[30][30] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,3,0,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1,1},
    {1,0,1,1,0,1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,3,1},
    {1,0,1,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1},
    {1,0,1,0,1,1,1,0,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0,0,0,1}, // mapa generico 
    {1,0,0,0,0,3,1,0,1,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1},
    {1,0,1,1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1},
    {1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,1,0,0,3,1,0,1,0,0,0,0,3,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,0,1,1,1,0,0,0,1,0,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,3,0,1,1,0,1,1},
    {1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,1,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1},
    {1,0,0,0,0,3,1,0,0,0,1,0,1,1,1,0,1,3,1,0,0,0,1,0,1,3,1,0,0,1},
    {1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,3,1,0,1,0,1,0,1,0,1,1,1,0,1,1},
    {1,3,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,1},
    {1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1,1,0,0,1,0,0,1,0,0,0,1,1,1,0,1,1,1,0,1,1},
    {1,1,1,0,1,0,0,0,3,1,0,0,1,1,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,1,1,1},
    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,3,1},
    {1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int menu(){
    system("color 0F"); // Muda a cor do terminal para branco
    int escolha;
    cout << "Menu de opciones" << endl;
    cout << "1. jogar" << endl;
    cout << "2. ver pontuação" << endl;
    cout << "3. sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> escolha;
    switch (escolha)
    {
    case 1:
        // código para jogar
        system("cls");
        jogar();
        break;
    case 2:
        // código para ver pontuação
        break;
    case 3:
        cout << "Saindo do jogo..." << endl;
        system("pause");
        system("cls");
        return 0;
    
    default:
        cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
        system("pause");
        system("cls");
        return menu(); // Chama o menu novamente
        break;
    }
    return 0;
}

void monta_mapa(){
    int l, c;
    for(l=0; l<30; l++){
        for(c=0; c<30; c++){
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

void jogar(){
    int key, saiu=0;
    namespace sw = stopwatch; // namespace necessario
    sw::Stopwatch my_watch; // cria o cronometro
    my_watch.start(); // começa o cronometro
    system("color 0A"); // Muda a cor do terminal para verde
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
    std::uint64_t elapsed_s = my_watch.elapsed<sw::seconds>();  // duração de quanto demorou pra concluir a ação, nesse caso o labirinto em segundos
    std::uint64_t minutes = elapsed_s / 60;// Calcula minutos
    std::uint64_t seconds = elapsed_s % 60;// Calcula segundos restantes
    std::cout << "Tempo decorrido: " << minutes << " minutos e " << seconds << " segundos" << std::endl;// resultado na tela
    menu(); // Volta para o menu após jogar
}



int main()
{
    menu();
    return 0;
}
