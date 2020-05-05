#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int board[55][11];
bool check[10];
int num[10]; // 타순이 적혀있는 배열
bool base[5];

int ans=-1;

int play(){

    int res = 0;
    int start_player = 1;

    for(int i=1; i<=N; i++){ // 1~N 이닝

        // init
        int out_cnt = 0;
        bool flag=false; // 이닝 끝나는지 확인
        memset(base, 0, sizeof(base)); // 새 이닝 시작 할 때마다 초기화

        while(1){
            for(int k=start_player; k<=9; k++){ // 1번 주자부터 9번 주자까지 

                int cur = num[k];
                
                if(board[i][cur]==1){
                    if(base[3]==1) {res++; base[3]=0;}
                    if(base[2]==1) {base[3]=1; base[2]=0;}
                    if(base[1]==1) base[2]=1;

                    base[1]=1;
                }
                else if(board[i][cur]==2){
                    if(base[3]==1) {res++; base[3]=0;}
                    if(base[2]==1) res++;
                    if(base[1]==1) { base[3]=1; base[1]=0;}

                    base[2]=1;
                }
                else if(board[i][cur]==3){
                    if(base[3]==1) res++;
                    if(base[2]==1) {res++; base[2]=0;}
                    if(base[1]==1) {res++; base[1]=0;}

                    base[3]=1;
                }
                else if(board[i][cur]==4){
                    if(base[3]==1) {res++; base[3]=0;}
                    if(base[2]==1) {res++; base[2]=0;}
                    if(base[1]==1) {res++; base[1]=0;}

                    res++;
                }

                else if(board[i][cur]==0)
                    out_cnt++;
                

                if(out_cnt==3){
                    flag=true;

                    start_player = k+1;
                    if(start_player==10) start_player=1;

                    break;
                }
            }

            if(flag) break;
            start_player=1;
        }
    }

    return res;
}

void dfs(int idx){
    if(idx==4) {
        dfs(idx+1);
        return;
    }

    if(idx > 9){
        ans = max(ans, play());
        return;
    }

    for(int i=1; i<=9; i++){
        if(check[i]==true) continue;

        check[i]=true;
        num[idx]=i;
        dfs(idx+1);            
        check[i]=false;
    }

}

int main(){
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=9; j++)
            cin >> board[i][j];

    // 타순 정하기
    check[1]=true;
    num[4]=1;
    dfs(1);

    cout << ans;
    return 0;
}