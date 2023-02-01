/**
 * 23-02-01
 * BOJ 11478
 */

import java.io.*;
import java.util.HashSet;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine();

    HashSet<String> hs = new HashSet<>();

    for(int i=0; i<s.length(); i++){
      for(int j=i; j<s.length(); j++){
        String cur = s.substring(i, j + 1);

        if(!hs.contains(cur)) hs.add(cur);
      }
    }

    System.out.println(hs.size());
  }
}
