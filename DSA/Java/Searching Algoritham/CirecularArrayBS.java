package com.jay.leetCode.medium;

public class CirecularArrayBS {
	public static void main(String[] args) {
		//Find the target element in Circular Array usng Binary Search

		int[] arr= {4,5,6,7,0,1,2};// Sorted Circular Array
		int tar = 6; // Target elemnt

		//1. Find the Pivot Lelment
		//2. if not found Pivot elemnet then find target using normal Binary Serch
		//3. Let's Get Started
		
		System.out.println(findPivot(arr));
		System.out.println(serch(arr, tar));
		
	}
	
	// now time to check target element
	static int serch(int arr[], int tar) {
		int pivot = findPivot(arr); // first find then pivot elemnet
		
		if (pivot == -1) { //if pivot element return -1 then finding the array in simple Binarry serch and return answer
			System.out.println(SimpleBinary(arr, tar, 0, arr.length-1));
		}
		
		if(pivot == tar) { // if target element double equal to pivot element then return the pivot as answer
			return pivot;
		}
		
		if(tar >= arr[0]) { // if target element grater than arr[0] then array serch in simple binary serch return the answer
			return SimpleBinary(arr, tar, 0, pivot-1);
		}

		return SimpleBinary(arr, tar, pivot+1, arr.length-1);

	}
	
	
	//	finding Pivot element "Pivot element menas Maximum value"
	static int findPivot(int[] arr) {
		int start = 0; // Required two pointer Start and End pointer
		int end = arr.length-1;

		while(start<=end) { // check if Start and End Pointer is less or equal but not grater
			int mid = (start+end)/2; // if lessthan End then finding the mid pointer of the given Array
			

			// Now check tke mid alway leassthan End && Arr[mid] graterthan Arr[mid+1] then return Mid poiter
			// any one condistion is false then check the next conditon 
			if (mid < end && arr[mid] > arr[mid+1]) {
				return mid;
			}

			// Now check tke mid alway graterthan End && Arr[mid] lessthan Arr[mid-1] then return Mid poiter
			// any one condistion is false then check the next conditon
			if (mid > start && arr[mid] < arr[mid-1]) {
				return mid-1;
			}

			
			if(arr[mid] <= arr[start]) {
				end = mid-1;
			}else {
				start = mid+1;
			}
		}

		//if all condition flase then return -1 it menas pivot element not found
		return -1;
	}
	
//	Finding Binary search
	static int SimpleBinary(int arr[], int tar, int start, int end){
		// simple binary serch required 4 arguments
		//1. array
		//2. Traget Ekement
		//3. start point
		//4. End point
		
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
