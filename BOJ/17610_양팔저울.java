/**
 * 22-04-13
 * BOJ 17610 양팔저울
 * DFS
 */

import java.io.*;
import java.util.*;

public class test3 {
  static int N, mx = 0;
  static int[] arr;
  static boolean[] chk;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    arr = new int[N];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      arr[i] = Integer.parseInt(st.nextToken());
      mx += arr[i];
    }

    chk = new boolean[mx + 1];

    dfs(0, 0);

    int cnt = 0;
    for(int i=1; i<=mx; i++){
      if(chk[i]) cnt++;
    }

    System.out.println(mx - cnt);
  }

  static void dfs(int idx, int w){
    if(idx == N){
      if(w > 0){
        chk[w] = true;
      }
      return;
    }

    dfs(idx + 1, w);
    dfs(idx + 1, w + arr[idx]);
    dfs(idx + 1, w - arr[idx]);
  }
}