/**
 * 23-09-22
 * BOJ 14495 피보나치 비스무리한 수열
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    long[] d = new long[N + 3];

    d[1] = 1;
    d[2] = 1;
    d[3] = 1;

    for(int i=4; i<=N; i++){
      d[i] = d[i-1] + d[i-3];
    }

    System.out.println(d[N]);
  }
}
