/**
 * 23-01-10
 * Programmers 연습 - 서울에서 김서방 찾기
 */

class Solution {
  public String solution(String[] seoul) {
    String answer = "김서방은 ";

    for(int i=0; i<seoul.length; i++){
      if(seoul[i].equals("Kim")){
        String s = Integer.toString(i);
        answer += s;
        answer += "에 있다";
      }
    }

    return answer;
  }
}