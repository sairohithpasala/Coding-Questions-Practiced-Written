//Inversions A subsequence is created by deleting zero or more elements from a list while
// maintaining the order. For example, the subsequences of [1,2,3] are
//[U. [2]. [3] [1,2],[1.3] [2,3]. [1,2,3]. An inversion is a strictly decreasing subsequence
//of length 3.More formally, given an.....

//  https://www.chegg.com/homework-help/questions-and-answers/2-inversions-subsequence-created-deleting-zero-elements-list-maintaining-order-example-sub-q73192845

#include<iostream>
using namespace std ;
  
int   maxInversion(int array[], int n) {
   int cntInv = 0 ;
   int ele = 0 ;
   int subs[3] ;
  
   int fixed1 ;
   int fixed2 ;
   for(int i = 0; i < n-1; ++i) {
       fixed1 = i ;
       subs[ele] = array[fixed1] ;
       for(int j = i+1; j < n-1; ++j) {
           if(array[fixed1] > array[j]) {
               fixed2 = j ;
               subs[++ele] = array[fixed2] ;
               for(int k = fixed2; k < n-1; ++k) {
                   if(array[fixed2] > array[k+1])
                       subs[++ele] = array[k+1] ;
                   if(ele == 2) {
                       cout << "\n[ " ;
                       for(int index = 0; index < 3; ++index) cout << subs[index] << " " ;
                       cout << "]" ;
                       cntInv++ ;
                       --ele ;
                   }
               }
               --ele ;
           }
       }
   }
   return cntInv ;
}

int main() {
   int size ;
   cout << "Enter the size of array : " ;    cin >> size ;
  
   int array[size] = {0} ;
  
   cout << "Enter the elements of array : " ;
   for(int i = 0; i < size; ++i) cin >> array[i] ;
  
   cout << "\nNumber of inversion : " << maxInversion(array, size) ;
   return 0 ;
}