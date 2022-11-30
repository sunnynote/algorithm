/**
 * 22-11-30
 * Programmers 연습 - 문자열을 정수로 바꾸기
 */

class Solution {
  public int solution(String s) {
    int answer = 0;

    if(s.charAt(0)=='+' || s.charAt(0)=='-'){
      String cur = "";
      for(int i=1; i<s.length(); i++){
        cur += s.charAt(i);
      }

      int res = Integer.parseInt(cur);

      if(s.charAt(0) == '-') answer -= res;
      else answer = res;
    }
    else answer = Integer.parseInt(s);

    return answer;
  }
}