#include <iostream>
using namespace std;

string s;

void solve(){
  for(int i=0; i<s.length(); i++){
    if('a'<=s[i] && s[i]<='z'){
      s[i] -= 32;
    }
    else{
      s[i] += 32;
    }
  }
  cout << s;
}

void input(){
  cin >> s;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}