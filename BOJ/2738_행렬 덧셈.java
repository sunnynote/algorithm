/**
 * 23-02-17
 * BOJ 2738 godfuf
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class sdf {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int[][] ans = new int[N][M];

    for(int k=0; k<2; k++) {
      for (int i=0; i<N; i++) {
        st = new StringTokenizer(br.readLine());
        for (int j=0; j<M; j++) {
          ans[i][j] += Integer.parseInt(st.nextToken());
        }
      }
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        System.out.print(ans[i][j] + " ");
      }
      System.out.println();
    }

  }
}
