/**
 * 22-12-28
 * Programmers 연습 - 프린터
 */

import java.util.*;

class Solution {
  class Pair{
    int priority;
    int idx;

    public Pair(int priority, int idx){
      this.priority = priority;
      this.idx = idx;
    }
  }

  public int solution(int[] priorities, int location) {
    int answer = 0;

    Queue<Pair> q = new LinkedList<>();

    for(int i=0; i<priorities.length; i++){
      q.add(new Pair(priorities[i], i));
    }

    int cnt = 0;

    while(!q.isEmpty()){
      Pair x = q.poll();

      boolean f = false;

      for(Pair p : q){
        if(x.priority < p.priority){
          f = true;
          break;
        }
      }

      if(f){
        q.add(x);
      }
      else{
        cnt++;

        if(x.idx == location){
          answer = cnt;
          break;
        }
      }
    }

    return answer;
  }
}