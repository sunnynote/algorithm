/**
 * 22-12-07
 * Programmers 연습 - x만큼 간격이 있는 n개의 숫자
 */

class Solution {
  public long[] solution(int x, int n) {
    long[] answer = {};
    answer = new long[n];

    answer[0] = x;

    for(int i=1; i<n; i++){
      answer[i] = answer[i-1] + x;
    }

    return answer;
  }
}