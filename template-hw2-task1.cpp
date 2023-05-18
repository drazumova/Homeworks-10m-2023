#include <iostream>

using namespace std;

template<int n>
class TicTac {
    int status;
    char field[n][n];
    int cnt;
    
    int check_win() {
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                if(field[i][j] == field[i + 1][j] && field[i + 1][j] == field[i + 2][j]) {
                    if(field[i][j] == 'x') return 1;
                    if(field[i][j] == '0') return 2;
                }
                if(field[i][j] == field[i][j + 1] && field[i][j + 1] == field[i][j + 2]) {
                    if(field[i][j] == 'x') return 1;
                    if(field[i][j] == '0') return 2;
                }
                if(field[i][j] == field[i + 1][j + 1] && field[i + 1][j + 1] == field[i + 2][j + 2]) {
                    if(field[i][j] == 'x') return 1;
                    if(field[i][j] == '0') return 2;
                }
                if(i > 1 && j > 1) {
                    if(field[i][j] == field[i - 1][j - 1] && field[i - 1][j - 1] == field[i - 2][j - 2]) {
                        if(field[i][j] == 'x') return 1;
                        if(field[i][j] == '0') return 2;
                    }    
                }
            }
        }
        return 0;
    }
    
    public:
    TicTac() {
        cnt = 0;
        status = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                field[i][j] = '*';
            }
        }
    }
    
    int get_status() {
        return status;
    }
    
    bool make_move_x(int position_x, int position_y) { //true - сделал ход, иначе нет
        if(status != 0 || cnt % 2 == 1) return false;
        if(position_x <= 0 || position_x > n) return false;
        if(position_y <= 0 || position_y > n) return false;
        if(field[position_x - 1][position_y - 1] != '*') return false;
        
        else {
            field[position_x - 1][position_y - 1] = 'x';
            cnt++;
            int current_status = check_win();
            if(current_status == 0 && cnt == n * n) {
                status = 3; return true;
            }
            else {
                status = current_status;
                return true;
            }
        }
    }
    
    bool make_move_0(int position_x, int position_y) { //true - сделал ход, иначе нет
        if(status != 0 || cnt % 2 == 0) return false;
        if(position_x <= 0 || position_x > n) return false;
        if(position_y <= 0 || position_y > n) return false;
        if(field[position_x - 1][position_y - 1] != '*') return false;
        
        else {
            field[position_x - 1][position_y - 1] = '0';
            cnt++;
            int current_status = check_win();
            if(current_status == 0 && cnt == n * n) {
                status = 3; return true;
            }
            else {
                status = current_status;
                return true;
            }
        }
    }
};

int main() {
}
