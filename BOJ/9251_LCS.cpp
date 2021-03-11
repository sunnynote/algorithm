/**
 * 21-03-09
 * LCS - DP
 * */

#include <iostream>
using namespace std;

int d[1005][1005];

int mx(int a, int b){
    if(a>b) return a;
    return b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string A, B;
    cin >> A >> B;

    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=B.size(); j++){
            if(A[i-1]==B[j-1]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = mx(d[i-1][j], d[i][j-1]); 
        }
    }

    cout << d[A.size()][B.size()];

    return 0;
}