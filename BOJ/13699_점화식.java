/**
 * 23-11-07
 * BOJ 13699 점화식
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    long[] memo = new long[36];

    memo[0] = 1;
    memo[1] = 1;

    for(int i=2; i<=N; i++){
      for(int j=0; j<i; j++){
        memo[i] += memo[j] * memo[i-1-j];
      }
    }

    System.out.print(memo[N]);
  }
}
