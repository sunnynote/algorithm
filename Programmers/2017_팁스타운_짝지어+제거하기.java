/**
 * 22-10-19
 * Programmers 2017 팁스타운 - 짝지어 제거하기
 */

import java.util.*;

class Solution
{
  public int solution(String s)
  {
    int answer = 0;
    Stack<Character> st = new Stack<>();

    for(int i=0; i<s.length(); i++){
      if(!st.isEmpty()){
        if(st.peek() == s.charAt(i)){
          st.pop();
        }
        else st.push(s.charAt(i));
      }
      else{
        st.push(s.charAt(i));
      }
    }

    if(st.isEmpty()) answer = 1;
    return answer;
  }
}