import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> fac = new ArrayList<Integer>();
        for(int i=0;i<=10;i++){
            int ans=1;
            for(int j=1;j<=i;j++){
                ans*=j;
            }
            fac.add(ans);
        }
        int ans=0;
        int p = sc.nextInt();
        for(int i=10;i>=0;i--){
            while(p>=fac.get(i)){
                p-=fac.get(i);
//                System.out.println(i);
                ans++;
            }
        }
        System.out.println(ans);
    }
}
