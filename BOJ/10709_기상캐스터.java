/**
 * 23-10-03
 * BOJ 10709 기상캐스터
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    char[][] arr = new char[N][M];
    int[][] chk = new int[N][M];

    for(int i=0; i<N; i++){
      String s = br.readLine();
      for(int j=0; j<M; j++){
        arr[i][j] = s.charAt(j);

        if(arr[i][j] == 'c') chk[i][j] = 0;
        else chk[i][j] = -1;
      }
    }

    for(int i=0; i<N; i++){
      for(int j=1; j<M; j++){
        if(chk[i][j] == 0) continue;
        if(chk[i][j-1] != -1){
          chk[i][j] = chk[i][j-1] + 1;
        }
      }
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        System.out.print(chk[i][j] +  " ");
      }
      System.out.println();
    }
  }
}
