#include <iostream>
using namespace std;

int N, M;
int need[10005];

int calc(int mid){
    int sum=0;
    for(int i=0; i<N; i++){
        if(need[i] >= mid)
            sum += mid;
        else sum += need[i];
    }
    return sum;
}

int main(){
    cin >> N;

    int max_need=0;
    for(int i=0; i<N; i++){
        cin >> need[i];
        max_need = max(max_need, need[i]);
    }

    cin >> M;

    int left = 0;
    int right = max_need;

    while(left <= right){
        int mid = (left+right)/2; // 임시 예산(중간값)
        
        // 임시 예산으로 합을 구해 전체 예산과 비교 
        if(calc(mid) <= M){
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << right;
    return 0;
}