/**
 * BOJ 1965 상자넣기
 * LIS ..
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int a[1005];
int d[1005];
int ans = -1;

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    fill(d, d+n+1, 1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(a[i] > a[j] && d[i] < d[j]+1){
                d[i] = max(d[i], d[j]+1);
            }
        }
        ans = max(ans, d[i]);
    }
    
    cout << ans;

    return 0;
}