#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int board[22][22];
int ans = 0;

void play(int d){
    queue <int> q;

    if(d==0){ // left
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(board[i][j]!=0){
                    q.push(board[i][j]);
                    board[i][j]=0;
                }
            }

            int idx=0;
            while(!q.empty()){
                int x = q.front();
                q.pop();

                if(board[i][idx]==0)
                    board[i][idx]=x;
                else if(board[i][idx]==x)
                    board[i][idx++] *= 2;
                else
                    board[i][++idx] = x;
            }
        }
    }

    else if(d==1){ // right
        for(int i=0; i<N; i++){
            for(int j=N-1; j>=0; j--){
                if(board[i][j]!=0){
                    q.push(board[i][j]);
                    board[i][j]=0;
                }
            }

            int idx=N-1;
            while(!q.empty()){
                int x = q.front();
                q.pop();

                if(board[i][idx]==0)
                    board[i][idx]=x;
                else if(board[i][idx]==x)
                    board[i][idx--] *= 2;
                else
                    board[i][--idx] = x;
            }
        }
    }

    else if(d==2){ // up
        for(int j=0; j<N; j++){
            for(int i=0; i<N; i++){
                if(board[i][j]!=0){
                    q.push(board[i][j]);
                    board[i][j]=0;
                }
            }

            int idx=0;
            while(!q.empty()){
                int x = q.front();
                q.pop();

                if(board[idx][j]==0)
                    board[idx][j]=x;
                else if(board[idx][j]==x)
                    board[idx++][j] *= 2;
                else
                    board[++idx][j] = x;
            }
        }
    }

    else if(d==3){ // down
        for(int j=0; j<N; j++){
            for(int i=N-1; i>=0; i--){
                if(board[i][j]!=0){
                    q.push(board[i][j]);
                    a[i][j]=0;
                }
            }

            int idx=N-1;
            while(!q.empty()){
                int x = q.front();
                q.pop();

                if(board[idx][j]==0)
                    board[idx][j]=x;
                else if(board[idx][j]==x)
                    board[idx--][j] *= 2;
                else
                    board[--idx][j] = x;
            }
        }
    }


}

int func(){
    int res=-1;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            res = max(res, board[i][j]);
    return res;
}

void dfs(int cnt){
    if(cnt==5){
        ans = max(ans, func());
        return;
    }

    int tmp[22][22];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            tmp[i][j] = board[i][j];
    
    for(int dir=0; dir<4; dir++){
        play(dir);
        dfs(cnt+1);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                board[i][j] = tmp[i][j];
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    dfs(0);

    cout << ans;
    return 0;
}