import java.io.*;
import java.util.StringTokenizer;

public class ds {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long N = Long.parseLong(st.nextToken());
    long R = Long.parseLong(st.nextToken());

    long ans = ;
    System.out.print(R * 2 + N - 1);
  }
}
