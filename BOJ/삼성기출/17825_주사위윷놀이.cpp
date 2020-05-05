#include <iostream>
#include <algorithm>
using namespace std;

int horse[4];
int dice[11];
int map[35];
int score[35];
int turnIdx[35];
bool sel[35];

int ans = 0;

void dfs(int cnt, int sum){
    if(cnt==10){
        ans = max(ans, sum);
        return;
    }

    for(int i=0; i<4; i++){
        int cur = horse[i]; // 현재 위치 idx 저장
        int nex = cur; // 다음 위치 idx
        
        int move = dice[cnt]; // 이번 주사위 눈(이동 횟수)

        if(turnIdx[cur] > 0){ // 현재 위치가 반환점이면
            nex = turnIdx[cur]; // idx 조정
            move -= 1;
        }

        while(move--) nex = map[nex];

        // 다음 위치가 종료 위치 아닌데, 말이 있다면 다음 턴으로
        if(nex!=21 && sel[nex]==true) continue;

        sel[cur]=false;
        sel[nex]=true;
        horse[i]=nex;

        dfs(cnt+1, sum+score[nex]);
        
        horse[i]=cur;
        sel[nex]=false;
        sel[cur]=true;
    }
}

int main(){
    for(int i=0; i<10; i++) cin >> dice[i];

    for(int i=0; i<=31; i++) map[i] = i+1;
    map[21]=21; map[27]=20; map[29]=25; map[32]=25;
    
    turnIdx[5]=22; turnIdx[10]=28; turnIdx[15]=30; turnIdx[25]=26;

    for(int i=0; i<=20; i++) score[i] = i*2;
    score[22]=13; score[23]=16; score[24]=19;
    score[25]=25; score[26]=30; score[27]=35;
    score[28]=22; score[29]=24; score[30]=28;
    score[31]=27; score[32]=26;

    dfs(0,0);

    cout << ans;
    return 0;
}