/**
 * 23-05-24
 * BOJ 27433 팩토리얼 2
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ss {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    long N = Long.parseLong(br.readLine());
    long ans = 1;

    for(int i=2; i<=N; i++){
      ans *= i;
    }

    System.out.println(ans);
  }
}
