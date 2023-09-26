import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ㄴ {
  static int[] dx = {-1, 0, 1, 0};
  static int[] dy = {0, 1, 0, -1};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    int res = Integer.parseInt(br.readLine());
    int[][] arr = new int[N][N];

    int start = N / 2;
    int d = 0;
    int val = 1;
    int idx = 1;

    arr[start][start] = val++;

    int x = start;
    int y = start;

    while(true){
      if(val > N*N) break;

      for(int i=0; i<2; i++){
        for(int j=0; j<idx; j++) {
          if (val > N*N) break;

          int nx = x + dx[d];
          int ny = y + dy[d];

          arr[nx][ny] = val++;
          x = nx;
          y = ny;
        }

        d = (d + 1) % 4;
      }

      idx++;
    }

    int ans_x = -1;
    int ans_y = -1;

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(arr[i][j] == res){
          ans_x = i;
          ans_y = j;
        }
        sb.append(arr[i][j] + " ");
      }
      sb.append('\n');
    }

    System.out.print(sb);
    System.out.print((ans_x + 1) + " "+ (ans_y + 1));
  }
}
