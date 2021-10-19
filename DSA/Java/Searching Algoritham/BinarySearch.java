package com.jay.practice;

public class BinarySearch {
	//Simple Binary Serch Program Using you can finding the target Element
	public static void main(String[] args) {
		int arr[] = {2,4,6,8,9,11, 12, 14, 20,36,48}; // Sorted Array
		int target = 12; // Target Element
		System.out.println(SimpleBinary(arr, target));
	}
	
	//Created Function for finding target Element
	static int SimpleBinary(int arr[], int tar){
		
		// Required Start Posinter And Ending Pointer
		int start =0; 
		int end = arr.length-1; 
		
		while(start <= end) { // check if Start and End Pointer is less or equal but not grater
			int mid = (start+end)/2; // if lessthan End then finding the mid pointer of the given Array
			
			//Usingthis if elese statment you can finding the target element graterthan or lessthan or equal to mid?
			// If answer found than return the element position or not found then return the -1
			if (arr[mid] > tar) {   
				end = mid-1;
			}else if (arr[mid] < tar) {
				start =mid+1;
			}else {
				return mid;
			}
		}
		return -1;
	}
}
