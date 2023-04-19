
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());

    for(int t=0; t<T; t++){
      int N = Integer.parseInt(br.readLine());

      if(t != 0) System.out.println();

      if(N == 1){
        System.out.println("#");
        continue;
      }

      for(int i=0; i<N; i++){
        System.out.print("#");
      }
      System.out.println();

      for(int i=0; i<N-2; i++){
        System.out.print("#");
        for(int j=0; j<N-2; j++){
          System.out.print("J");
        }
        System.out.println("#");
      }

      for(int i=0; i<N; i++){
        System.out.print("#");
      }
      System.out.println();
    }
  }
}
