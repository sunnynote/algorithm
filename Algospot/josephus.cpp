/**
 * 21-01-26
 * */

// 문제가 너무 무서운데요 ..
// iter와 erase의 활용 학습하기

#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector <int> v;

void solve(){
    for(int i=1; i<=N; i++)
        v.push_back(i);
    
    vector<int>::iterator iter = v.begin();

    while(1){
        if(v.size()==2) break;

        iter = v.erase(iter); // 제거 후 다음 iter 반환
        if(iter==v.end()) iter = v.begin();

        for(int i=0; i<K-1; i++){
            iter++;
            if(iter==v.end()) iter = v.begin();
        }
    }

    for(int i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        v.clear();

        cin >> N >> K;
        solve();
    }

    return 0;
}
