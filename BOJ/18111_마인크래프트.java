/**
 * 22-04-28
 * BOJ 18111 마인 크래프트
 * 구현
 */

import java.io.*;
import java.util.*;

public class test6 {
  static int N, M, B;
  static int[][] arr;
  static int ans_t, ans_h, mx;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    B = Integer.parseInt(st.nextToken());

    arr = new int[N+1][M+1];
    ans_t = Integer.MAX_VALUE;
    ans_h = Integer.MIN_VALUE;

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());

      for(int j=0; j<M; j++){
        arr[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    solve();

    System.out.println(ans_t + " " + ans_h);
  }

  static void solve(){
    for(int h=0; h<=256; h++){

      int t = 0;
      int b = B;

      for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
          if(arr[i][j] > h){
            b += (arr[i][j] - h);
            t += (arr[i][j] - h) * 2;
          }
          else if(arr[i][j] < h){
            b -= (h - arr[i][j]);
            t += (h - arr[i][j]);
          }
        }
      }

      if(b < 0) continue;

      if(ans_t == t && ans_h < h){
        ans_h = h;
        continue;
      }

      if(ans_t >= t){
        ans_t = t;
        ans_h = h;
      }
    }
  }
}
