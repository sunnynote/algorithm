/**
 * 200616
 * BOJ 8980
 * 택배
 * greedy
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, C, M;
int ans = 0;
pair< pair<int,int>, int> arr[2005]; //도착, 시작, 갯수
int res[2005]; 

bool cmp(pair< pair<int,int>, int> A, pair< pair<int,int>, int> B){
    if(A.first.first < B.first.first) return true;
    else if(A.first.first == B.first.first){
        if(A.first.second < B.first.second) return true;
    }
    return false;
}

void solve(){
    for(int i=0; i<M; i++){
        int mxBox = 0;

        int from = arr[i].first.second;
        int to = arr[i].first.first;
        int cnt = arr[i].second;

        for(int j=from; j<to; j++)
            mxBox = max(mxBox, res[j]);

        int plusBox = min(cnt, C-mxBox); // 최대 가능(C-mxBox)과 현재 양 비교해서 운반 가능 체크
        ans += plusBox;

        for(int j=from; j<to; j++)
            res[j] += plusBox; // 그 구간에서 운반한 양 체크

        // cout << from << ' ' << to << '\n';
        // for(int j=1; j<=N; j++)
        //     cout << res[j]<<' ';
        // cout <<'\n';
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> C >> M;
    for(int i=0; i<M; i++){
        int from, to, cnt;
        cin >> from >> to >> cnt;

        arr[i].first.first = to;
        arr[i].first.second = from;
        arr[i].second = cnt;
    }

    sort(arr, arr+M, cmp);
    solve();
    cout << ans;

    return 0;
}
