/**
 * 22-02-18
 * BOJ 10830 행렬 제곱
 * 분할 정복
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test {
  final static int MOD = 1000;
  static int N;
  static long B;
  static long[][] mat;
  static long[][] ans;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    B = Long.parseLong(st.nextToken());

    mat = new long[N][N];
    ans = new long[N][N];

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0; j<N; j++){
        mat[i][j] = Long.parseLong(st.nextToken()) % MOD;
      }
    }

    ans = solve(mat, B);

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        System.out.print(ans[i][j] + " ");
      }
      System.out.println();
    }
  }

  static long[][] solve(long[][] arr, long n){
    if(n==1)
      return arr;

    long[][] ret = solve(arr, n/2);
    ret = mul(ret, ret);

    if(n%2==1)
      ret = mul(ret, mat);

    return ret;
  }

  static long[][] mul(long[][] a1, long[][] a2){
    long[][] ret = new long[N][N];

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        for(int k=0; k<N; k++){
          ret[i][j] += (a1[i][k] * a2[k][j]);
          ret[i][j] %= MOD;
        }
      }
    }
     return ret;
  }
}