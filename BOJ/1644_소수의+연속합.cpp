/**
 * 200710
 * BOJ 1644 소수의 연속합
 * two pointer
 * */

#include <iostream>
using namespace std;

int N;
bool prime[4000005];
int nprime[4000005];
int idx=1;

void findPrime(){
    for(int i=2; i<=N; i++)
        prime[i] = true;

    for(int i=2; i*i<=N; i++){
        if(!prime[i]) continue;
        for(int j=i+i; j<=N; j+=i){
            prime[j] = false;
        }
    }

    for(int i=2; i<=N; i++){
        if(!prime[i]) continue;
        nprime[idx++] = i;
    }
}

int solve(){
    int ans=0, sum=0;
    int s=1, e=1;

    while(1){
        if(sum>=N) 
            sum -= nprime[s++];
        else if(e>idx)
            break;
        else
            sum += nprime[e++];

        if(sum==N) ans++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;

    findPrime();
        
    cout << solve();
    return 0;
}
