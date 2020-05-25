import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void playWithBigInt()
	{
		Scanner sc = new Scanner(System.in);
		
		String s1 = sc.next();
		
		BigInteger b1 = new BigInteger(s1);
		BigInteger b2 = new BigInteger("425234347687347676");

        //add two big integers
		b1 = b1.add(b2);
		System.out.println(b1);

        //multiply two big integers;
        b1 = b1.multiply(b2);
        System.out.println(b1);

        // Set bits count
        System.out.println(b1.bitCount());

        // Total bits count
        System.out.println(b1.bitLength());

        //integer into big integer
        int a, b;
        a = sc.nextInt();
        b = sc.nextInt();
        BigInteger b3, b4;
        b3 = BigInteger.valueOf(a);
        b4 = BigInteger.valueOf(b);
        System.out.println(a);
        System.out.println(b);

        //print their gcd
        System.out.println(b3.gcd(b4));

        //base conversion
        BigInteger b5 = new BigInteger("10010", 2); // indicating no is a base 2;
        System.out.println(b5);

        // power of a number
        // NOTE: power can only be an integer
        System.out.println(b3.pow(2));
	}

	public static void main(String args[])
	{
		playWithBigInt();
	}
}