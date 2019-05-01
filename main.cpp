#include <windows.h>
#include "gameOfLife.h"

using namespace std;

void gotoxy(int xpos, int ypos){
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
} 


int main(){
    gameOfLife game;
    while(true){
        Sleep(50);
        gotoxy(0,0);
        game.showBoard();
        game.update();
    }
}