import java.io.BufferedReader;
import java.io.*;

public class p9251{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String A = br.readLine();
        String B = br.readLine();
        int[][] d = new int[A.length()+1][B.length()+1];

        for(int i=1; i<=A.length(); i++){
            for(int j=1; j<=B.length(); j++){
                if(A.charAt(i-1)==B.charAt(j-1)) d[i][j] = d[i-1][j-1] + 1;
                else d[i][j] = Math.max(d[i-1][j], d[i][j-1]);
            }
        }
        System.out.println(d[A.length()][B.length()]);
    }
}