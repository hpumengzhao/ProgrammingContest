import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T=sc.nextInt();
        String s = sc.nextLine();
        while(T-->0){
            s=sc.nextLine();
            int[] cnt = new int[26];
            for(int i=0;i<s.length();i++){
                char c=s.charAt(i);
//                System.out.println((int)(c-'a'));
                cnt[c-'a']++;
            }
            int both=0;
            int sing=0;
            for(int i=0;i<26;i++){
                if(cnt[i]>=2){
                    both++;
                }else if(cnt[i]==1){
                    sing++;
                }
            }
            System.out.println(both+sing/2);
        }
    }
}
