/**
 * 22-11-16
 * Programmers 연습 - 다음 큰 숫자
 */

class Solution {
  public int solution(int n) {
    int answer = 0;

    boolean f = false;
    int res = func(n);

    while(!f){
      int val = func(++n);
      if(res == val){
        answer = n;
        f = true;
      }
    }

    return answer;
  }

  int func(int N){
    int cnt = 0;

    while(N != 0){
      if(N % 2 == 1) cnt++;
      N /= 2;
    }

    return cnt;
  }
}