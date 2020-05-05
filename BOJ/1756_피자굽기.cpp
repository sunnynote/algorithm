#include <iostream>
using namespace std;

int oven[300005];
int new_oven[300005];
int pizza[300005];

int main(){
    int D, N;
    cin >> D >> N;

    new_oven[0] = 987654321;
    for(int i=1; i<=D; i++){
        cin >> oven[i];
        if(new_oven[i-1] < oven[i]) new_oven[i] = new_oven[i-1];
        else new_oven[i] = oven[i];
    }

    for(int i=1; i<=N; i++){
        cin >> pizza[i];
    }

    int idx = 1; // 피자인덱스
    int ans = 0;
    for(int i=D; i>0; i--){
        if(pizza[idx] > new_oven[i]) continue;
        
        idx++;
        if(idx>N){
            cout << i; return 0;
        }
    }
    cout << 0;
    return 0;
}