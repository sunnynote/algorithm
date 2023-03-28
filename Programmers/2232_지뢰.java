import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class sd {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    int[] arr = new int[N+2];

    for(int i=1; i<=N; i++){
      arr[i] = Integer.parseInt(br.readLine());
    } // input end

    arr[0] = 0;
    arr[N+1] = 0;

    for(int i=0; i<N; i++){
      if(arr[i] <= arr[i+1] && arr[i+1] >= arr[i+2]){
        System.out.println(i+1);
      }
    }
  }
}
