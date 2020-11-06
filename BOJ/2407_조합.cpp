/**
 * 20-11-06
 * BOJ 2407 조합
 * string, dp(memoization) 이용하여 big int 구현
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
string cache[101][101];

string calcSum(string num1, string num2){
    long long sum = 0;
    string res;

    while(!num1.empty() || !num2.empty() || sum){
        if(!num1.empty()){
            sum += num1.back() - '0';
            num1.pop_back();
        }

        if(!num2.empty()){
            sum += num2.back() - '0';
            num2.pop_back();
        }

        res.push_back(sum%10+'0');
        sum/=10;
    }

    reverse(res.begin(), res.end());
    return res;
}

string combination(int n, int m){
    if(n==m || m==0) return "1";

    string &ret = cache[n][m];
    if(ret != "") return ret;

    ret = calcSum(combination(n-1,m-1), combination(n-1,m));
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    cout << combination(N,M);
    return 0;
}
