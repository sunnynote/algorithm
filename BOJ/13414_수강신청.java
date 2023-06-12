/**
 * 23-06-12
 * BOJ 13414 수강신청
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int K = Integer.parseInt(st.nextToken());
    int L = Integer.parseInt(st.nextToken());

    Map<String, Integer> hm = new HashMap<>();
    int idx = 0;

    for(int i=0; i<L; i++){
      String s = br.readLine();

      hm.put(s, idx++);
    }

    List<String> keySet = new ArrayList<>(hm.keySet());

    keySet.sort(new Comparator<String>() {
      @Override
      public int compare(String o1, String o2) {
        return hm.get(o1).compareTo(hm.get(o2));
      }
    });

    int cnt = 0;

    for(String key : keySet){
      if(cnt >= K) break;

      System.out.println(key);
      cnt++;
    }
  }
}
