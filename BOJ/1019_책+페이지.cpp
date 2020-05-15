#include <iostream>
using namespace std;

int N;
int ans[10];

void calc(int x, int weight){
    while(x > 0){
        ans[x%10] += weight;
        x/=10;
    }
}

void solution(){
    
    int start = 1;
    int weight = 1;
    
    while(start<=N){
        // 시작수의 끝자리 0으로 만들기
        while(start%10 != 0 && start <= N){
            calc(start, weight);
            start++;
        }

        // 마지막수의 끝자리 9로 만들기
        while(N%10 != 9 && start <= N){
            calc(N, weight);
            N--;
        }
        if(N<start) break;

        start /= 10;
        N /= 10;

        // 횟수 추가
        for(int i=0; i<=9; i++)
            ans[i] += (N-start+1) * weight;
        
        weight *= 10;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    
    solution();

    for(int i=0; i<=9; i++)
        cout << ans[i] << ' ';

    return 0;
}