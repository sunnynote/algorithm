/**
 * 2021-12-09
 * BOJ 14468 소가 길을 건너간 이유 2
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p14468 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        int[] pos1 = new int[26]; // 시작점
        int[] pos2 = new int[26]; // 끝점
        int ans = 0;

        for(int i=0; i<str.length(); i++){
            int idx = str.charAt(i) - 'A';

            if(pos1[idx]==0) pos1[idx] = i+1;
            else pos2[idx] = i+1;
        }

        for(int i=0; i<26; i++)
            for(int j=0; j<26; j++)
                if(pos1[i]<pos1[j] && pos1[j]<pos2[i] && pos2[i]<pos2[j]) ans++;

        System.out.println(ans);
    }
}