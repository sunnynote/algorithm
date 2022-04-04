/**
 * @file 1374.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 1374 강의실 / 그리디, 우선순위 큐
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <pair<int,int> > v;
priority_queue < int, vector<int>, greater<int> > pq;

int mx(int a, int b){
    if(a > b) return a;
    return b;
}

int main(){
    int N, idx, s, e;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> idx >> s >> e;
        v.push_back({s, e});
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

    cout << ans << '\n';
}
