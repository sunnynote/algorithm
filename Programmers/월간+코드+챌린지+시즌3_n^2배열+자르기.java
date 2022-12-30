/**
 * 22-12-30
 * Programmers 월간 코드 챌린지 시즌3 - n^2 배열 자르기
 */

class Solution {
  public int[] solution(int n, long left, long right) {
    int[] answer = {};

    int N = (int)(right/n)  - (int)(left/n) + 1;
    int[][] arr = new int[N][n];
    int val = (int)(left/n);

    for(int i=0; i<N; i++){
      val++;

      for(int j=0; j<n; j++){
        if(val > j) arr[i][j] = val;
        else arr[i][j] = j + 1;
      }
    }

    int idx = 0;
    int[] res = new int[N*n];

    for(int i=0; i<N; i++){
      for(int j=0; j<n; j++){
        res[idx++] = arr[i][j];
      }
    }

    int end_idx = (int)(right - left);
    int st = (int)(left % n);

    answer = new int[end_idx + 1];
    idx = 0;

    while(true){
      if(idx > end_idx) break;
      answer[idx++] = res[st++];
    }

    return answer;
  }
}