/**
 * 200519
 * BOJ 1517 버블소트
 */

// no bubbleSort, yes mergeSort

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[500005];
int b[500005];
long long ans=0;

void merge(int start, int mid, int end){

    int i = start;
    int j = mid+1;
    int idx = start;

    // 분할 된 배열의 merge
    while(i<=mid && j<=end){
        if(a[i] <= a[j]) 
            b[idx++] = a[i++];
        else{ // swqp point 
            b[idx++] = a[j++];
            ans += (mid - i + 1);
        }
    }

    // 남아 있는 값 일괄 copy
    if(i > mid){
        for(int l=j; l<=end; l++)
            b[idx++] = a[l];
    }
    else{
        for(int l=i; l<=mid; l++)
            b[idx++] = a[l];
    }

    // b->a
    for(int l=start; l<=end; l++)
        a[l] = b[l];
}

void mergeSort(int left, int right){
    int mid = (left+right)/2;

    if(left < right){
        mergeSort(left, mid);
        mergeSort(mid+1, right);
    
        merge(left, mid, right);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> a[i];
    
    mergeSort(1, N);
    cout << ans;
    
    return 0;
}