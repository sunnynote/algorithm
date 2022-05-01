#include <iostream>
using namespace std;

int N;
string s;
bool chk[27];

void solve(){
  for(int i=0; i<26; i++){
    chk[i] = false;
  }

  for(int i=0; i<s.length(); i++){
    chk[s[i] - 'A'] = true;
  }

  int ans = 0;
  for(int i=0; i<26; i++){
    if(!chk[i]) ans += (i + 'A');
  }
  
  cout << ans << '\n';
}

void input(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> s;
    solve();
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();

  return 0;
}