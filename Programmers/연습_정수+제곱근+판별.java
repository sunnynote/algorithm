/**
 * 22-11-23
 * Programmers 여
 */
class Solution {
  public long solution(long n) {
    long answer = 0;

    for(long i=1; i*i<=n; i++){
      if(i*i == n){
        answer = (i+1) * (i+1);
      }
    }

    if(answer == 0) answer = -1;

    return answer;
  }
}