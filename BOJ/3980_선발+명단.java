/**
 * 22-04-18
 * BOJ 3980 선발 명단
 * 백트래킹
 */

import java.io.*;
import java.util.*;

public class test5 {
  static final int N = 11;
  static int[][] arr;
  static boolean[] chk;
  static int ans;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int T = Integer.parseInt(br.readLine());

    while(T-- > 0){
      arr = new int[N][N];
      chk = new boolean[N];
      ans = 0;

      for(int i=0; i<N; i++){
        st = new StringTokenizer(br.readLine());
        for(int j=0; j<N; j++){
          arr[i][j] = Integer.parseInt(st.nextToken());
        }
      }

      solve(0, 0);
      System.out.println(ans);
    }
  }

  static void solve(int cnt, int res){
    if(cnt==N){
      ans = Math.max(ans, res);
      return;
    }

    for(int i=0; i<N; i++){
      if(chk[i] || arr[cnt][i] == 0) continue;

      chk[i] = true;
      solve(cnt + 1, res + arr[cnt][i]);
      chk[i] = false;
    }
  }
}