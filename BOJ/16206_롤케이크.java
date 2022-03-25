/**
 * 22-03-25
 * BOJ 16206 롤케이크
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    int[] arr = new int[N];
    int ans = 0;

    ArrayList<Integer> lst = new ArrayList<>();

    st = new StringTokenizer(br.readLine());
    for(int i=0; i<N; i++){
      arr[i] = Integer.parseInt(st.nextToken());

      if(arr[i]==10){
        ans++;
        arr[i] = 0;
      }
      else if(arr[i] % 10 == 0){
        lst.add(arr[i]);
        arr[i] = 0;
      }
    }

    Collections.sort(lst);

    // 10 단위 먼저
    for(int i=0; i<lst.size(); i++){
      int cur = lst.get(i);

      while(true){
        if(cur == 0 || M == 0){
          break;
        }

        cur -= 10;
        ans++;
        if(cur != 10) M--;
      }
    }

    Arrays.sort(arr);
    for (int i = N-1; i >= 0; i--) {
      int cur = arr[i];

      while(true){
        if(cur < 10 || M == 0){
          break;
        }

        cur -= 10;
        ans++;
        M--;
      }
    }

    System.out.println(ans);
  }
}