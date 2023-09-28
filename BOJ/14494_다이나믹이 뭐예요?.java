/**
 * 23-09-28
 * BOJ 14494 다이나믹이 뭐예요?
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

    long[][] d = new long[N+1][M+1];

    for(int i=1; i<=N; i++){
      d[i][1] = 1;
    }
    for(int j=1; j<=M; j++){
      d[1][j] = 1;
    }

    for(int i=2; i<=N; i++){
      for(int j=2; j<=M; j++){
        d[i][j] = (d[i][j-1] + d[i-1][j-1] + d[i-1][j]) % 1000000007;
      }
    }

    System.out.println(d[N][M]);
  }
}
