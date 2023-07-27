/**
 * 23-07-27
 * BOJ
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    for(int i=0; i<N; i++){
      String s = br.readLine();
      System.out.println( (i+1) + ". " + s);
    }
  }
}
