/**
 * 200904
 * BOJ 15661 스타트와 링크
 * DFS
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int board[22][22];
bool check[22];

vector <int> teamA, teamB;
int ans = 2e9;

void makeTeam(){
    teamA.clear();
    teamB.clear();

    for(int i=1; i<=N; i++){
        if(check[i]) teamA.push_back(i);
        else teamB.push_back(i);
    }
}

void calcScore(){
    int scoreA=0, scoreB=0;

    for(int i=0; i<teamA.size()-1; i++)
        for(int j=i+1; j<teamA.size(); j++)
            scoreA += (board[teamA[i]][teamA[j]] + board[teamA[j]][teamA[i]]);

    for(int i=0; i<teamB.size()-1; i++)
        for(int j=i+1; j<teamB.size(); j++)
            scoreB += (board[teamB[i]][teamB[j]] + board[teamB[j]][teamB[i]]);

    int diff = abs(scoreA-scoreB);
    if(ans > diff) ans = diff;
}

void dfs(int idx, int cnt){
    if(cnt == N/2+1) return;

    if(cnt>=1){
        makeTeam();
        calcScore();
    }

    for(int i=idx; i<=N; i++){
        if(check[i]) continue;

        check[i] = true;
        dfs(i, cnt+1);
        check[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> board[i][j];
    
    dfs(1, 0);
    cout << ans;
    return 0;
}