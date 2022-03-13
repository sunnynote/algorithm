import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test2 {
  static int N;
  static int d, k, c;
  static int[] arr;
  static int[] chk;
  static int ans, mx;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    d = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());
    arr = new int[N+k-1];
    chk = new int[N+k-1];
    ans = 0;
    mx = 0;

    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(br.readLine());
    }

    int cnt = 0;
    for(int i=N; i<N+k-1; i++){
      arr[i] = arr[cnt++];
    }

    solve();

    System.out.println(ans);
  }

  static void solve(){
    for(int i=0; i<k; i++){
      if(chk[arr[i]]==0) mx++;
      chk[arr[i]]++;
    }

    for(int i=1; i<N+k-1; i++){


      chk[arr[i-1]]--;

      chk[arr[i]]++;
    }
  }
}