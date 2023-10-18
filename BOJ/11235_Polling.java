/**
 * 23-10-18
 * BOJ 11235 Polling
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    HashMap<String, Integer> hm = new HashMap<>();

    int mx = -1;

    for(int i=0; i<N; i++){
      String s = br.readLine();

      if(!hm.containsKey(s)){
        hm.put(s, 1);
      }
      else{
        hm.replace(s, hm.get(s) + 1);
      }
      if(mx < hm.get(s)) mx = hm.get(s);
    }

    ArrayList<String> list = new ArrayList<>();
    for(Map.Entry<String, Integer> entry : hm.entrySet()){
      if(entry.getValue() == mx) list.add(entry.getKey());
    }

    Collections.sort(list);

    for(int i=0; i<list.size(); i++){
      System.out.println(list.get(i));
    }
  }
}
