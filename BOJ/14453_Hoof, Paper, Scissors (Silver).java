/**
 * 22-04-26
 * BOJ 14453 Hoof, Paper, Scissors (Silver)
 * prefix sum
 */

import java.io.*;
import java.util.*;

public class test6 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    int[][] arr = new int[N+1][3];

    for(int i=0; i<N; i++){
      String s = br.readLine();

      if(s.equals("H")){
        arr[i][0]++;
      }
      else if(s.equals("P")){
        arr[i][1]++;
      }
      else{ // S
        arr[i][2]++;
      }

      if(i == 0) continue;

      arr[i][0] += arr[i-1][0];
      arr[i][1] += arr[i-1][1];
      arr[i][2] += arr[i-1][2];
    }

    int ans = 0;
    for(int i=1; i<N; i++){
      int l = Math.max(arr[i-1][0], Math.max(arr[i-1][1], arr[i-1][2]));
      int r = Math.max( (arr[N-1][0] - arr[i-1][0]), Math.max(arr[N-1][1] - arr[i-1][1], arr[N-1][2] - arr[i-1][2]));

      ans = Math.max(ans, (l + r));
    }

    ans = Math.max(ans, Math.max(arr[N-1][0], Math.max(arr[N-1][1], arr[N-1][2])));

    System.out.println(ans);
  }
}