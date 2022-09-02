use std::cmp::*;

fn f(n: usize, nums: &Vec<i32>, dp: &mut Vec<i32>) -> i32 {
    if n == 0 {
        return nums[n];
    }
    if n == 1 {
        return max(nums[1], nums[0]);
    }
    if dp[n] != -1 {
        return dp[n];
    }

    dp[n] = max(nums[n] + f(n - 2, &nums, dp), 0 + f(n - 1, &nums, dp));
    return dp[n];
}

fn rob(nums: Vec<i32>) -> i32 {
    let n: usize = nums.len();

    if n == 1 {
        return nums[0];
    }
    let mut nums2: Vec<i32> = vec![0; n - 1];
    nums2.copy_from_slice(&nums[1..]);

    let mut dp: Vec<i32> = vec![-1; 110];
    let ef: i32 = f(n - 2, &nums2, &mut dp);

    let mut nums1: Vec<i32> = vec![0; n - 1];
    nums1.copy_from_slice(&nums[0..(n - 1)]);

    let mut dp: Vec<i32> = vec![-1; 110];
    let el: i32 = f(n - 2, &nums1, &mut dp);

    return max(el, ef);
}

fn main() {
    // let nums : Vec<i32> = vec![1,2,3,1];
    // let nums : Vec<i32> = vec![2,7,9,3,1];
    let nums: Vec<i32> = vec![2, 3, 2];

    // BottomUp SpaceOptimization

    // if n == 1 {
    //     return nums[0];
    // }

    // if n == 2 {
    //     return std::cmp::max(nums[0], nums[1]);
    // }

    // Excluding First
    let mut prev2 = nums[1];
    let mut prev = max(nums[1], nums[2]);
    for i in 3..nums.len() {
        let curr = max(prev2 + nums[i], prev + 0);

        prev2 = prev;
        prev = curr;
    }
    let ef = prev;

    // Excluding Last
    let mut prev2 = nums[0];
    let mut prev = max(nums[0], nums[1]);
    for i in 2..nums.len() {
        let curr = max(prev2 + nums[i], prev + 0);

        prev2 = prev;
        prev = curr;
    }

    let el = prev2;
    println!("BottomUp SpaceOptimization: {}", max(el, ef));

    // TopDown Recursion
    println!("TopDown Recursion: {}", rob(nums));
}
