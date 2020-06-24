/**
 * 200623
 * BOJ 2023 신기한 소수
 * 백트래킹
 * */
#include <iostream>
using namespace std;

int N;

bool isPrime(int n){
    for(int i=2; i*i<n; i++)
        if(n%i==0) return false;
    
    return true;
}

void func(int num, int len){
    if(len==N){
        cout << num << '\n';
        return;
    }

    for(int i=1; i<=9; i+=2){ // 홀수만 가능
        int isAvail = num*10 + i;

        if(isPrime(isAvail))
            func(isAvail, len+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    // 시작 가능한 수 -- 소수 2,3,5,7
    func(2,1);
    func(3,1);
    func(5,1);
    func(7,1);

    return 0;
}