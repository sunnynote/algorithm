#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string s;
map <char,int> mp;
int maxx=0;
int cnt=0;
char ans;

void input(){
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
}

void solution(){
    int len = s.size();
    for(int i=0; i<len; i++){
        if(mp.count(s[i])) mp[s[i]]++;
        else mp[s[i]]=1;
    }

    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(maxx == it->second)
            cnt++;
        else if(maxx < it->second){
            ans = it->first;
            maxx = it->second;
            cnt = 0;
        }
    }

    if(cnt==0) cout << ans;
    else cout << '?';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    input();
    solution();

    return 0;
}