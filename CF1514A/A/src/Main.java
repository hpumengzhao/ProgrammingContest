import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int[] pos = new int[n+1];
            for(int i=1;i<=n;i++) pos[i]=i;
            if(n%2==0){
                for(int i=1;i<=n;i+=2){
                    int tmp=pos[i];
                    pos[i]=pos[i+1];
                    pos[i+1]=tmp;
                }
            }else {
                for(int i=1;i<=n-1;i+=2){
                    int tmp=pos[i];
                    pos[i]=pos[i+1];
                    pos[i+1]=tmp;
                }
                int tmp=pos[n];
                pos[n]=pos[n-1];
                pos[n-1]=tmp;
            }
            for(int i=1;i<=n;i++){
                System.out.print(pos[i]+" ");
            }
            System.out.println("");
        }
    }
}
