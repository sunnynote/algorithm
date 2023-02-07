/**
 * 23-02-07
 * BOJ 2910 빈도 정렬
 */

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int C = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());

    HashMap<Integer, Integer> list = new LinkedHashMap<>();

    for(int i=0; i<N; i++){
      int cur = Integer.parseInt(st.nextToken());

      if(list.containsKey(cur)){
        list.replace(cur, list.get(cur) + 1);
      }
      else{
        list.put(cur, 1);
      }
    }

    ArrayList<Integer> arr = new ArrayList<>(list.keySet());

    Collections.sort(arr, new Comparator<Integer>() {
      @Override
      public int compare(Integer o1, Integer o2) {
        return list.get(o2) - list.get(o1);
      }
    });

    for(Integer val : arr){
      for(int i=0; i<list.get(val); i++){
        System.out.print(val + " ");
      }
    }
  }
}
