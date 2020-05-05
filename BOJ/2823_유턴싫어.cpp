#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
char a[12][12];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool flag=true;

void func(int x, int y){
    int cnt = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<=nx && nx<N && 0<=ny && ny<M){
            if(a[nx][ny]=='.') cnt++;
        }
    }

    if(cnt<=1) flag=false;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            a[i][j] = s[j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(a[i][j]=='.') func(i, j);
            if(!flag) break;
        }
    }

    if(flag) cout << 0;
    else cout << 1;

    return 0;
}