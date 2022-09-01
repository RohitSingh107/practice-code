use proconio::input;
use std::cmp::*;

fn minimum_cost(n: usize, k: usize, h: &Vec<i64>, dp: &mut Vec<i64>) -> i64 {
    if n == 0 {
        return 0;
    }

    if dp[n] != -1 {
        return dp[n];
    }

    let mut cost: i64 = i64::MAX;

    for i in 1..(k + 1) {
        if n >= i {
            cost = min(
                cost,
                minimum_cost(n - i, k, h, dp) + (h[n] - h[n - i]).abs(),
            );
        }
    }

    dp[n] = cost;

    return dp[n];
}

fn main() {
    input! {
        n : usize,
        k : usize,
        h : [i64;n]
    }

    let mut dp: Vec<i64> = vec![-1; 100010];

    let mc = minimum_cost(n - 1, k, &h, &mut dp);

    println!("{}", mc);
}
