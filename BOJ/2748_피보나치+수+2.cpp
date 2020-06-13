#include <iostream>
using namespace std;

long long f[92];

long long fi(int n){
    if(n==0 || n==1 || f[n]!=0) return f[n];
    return f[n] = fi(n-1) + fi(n-2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    f[0] = 0;
    f[1] = 1;

    fi(N);
    cout << f[N];

    return 0;
}
