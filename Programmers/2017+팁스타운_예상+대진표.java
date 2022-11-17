/**
 * 22-11-17
 * Programmers 2017 팁스타운 - 예상 대진표
 */

class Solution
{
  public int solution(int n, int a, int b)
  {
    int answer = 0;

    while(true){
      a = a / 2 + a % 2;
      b = b / 2 + b % 2;

      answer++;

      if(a == b) break;
    }


    return answer;
  }
}