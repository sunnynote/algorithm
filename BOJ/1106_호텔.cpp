/**
 * 21-03-30
 * BOJ 1106 호텔
 * DP
* */
#include <iostream>
#include <algorithm>
using namespace std;

int arr[21][2];
int d[100*1000 + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int C, N;
    cin >> C >> N;

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;

        arr[i][0] = a; // cost
        arr[i][1] = b; // customer
    }

    d[0] = 0; // d[비용] = 고객 수
    for(int k=0; k<N; k++) 
        for(int x=0; x<=100*1000; x++)
            if(x - arr[k][0]>=0)
                d[x] = max(d[x], d[x - arr[k][0]] + arr[k][1]);

    int ans = -1;
    for(int x=0; x<=100*1000; x++)
        if(d[x] >= C) {
            ans = x;
            break;
        }

    cout << ans << '\n';

    return 0;
}