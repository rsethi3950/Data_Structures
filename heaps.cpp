#include<iostream>
#include<math.h>
using namespace std;
void max_heapify(int a[],int i, int h){
    int l=2*i+1;
    int r=2*i+2;
   // int heapsize=9;
    int largest=i;
    if(l<h && a[l]>a[i]){
        largest=l;
    }
    if(r<h && a[r]>a[largest]){
        largest=r;
    }
    if(largest != i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        max_heapify(a,largest,h);
    }
}
void build_maxHeap(int a[], int h, int len){
    int n=(len/2)-1;
    cout<<"n is "<<n<<endl;
    for(int i=n; i>=0; i--){
        max_heapify(a,i,h);
    }
}
void heapSort(int a[],int h, int len){
    build_maxHeap(a,h,len);
    for(int i=len-1; i>=1; i--){
        int temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        h--;
        max_heapify(a,0,h);
    }
}
int main(){
//int a[7]={5,9,6,7,1,3,8};
int a[9]={4,5,8,7,1,2,3,6,9};
int heapsize=9;
int length=9;
//build_maxHeap(a,heapsize,length);
//max_heapify(a,0);
heapSort(a,heapsize,length);
for(int i=0; i<9; i++){
    cout<<a[i]<<" ";
}
return 0;
}
