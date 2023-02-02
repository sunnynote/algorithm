/**
 * 23-02-02
 * BOJ 7795 먹을 것인가 먹힐 것인가
 * 투 포인터
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int T= Integer.parseInt(br.readLine());
    for(int t=0; t<T; t++){
      st = new StringTokenizer(br.readLine());
      int N = Integer.parseInt(st.nextToken());
      int M = Integer.parseInt(st.nextToken());

      int[] arrA = new int[N];
      int[] arrB = new int[M];

      st = new StringTokenizer(br.readLine());
      for(int i=0; i<N; i++){
        arrA[i] = Integer.parseInt(st.nextToken());
      }

      st = new StringTokenizer(br.readLine());
      for(int i=0; i<M; i++){
        arrB[i] = Integer.parseInt(st.nextToken());
      }

      Arrays.sort(arrA);
      Arrays.sort(arrB);

      int sum = 0;
      int idx = M-1;
      int cnt = M;

      for(int i=N-1; i>=0; i--){
        while(true){
          if(arrA[i] > arrB[idx]) break;

          if(idx > 0 && arrA[i] <= arrB[idx]){
            idx--;
            cnt--;
          }
          if(idx == 0 && arrA[i] <= arrB[idx]){
            cnt = 0;
            break;
          }
        }
        sum += cnt;
      }

      System.out.println(sum);
    }
  }
}
