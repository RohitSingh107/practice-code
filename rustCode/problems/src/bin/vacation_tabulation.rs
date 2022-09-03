use proconio::input;
use std::cmp::*;

fn main() {
    input! {
        n : usize,
        plan : [[i32; 3]; n]
    }

    let mut dp: Vec<Vec<i32>> = vec![vec![0; 3]; n +1];

    dp[0][0] = plan[0][0];
    dp[0][1] = plan[0][1];
    dp[0][2] = plan[0][2];

    for i in 1..n {
        dp[i][0] = max(dp[i][0], max(dp[i-1][1] + plan[i][0], dp[i-1][2] + plan[i][0]));
        dp[i][1] = max(dp[i][1], max(dp[i-1][0] + plan[i][1], dp[i-1][2] + plan[i][1]));
        dp[i][2] = max(dp[i][2], max(dp[i-1][1] + plan[i][2], dp[i-1][0] + plan[i][2]));
    }

    println!("{}", max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])));
}
