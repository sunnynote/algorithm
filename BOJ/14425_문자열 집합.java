import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int ans = 0;

    String[] arr = new String[N];

    for(int i = 0; i < N; i++){
      arr[i] = br.readLine();
    }

    for(int i = 0; i < M; i++){
      String cur = br.readLine();
      for(int j = 0; j < N; j++){
        if(arr[j].equals(cur)) ans++;
      }
    }

    System.out.print(ans);
  }
}
