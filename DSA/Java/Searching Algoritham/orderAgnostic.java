package com.jay.practice;

public class orderAgnostic {
	//Finding the Order of then array and ten after find Target Element
	public static void main(String[] args) {
		
		int arr[] = {12,11,9,8,7,6,5,4,3,2,1}; // Sorted Array
		int target = 12;// Target Element
		System.out.println(orderAgnosticBS(arr, target));

	}
	
	//Created Function for finding orer of array
	static int orderAgnosticBS(int arr[], int tar) {
		// Required Start Posinter And Ending Pointer
		int start = 0;
		int end = arr.length-1;
		
//		check wether Asseding or descending
		boolean isAsc;
		if(arr[start] < arr[end]) {
			isAsc = true;
		}else {
			isAsc = false;
		}
		
		while(start <= end) {
//			find mid and target same or not
			int mid = (start+end)/2;
			if (arr[mid] == tar) {
				return mid;
			}
			if(isAsc) {
				if (arr[mid] > tar) {
					end = mid-1;
				}else {
					start =mid+1;
				}
			}else {
				if (arr[mid] < tar) {
					end = mid-1;
				}else {
					start =mid+1;
				}
			}
		}	
		
		return -1;
	}
}
