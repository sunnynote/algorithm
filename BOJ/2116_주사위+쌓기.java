/**
 * 22-04-12
 * BOJ 2116 주사위 쌓기
 * BF
 */

import java.io.*;
import java.util.*;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[][] dice = new int[N + 1][7];
    int[] pair = new int[7];

    for(int i=1; i<=N; i++){
      st = new StringTokenizer(br.readLine());

      for(int j=1; j<=6; j++){
        dice[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    pair[1] = 6;
    pair[2] = 4;
    pair[3] = 5;
    pair[4] = 2;
    pair[5] = 3;
    pair[6] = 1;

    int ans = 0;

    for(int k=1; k<=6; k++){

      // 1번 주사위의 down, top
      int dwn = dice[1][k];
      int tp = dice[1][pair[k]];

      int mx = -1;

      // 나머지 면 중에서 최댓값 찾기
      for(int i=1; i<=6; i++){
        if(dice[1][i]==dwn || dice[1][i]==tp) continue;
        mx = Math.max(mx, dice[1][i]);
      }

      int sum = mx;

      // 다음 주사위를 탐색한다.
      for(int i=2; i<=N; i++){

        int nx_mx = -1;

        // 다음 주사위
        for(int j=1; j<=6; j++){
          if(dice[i][j] == tp) {
            dwn = dice[i][j];
            tp = dice[i][pair[j]];
            break;
          }
        }

        for(int j=1; j<=6; j++){
          if(dice[i][j]==dwn || dice[i][j]==tp) continue;
          nx_mx = Math.max(nx_mx, dice[i][j]);
        }

        sum += nx_mx;
      }

      ans = Math.max(ans, sum);

    }
    System.out.println(ans);
  }

}