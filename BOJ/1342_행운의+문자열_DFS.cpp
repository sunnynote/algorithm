#include <iostream>
#include <vector>
using namespace std;

string s;
int alpha[28];

vector <char> v;
bool check[11];

int ans = 0;

int factorial(int N){
    int ret = 1;
    for(int i=N; i>=1; i--)
        ret *= i;
    return ret;
}

void dfs(int cnt){
    if(cnt==s.size()){

        bool flag = true;
        for(int i=0; i<v.size()-1; i++){
            if(v[i] == v[i+1]){
                flag = false;
                break;
            }
        }
        if(flag) ans++;

        return;
    }

    for(int i=0; i<s.size(); i++){
        if(check[i]) continue;

        v.push_back(s[i]);
        check[i] = true;
        dfs(cnt+1);
        check[i] = false;
        v.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    for(int i=0; i<s.size(); i++)
        alpha[s[i]-'a']++;

    dfs(0);

    for(int i=0; i<26; i++)
        if(alpha[i] > 1)
            ans /= factorial(alpha[i]);
    
    cout << ans << '\n';
    return 0;
}