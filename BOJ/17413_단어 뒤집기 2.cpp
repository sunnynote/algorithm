/**
 * @file 17413.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 17413 단어 뒤집기 2 / 스택
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <stack>
using namespace std;

int main(){
  stack<char> st;

  string s;
  getline(cin, s);
  s += " ";

  for(int i=0; i<s.length(); i++){
    
    if(s[i] == '<'){
      while(!st.empty()){
        cout << st.top();
        st.pop();
      }
      
      while(s[i] != '>'){
        st.push(s[i++]);
      }

      string tmp = "";
      while(!st.empty()){
        tmp += st.top();
        st.pop();
      }

      for(int i=tmp.size()-1; i>=0; i--){
        cout << tmp[i];
      } cout << ">";
    }
    else if(s[i] == ' '){
      while(!st.empty()){
        cout << st.top();
        st.pop();
      }
      cout << ' ';
    }
    else{
      st.push(s[i]);
    }
  }
}