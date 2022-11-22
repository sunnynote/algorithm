/**
 * 22-11-22
 * Programmers 연습 - 멀리 뛰기
 */

class Solution {
  public long solution(int n) {
    long answer = 0;

    long[] arr = new long[n + 1];

    arr[0] = 1;
    arr[1] = 1;

    for(int i=2; i<=n; i++){
      arr[i] = (arr[i-1] + arr[i-2]) % 1234567;
    }

    answer = arr[n];

    return answer;
  }
}