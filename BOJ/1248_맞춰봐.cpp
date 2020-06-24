/**
 * 200623
 * BOJ 1248 맞춰봐
 * 백트래킹
 * */ 

#include <iostream>
#include <vector>
using namespace std;

int N;
char str[11][11];
vector <int> v;

bool check(int idx){
    int sum = 0;

    for(int i=idx; i>=0; i--){
        sum += v[i];

        if(str[i][idx]=='+' && sum<=0) return false;
        if(str[i][idx]=='-' && sum>=0) return false;
        if(str[i][idx]=='0' && sum!=0) return false;
    }
    return true;
}

void func(int len){
    if(len==N){
        for(int i=0; i<N; i++)
            cout << v[i] << ' ';
        exit(0);
    }

    for(int i=-10; i<=10; i++){
        v.push_back(i);
        if(check(len))
            func(len+1);
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    string s;
    cin >> s;

    int idx=0;
    for(int i=0; i<N; i++)
        for(int j=i; j<N; j++)
            str[i][j] = s[idx++];

    func(0);

    return 0;
}
