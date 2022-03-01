/**
 * 22-03-01
 * BOJ 10836 여왕벌
 * 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test {
  static int N, M;
  static int[][] arr;
  static int[] val;
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    M = Integer.parseInt(st.nextToken());
    N = Integer.parseInt(st.nextToken());

    arr = new int[M][M];
    val = new int[M*2];

    for(int k=0; k<N; k++){
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      int c = Integer.parseInt(st.nextToken());
      val[a]++;
      val[b+a]++;
    }

    int cnt = 0;
    int sum = 0;

    // 세로 채우기
    for(int i=M-1; i>=0; i--) {
      sum += val[cnt++];
      arr[i][0] = sum;
    }

    // 가로 채우기
    for(int j=1; j<M; j++) {
      sum += val[cnt++];
      arr[0][j] = sum;
    }

    for(int i=1; i<M; i++)
      for(int j=1; j<M; j++)
        arr[i][j] = arr[0][j];

    for(int i=0; i<M; i++){
      for(int j=0; j<M; j++){
        System.out.print(arr[i][j] + 1 + " ");
      }
      System.out.println();
    }
  }
}