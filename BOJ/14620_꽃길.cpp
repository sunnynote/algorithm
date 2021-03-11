#include <iostream>
#define INF 987654321
using namespace std;

int N;
int map[12][12];
int chk[12][12];
int ans = INF;

int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,-1,1};

void flower(int x, int y, bool b){
    for(int i=0; i<5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        chk[nx][ny] = b;
    }
}

bool isCheck(int x, int y){
    for(int i=0; i<5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(chk[nx][ny]) return false;
    }
    return true;
}

void solve(int cnt){
    if(cnt==3) {
        int sum = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(chk[i][j]) sum += map[i][j];

        if(ans > sum) ans = sum;
        return;
    }

    for(int i=1; i<N-1; i++){
        for(int j=1; j<N-1; j++){
            if(!isCheck(i, j)) continue;
            
            flower(i, j, true);
            solve(cnt+1);
            flower(i, j, false);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> map[i][j];

    for(int i=1; i<N-1; i++)
        for(int j=1; j<N-1; j++)
            if(isCheck(i, j)) solve(0);

    cout << ans << '\n';

    return 0;
}