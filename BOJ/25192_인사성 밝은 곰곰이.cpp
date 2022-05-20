#include <iostream>
#include <set>
using namespace std;

int N;
set <string> st;
int ans = 0;

void solve(){
  cout << ans << '\n';
}

void input(){
  cin >> N;

  string s;
  for(int i=0; i<N; i++){
    cin >> s;
    if(s == "ENTER"){
      ans += st.size();
      st.clear();
    }
    else{
      st.insert(s);
    }
  }

  ans += st.size();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}