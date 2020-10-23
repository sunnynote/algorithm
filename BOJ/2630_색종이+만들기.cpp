/**
 * 20-10-05
 * BOJ 2630 색종이 만들기
 * 분할정복
 * */

#include <iostream>
using namespace std;

int N;
int map[130][130];
int white=0, blue=0;

void solve(int x, int y, int size){
    if(size==1){
        if(map[x][y]==0) white++;
        else blue++;
        return;
    }

    bool flag=false;
    int cur=map[x][y];

    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(cur!=map[i][j]) {
                flag=true; break;
            }
        }
        if(flag) break;
    }

    if(flag){
        solve(x,y,size/2);
        solve(x,y+size/2, size/2);
        solve(x+size/2, y, size/2);
        solve(x+size/2, y+size/2, size/2);
    }
    else {
        if(cur==0) white += 1;
        else blue += 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> map[i][j];
    
    solve(0,0,N);
    cout << white << '\n' << blue << '\n';
    return 0;
}
