import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class p1911 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int[][] arr = new int[N][2];
        
        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2){
                if(o1[0]==o2[0]) return Integer.compare(o1[1], o2[1]);
                return Integer.compare(o1[0], o2[0]);
            }            
        });

        int ans = 0; // 필요한 널빤지 갯수
        int loc = 0; // 널빤지 마지막 위치
        for(int i=0; i<N; i++){
            int start = arr[i][0];
            int end = arr[i][1];

            if(start < loc) start = loc;
            if(start > end) continue; // 범위 넘어가면 다음 웅덩이

            int diff = end - start;
            int cnt = diff / L;
            if( diff%L != 0 ) cnt++;

            ans += cnt;
            loc = start + cnt*L;
            System.out.println(ans);
        }
        System.out.println(ans);
    }
}
