/**
 * 22-12-13
 * Programmers 연습 - 정수 내림차순으로 배치하기
 */

class Solution {
  public long solution(long n) {
    long answer = 0;
    int[] arr = new int[10];

    while(n != 0){
      int res = (int)(n % 10);
      arr[res]++;
      n /= 10;
    }

    String s = "";
    for(int i=9; i>=0; i--){
      if(arr[i] == 0) continue;

      for(int j=0; j<arr[i]; j++){
        int cur = i;

        s += Integer.toString(cur);
      }
    }

    answer = Long.parseLong(s);

    return answer;
  }
}