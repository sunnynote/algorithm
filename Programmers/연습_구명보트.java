/**
 * 22-10-20
 * Programmers 연습 - 구명보트
 */

import java.util.*;

class Solution {
  public int solution(int[] people, int limit) {
    int answer = 0;

    Arrays.sort(people);

    int le = 0;
    int ri = people.length - 1;

    while(le <= ri){
      if(people[le] + people[ri] <= limit){
        le++;
      }
      ri--;
      answer++;
    }

    return answer;
  }
}