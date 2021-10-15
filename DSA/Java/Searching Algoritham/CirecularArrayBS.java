package com.jay.leetCode.medium;

public class CirecularArrayBS {
	public static void main(String[] args) {
		
		int[] arr= {4,5,6,7,0,1,2};
		int tar = 6;
		
		System.out.println(findPivot(arr));
		System.out.println(serch(arr, tar));
		
	}
	
	static int serch(int arr[], int tar) {
		int pivot = findPivot(arr);
		
		if (pivot == -1) {
			System.out.println(SimpleBinary(arr, tar, 0, arr.length-1));
		}
		
		if(pivot == tar) {
			return pivot;
		}
		
		if(tar >= arr[0]) {
			return SimpleBinary(arr, tar, 0, pivot-1);
		}
		return SimpleBinary(arr, tar, pivot+1, arr.length-1);

	}
	
	
//	finding Pivot element
	static int findPivot(int[] arr) {
		int start = 0;
		int end = arr.length-1;
		while(start<=end) {
			int mid = (start+end)/2;
			
			if (mid < end && arr[mid] > arr[mid+1]) {
				return mid;
			}
			if (mid > start && arr[mid] < arr[mid-1]) {
				return mid-1;
			}
			
			if(arr[mid] <= arr[start]) {
				end = mid-1;
			}else {
				start = mid+1;
			}
		}
		return -1;
	}
	
//	Finding Binary search
	static int SimpleBinary(int arr[], int tar, int start, int end){
		
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
