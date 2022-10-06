/**
 * 22-10-06
 Programmers
 Lv2. JadenCase 문자열 만들기

 헤맸던 tc
 Parameters : "  4  for the last week"
 Return : "  4  For The Last Week"
 */

class Solution {
  public String solution(String s) {
    String answer = "";

    s = s.toLowerCase();

    if('a' <= s.charAt(0) && s.charAt(0) <= 'z'){
      answer += (char)(s.charAt(0) - 32);
    }
    else answer += s.charAt(0);

    for(int i=1; i<s.length(); i++){
      if(s.charAt(i-1) == ' ' && s.charAt(i) != ' '
              && 'a' <= s.charAt(i) && s.charAt(i) <= 'z'){
        answer += (char)(s.charAt(i) - 32);
      }
      else answer += s.charAt(i);
    }

    return answer;
  }
}