import java.util.*;

 class Dcoder
 {
   public static void main(String args[])
   { 
     Scanner in = new Scanner(System.in);
     System.out.println("ENTER SIZE:");
    int size=in.nextInt();
    System.out.println("Elements of Array:");
    int[] arr= new int[size];
    for(int i=0;i<size;i++){
      arr[i]=in.nextInt();
    }
    System.out.println("ENTER TARGET;");
    int tar=in.nextInt();
 
    System.out.println("INDEX OF TARGET IS:"+binarySearch(arr, tar, 0, arr.length-1));
   }
   static int binarySearch(int[] arr, int tar, int st, int end){
    
    if(st>end){
      return -1;
    }
     int mid= st+(end-st)/2;
     
     if(tar==arr[mid]){
       return mid;
     }
     if(tar<arr[mid]){
       return binarySearch(arr, tar, st, mid-1);
     }
     else{
      return binarySearch(arr, tar, mid+1,end);
     }
     
   }
 }
