/**
 * 23-03-02
 * BOJ 1652 누울 자리를 찾아라
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    char[][] map = new char[N][N];

    for(int i=0; i<N; i++){
      String s = br.readLine();
      for(int j=0; j<N; j++){
        map[i][j] = s.charAt(j);
      }
    }

    int ans = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N - 1; j++){
        if(j < N - 2){
          if(map[i][j] == '.' && map[i][j+1] == '.' && map[i][j+2] == 'X'){
            ans++;
          }
        }
        else if(j == N - 2){
          if(map[i][j] == '.' && map[i][j+1] == '.'){
            ans++;
          }
        }
      }
    }
    System.out.print(ans + " ");

    ans = 0;
    for(int j=0; j<N; j++){
      for(int i=0; i<N - 1; i++){
        if(i < N - 2){
          if(map[i][j] == '.' && map[i+1][j] == '.' && map[i+2][j] == 'X'){
            ans++;
          }
        }
        else if(i == N - 2){
          if(map[i][j] == '.' && map[i+1][j] == '.'){
            ans++;
          }
        }
      }
    }

    System.out.print(ans);
  }
}
