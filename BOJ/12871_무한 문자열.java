/**
 * 23-06-21
 * BOJ 12871 무한 문자열
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ㄴ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s1 = br.readLine();
    String s2 = br.readLine();

    int ans = 0;

    String tmp1 = "";
    String tmp2 = "";

    for(int i=0; i<s2.length(); i++){
      tmp1 += s1;
    }
    for(int i=0; i<s1.length(); i++){
      tmp2 += s2;
    }
    if(tmp1.equals(tmp2)) ans = 1;
    System.out.println(tmp1);
    System.out.println(tmp2);

    System.out.println(ans);
  }
}
