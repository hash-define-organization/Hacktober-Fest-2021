import java.util.*;


 class Dcoder
 {
   public static void main(String args[])
   { 
    Scanner in = new Scanner(System.in);

    System.out.println("Enter the Size:");
    int size= in.nextInt();

    System.out.println("Elements of array:");
    int[] arr = new int[size];
    for(int i=0;i<size;i++){
     arr[i]=in.nextInt();
   }
   System.out.println("Target;");
   int target= in.nextInt();
   System.out.println("Index of target is:"+binarySearch(arr, target));
   }
   static int binarySearch(int[] arr,int target){
   int start = 0;
  int end=arr.length-1;
   int mid= start+(end-start)/2;
   while(start <= end){
     if(target<arr[mid]){
       end=mid-1;
     }
     else if(target>arr[mid]){
       start= mid+1;
     }
     else{
       return mid;
     }}
     return -1;
    }}
 
