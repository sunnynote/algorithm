/**
 * 22-12-01
 * Programmers 연습 - 하샤드 수
 */

class Solution {
  public boolean solution(int x) {
    boolean answer = true;

    int n = x;
    int sum = 0;

    while(n != 0){
      sum += (n % 10);
      n /= 10;
    }

    if(x % sum != 0) answer = false;

    return answer;
  }
}