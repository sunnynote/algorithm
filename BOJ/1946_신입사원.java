/**
 * 22-03-26
 * BOJ 1946 신입사원
 * 그리디
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int T = Integer.parseInt(br.readLine());

    while(T-- > 0){
      int N = Integer.parseInt(br.readLine());

      int[][] arr = new int[N][2];

      for(int i=0; i<N; i++){
        st = new StringTokenizer(br.readLine());

        arr[i][0] = Integer.parseInt(st.nextToken());
        arr[i][1] = Integer.parseInt(st.nextToken());
      }

      Arrays.sort(arr, new Comparator<int[]>() {
        @Override
        public int compare(int[] o1, int[] o2) {
          if(o1[0]==o2[0])
            return o1[1] - o2[1];
          return o1[0] - o2[0];
        }
      });

      int val = arr[0][1];
      int ans = 1;

      for(int i=1; i<N; i++){
        if(val > arr[i][1]){
          val = arr[i][1];
          ans++;
        }
      }

      System.out.println(ans);
    }
  }
}