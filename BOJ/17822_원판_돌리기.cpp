#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int N, M, T;
int board[55][55];
bool check[55][55];

int main(){
    cin >> N >> M >> T;
    for(int i=1; i<=N; i++)
        for(int j=0; j<M; j++)
            cin >> board[i][j];

    for(int k=0; k<T; k++){
        int X, D, K;
        cin >> X >> D >> K;
        if(D==0){ // 시계방향
            for(int i=X; i<=N; i+=X){

                deque<int> dq;
                for(int j=0; j<M; j++)
                    dq.push_back(board[i][j]);

                for(int j=1; j<=K; j++){
                    dq.push_front(dq.back());
                    dq.pop_back();
                }

                for(int j=0; j<M; j++)
                    board[i][j] = dq[j];
            }

        }
        else { // 반시계방향
            for(int i=X; i<=N; i+=X){

                deque<int> dq;
                for(int j=0; j<M; j++)
                    dq.push_back(board[i][j]);

                for(int j=1; j<=K; j++){
                    dq.push_back(dq.front());
                    dq.pop_front();
                }

                for(int j=0; j<M; j++)
                    board[i][j] = dq[j];
            }
        }

        memset(check, 0, sizeof(check));
        bool flag=false;

        for(int i=1; i<=N; i++){
            
            for(int j=0; j<M; j++){
                if(board[i][j]==0) continue;

                if(j==M-1){
                    if(board[i][j]==board[i][0]){
                        check[i][j]=true;
                        check[i][0]=true;
                        flag=true;
                    }
                }
                else{
                    if(board[i][j]==board[i][j+1]){
                        check[i][j]=true;
                        check[i][j+1]=true;
                        flag=true;
                    }
                }
            }
        }

        for(int j=0; j<M; j++){
            for(int i=1; i<N; i++){
                if(board[i][j]==0) continue;

                if(board[i][j]==board[i+1][j]){
                    check[i][j]=true;
                    check[i+1][j]=true;
                    flag=true;
                }
            }
        }
        
        if(flag){
            for(int i=1; i<=N; i++){
                for(int j=0; j<M; j++){
                    if(check[i][j]==true){
                        board[i][j]=0;
                    }
                }
            }
        }
        else{
            float avg=0;
            int sum=0;
            int cnt=0;

            for(int i=1; i<=N; i++){
                for(int j=0; j<M; j++){
                    if(board[i][j]!=0){
                        cnt++;
                        sum += board[i][j];
                    }
                }
            }

            if(sum!=0) avg = (float)sum/ (float)cnt;
            for(int i=1; i<=N; i++){
                for(int j=0; j<M; j++){
                    if(board[i][j]==0) continue;

                    if(avg<board[i][j])
                        board[i][j]-=1;
                    else if(avg>board[i][j])
                        board[i][j]+=1;
                }
            }
        }
    }


    int ans = 0;

    for(int i=1; i<=N; i++)
        for(int j=0; j<M; j++)
            ans += board[i][j];

    
    cout << ans;
    return 0;
}