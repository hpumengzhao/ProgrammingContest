import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        long  k=sc.nextLong();
        Map<Integer,Integer> id = new HashMap<Integer,Integer>();
        int[] a=new int[n];
        long[] ans=new long[n];
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
            id.put(a[i],i);
        }
        Arrays.sort(a);
        for(int i=0;i<n;i++){
            ans[i]=k/n;
        }
        for(int i=0;i<k%n;i++){
            ans[id.get(a[i])]++;
        }
        for(int i=0;i<n;i++){
            System.out.println(ans[i]);
        }
    }
}
