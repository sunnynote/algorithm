/**
 * @file 1090.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 1090 체커, BF
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int num[50][2];
int ans[50];

void solve(int x, int y){
    vector <int> dist;

    // 현재 후보(x,y)와 주어진 N개 점에 대한 dist를 구한다.
    for(int i=0; i<N; i++){
        dist.push_back(abs(x - num[i][0]) + abs(y - num[i][1]));
    }

    // 거리 작은 수부터 구해야하니 정렬한다.
    sort(dist.begin(), dist.end());

    int sum = 0;
    for(int i=0; i<N; i++){
        sum += dist[i]; // N개까지의 이동 횟수
        if(ans[i] > sum) ans[i] = sum;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> num[i][0] >> num[i][1];
    }

    for(int i=0; i<N; i++){
        ans[i] = 987654321;
    }

    // x, y 좌표 조합하여 모든 수 체크
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            solve(num[i][0], num[j][1]);
        }
    }

    for(int i=0; i<N; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}