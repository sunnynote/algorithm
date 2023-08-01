/**
 * 23-08-01
 * BOJ 7785 회사에 있는 사람
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class ds {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    HashSet<String> hs = new HashSet<>();
    HashMap<String, String> hm = new HashMap<>();

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());
      String s1 = st.nextToken();
      String s2 = st.nextToken();

      if(!hm.containsKey(s1)){
        hm.put(s1, s2);
      }
      else{
        hm.remove(s1);
      }
    }

    ArrayList<String> li = new ArrayList<>(hm.keySet());

    Collections.sort(li, Collections.reverseOrder());

    for(String i : li){
      System.out.println(i);
    }
  }
}
