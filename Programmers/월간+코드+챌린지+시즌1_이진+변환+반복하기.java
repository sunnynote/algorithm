/**
 * 22-10-17
 * Programmers 월간 코드 챌린지 시즌1 - 이진 변환 반복하기
 */

class Solution {
  public int[] solution(String s) {
    int[] answer = {0, 0};

    String str = s;

    while(true){
      answer[0]++;
      int len = str.length();
      int cnt = 0;

      for(int i=0; i<len; i++){
        if(str.charAt(i) == '0') answer[1]++;
        else cnt++;
      }

      str = solve(cnt);
      System.out.println(cnt + " " + str);

      if(str.equals("1")) break;
    }

    return answer;
  }

  String solve(int n){
    String two = "";
    while(n > 0){
      if(n % 2 == 0) two += "0";
      else two += "1";
      n /= 2;
    }

    String tenToTwo = "";
    for(int i=two.length()-1; i>=0; i--){
      tenToTwo += two.charAt(i);
    }

    return tenToTwo;
  }
}