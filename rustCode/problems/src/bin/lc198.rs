use std::cmp::*;

fn f(n: usize, nums: &Vec<i32>, dp : &mut Vec<i32>) -> i32 {
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

    let mut dp : Vec<i32> = vec![-1; 110];

    return f(nums.len() - 1, &nums, &mut dp);
}


fn main() {
    // let nums : Vec<i32> = vec![1,2,3,1];
    let nums : Vec<i32> = vec![2,7,9,3,1];

    // BottomUp Tabulation
    let n = nums.len();
    let mut dp : Vec<i32> = vec![0 ; n + 1];

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for i in 2..n {
        dp[i] = max( dp[i-2] + nums[i], dp[i-1] + 0);
    }
    println!("BottomUp: {}",dp[n-1]);

    // BottomUp SpaceOptimization
    let mut prev2 = nums[0];
    let mut prev = max(nums[0], nums[1]);
    for i in 2..nums.len() {
        let curr = max( prev2 + nums[i], prev + 0);

        prev2 = prev;
        prev = curr;

    }
    println!("BottomUp SpaceOptimization: {}",prev);


    // TopDown Recursion
    println!("TopDown Recursion: {}",rob(nums));




}
