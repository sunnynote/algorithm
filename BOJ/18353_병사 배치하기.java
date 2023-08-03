/**
 * 23-08-03
 * BOJ 18353 병사 배치하기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class d {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    int[] arr = new int[N];
    int[] res = new int[N];

    StringTokenizer st = new StringTokenizer(br.readLine());

    for(int i=N-1; i>=0; i--){
      arr[i] = Integer.parseInt(st.nextToken());
    }

    for(int i=0; i<N; i++){
      res[i] = 1;

      for(int j=0; j<i; j++){
        if(res[i] < res[j] + 1 && arr[j] < arr[i]){
          res[i] = res[j] + 1;
        }
      }
    }

    int mx = -1;
    for(int i=0; i<N; i++){
      if(mx < res[i]) mx = res[i];
    }

    System.out.print(N - mx);
  }
}
