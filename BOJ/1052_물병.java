/**
 * 22-04-14
 * BOJ 1052 물병
 * 그리디
 */

import java.io.*;
import java.util.*;

public class test2 {
  static int N, K;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    if (N <= K) {
      System.out.println(0);
    }
    else {
      int ans = 0;

      while(true){
        int n = N;
        if(getCnt(n) <= K) break;

        N++;
        ans++;
      }

      System.out.println(ans);
    }
  }

  static int getCnt(int n){
    int cnt = 0;

    while(n > 0){
      if(n % 2 == 1) cnt++;
      n /= 2;
    }

    return cnt;
  }
}