/**
 * 23-01-03
 * Programmers 연습 - 콜라츠 추측
 */

class Solution {
  public int solution(int num) {
    int answer = 0;
    int cnt = 0;

    if(num == 1) return 0;

    long n = new Long(num);

    while(true){
      if(n == 1 || answer > 500) break;

      answer++;

      if(n % 2 == 0){
        n /= 2;
      }
      else{
        n *= 3;
        n += 1;
      }
    }

    if(answer > 500) answer = -1;

    return answer;
  }
}