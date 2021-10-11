// In the question it is given that we have to solve
// this question in O(logN)
// Hence Binary Search is applied here.

// Brute force solution is left to the viewer.

const searchRange = (nums, target) => {
    let answer = [-1, -1];
    answer[0] = search(nums, target, true);

    if (answer[0] != -1) {
        answer[1] = search(nums, target, false);
    }

    return answer;
};

const search = (nums, target, findStartIndex) => {
    let ans = -1;
    let start = 0;
    let end = nums.length - 1;

    while (start <= end) {
        let mid = Math.floor(start + (end - start) / 2);

        if (target < nums[mid]) {
            end = mid - 1;
        } else if (target > nums[mid]) {
            start = mid + 1;
        } else {
            ans = mid;
            if (findStartIndex) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return ans;
};

const main = () => {
    const nums = [5, 7, 7, 8, 8, 10];
    const target = 8;

    const result = searchRange(nums, target);

    console.log(result);
};
main();
