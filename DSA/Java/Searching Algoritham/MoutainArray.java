package com.jay.practice;

public class MoutainArray {
	public static void main(String[] args) {
		int arr[]= {1,3,5,6,4,2,1};
		System.out.println(peakIndexInMountaineArray(arr));
		
	}
	
	static int peakIndexInMountaineArray(int arr[]) {
		int start =0;
		int end = arr.length-1;
		
		while(start <= end) {
			int mid = (start+end)/2;
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
