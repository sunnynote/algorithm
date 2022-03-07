/**
 * 22-03-07
 * BOJ 7682 틱택토
 * 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test {
  static final int N = 3;
  static char[][] map;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    while(true){
      String str = br.readLine();
      if(str.equals("end")) break;

      map = new char[N][N];

      int cnt = 0;
      int x_cnt = 0, o_cnt = 0;

      for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
          map[i][j] = str.charAt(cnt++);

          if(map[i][j]=='X') x_cnt++;
          else if(map[i][j]=='O') o_cnt++;
        }
      }

      boolean f = false;

      boolean x_f = chk('X');
      boolean o_f = chk('O');

      if(x_cnt==o_cnt || x_cnt-1==o_cnt) {
        if (x_cnt + o_cnt == 9 && !o_f) {
            f = true;
        } else {
          if (x_cnt > o_cnt && x_f && !o_f) {
            f = true;
          } else if(x_cnt==o_cnt && !x_f && o_f) {
            f = true;
          }
        }
      }

      if(f) sb.append("valid").append("\n");
      else sb.append("invalid").append("\n");
    }
    System.out.print(sb);
  }

  static boolean chk(char c){
    boolean f = false;
    if(map[0][0]==c && map[0][0]==map[1][1] && map[1][1]==map[2][2])
      f = true;
    else if(map[0][2]==c && map[0][2]==map[1][1] && map[1][1]==map[2][0])
      f = true;
    else if(map[0][0]==c && map[0][0]==map[0][1] && map[0][1]==map[0][2])
      f = true;
    else if(map[1][0]==c && map[1][0]==map[1][1] && map[1][1]==map[1][2])
      f = true;
    else if(map[2][0]==c && map[2][0]==map[2][1] && map[2][1]==map[2][2])
      f = true;
    else if(map[0][0]==c && map[0][0]==map[1][0] && map[1][0]==map[2][0])
      f = true;
    else if(map[0][1]==c && map[0][1]==map[1][1] && map[1][1]==map[2][1])
      f = true;
    else if(map[0][2]==c && map[0][2]==map[1][2] && map[1][2]==map[2][2])
      f = true;

    return f;
  }
}