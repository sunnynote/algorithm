/**
 * 22-10-11
 * Programmer - 올바른 괄호
 */

import java.util.*;

class Solution {
  Stack <Character> st = new Stack<>();

  boolean solution(String s) {
    boolean answer = true;

    int len = s.length();

    for(int i=0; i<len; i++){
      char cur = s.charAt(i);

      if(cur == '('){
        st.push(cur);
      }
      else{
        if(!st.isEmpty()){
          st.pop();
        }
        else{
          return false;
        }
      }
    }

    if(!st.isEmpty()){
      answer = false;
    }

    return answer;
  }
}