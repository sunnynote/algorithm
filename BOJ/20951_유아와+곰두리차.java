/**
 * 22-02-21
 * BOJ 20951 유아와 곰두리차
 * DP
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class test {
  static int N, M;
  static ArrayList<Integer>[] v;
  static long[][] dp;
  static final long MOD = 1000000007L;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    v = new ArrayList[N+1];
    dp = new long[8][N+1];

    for(int i=1; i<=N; i++)
      v[i] = new ArrayList<Integer>();

    for(int i=0; i<M; i++){
      int x, y;
      st = new StringTokenizer(br.readLine());
      x = Integer.parseInt(st.nextToken());
      y = Integer.parseInt(st.nextToken());

      v[x].add(y);
      v[y].add(x);
      dp[0][x] = 1;
      dp[0][y] = 1;
    }

    // solve
    for(int i=1; i<=7; i++)
      for(int j=1; j<=N; j++)
        for(int k=0; k<v[j].size(); k++)
          dp[i][v[j].get(k)] = ( dp[i][v[j].get(k)] % MOD + dp[i-1][j] % MOD ) % MOD;

    long ans = 0;
    for(int i=1; i<=N; i++)
      ans = (ans%MOD + dp[7][i]%MOD) % MOD;

    System.out.println(ans);
  }
}