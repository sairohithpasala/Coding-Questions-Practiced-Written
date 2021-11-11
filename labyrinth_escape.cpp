
// https://www.chegg.com/homework-help/questions-and-answers/re-exploring-mysterious-labyrinth-shape-rectangular-matrix-containing-obstacles-teleports--q55542980




#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,m;
   n=10, m=20;
   vector< pair <int,int> > vect;
//lets input coordinates of obstacles first
// initialising 1st and 2nd element of
// pairs with array values
int arr[] = {0, 3, 4, 7 }; //x coordinates of obstacles
int arr1[] = {2, 4, 2, 6}; // y coordinates of obstacles
int x = sizeof(arr)/sizeof(arr[0]);
  
// Entering values in vector of pairs
for (int i=0; i<x; i++)
vect.push_back( make_pair(arr[i],arr1[i]) );
  
  
// lets input coordinates of teleports now, firstly initial position
vector< pair <int,int> > v;
  
// initialising 1st and 2nd element of
// pairs with array values
int arr2[] = {1, 2, 5, 4 };
int arr3[] = {3, 6, 2, 5};
int y = sizeof(arr)/sizeof(arr[0]);
  
// Entering values in vector of pairs
for (int i=0; i<y; i++) {
v.push_back( make_pair(arr2[i],arr3[i]) );
}
  
//lets input coordinates of final position of teleports
vector< pair <int,int> > vec;
  
// initialising 1st and 2nd element of
// pairs with array values
int arr4[] = {0, 0, 5, 0 };
int arr5[] = {3, 6, 0, 5};
int z = sizeof(arr)/sizeof(arr[0]);
  
// Entering values in vector of pairs
for (int i=0; i<z; i++) {
vec.push_back( make_pair(arr4[i],arr5[i]) );
}
  
int a[n][m]={0}; //creating a n*m labyrinth
int flag=0;
int k=0; //for moving through obstacles
int l=0; //for moving through teleports
for(int i=0;i<n;i++){
for(int j=1;j<m;j++){
if(i!=vect[k].first && j!=vect[k].second){
k++;
continue; // if there are no obstacles we move to next right cell
}else if(i==v[l].first && j==v[l].second){
i=vec[l].first;
j=vec[l].second;
l++;
}else{
flag=1; //means we met an obstacle.
break; //we break outta the loop
}
  
}
if(flag==1)break; //to break outta the outer loop;
}
if(flag==0){
cout<<"true"<<endl; //no obstacles found and we exit the labyrinth
}else{
cout<<"false"<<endl; // means flag=1 and we met an obstacle
}
  
return 0;
}


