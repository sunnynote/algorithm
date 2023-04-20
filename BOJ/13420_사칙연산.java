import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ㄴd {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());

    for(int i=1; i<=N; i++){
      st = new StringTokenizer(br.readLine());

      long val1 = Long.parseLong(st.nextToken());
      String ch = st.nextToken();
      long val2 = Long.parseLong(st.nextToken());
      String tmp = st.nextToken();
      long ans = Long.parseLong(st.nextToken());

      long res = -1;

      if(ch.equals("+")){
        res = val1 + val2;
      }
      else if(ch.equals("-")){
        res = val1 - val2;
      }
      else if(ch.equals("*")){
        res = val1 * val2;
      }
      else{
        res = val1 / val2;
      }

      if(res == ans){
        System.out.println("correct");
      }
      else{
        System.out.println("wrong answer");
      }
    }

  }
}
