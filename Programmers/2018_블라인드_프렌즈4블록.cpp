#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool check[32][32];
bool flag;

void isBox(int x, int y, vector<string> &board){
    if(board[x][y] == board[x][y+1]
        && board[x][y] == board[x+1][y]
        && board[x][y] == board[x+1][y+1]){
            flag = true;

            check[x][y]=1;
            check[x][y+1]=1;
            check[x+1][y]=1;
            check[x+1][y+1]=1;
        }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1){
        flag = false;
        memset(check, 0, sizeof(check));

        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(board[i][j]=='.') continue;
                isBox(i,j, board);
            }
        }

        if(!flag) break;

        // down
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(check[i][j]==1){
                    answer++;

                    for(int k=i-1; k>=0; k--){
                        board[k+1][j] = board[k][j];
                        board[k][j]='.';
                    }
                }
            }
        }
    }
    
    
    return answer;
}