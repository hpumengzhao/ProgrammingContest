import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a,b;
        Scanner sc = new Scanner(System.in);
        a=sc.nextInt();
        b=sc.nextInt();
        System.out.println(check(a,b)?"Yes":"No");
    }
    public static Boolean  check(int a,int b){
        return b>=a&&b<=6*a;
    }
}
