/**
 * 22-03-08
 * BOJ 12852 1로 만들기2
 * dp
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test {
  static int N;
  static int[] d;
  static int[] prev;
  static int ans = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    d = new int[N + 1];
    prev = new int[N + 1];

    System.out.println(solve(N));

    while(true){
      if(N==0) break;
      System.out.print(N + " ");
      N = prev[N];
    }

  }

  static int solve(int x){
    d[1] = 0;

    for(int i=2; i<=N; i++){
      // 3)
      d[i] = d[i-1] + 1;
      prev[i] = i - 1;

      // 1)
      if(i%3 == 0){
        if(d[i] > d[i/3] + 1){
          d[i] = d[i/3] + 1;
          prev[i] = i/3;
        }
      }

      // 2)
      if(i%2 == 0){
        if(d[i] > d[i/2] + 1){
          d[i] = d[i/2] + 1;
          prev[i] = i/2;
        }
      }
    }

    return d[x];
  }
}