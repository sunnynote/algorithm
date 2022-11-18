/**
 * 22-11-18
 * Programmers
 * Summer/Winter Coding 2018 - 점프와 순간 이동
 */

import java.util.*;

public class Solution {
  public int solution(int n) {
    int ans = 0;

    while(n != 0){
      if(n % 2 == 0){
        n /= 2;
      }
      else{
        ans++;
        n--;
      }
    }

    return ans;
  }
}
