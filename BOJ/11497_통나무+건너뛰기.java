/**
 * 22-03-28
 * BOJ 11497 통나무 건너뛰기
 * 그리디
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int T = Integer.parseInt(br.readLine());

    while(T-- > 0){
      int N = Integer.parseInt(br.readLine());
      int[] arr = new int[N];
      int[] res = new int[N];

      st = new StringTokenizer(br.readLine());
      for(int i=0; i<N; i++){
        arr[i] = Integer.parseInt(st.nextToken());
      }

      Arrays.sort(arr);

      int cnt = 0;
      for(int i=0, j=N-1; i<N/2; i++, j--){
        res[i] = arr[cnt++];
        res[j] = arr[cnt++];
      }

      if(N % 2 == 1) res[N/2] = arr[N - 1];

      int ans = Integer.MIN_VALUE;
      for(int i=1; i<N; i++){
        ans = Math.max(ans, Math.abs(res[i-1]-res[i]));
      }

      System.out.println(ans);
    }
  }
}