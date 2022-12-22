/**
 * 22-12-22
 * Programmers 월간 코드 챌린지 시즌2 - 괄호 회전하기
 */

import java.util.Stack;

class Solution {
  public int solution(String s) {
    int answer = 0;

    boolean f = false;
    String cur = s;
    cur += s;

    for(int i=0; i<s.length(); i++){
      if(func(cur, i)){
        answer++;
      }
    }

    return answer;
  }

  boolean func(String s, int cnt){
    Stack<Character> st = new Stack<>();
    boolean f = true;

    for(int i=cnt; i<s.length()/2 + cnt; i++){
      char c = s.charAt(i);

      if(st.isEmpty()){
        st.push(c);
      }
      else if(st.peek() == '[' && c ==']'){
        st.pop();
      }
      else if(st.peek() == '(' && c ==')'){
        st.pop();
      }
      else if(st.peek() == '{' && c == '}'){
        st.pop();
      }
      else{
        st.push(c);
      }
    }

    if(!st.isEmpty()){
      f = false;
    }

    return f;
  }
}