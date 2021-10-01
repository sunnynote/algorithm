/**
 * 21-10-01
 * BOJ 5618 공약수
 * 수학(약수)
 * */
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    int a, b, c;
    if(N==2){
        cin >> a >> b;
        for(int i=1; i<=a && i<=b; i++)
            if(a%i==0 && b%i==0)
                cout << i <<'\n';
    }
    else{
        cin >> a >> b >> c;
        for(int i=1; i<=a && i<=b && i<=c; i++)
            if(a%i==0 && b%i==0 && c%i==0)
                cout << i <<'\n';
    }

    return 0;
}