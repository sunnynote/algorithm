/**
 * 22-04-05
 * BOJ 2643 색종이 올려 놓기
 * DP, LIS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class test1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[][] arr = new int[N][2];
    int[] d = new int[N];
    int ans = 0;

    for(int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());

      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());

      if(x > y) {
        arr[i][0] = x;
        arr[i][1] = y;
      }
      else {
        arr[i][0] = y;
        arr[i][1] = x;
      }
    }

    Arrays.sort(arr, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        if(o1[0] == o2[0]) return o2[1] - o1[1];
        return o2[0] - o1[0];
      }
    });


    for(int i = 0; i < N; i++) {
      d[i] = 1;
      System.out.println(arr[i][0] + " " + arr[i][1]);
    }

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < i; j++) {

        if(arr[i][0] <= arr[j][0] && arr[i][1] <= arr[j][1]){
          if(d[i] < d[j] + 1){
            d[i] = d[j] + 1;
          }
        }
      }

      ans = Math.max(ans, d[i]);
    }

    System.out.println(ans);
  }
}
