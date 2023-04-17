import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());

    for(int i=1; i<=N; i++) {
      String s = br.readLine();

      st = new StringTokenizer(s);
      Stack<String> stk = new Stack<>();

      while(st.hasMoreTokens()){
        stk.add(st.nextToken());
      }

      System.out.print("Case #" + i + ":");

      while(!stk.empty()){
        System.out.print(" " + stk.pop());
      }

      System.out.println();
    }
  }
}
