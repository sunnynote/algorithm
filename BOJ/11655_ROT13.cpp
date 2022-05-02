#include <iostream>
using namespace std;

string s;
string ans = "";

void solve(){
  for(int i=0; i<s.length(); i++){
    int n = s[i] + 13;

    if('A' <= s[i] && s[i] <= 'Z'){
      if(n > 90) n -= 26;
      ans += (char)n;
    }
    else if('a' <= s[i] && s[i] <= 'z'){
      if(n > 122) n -= 26;
      ans+= (char)n;
    }
    else{
      ans += s[i];
    }
  }
  cout << ans;
}

void input(){
  getline(cin, s);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}