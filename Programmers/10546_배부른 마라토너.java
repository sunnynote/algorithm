/**
 * 23-08-11
 * BOJ 10546 배부른 마라토너
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    HashMap<String, Integer> hm = new HashMap<>();

    for(int i=0; i<N; i++){
      String s = br.readLine();

      if(!hm.containsKey(s)) hm.put(s, 1);
      else hm.replace(s, hm.get(s) + 1);
    }

    for(int i=0; i<N-1; i++){
      String s = br.readLine();

      hm.replace(s, hm.get(s) - 1);
    }

    for(String s : hm.keySet()){
      if(hm.get(s) == 1) System.out.println(s);
    }
  }
}
