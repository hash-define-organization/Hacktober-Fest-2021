package com.jay.practice;

public class orderAgnostic {
	public static void main(String[] args) {
		
	
		// TODO Auto-generated method stub
		int arr[] = {12,11,9,8,7,6,5,4,3,2,1};
		int target = 12;
		System.out.println(orderAgnosticBS(arr, target));

	}
	
	static int orderAgnosticBS(int arr[], int tar) {
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
