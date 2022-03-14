/**
 * 22-03-14
 * BOJ 23351 물 주기
 * 그리디
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());
    int A = Integer.parseInt(st.nextToken());
    int B = Integer.parseInt(st.nextToken());

    int[] chk = new int[N+A+1];

    for(int i=0; i<N; i++)
      chk[i] = K;

    boolean f = false;

    int ans = 0;
    int idx = 0;

    while(true){
      if(f) break;

      ans++;

      for(int i=idx; i<idx+A; i++)
        chk[i] += B;

      idx = (idx+A) % N;

      for(int i=0; i<N; i++){
        chk[i] -= 1;

        if(chk[i] <= 0)
          f = true;
      }
    }

    System.out.println(ans);
  }
}