/**
 * 200605
 * BOJ 1038 감소하는 수
 * */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
queue <long long> q;
vector <long long> desNum;
int idx;

void solve(){
    for(int i=0; i<=9; i++){
        q.push(i);
        desNum.push_back(i);
    }
    idx=9;

    while(idx <= N){
        if(q.empty()) return;

        long long num = q.front();
        q.pop();

        for(int i=0; i<=9; i++){
            // 끝자리를 비교해서 i가 작으면 감소하는 수
            if(num%10 > i){ 
                long long tmp = num*10 + i;
                desNum.push_back(tmp);
                q.push(tmp);
                idx++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    solve();
    sort(desNum.begin(), desNum.end());

    /**
     * 숫자는 9876543210으로 고정되어 있고,
     * 선택할지, 안할지 구분 > 2^10 = 1024가지
     * 아무것도 선택하지 않음 > 1가지
     * */

    if(1023 <= N) cout << -1;
    else cout << desNum[N];

    return 0;
}
