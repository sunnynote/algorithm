/**
 * 22-03-23
 * BOJ 2381 최대거리
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int N = Integer.parseInt(br.readLine());
    int[][] arr = new int[N+1][2];
    int mx, mn, p_res, m_res;

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());

      arr[i][0] = Integer.parseInt(st.nextToken());
      arr[i][1] = Integer.parseInt(st.nextToken());
    }

    mx = Integer.MIN_VALUE;
    mn = Integer.MAX_VALUE;

    for(int i=0; i<N; i++){
      mx = Math.max(mx, arr[i][0] + arr[i][1]);
      mn = Math.min(mn, arr[i][0] + arr[i][1]);
    }

    p_res = mx - mn;

    mx = Integer.MIN_VALUE;
    mn = Integer.MAX_VALUE;

    for(int i=0; i<N; i++){
      mx = Math.max(mx, arr[i][0] - arr[i][1]);
      mn = Math.min(mn, arr[i][0] - arr[i][1]);
    }

    m_res = mx - mn;

    System.out.println(Math.max(p_res, m_res));
  }
}