/**
 * 23-04-03
 * BOJ 10811 바구니 뒤집기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    int[] arr = new int[N+1];

    for(int i=1; i<=N; i++){
      arr[i] = i;
    }

    for(int i=0; i<M; i++){
      st = new StringTokenizer(br.readLine());

      int l = Integer.parseInt(st.nextToken());
      int r = Integer.parseInt(st.nextToken());

      for(int j=l; j<=r; j++, r--){
        int tmp = arr[j];
        arr[j] = arr[r];
        arr[r] = tmp;
      }
    }

    for(int i=1; i<=N; i++){
      System.out.print(arr[i] + " ");
    }
  }
}
