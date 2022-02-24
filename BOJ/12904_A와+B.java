/**
 * 22-02-24
 * BOJ 12904 A와 B
 * 문자열
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringBuilder S = new StringBuilder(br.readLine());
    StringBuilder T = new StringBuilder(br.readLine());

    int sLen = S.length();
    int tLen = T.length();

    while(sLen < tLen){
      if(T.charAt(tLen - 1) == 'A'){
        T.deleteCharAt(tLen-1);
      }
      else{
        T.deleteCharAt(tLen-1);
        T.reverse();
      }
      tLen--;
    }

    if(T.toString().equals(S.toString()))
      System.out.println(1);
    else
      System.out.println(0);
  }
}