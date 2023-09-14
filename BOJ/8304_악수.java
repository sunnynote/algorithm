/**
 * 23-09-14
 * BOJ 8394 악수
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    int[] d = new int[N + 2];

    d[0] = 0;
    d[1] = 1;
    d[2] = 2;

    for(int i=3; i<=N; i++){
      d[i] = (d[i-1] % 10 + d[i-2] % 10) % 10;
    }

    System.out.println(d[N]);
  }
}
