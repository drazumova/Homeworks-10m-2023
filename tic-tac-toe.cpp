#include <iostream>
using namespace std;
template<int N>
class game{
private:
    int board[N][N];
    int currentPlayer;

public:
    game(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                board[i][j]=0;
            }
        }
        currentPlayer=1;
    }
    bool makeMove(int x,int y){
        if(board[x][y]==0){
            board[x][y]=currentPlayer;
            currentPlayer=(currentPlayer==1)? 2 : 1;//меняем игрока
            return true;
        } 
        else{
            return false;
        }
    }
    int getStatus(){
        for(int i=0;i<N;i++) {
            if(board[i][0]!=0 && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
                return board[i][0];
            }
        }
        for(int j=0;j<N;j++) {
            if(board[0][j]!=0 && board[0][j]==board[1][j] && board[1][j]==board[2][j]){
                return board[0][j];
            }
        }
        if(board[0][0]!=0 && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            return board[0][0];
        }
        if(board[0][2]!=0 && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            return board[0][2];
        }
        bool isDraw=true;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]==0){
                    isDraw=false;
                    break;
                }
            }
            if(isDraw==false){
                break;
            }
        }
        if(isDraw==true){
            return 3;
        }
        return 0;
    }
};
int main(){}