package com.jay.practice;

public class BinarySearch {
	public static void main(String[] args) {
		int arr[] = {2,4,6,8,9,11, 12, 14, 20,36,48};
		int target = 12;
		System.out.println(SimpleBinary(arr, target));
	}
	
	static int SimpleBinary(int arr[], int tar){
		
		int start =0;
		int end = arr.length-1;
		
		while(start <= end) {
			int mid = (start+end)/2;
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
