/**
 * 22-11-02
 * Programmers 연습 - 자연수 뒤집어 배열로 만들기
 */

class Solution {
  public int[] solution(long n) {

    String s = Long.toString(n);
    int N = s.length();
    int[] answer = new int[N];

    for(int i=0; i<N; i++){
      answer[i] = s.charAt(N-1-i) - '0';
    }

    return answer;
  }
}