/**
 * 22-10-18
 * Programmers 연습문제 - 카펫
 */

class Solution {
  public int[] solution(int brown, int yellow) {
    int[] answer = {0, 0};

    int N = brown + yellow;
    int cur = 3;

    boolean f = false;

    while(!f){
      if(N % cur == 0){
        int n = N / cur;

        if((n-2)*(cur-2) == yellow){
          answer[0] = n;
          answer[1] = cur;
          f = true;
        }
      }
      cur++;
    }

    return answer;
  }
}