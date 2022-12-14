/**
 * 22-12-14
 * Programmers 연습 - 나머지가 1이 되는 수 찾기
 */

class Solution {
  public int solution(int n) {
    int answer = 0;
    boolean f = false;
    int cnt = 2;

    while(true){
      if(f) break;

      if(n % cnt == 1){
        answer = cnt;
        f = true;
      }

      cnt++;
    }
    return answer;
  }
}