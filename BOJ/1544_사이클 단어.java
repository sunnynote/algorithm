/**
 * 23-09-27
 * BOJ 1544 
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    HashSet<String > hs = new HashSet<>();

    for(int i=0; i<N; i++){
      String s = br.readLine();

      if(hs.isEmpty()) hs.add(s);
      else{
        boolean f = false;

        String ss = s + s;

        String tmp = "";

        for(int j=0; j<s.length(); j++){
          tmp = "";
          for(int k=j; k<j + s.length(); k++){
            tmp += ss.charAt(k);
          }

          if(hs.contains(tmp)) {
            f = true;
            break;
          }
        }

        if(!f) hs.add(tmp);
      }
    }

    System.out.print(hs.size());

  }
}
