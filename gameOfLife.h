#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class gameOfLife{
    private:
        vector<vector<int>> board;
    public:
        gameOfLife(){
            CONSOLE_SCREEN_BUFFER_INFO screen;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen);
            int console_RL = screen.srWindow.Right - screen.srWindow.Left;
            int console_BT = screen.srWindow.Bottom - screen.srWindow.Top;
            board = vector<vector<int>>(console_BT,vector<int>(console_RL/3,0));
            srand(time(0));
            for(auto& i : board) for(auto& j : i) j = rand()%2;
        }
        void update(){
            int m = board.size(), n = board[0].size(), count = 0;
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    count = 0;
                    for(int I = max(i-1, 0); I < min(i+2, m); ++I)
                        for(int J = max(j-1, 0); J < min(j+2, n); ++J)
                            count += board[I][J] & 1;
                    if(count == 3 || count - board[i][j] == 3)
                        board[i][j] |= 2;
                }
            }
            for(auto& i : board) for(auto& j : i) j >>= 1;
        }
        void showBoard(){
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            for(auto& i : board){
                for(auto& j : i){
                    SetConsoleTextAttribute(hConsole, j ? 14 : 8);
                    printf( j ? " o " : " . " );
                }
                printf("\n");
            }
        }

};