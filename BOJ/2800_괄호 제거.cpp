/**
 * @file 2800.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2800 괄호 제거 / DFS
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <stack>
#include <set>
#include <vector>
using namespace std;

string s;
bool chk[201];

stack <char> st;
vector <pair<int,int> > v;
set <string> ans;

void solve(int idx, int cnt){
  if(idx == v.size()){
    if(cnt > 0){
      string tmp = "";
      for(int i=0; i<s.length(); i++){
        if(chk[i]) tmp += s[i];
      }
      ans.insert(tmp);
    }
    return;
  }

  // // 괄호 삭제X
  solve(idx + 1, cnt);

  // // 괄호 삭제O
  chk[v[idx].first] = false;
  chk[v[idx].second] = false;
  solve(idx + 1, cnt + 1);
  chk[v[idx].first] = true;
  chk[v[idx].second] = true;
}

void input(){
  cin >> s;

  for(int i=0; i<s.length(); i++){
    if(s[i] == '(') st.push(i);
    else if(s[i] == ')'){
      v.push_back({st.top(), i});
      st.pop();
    }
  }

  for(int i=0; i<s.length(); i++){
    chk[i] = true;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve(0, 0);

  for(auto it = ans.begin(); it!=ans.end(); it++){
    cout << *it << '\n';
  }

  return 0;
}