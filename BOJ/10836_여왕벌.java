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
  static int[][] tmp;

  static int[] dx = {0,-1,-1};
  static int[] dy = {-1,-1,0};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    M = Integer.parseInt(st.nextToken());
    N = Integer.parseInt(st.nextToken());

    arr = new int[M][M];
    val = new int[M*2];

    for(int i=0; i<M; i++)
      for(int j=0; j<M; j++)
        arr[i][j] = 1;

    for(int k=0; k<N; k++){
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());
      int c = Integer.parseInt(st.nextToken());

      fill_size(a, b, c);
      calc();
    }

    for(int i=0; i<M; i++){
      for(int j=0; j<M; j++){
        System.out.print(arr[i][j] + " ");
      }
      System.out.println();
    }
  }

  static void fill_size(int a, int b, int c){
    int idx = 0;
    for(int i=0; i<a; i++)
      val[idx++] = 0;
    for(int j=0; j<b; j++)
      val[idx++] = 1;
    for(int i=0; i<c; i++)
      val[idx++] = 2;


    tmp = new int[M][M];
    int cnt = 0;

    // 세로 채우기
    for(int i=M-1; i>=0; i--)
      tmp[i][0] = val[cnt++];

    // 가로 채우기
    for(int j=1; j<M; j++)
      tmp[0][j] = val[cnt++];
  }

  static void calc(){
    for(int i=M-1; i>=0; i--){
      arr[i][0] += tmp[i][0];
    }
    for(int j=1; j<M; j++){
      arr[0][j] += tmp[0][j];
    }

    for(int i=1; i<M; i++){
      for(int j=1; j<M; j++){

        int mx = -1;
        for(int k=0; k<3; k++){
          int nx = i + dx[k];
          int ny = j + dy[k];
          if(mx < arr[nx][ny])
            mx = arr[nx][ny];
        }

        arr[i][j] = mx;
      }
    }

  }
}