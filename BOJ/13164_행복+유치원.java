/**
 * 22-03-17
 * BOJ 13164 행복 유치원
 * 그리디
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class test2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());

    int[] arr = new int[N];
    int[] diff = new int[N-1];

    st = new StringTokenizer(br.readLine());
    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    for(int i=1; i<N; i++){
      diff[i-1] = arr[i] - arr[i-1];
    }

    Arrays.sort(diff);

    int ans = 0;
    for(int i=0; i<N-K; i++){
      ans += diff[i];
    }
    System.out.println(ans);
  }
}