import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-->0){
            int n = sc.nextInt();
            if(n%3==0){
                System.out.println(n/3+" "+n/3);
            }
            if(n%3==1){
                System.out.println((n/3+1)+" "+n/3);
            }
            if(n%3==2){
                System.out.println(n/3+" "+(n/3+1));
            }
        }
    }
}
