/**
 * 22-04-17
 * BOJ 2594 놀이공원
 * 구현
 */

import java.io.*;
import java.util.*;

public class test5 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int[][] arr = new int[N + 2][2];

    arr[0][0] = 600;
    arr[0][1] = 600;

    for(int i=1; i<=N; i++){
      st = new StringTokenizer(br.readLine());

      String s = st.nextToken();
      String e = st.nextToken();

      arr[i][0] = Integer.parseInt(s.substring(0, 2)) * 60 + Integer.parseInt(s.substring(2, 4)) - 10;
      arr[i][1] = Integer.parseInt(e.substring(0, 2)) * 60 + Integer.parseInt(e.substring(2, 4)) + 10;
    }

    arr[N + 1][0] = 1320;
    arr[N + 1][1] = 1320;

    Arrays.sort(arr, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        if(o1[0] == o2[0]) return o1[1] - o2[1];
        return o1[0] - o2[0];
      }
    });

    int mx = 0;
    int end = 600;

    for(int i=0; i<N + 2; i++){
      if(end >= arr[i][0]){
        end = Math.max(end, arr[i][1]);
      } else {
        mx = Math.max(mx, arr[i][0] - end);
        end = arr[i][1];
      }
    }

    System.out.println(mx);
  }
}