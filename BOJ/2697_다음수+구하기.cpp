/**
 * @file 2697.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2697 다음수 구하기 / 구현
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--){
      string s;
      cin >> s;

      int idx = -1;
      int val = 0;
      for(int i=s.length()-2; i>=0; i--){
        if(s[i] - '0' < s[i+1] - '0'){
          idx = i;
          val = s[i] - '0';
          break;
        }
      }

      if(idx == -1){
        cout << "BIGGEST" << '\n';
      }
      else{
        string ans = "";
        for(int i=0; i<idx; i++){
          ans += s[i];
        }

        int chk[10];
        for(int i=0; i<=9; i++) chk[i] = 0;
        for(int i=idx; i<s.length(); i++){
          chk[s[i] - '0']++;
        }

        for(int i=val + 1; i<=9; i++){
          if(chk[i] != 0){
            chk[i]--;
            ans += (i + '0');
            break;
          }
        }

        for(int i=0; i<=9; i++){
          while(chk[i] != 0){
            ans += (i + '0');
            chk[i]--;
          }
        }

        cout << ans << '\n';
      }
    }
}