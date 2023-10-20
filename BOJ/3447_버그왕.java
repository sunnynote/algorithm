/**
 * 23-10-20
 * BOJ 3447 버그왕
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ㅇㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String s = "";

    String reg = ".*BUG.*";

    while((s = br.readLine()) != null){

      while(s.matches(reg)){
        s = s.replaceAll("BUG", "");
      }

      System.out.println(s);
    }
  }
}
