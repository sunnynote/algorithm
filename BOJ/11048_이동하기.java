/**
 * 22-03-16
 * BOJ 11048 이동하기
 * DP
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int[][] maze = new int[N][M];
    int[][] d = new int[N][M];

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0; j<M; j++){
        maze[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    d[0][0] = maze[0][0];

    for(int i=1; i<N; i++){
      d[i][0] = d[i-1][0] + maze[i][0];
    }

    for(int j=1; j<M; j++){
      d[0][j] = d[0][j-1] + maze[0][j];
    }

    for(int i=1; i<N; i++){
      for(int j=1; j<M; j++){
        d[i][j] += (maze[i][j] + Math.max(d[i-1][j-1], Math.max(d[i-1][j], d[i][j-1])));
      }
    }

    System.out.println(d[N-1][M-1]);
  }
}