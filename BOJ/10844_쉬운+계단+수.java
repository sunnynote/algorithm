/**
 * 22-03-15
 * BOJ 10844 쉬운 계단수
 * DP : D[N][L] -> 길이 N일 때, 마지막 수 L일 경우의 계단수
 */

import java.util.Scanner;

public class test2 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[][] d = new long[101][10];

    for(int i=1; i<=9; i++){
      d[1][i] = 1; // 1~9 초기 : 1
    }

    for(int i=2; i<=N; i++){ // 자릿수
      for(int j=0; j<=9; j++){ // 0~9 채운다

        if(j > 0){ // 0 제외
          d[i][j] += d[i-1][j-1];
        }
        if(j < 9){ // 9 제외
          d[i][j] += d[i-1][j+1];
        }

        d[i][j] %= 1000000000;
      }
    }

    long ans = 0;
    for(int i=0; i<=9; i++){
      ans += d[N][i];
    }

    System.out.println(ans % 1000000000);
  }
}