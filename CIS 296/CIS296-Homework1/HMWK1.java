/*
    Name: Srinivas Simhan
    Due: 9/23/18
    Class: CIS 296 - Baugh
    Assignment: Homework #1
*/

package test.pkg1;
/*
    A pentagonal number is defined as n(3n-1)/2
    for n=1,2,..., and so on. Therefore, the first
    few numbers are 1, 5, 12, 22, ... .

    Written is a method with the following 
    header that returns a pentagonal number:
    public static int getPentagonalNumber(int n)
    Here is a test program that uses this method
    to display the first 100 pentagonal numbers 
    with 10 numbers on each line.
*/

public class Test1
{
    public static int getPentagonalNumber(int n)
    {
        return (n * (3 * n - 1)) / 2;
    }
    
    public static void main(String[] args)
    {
        System.out.println("The first 100 pentagonal number are:");
        for (int i = 1; i < 101; i++)
        {
            System.out.printf("%7d ", getPentagonalNumber(i));
            if (i % 10 == 0)
            {
                System.out.println();
            }
        }
        System.out.println("Thank you for trying out the program!");   
    }  
}
