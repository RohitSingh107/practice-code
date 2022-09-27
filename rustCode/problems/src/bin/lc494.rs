// https://leetcode.com/problems/target-sum/

fn f(i: usize, t: i32, nums: &Vec<i32>, dp: &mut Vec<Vec<i32>>) -> i32 {
    // if t == 0 {
    //     return 1;
    // }

    if i == 0 {
        if t == 0 && nums[0] == 0 {
            return 2;
        }

        if t == nums[0] || t == 0 {
            return 1;
        }

        return 0;
    }

    if t - nums[i] < 0 {
        return f(i - 1, t, nums, dp);
    }
    return f(i - 1, t - nums[i], nums, dp) + f(i - 1, t, nums, dp);
}

fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
    let mut total = 0;
    let n = nums.len();
    for i in 0..n {
        total += nums[i];
    }

    if total - target < 0 {
        return 0;
    }

    if (total + target) % 2 != 0 {
        return 0;
    }
    let mut dp = vec![vec![-1; total as usize + 1]; n + 1];

    return f(n - 1, (target + total) / 2, &nums, &mut dp);
}

fn main() {
    // let nums = vec![1, 2, 3, 1];
    // let target = 3;

    let nums = vec![0, 0, 0, 0, 0, 0, 0, 0, 1];
    let target = 1;
    println!("{}", find_target_sum_ways(nums, target));
}

// s1 - s2 = t
// s1 = t + s2
// s1 = t + (sum - s1)
// 2s1 = t + sum
// s1 = (t + sum) / 2
