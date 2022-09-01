use proconio::input;
use std::cmp::*;

fn minimum_cost(n: usize, h: &Vec<i64>, dp : &mut Vec<i64>) -> i64 {
    if n == 0 {
        return 0;
    }

    if dp[n] != -1 {
    return dp[n];
    }

    // let mut cost = i64::MAX;
    // cost = min(cost, minimum_cost(n - 1, h) + (h[n] - h[n - 1]).abs());
    let mut cost = minimum_cost(n - 1, h, dp) + (h[n] - h[n - 1]).abs();
    if n != 1 {
        cost = min(cost, minimum_cost(n - 2, h, dp) + (h[n] - h[n - 2]).abs());
    }

    dp[n] = cost;

    return dp[n];
}

fn main() {
    input! {
        n : usize,
        h: [i64;n]
    }

    let mut dp : Vec<i64> = vec![-1; 100010];

    let mc: i64 = minimum_cost(n -1, &h, &mut dp);

    println!("{}", mc);
}
