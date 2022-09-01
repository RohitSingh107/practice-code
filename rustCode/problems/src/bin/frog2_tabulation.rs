use proconio::input;
use std::cmp::*;

fn main() {
    input! {
        n : usize,
        k : usize,
        h : [i64;n]
    }

    let mut dp: Vec<i64> = vec![0; n];

    dp[0] = 0;

    for i in 1..n {
        dp[i] = i64::MAX;
        for j in 1..(k + 1) {
            if i >= j {
                dp[i] = min(dp[i], dp[i - j] + (h[i] - h[i - j]).abs());
            }
        }
    }

    println!("{}", dp[n - 1]);
}
