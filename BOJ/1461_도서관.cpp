/**
 * 200521
 * BOJ 1461 도서관
 * 시뮬레이션 : 왼쪽, 오른쪽 따로 관리한다.
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int leftLoc[10005];
int rightLoc[10005];
int leftIdx=0, rightIdx=0;
int leftMx=-1, rightMx=-1;

int ans = 0;

void leftCalc(){
    int idx = leftIdx-1;

    while(1){
        if(idx<0) break;
        ans += leftLoc[idx]*2;
        idx-=M;
    }
}

void rightCalc(){
    int idx = rightIdx-1;
    
    while(1){
        if(idx<0) break;
        ans += rightLoc[idx]*2;
        idx-=M;
    }
}

void solve(){
    if(leftMx >= rightMx){
        ans += leftLoc[leftIdx-1];
        leftIdx-=M;
    }
    else{
        ans += rightLoc[rightIdx-1];
        rightIdx-=M;
    }

    leftCalc();
    rightCalc();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        if(x<0){ // 인풋이 음수일 때
            if(leftMx < abs(x)) leftMx = abs(x);
            leftLoc[leftIdx++] = abs(x);
        }
        else{ // 인풋이 양수일 때
            if(rightMx < x) rightMx = x;
            rightLoc[rightIdx++] = x;
        }
    }
    sort(leftLoc, leftLoc+leftIdx);
    sort(rightLoc, rightLoc+rightIdx);

    solve();
    
    cout << ans << '\n';
    return 0;
}

