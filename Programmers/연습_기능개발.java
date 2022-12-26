/**
 * 22-12-26
 * Programmers 연습 - 기능개발
 */

import java.util.*;

class Solution {
  public int[] solution(int[] progresses, int[] speeds) {
    int N = progresses.length;
    int[] answer = new int[N];

    int[] res = new int[N];

    for(int i=0; i<N; i++){
      res[i] = (int) Math.ceil( (double)(100-progresses[i]) / speeds[i] );
    }

    int[] res2 = new int[N];
    res2[0] = res[0];

    for(int i=1; i<N; i++){
      if(res2[i-1] > res[i]) res2[i] = res2[i-1];
      else res2[i] = res[i];
    }

    int cnt = 1;
    int idx = 0;
    for(int i=0; i<N-1; i++){
      if(res2[i] != res2[i+1]){
        answer[idx++] = cnt;
        cnt = 1;
      }
      else{
        cnt++;
      }
    }

    answer[idx++] = cnt;
    answer = Arrays.copyOf(answer, idx);

    return answer;
  }
}