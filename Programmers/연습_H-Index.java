/**
 * 22-12-15
 * Programmers 연습 - H-Index
 */

import java.util.*;

class Solution {
  public int solution(int[] citations) {
    int answer = 0;

    Integer[] arr = Arrays.stream(citations).boxed().toArray(Integer[]::new);
    Arrays.sort(arr, Collections.reverseOrder());
    int n = arr.length;

    for(int i=0; i<n; i++){
      for(int j=n; j>=0; j--){
        if(j > arr[i]) continue;

        if(j <= i+1 && j >= n-i-1){
          if(answer < j){
            answer = j;
            break;
          }
        }
      }
    }

    return answer;
  }
}