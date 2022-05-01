#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  while(N--){
    int a, b;
    cin >> a >> b;

    int ans = 0;

    for(int i=a; i<=b; i++){
      string s = to_string(i);

      for(int j=0; j<s.length(); j++){
        if(s[j] == '0') ans++;
      }
    }
    cout << ans << '\n';
  }
}