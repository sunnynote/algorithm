/**
 * 23-10-02
 * BOJ 1251 단어 나누기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;

public class ㅇㄴ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String S = br.readLine();

    int len = S.length();
    LinkedList<String> li = new LinkedList<>();

    for(int i=1; i<len-1; i++){
      for(int j=i+1; j<len; j++){
        StringBuilder sb1 = new StringBuilder(S.substring(0, i)).reverse();
        StringBuilder sb2 = new StringBuilder(S.substring(i, j)).reverse();
        StringBuilder sb3 = new StringBuilder(S.substring(j, len)).reverse();
        String res = sb1.toString() + sb2.toString() + sb3.toString();
        li.add(res);
      }
    }

    Collections.sort(li);
    System.out.print(li.get(0));
  }
}
