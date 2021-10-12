// In this problem, linear search is an option which is left 
// to the viewer.

// This solution is implemented using binary search technique
// Time complexity: O(logN)

const nextGreatestLetter = (letters, target) => {
    let start = 0;
    let end = letters.length - 1;

    while (start <= end) {
        let mid = start + (end - start) / 2;
        if (target < letters[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return letters[start%letters.length];
};

const main = () =>{

    // Input array
    const letters = ["c","f","j"];
    const target = "a"

    const answer = nextGreatestLetter(letters, target);
    console.log(answer);
}

main();