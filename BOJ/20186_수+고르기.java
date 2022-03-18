/**
 * 22-03-18
 * BOJ 20186 수 고르기
 * 정렬
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class test2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());

    int[] arr = new int[N];
    boolean[] chk = new boolean[N];

    st = new StringTokenizer(br.readLine());

    ArrayList<Info> list = new ArrayList<>();

    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(st.nextToken());
      list.add(new Info(arr[i], i));
    }

    Collections.sort(list, new Comparator<Info>() {
      @Override
      public int compare(Info o1, Info o2) {
        if(o1.val == o2.val){
          return o1.idx - o2.idx;
        }
        return o2.val - o1.val;
      }
    });

    for(int i=0; i<K; i++){
      chk[list.get(i).idx] = true;
    }

    int cnt = 0, ans = 0;
    for(int i=0; i<N; i++){
      if(chk[i]){
        ans += (arr[i] - cnt);
        cnt++;
      }
    }

    System.out.println(ans);
  }
}

class Info{
  int val, idx;
  Info(int val, int idx){
    this.val = val;
    this.idx = idx;
  }
}