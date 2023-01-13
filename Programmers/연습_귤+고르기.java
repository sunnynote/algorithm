/**
 * 23-01-13
 * Programmers 연습 - 귤 고르기
 */

import java.util.*;

class Solution {
  public int solution(int k, int[] tangerine) {
    int answer = 0;
    HashMap <Integer,Integer> hs = new HashMap<>();

    for(int i=0; i<tangerine.length; i++){
      if(hs.containsKey(tangerine[i])){
        hs.put(tangerine[i], hs.get(tangerine[i]) + 1);
      }
      else{
        hs.put(tangerine[i], 1);
      }
    }

    List<Integer> arr = new ArrayList<>(hs.keySet());

    arr.sort((o1, o2) -> hs.get(o2) - hs.get(o1));

    int res = 0;
    for(Integer key : arr){
      if(res >= k) break;

      res += hs.get(key);
      answer++;
    }

    return answer;
  }
}