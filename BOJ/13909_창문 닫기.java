/**
 * 23-04-12
 * BOJ 13909 창문 닫기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    int ans = 0;

    for(int i=1; i*i<=N; i++){
     ans++;
    }

    System.out.println(ans);
  }
}
