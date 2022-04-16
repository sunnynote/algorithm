/**
 * 22-04-16
 * BOJ 15486 퇴사 2
 * DP
 */

import java.io.*;
import java.util.*;

public class test2 {
  static int N;
  static int[][] arr;
  static int[] d;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    arr = new int[N + 5][2];
    d = new int[N + 5];

    for(int i=1; i<=N; i++){
      st =  new StringTokenizer(br.readLine());
      arr[i][0] = Integer.parseInt(st.nextToken());
      arr[i][1] = Integer.parseInt(st.nextToken());
    }

    int mx = 0;

    for(int i=1; i<=N+1; i++){
      mx = Math.max(mx, d[i]);

      if(i + arr[i][0] > N + 1) continue;

      d[i + arr[i][0]] = Math.max(d[i + arr[i][0]], mx + arr[i][1]);
    }

    System.out.println(mx);
  }
}