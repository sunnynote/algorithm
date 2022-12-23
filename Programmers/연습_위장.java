/**
 * 22-12-23
 * Programmers 연습 - 위장
 */

import java.util.*;

class Solution {
  public int solution(String[][] clothes) {
    int answer = 1;

    HashMap<String,Integer> mp = new HashMap<>();

    for(int i=0; i<clothes.length; i++){
      String kind = clothes[i][1];

      if(mp.containsKey(kind)){
        mp.put(kind, mp.get(kind) + 1);
      }
      else{
        mp.put(kind, 1);
      }
    }

    for(Map.Entry<String,Integer> entry : mp.entrySet()){
      answer *= (entry.getValue() + 1);
    }

    answer -= 1;

    return answer;
  }
}