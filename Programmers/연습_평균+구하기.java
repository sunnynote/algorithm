/**
 * 22-11-01
 * Programmers 연습 - 평균 구하기
 */

class Solution {
  public double solution(int[] arr) {
    double answer = 0;
    int N = arr.length;

    for(int i=0; i<N; i++){
      answer += arr[i];
    }

    answer /= N;

    return answer;
  }
}