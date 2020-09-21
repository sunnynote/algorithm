/**
 * 200921 
 * BOJ 2643
 * 색종이 올려 놓기
 * DP -- LIS (Longest Increasing Subsequence)
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N;;
pair<int,int> arr[102];
int d[102];

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first>b.first) return true;
    else if(a.first==b.first){
        if(a.second>b.second) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        if(x>y){
            arr[i].first = x;
            arr[i].second = y;
        }
        else {
            arr[i].first = y;
            arr[i].second = x;
        }
    }

    sort(arr, arr+N, cmp);
    for(int i=0; i<N; i++){
        d[i]=1;
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        
        for(int j=0; j<i; j++){
            if(arr[j].first>=arr[i].first && arr[j].second>=arr[i].second){
                if(d[i] < d[j]+1){
                    d[i] = d[j]+1;
                }
            }
        }

        ans = max(ans, d[i]);
    }

    cout << ans;

    return 0;
}
