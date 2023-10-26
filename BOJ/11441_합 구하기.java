/**
 * 23-10-26
 * BOJ 11441 합 구하기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());

    int[] arr = new int[N + 1];
    int[] sum = new int[N + 1];

    st = new StringTokenizer(br.readLine());

    for(int i=1; i<=N; i++){
      arr[i] = Integer.parseInt(st.nextToken());

      if(i==1) sum[i] = arr[i];
      else sum[i] = sum[i-1] + arr[i];
    }

    int M = Integer.parseInt(br.readLine());

    for(int i=0; i<M; i++){
      st = new StringTokenizer(br.readLine());

      int l = Integer.parseInt(st.nextToken());
      int r = Integer.parseInt(st.nextToken());

      System.out.println(sum[r] - sum[l-1]);
    }
  }
}
