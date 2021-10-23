public class Insertion_two_array {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums2);
        Set<Integer> set = new HashSet<Integer>();
        for(int num : nums1){
            if(binarySearch(nums2, num))
                set.add(num);
        }
        
        int i = 0;
        int[] res = new int[set.size()];
        for(Integer num : set){
            res[i++] = num;
        }
        return res;
    }
    
  //using binary Search
    
    private boolean binarySearch(int[] num, int x){
        int high = num.length - 1;
        int low = 0;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(x < num[mid]){
                high = mid - 1;
            } else if(x > num[mid]){
                low = mid + 1;
            } else {
                return true;
            }
        }
        
        return false;
    }
}
