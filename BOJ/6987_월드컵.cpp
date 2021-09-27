/**
 * 21-09-27
 * BOJ 6987 월드컵
 * DFS
 * */

#include <iostream>
using namespace std;

int info[6][3];
int res[6][3];
bool ans[4];

int list1[16] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4}; // A~F idx list
int list2[16] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};

void solve(int cnt, int k){
    if(cnt==15) {
        if(ans[k]) return;

        for(int i=0; i<6; i++)
            for(int j=0; j<3; j++)
                if(info[i][j] != res[i][j]) return;
                
        ans[k] = true;
        return;
    }

    int a_team = list1[cnt];
    int b_team = list2[cnt];

    /**
     * 1) a win, b lose
     * 2) a draw, b draw
     * 3) a lose, b win
     * */

    // a win, b lose
    res[a_team][0]++;
    res[b_team][2]++;
    solve(cnt+1, k);
    res[a_team][0]--;
    res[b_team][2]--;

    // a draw, b draw
    res[a_team][1]++;
    res[b_team][1]++;
    solve(cnt+1, k);
    res[a_team][1]--;
    res[b_team][1]--;

    // a lose, b win
    res[a_team][2]++;
    res[b_team][0]++;
    solve(cnt+1, k);
    res[a_team][2]--;
    res[b_team][0]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for(int k=0; k<4; k++){
        int sum = 0;

        for(int i=0; i<6; i++){
            for(int j=0; j<3; j++){
                cin >> info[i][j];
                sum += info[i][j];
            }
        }

        solve(0, k);
    }

    for(int i=0; i<4; i++)
        cout << ans[i] <<' ';

    return 0;
}