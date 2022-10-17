/**
 * 22-10-11
 * Programmers 연습문제 - 최솟값 만들기
 */

import java.util.*;

class Solution
{
  public int solution(int []A, int []B)
  {
    int answer = 0;

    Arrays.sort(A);
    Arrays.sort(B);

    int len = A.length;

    for(int i=0; i<len; i++){
      answer += A[i] * B[B.length - i - 1];
    }

    return answer;
  }
}