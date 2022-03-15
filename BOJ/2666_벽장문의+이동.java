/**
 * 22-03-12
 * BOJ 2666 벽장문의 이동
 * DP
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test2 {
  static int N, len;
  static int[] arr;
  static int[][][] dp;
  static int MX = 20;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    N = Integer.parseInt(br.readLine());
    arr = new int[MX+1];
    dp = new int[MX+1][MX+1][MX+1];

    st = new StringTokenizer(br.readLine());
    int X1 = Integer.parseInt(st.nextToken());
    int X2 = Integer.parseInt(st.nextToken());

    len = Integer.parseInt(br.readLine());
    for(int i=0; i<len; i++){
      arr[i] = Integer.parseInt(br.readLine());
    }

    for(int i=0; i<=MX; i++)
      for(int j=0; j<=MX; j++)
        for(int k=0; k<=MX; k++)
          dp[i][j][k] = -1;

    System.out.println(solve(X1, X2, 0));
  }

  static int solve(int x1, int x2, int idx){
    if(idx==len)
      return 0;

    if(dp[x1][x2][idx] != -1)
      return dp[x1][x2][idx];

    dp[x1][x2][idx] = Math.min(
            solve(arr[idx], x2, idx+1) + Math.abs(arr[idx] - x1),
            solve(x1, arr[idx], idx+1) + Math.abs(arr[idx] - x2));

    return dp[x1][x2][idx];
  }
}