/**
 * 23-01-27
 * Programmers 연습 - 연속 부분 수열 합의 개수
 */

import java.util.*;

class Solution {
  public int solution(int[] elements) {
    int answer = 0;

    int N = elements.length;

    int[] arr = new int[N * 2];

    for(int i=0; i<N; i++){
      arr[i] = elements[i];
      arr[i + N] = elements[i];
    }

    HashSet <Integer> hs = new HashSet<>();

    for(int i=1; i<=N; i++){ // 길이가 i (1~N)

      for(int j=0; j<N; j++){ // 시작하는 원소 인덱스
        int sum = 0;

        for(int k=j; k<i+j; k++){ // 실제로 길이 채우기
          sum += arr[k];
        }

        hs.add(sum);
      }
    }

    answer = hs.size();

    return answer;
  }
}