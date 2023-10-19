import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    char[][][] arr = new char[N][5][7];

    for(int k=0; k<N; k++){
      for(int i=0; i<5; i++){
        String s = br.readLine();
        for(int j=0; j<7; j++){
          arr[k][i][j] = s.charAt(j);
        }
      }
    }

    int mn = 36;
    int[] ans = new int[2];

    for(int k=0; k<N-1; k++){
      for(int kk=k+1; kk<N; kk++){
        int cnt = 0;

        for(int i=0; i<5; i++){
          for(int j=0; j<7; j++){
            if(arr[k][i][j] != arr[kk][i][j]) cnt++;
          }
        }

        if(mn > cnt){
          mn = cnt;
          ans[0] = k + 1;
          ans[1] = kk + 1;
        }
      }
    }

    System.out.print(ans[0] + " " + ans[1]);
  }
}
