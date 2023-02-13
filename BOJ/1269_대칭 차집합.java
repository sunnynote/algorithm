/**
 * 23-02-13
 * BOJ 1269 대칭 차집합
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int A = Integer.parseInt(st.nextToken());
    int B = Integer.parseInt(st.nextToken());

    HashMap<Integer, Integer> hm = new HashMap<>();

    st = new StringTokenizer(br.readLine());
    for(int i=0; i<A; i++){
      int cur = Integer.parseInt(st.nextToken());
      hm.put(cur, 1);
    }

    st = new StringTokenizer(br.readLine());
    for(int i=0; i<B; i++){
      int cur = Integer.parseInt(st.nextToken());

      if(!hm.containsKey(cur)){ // 없으면
        hm.put(cur, 1);
      }
      else{ // 있으면
        hm.replace(cur, hm.get(cur) + 1);
      }
    }

    int ans = 0;
    for(Integer i : hm.keySet()){
      if(hm.get(i) == 1){
        ans++;
      }
    }

    System.out.print(ans);
  }
}
