import java.util.Arrays;
import java.util.Scanner;

public class Solution
{
   public static void main(String[] args) {
   Scanner input = new Scanner(System.in);
  
   //taking input of n
   int num = input.nextInt();
   //creating integer array of num size
   int [] arr = new int[num];
   //taking input elements of array
   for(int i=0; i<num; i++ ) {
arr[i] = input.nextInt();
}
  
/*Algorithm is to maximise sum such that no two elements are adjacent
Iterate through array and two sums are maintained first one includes previous element
second sum does not include previous element
max sum excluding current element will be maximum of inclusive_prev_element and exclusive_prev_elemnt
max sum including current element will be exclusive_prev_elemnt + current element
after iteration is completed, answer is maximum of exclusive_prev_elemnt and inclusive_prev_element*/
int inclusive_prev_element = arr[0];
int exclusive_prev_elemnt = 0;
int temp;
  
for (int i = 1; i < num; i++)
{
if (inclusive_prev_element > exclusive_prev_elemnt) {
temp = inclusive_prev_element;
}
else {
temp = exclusive_prev_elemnt;
}
  
inclusive_prev_element = exclusive_prev_elemnt + arr[i];
exclusive_prev_elemnt = temp;
}
  
if (inclusive_prev_element > exclusive_prev_elemnt) {
System.out.println("\n" + inclusive_prev_element);
}
else {
System.out.println("\n" + exclusive_prev_elemnt);
}

   }
}