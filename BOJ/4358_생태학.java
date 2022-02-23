/**
 * 22-02-23
 * BOJ 4358 생태학
 * 문자열
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class test {
  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    HashMap<String, Integer> mp = new HashMap<String, Integer>();
    int all = 0;

    while(true){
      String tree = br.readLine();
      if(tree==null || tree.length()==0) break;

      all++;

      if(!mp.containsKey(tree)){ // 없으면 삽입
        mp.put(tree, 1);
      }
      else{ // 있으면 카운트++
        mp.put(tree, mp.get(tree)+1);
      }
    }

    // 키 값을 배열로 만들기
    Object[] arr = mp.keySet().toArray();
    Arrays.sort(arr);

    StringBuilder sb = new StringBuilder();
    for(int i=0; i<arr.length; i++){
      double per = ((double)mp.get(arr[i]) / (double)all) * 100;
      sb.append(arr[i] + " " + String.format("%.4f", per) + "\n");
    }

    System.out.println(sb.toString());
  }
}