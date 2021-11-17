/**
 * 21-11-17
 * BOJ 16198 에너지 모으기
 * 백트래킹, 벡터
 * */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans = -1;
vector <int> v;

void solve(vector<int> v, int cnt, int sum){
    if(cnt==N-2){ // v.size()==2
        if(ans < sum) ans = sum;
        return;
    }

    for(int i=1; i<v.size()-1; i++){
        vector <int> tmp = v;
        tmp.erase(tmp.begin() + i);
        solve(tmp, cnt+1, sum + v[i-1]*v[i+1]);
    }
}

void input(){
    cin >> N;

    int x;
    for(int i=0; i<N; i++){
        cin >> x;
        v.push_back(x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve(v, 0, 0);

    cout << ans << '\n';

    return 0;
}