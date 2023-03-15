/**
 * 23-03-15
 * BOJ 20291 파일 정리
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    HashMap<String, Integer> hm = new HashMap<>();

    for(int i=0; i<N; i++){
      String s = br.readLine();
      StringTokenizer st = new StringTokenizer(s, ".");
      String s1 = st.nextToken();
      String s2 = st.nextToken();

      if(!hm.containsKey(s2)){
        hm.put(s2, 1);
      }
      else{
        hm.replace(s2, hm.get(s2)+1);
      }
    }

    List<String> li = new ArrayList<>(hm.keySet());

    Collections.sort(li);

    for(String s : li){
      System.out.println(s + " " + hm.get(s));
    }
  }
}
