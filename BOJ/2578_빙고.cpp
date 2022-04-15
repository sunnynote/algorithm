/**
 * @file 2578.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2578 빙고 / 구현
 * @version 0.1
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int bingo[6][6];

bool solve(){
    int res = 0;
    int cnt = 0;

    for(int i=1; i<=5; i++){
        cnt = 0;
        for(int j=1; j<=5; j++){
            if(bingo[i][j]==1) cnt++;
        }
        if(cnt == 5) res++;
    }

    for(int j=1; j<=5; j++){
        cnt = 0;
        for(int i=1; i<=5; i++){
            if(bingo[i][j]==1) cnt++;
        }
        if(cnt == 5) res++;
    }

    cnt = 0;
    for(int i=1; i<=5; i++){
        if(bingo[i][i]==1) cnt++;
    }
    if(cnt == 5) res++;

    cnt = 0;
    for(int i=1; i<=5; i++){
        if(bingo[i][6-i]==1) cnt++;
    }
    if(cnt == 5) res++;

    if(res >= 3) return true;
    return false;
}

int main(){
    int map[6][6];
    int arr[26];
    pair<int,int> chk[26];

    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            cin >> map[i][j];
            chk[map[i][j]].first = i;
            chk[map[i][j]].second = j;
        }
    }

    int idx = 0;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            cin >> arr[idx++];
        }
    }

    for(int i=1; i<=25; i++){
        bingo[chk[arr[i - 1]].first][chk[arr[i - 1]].second] = 1;
        if(i<15) continue;

        if(solve()) {
            cout << i;
            break;
        }
    }
}