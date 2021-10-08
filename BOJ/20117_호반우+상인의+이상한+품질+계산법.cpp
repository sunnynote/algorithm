/**
 * 21-10-08
 * BOJ 20117 호반우 상인의 이상한 품질 계산법
 * 그리디, 정렬
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];

void solve(){
    sort(arr, arr+N);

    int left = 0;
    int right = N-1;

    int sum = 0;
    while(left < right){
        sum += arr[right]*2;
        left++; right--;
    }

    if(N%2==1) sum += arr[N/2];
    cout << sum << '\n';
}

void input(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}