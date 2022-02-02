/**
 * 22-02-02
 * BOJ 11656 접미사 배열
 * 정렬
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class test{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        String[] arr = new String[str.length()];

        String cp = str;
        for(int i=0; i<str.length(); i++)
            arr[i] = cp.substring(i);

        Arrays.sort(arr);

        for(int i=0; i<str.length(); i++){
            System.out.println(arr[i]);
        }
    }
}