/**
 * 22-04-12
 * BOJ 1092 배
 * 그리디
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    ArrayList<Integer> crane = new ArrayList<>();

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      crane.add(Integer.parseInt(st.nextToken()));
    }

    int M = Integer.parseInt(br.readLine());
    ArrayList<Integer> box = new ArrayList<>();

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < M; i++){
      box.add(Integer.parseInt(st.nextToken()));
    }

    Collections.sort(crane, Collections.reverseOrder());
    Collections.sort(box, Collections.reverseOrder());

    int ans = 0;
    if(crane.get(0) < box.get(0)){
      ans = -1;
    }
    else{
      while(!box.isEmpty()){
        int idx = 0;

        for(int i=0; i<crane.size();){
          if(idx == box.size()){
            break;
          }
          else if (crane.get(i) >= box.get(idx)) {
            box.remove(idx);
            i++;
          }
          else {
            idx++;
          }
        }

        ans++;
      }
    }

    System.out.println(ans);
  }
}