/**
 * @file 19598.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 19598 최소 회의실 개수 / 그리디
 * @version 0.1
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <pair<int,int> > v;
priority_queue <int, vector<int>, greater<int> > pq;

int mx(int x, int y){
    if(x > y) return x;
    return y;
}

int main(){
    int N, a, b;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int ans = 0;

    for(int i=0; i<N; i++){
        int cur = v[i].first;

        while(!pq.empty() && pq.top() <= cur){
            pq.pop();
        }

        pq.push(v[i].second);
        ans = mx(ans, pq.size());
    }

    cout << ans << "\n";
}