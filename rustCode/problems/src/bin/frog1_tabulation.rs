use proconio::input;
use std::cmp::*;

fn main() {
    input! {
        n : usize,
        h: [i64;n]
    }

    let mut dp: Vec<i64> = vec![0; n + 1];

    dp[0] = 0;

    for i in 1..n {
        dp[i] = dp[i - 1] + (h[i] - h[i - 1]).abs();
        if i != 1 {
            dp[i] = min(dp[i], dp[i - 2] + (h[i] - h[i - 2]).abs());
        }
    }

    println!("{}", dp[n - 1]);
}
