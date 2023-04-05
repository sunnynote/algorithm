/**
 * 23-04-05
 * BOJ 2018 수들의 합 5
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    int ans = 0;

    int l = 1, r = 1, sum = 1;

    while(l <= N){
      if(sum == N) ans++;

      if(sum < N){
        r++;
        sum += r;
      }
      else if(sum >= N){
        sum -= l;
        l++;
      }
    }
    System.out.println(ans);
  }
}
