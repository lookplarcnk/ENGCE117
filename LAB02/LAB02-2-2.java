//Sum of integers 1 to 100;

import java.util.Scanner;

public class Sum1_to_100
{
  public static void main (String [] args)
  {
    int sum = 0;

    for (int i; i<101; i++)
    sum = sum+i;

    System.out.println("Sum is : "+sum);
  }
}