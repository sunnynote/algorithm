/**
 * 22-11-29
 * Programmers 연습 - 문자열 내 p와 y의 개수
 */

class Solution {
  boolean solution(String s) {
    boolean answer = true;

    int num_p = 0, num_y = 0;

    for(int i=0; i<s.length(); i++){
      char cur = s.charAt(i);

      if(cur=='P' || cur=='p') num_p++;
      if(cur=='Y' || cur=='y') num_y++;
    }

    if(num_p != num_y) answer = false;

    return answer;
  }
}