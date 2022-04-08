/**
 * 22-04-08
 * BOJ 9763 마을의 친밀도
 * BF
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test1 {
  static int[][] arr;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());

    arr = new int[N + 1][3];

    int ans = Integer.MAX_VALUE;

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());
      arr[i][0] = Integer.parseInt(st.nextToken());
      arr[i][1] = Integer.parseInt(st.nextToken());
      arr[i][2] = Integer.parseInt(st.nextToken());
    }

    for(int i=0; i<N; i++){
      int mn1 = Integer.MAX_VALUE;
      int mn2 = Integer.MAX_VALUE;

      for(int j=0; j<N; j++){
        if(i == j) continue;

        int d = calc(i, j);

        if(mn1 > d){
          mn2 = mn1;
          mn1 = d;
        }
        else if(mn2 > d){
          mn2 = d;
        }
      }

      ans = Math.min(ans, mn1 + mn2);
    }

    System.out.println(ans);
  }

  static int calc(int a, int b){
    return Math.abs(arr[a][0] - arr[b][0])
            + Math.abs(arr[a][1] - arr[b][1])
            + Math.abs(arr[a][2] - arr[b][2]);
  }
}