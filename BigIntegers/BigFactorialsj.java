import java.util.Scanner;
import java.math.BigInteger;

public class Main {

    static BigInteger fact(int n)
    {
        BigInteger ans = BigInteger.valueOf(1);

        for(int i = 2; i <= n; i++)
        {
            ans = ans.multiply(BigInteger.valueOf(i));
        }

        return ans;
    }

    public static void main(String args[]) {
        System.out.println("Hello World!");
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        System.out.println(fact(n));
    }
}