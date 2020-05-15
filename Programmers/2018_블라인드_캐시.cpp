#include <iostream>
using namespace std;

int N, M;

int solution(){
    int sum = 0;
    int cnt = 0;
    while(sum<=N*M){
        if( sum%M != 0) cnt++;
        sum += N;
    }    
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    cout << solution();

    return 0;
}