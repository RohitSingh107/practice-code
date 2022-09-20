// https://leetcode.com/problems/partition-equal-subset-sum/

fn f(i: usize, target: i32, nums: &Vec<i32>, dp: &mut Vec<Vec<i32>>) -> bool {
    if target == 0 {
        return true;
    }

    if target < 0 {
        return false;
    }

    if i == 0 {
        return nums[i] == target;
    }

    if dp[i][target as usize] != -1 {
        if dp[i][target as usize] == 1 {
            return true;
        }
        return false;
    }

    let ans = f(i - 1, target, nums, dp) || f(i - 1, target - nums[i], nums, dp);
    if ans == true {
        dp[i][target as usize] = 1;
        return true;
    }

    dp[i][target as usize] = 0;
    return false;
}

fn can_partition(nums: Vec<i32>) -> bool {
    let n = nums.len();

    let mut k = 0;

    for i in 0..n {
        k += nums[i];
    }

    if k & 1 == 1 {
        return false;
    }

    k = k / 2;

    // // TopDown Recursion
    // let mut dp: Vec<Vec<i32>> = vec![vec![-1; k as usize + 1]; n + 1];
    // f(n - 1, k / 2, &nums, &mut dp)

    // BottomUp Tabulation

    let mut dp: Vec<Vec<bool>> = vec![vec![false; k as usize + 1]; n + 1];

    for i in 0..n {
        for t in 0..(k as usize + 1) {
            if t == 0 {
                dp[i][t] = true;
                continue;
            }

            if i == 0 {
                dp[i][t] = nums[i] as usize == t;
                continue;
            }

            dp[i][t] = dp[i - 1][t];
            if t < nums[i] as usize {
                continue;
            }
            dp[i][t] = dp[i][t] || dp[i - 1][t - nums[i] as usize];
        }
    }

    return dp[n - 1][k as usize];
}

fn main() {
    // let nums = vec![1, 5, 11, 5];
    let nums = vec![1, 5, 10, 6];
    // let nums = vec![1, 2, 5];
    // let nums = vec![1,2,3,5];

    println!("{}", can_partition(nums));
}
