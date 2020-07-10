/**
 * 200710
 * BOJ 1806 부분합
 * two pointer
 * */

#include <iostream>
using namespace std;

int N, S;
int arr[100002];

int solve(){
    int sum=0;
    int ansLen=2e9, curLen=0;
    int s=1, e=1;

    while(1){
        if(sum>=S) {
            sum -= arr[s++];
            curLen--;
        }
        else if(e>N){
            break;
        }
        else {
            sum += arr[e++];
            curLen++;
        }

        if(sum>=S){
            if(ansLen>curLen)
                ansLen = curLen;
        }
    }

    if(ansLen==2e9) ansLen=0;
    return ansLen;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    
    cout << solve();
    return 0;
}
