import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int n=sc.nextInt();
            int[] pos = new int[2*n+1];
            int[] a = new int[n+1];
            int[] b = new int[n+1];
            for(int i=1;i<=n;i++){
                a[i]=sc.nextInt();
            }

            Arrays.sort(a);
        }
    }
}
