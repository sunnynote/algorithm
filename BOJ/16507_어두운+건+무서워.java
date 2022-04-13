/**
 * 22-04-12
 * BOJ 16507 어두운 건 무서워
 * 누적합 prefix_sum
 */

import java.io.*;
import java.util.*;

public class test3 {
  static int N, M, Q;
  static int[][] map;
  static int[][] sum;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    Q = Integer.parseInt(st.nextToken());

    map = new int[N + 1][M + 1];
    sum = new int[N + 1][M + 1];

    for(int i=1; i<=N; i++){
      st = new StringTokenizer(br.readLine());
      for(int j=1; j<=M; j++){
        map[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    prefix_sum();

    for(int i=0; i<Q; i++) {
      st = new StringTokenizer(br.readLine());

      int x1 = Integer.parseInt(st.nextToken());
      int y1 = Integer.parseInt(st.nextToken());
      int x2 = Integer.parseInt(st.nextToken());
      int y2 = Integer.parseInt(st.nextToken());

      int div = (x2 - x1 + 1) * (y2 - y1 + 1);

      int ans = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
      System.out.println(ans / div);
    }
  }

  static void prefix_sum(){
    for(int i=1; i<=N; i++){
      sum[i][1] = map[i][1];

      for(int j=2; j<=M; j++){
        sum[i][j] = sum[i][j-1] + map[i][j];
      }
    }

    for(int j=1; j<=M; j++){
      for(int i=2; i<=N; i++){
        sum[i][j] = sum[i-1][j] + sum[i][j];
      }
    }
  }
}