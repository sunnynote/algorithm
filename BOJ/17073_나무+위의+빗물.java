/**
 * 22-04-05
 * BOJ 17073 나무 위의 빗물
 * 그래프
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    double W = Integer.parseInt(st.nextToken());

    int[] leat_cnt = new int[N+1];
    for(int i=0; i<N-1; i++){
      st = new StringTokenizer(br.readLine());
      int U = Integer.parseInt(st.nextToken());
      int V = Integer.parseInt(st.nextToken());

      leat_cnt[U]++;
      leat_cnt[V]++;
    }

    int val = 0;
    for(int i=2; i<=N; i++) {
      if (leat_cnt[i] == 1) val++;
    }
    System.out.println(W/val);
  }
}
