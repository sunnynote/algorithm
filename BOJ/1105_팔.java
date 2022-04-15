/**
 * 22-04-15
 * BOJ 1105 팔
 * 그리디
 */

import java.io.*;
import java.util.*;

public class test2 {
  static String N, L;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = st.nextToken();
    L = st.nextToken();

    int ans = 0;
    if(N.length() == L.length()){
      for(int i=0; i<L.length(); i++){
        if(N.charAt(i) != L.charAt(i)){
          break;
        }
        if(N.charAt(i) == L.charAt(i) && L.charAt(i) == '8'){
          ans++;
        }
      }
    }

    System.out.println(ans);
  }
}