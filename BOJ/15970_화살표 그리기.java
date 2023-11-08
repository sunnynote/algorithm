/**
 * 23-11-08
 * BOJ 15970 화살표 그리기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int N = Integer.parseInt(br.readLine());

    ArrayList<ArrayList<Integer>> li = new ArrayList<>();

    for(int i=0; i<=N; i++){
      li.add(new ArrayList<>());
    }

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());

      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());

      li.get(y).add(x);
    }

    for(int i=1; i<=N; i++){
      if(li.size() == 0) continue;
      Collections.sort(li.get(i));
    }

    int ans = 0;

    // solve
    for(int i=1; i<=N; i++){
      if(li.size() == 0) continue;

      int sz = li.get(i).size();

      for(int j=0; j<sz; j++){
        if(j == 0){
          ans += (li.get(i).get(1) - li.get(i).get(0));
        }
        else if(j == sz - 1){
          ans += (li.get(i).get(sz-1) - li.get(i).get(sz-2));
        }
        else{
          int l = li.get(i).get(j) - li.get(i).get(j-1);
          int r = li.get(i).get(j+1) - li.get(i).get(j);

          ans += Math.min(l, r);
        }
      }
    }

    System.out.print(ans);
  }
}
