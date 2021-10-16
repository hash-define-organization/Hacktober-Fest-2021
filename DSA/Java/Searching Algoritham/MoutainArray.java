package com.jay.practice;

public class MoutainArray {
	//Peack the largets index value in given array using Binary Serch
	public static void main(String[] args) {
		int arr[]= {1,3,5,6,4,2,1};
		System.out.println(peakIndexInMountaineArray(arr));
		
	}
	//Created Function for finding Largest Element
	static int peakIndexInMountaineArray(int arr[]) {

		// Required Start Posinter And Ending Pointer
		int start =0;
		int end = arr.length-1;
		
		while(start <= end) { // check if Start and End Pointer is less or equal but not grater
			int mid = (start+end)/2; // if lessthan End then finding the mid pointer of the given Array
			
			//Usingthis if elese statment you can finding the Largest element graterthan or lessthan or equal to mid?
			// If answer found than return the element position or not found then return the start value
			if (arr[mid]> arr[mid+1]) {
//				you in decreasing part
				end = mid;
			}else {
//				you in Increasing part
				start = mid+1;
				
			}
		}
		return start; //or else you can return end because both are same
 	}
}
