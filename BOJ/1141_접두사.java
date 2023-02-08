/**
 * 23-02-08
 * BOJ 1141 접두사
 */

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    ArrayList<String> str = new ArrayList<>();

    for(int i = 0; i < N; i++){
      String s = br.readLine();
      str.add(s);
    }

    Collections.sort(str, new Comparator<String>() {
      @Override
      public int compare(String o1, String o2) {
        return Integer.compare(o2.length(), o1.length());
      }
    });

    HashSet<String> hs = new HashSet<>();

    for(String s : str){
      if(hs.size() == 0){
        hs.add(s);
        continue;
      }

      boolean f = true;
      for(String list : hs){
        if(list.startsWith(s)){
          f = false;
          break;
        }
      }

      if(f) hs.add(s);
    }

    System.out.println(hs.size());
  }
}
