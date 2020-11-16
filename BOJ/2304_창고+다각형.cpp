/**
 * 201116
 * BOJ 2304 창고 다각형
 * */
#include <iostream>
using namespace std;

int arr[1004];
int res[1004][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int a, b;
    int st = 1001;
    int en = 0;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        arr[a] = b;
        if(st > a) st = a;
        if(en < a) en = a;
    }
    
    int left = arr[st];
    for(int i=st; i<=en; i++){
        if(left < arr[i]) left = arr[i];
        res[i][0] = left;
    }
    
    int right = arr[en];
    int ans = 0;
    for(int i=en; i>=st; i--){
        if(right < arr[i]) right = arr[i];
        res[i][1] = right;
    }

    for(int i=st; i<=en; i++){
        if(res[i][0] > res[i][1]) ans += res[i][1];
        else ans += res[i][0];
    }
    cout << ans << '\n';

    return 0;
}