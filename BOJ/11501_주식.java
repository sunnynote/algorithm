/**
 * 23-05-15
 * BOJ 11501 주식
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int T = Integer.parseInt(st.nextToken());

    for(int t=1; t<=T; t++){
      int N = Integer.parseInt(br.readLine());
      int[] arr = new int[N];

      st = new StringTokenizer(br.readLine());

      for(int i=0; i<N; i++){
        arr[i] = Integer.parseInt(st.nextToken());
      } // input end

      long ans = 0;
      int mx = -1;

      for(int i=N-1; i>=0; i--){
        if(arr[i] < mx){
          ans += (mx - arr[i]);
        }
        else{
          mx = arr[i];
        }
      }

      System.out.println(ans);
    }
  }
}