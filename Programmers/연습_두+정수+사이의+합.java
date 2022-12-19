/**
 * 22-12-19
 * Programmers 연습 - 두 정수 사이의 합
 */

class Solution {
  public long solution(int a, int b) {
    long answer = 0;

    if(a > b){
      int tmp = a;
      a = b;
      b = tmp;
    }

    for(int i=a; i<=b; i++){
      answer += i;
    }

    return answer;
  }
}