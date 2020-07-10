/**
 * 200710
 * BOJ 2003 수들의 합 2
 * two pointer
 * */

#include <iostream>
using namespace std;

int N, M;
int arr[10004];
#include <iostream>
using namespace std;

int N, M;
int arr[10004];

int solve(){
    int ans = 0;
    int sum = 0;
    int s=1, e=1;

    while(1){
        if(sum>=M) 
            sum -= arr[s++];
        else if(e>N) 
            break;
        else
            sum += arr[e++];

        if(sum==M) ans++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    
    cout << solve();
    return 0;
}

int solve(){
    int ans = 0;
    int sum = 0;
    int s=1, e=1;

    while(1){
        if(sum>=M) 
            sum -= arr[s++];
        else if(e>N) 
            break;
        else
            sum += arr[e++];

        if(sum==M) ans++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> arr[i];
    
    cout << solve();
    return 0;
}
