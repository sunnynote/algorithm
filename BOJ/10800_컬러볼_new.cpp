/**
 * 21-03-15
 * BOJ 10800 컬러볼
 * 부분합, 정렬
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N;

struct Info{
    int idx, color, size, sum;
};

Info arr[200005];
int color[200005]; // 색의 합

bool cmp(Info &a1, Info &a2){
    return a1.size < a2.size;
}

bool idxCmp(Info &a1, Info &a2){
    return a1.idx < a2.idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> arr[i].color >> arr[i].size;
        arr[i].idx = i;
    }

    sort(arr+1, arr+1+N, cmp);

    int sum = 0; // 부분합
    for(int i=1, j=1; i<=N; i++){
        while(j<=N && arr[j].size < arr[i].size){
            sum += arr[j].size;
            color[arr[j].color] += arr[j].size;
            j++;
        }

        arr[i].sum = sum - color[arr[i].color];
    }

    sort(arr+1, arr+1+N, idxCmp);

    for(int i=1; i<=N; i++)
        cout << arr[i].sum << '\n';

    return 0;
}