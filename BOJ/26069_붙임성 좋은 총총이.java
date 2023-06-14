import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    boolean f = false;
    String[][] arr = new String[N][2];

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());

      String s1 = st.nextToken();
      String s2 = st.nextToken();

      arr[i][0] = s1;
      arr[i][1] = s2;
    }
    HashSet<String> hs = new HashSet<>();

    for(int i=0; i<N; i++){

      if(arr[i][0].equals("ChongChong") || arr[i][1].equals("ChongChong")){
        f = true;
        hs.add("ChongChong");
      }

      if(!f) continue;

      if(hs.contains(arr[i][0]) || hs.contains(arr[i][1])){
        hs.add(arr[i][1]);
        hs.add(arr[i][2]);
      }
    }

    System.out.println(hs.size());
  }
}
