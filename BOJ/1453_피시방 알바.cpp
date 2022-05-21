#include <iostream>
using namespace std;

int N;
bool chk[101];
int ans = 0;

void solve(){
  
}

void input(){
  cin >> N;

  int x;
  for(int i=0; i<N; i++){
    cin >> x;
    if(!chk[x]){
      chk[x] = true;
    }
    else ans++;
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}