/**
 * @file 7490.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 7490 0 만들기 / 백트래킹
 * @version 0.1
 * @date 2022-05-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int N;
string ans;
vector <int> v1;
vector <char> v2;

int calc(string s){
  v1.clear();
  v2.clear();
  
  v1.push_back(1);

  for(int i=1; i<s.length()-1; i+=2){
    if(s[i] == '+'){
      v1.push_back(s[i+1] - '0');
      v2.push_back('+');
    }
    else if(s[i] == '-'){
      v1.push_back(s[i+1] - '0');
      v2.push_back('-');
    }
    else if(s[i] == ' '){
      int n = v1.back() * 10 + (s[i+1] - '0');
      v1.pop_back();
      v1.push_back(n);
    }
  }

  int res = v1[0];
  for(int i=0; i<v2.size(); i++){
    if(v2[i] == '+') res += v1[i+1];
    else res -= v1[i+1];
  }

  return res;
}

void solve(int cnt, int idx, string s){
  if(cnt == N){
    if(calc(s) == 0){
      cout << s << '\n';
    }
    return;
  }
    
  // ' '
  solve(cnt + 1, idx + 1, s + " " + to_string(idx+1));
    
  // +
  solve(cnt + 1, idx + 1, s + "+" + to_string(idx+1));
  
  // -
  solve(cnt + 1, idx + 1, s + "-" + to_string(idx+1));
}

void input(){
  int T;
  cin >> T;

  while(T--){
    cin >> N;
    
    v1.clear();
    v2.clear();

    solve(1, 1, "1");
    cout << '\n';
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();

  return 0;
}