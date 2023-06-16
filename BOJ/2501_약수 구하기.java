/**
 * 23-06-16
 * BOJ 2501 약수 구하기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());

    boolean[] prime = new boolean[N + 1];
    int cnt = 0;

    for(int i=1; i<=N; i++){
      if(N % i == 0){
        prime[i] = true;
        cnt++;
      }
    }

    int ans = 0;
    if(cnt < K) System.out.print(0);
    else{
      for(int i=1; i<=N; i++){
        if(!prime[i]) continue;

        ans++;
        if(ans == K) System.out.print(i);
      }
    }
  }
}
