/**
 * 22-04-07
 * BOJ 2141 우체국
 * 그리디
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class test1 {
  static int N;
  static long[][] arr;
  static long sum = 0, ans = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    arr = new long[N][2];

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());

      arr[i][0] = Integer.parseInt(st.nextToken());
      arr[i][1] = Integer.parseInt(st.nextToken());

      sum += arr[i][1];
    }

    Arrays.sort(arr, new Comparator<long[]>() {
      @Override
      public int compare(long[] o1, long[] o2) {
        if(o1[0] < o2[0]) return -1;
        else if(o1[0] == o2[0]){
          if(o1[1] < o2[1]) return -1;
        }
        return 1;
      }
    });

    long val = 0;
    for(int i=0; i<N; i++){
      val += arr[i][1];

      if(val >= (sum + 1) / 2){
        ans = arr[i][0];
        break;
      }
    }

    System.out.println(ans);
  }
}