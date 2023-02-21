import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class sd {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine();
    String ans = "";

    for(int i = 0; i < s.length(); i++){
      if (s.charAt(i) == '.'){
        ans += ".";
        continue;
      }

      boolean type1 = false, type2 = false;

      // case 1
      if(i + 3 < s.length()) {
        int cnt = 0;
        for (int j = i; j < i + 4; j++) {
          if (s.charAt(j) == 'X') cnt++;
        }
        if (cnt == 4) type1 = true;
      }

      // case 2
      if (!type1 && i + 1 < s.length()) {
        int cnt = 0;
        for (int j = i; j < i + 2; j++) {
          if (s.charAt(j) == 'X') cnt++;
        }
        if (cnt == 2) type2 = true;
      }

      if (type1){
        i += 3;
        ans += "AAAA";
      }
      else if (type2){
        i += 1;
        ans += "BB";
      }
      else if (!type1 && !type2){
        ans = "-1";
        break;
      }
    }

    System.out.print(ans);
  }
}
