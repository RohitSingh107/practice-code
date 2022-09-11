use proconio::input;
use std::cmp::*;

fn f(i: usize, j: usize, grid: &Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == 0 {
        return grid[0][j];
    }

    if dp[i][j] != -1 {
        return dp[i][j];
    }

    if j == 0 {
        dp[i][0] = max(f(i - 1, 0, grid, dp), f(i - 1, 0 + 1, grid, dp)) + grid[i][j];
        return dp[i][0];
    }
    if j == grid[0].len() - 1 {
        dp[i][j] = max(f(i - 1, j - 1, grid, dp), f(i - 1, j, grid, dp)) + grid[i][j];
        return dp[i][j];
    }

    dp[i][j] = max(
        max(f(i - 1, j - 1, grid, dp), f(i - 1, j, grid, dp)),
        f(i - 1, j + 1, grid, dp),
    ) + grid[i][j];
    return dp[i][j];
}

fn solve() {
    input! {
        m : usize,
        n : usize,
        grid : [ [ i32 ; n] ; m]
    }

    // TopDown Recursion
    let mut dp: Vec<Vec<i32>> = vec![vec![-1; n]; m];

    let mut ans = 0;

    for j in 0..n {
        ans = max(ans, f(m - 1, j, &grid, &mut dp));
    }

    println!("\nTopdown Recursion: {}", ans);

    // BottomUp Tabulation

    let mut dp: Vec<Vec<i32>> = vec![vec![0; n]; m];

    for i in 0..m {
        for j in 0..n {
            if i == 0 {
                dp[0][j] = grid[0][j];
                continue;
            }

            if j == 0 {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + grid[i][j];
                continue;
            }

            if j == n - 1 {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + grid[i][j];
                continue;
            }

            dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + grid[i][j];
        }
    }

    let mut ans = 0;
    for j in 0..n {
        ans = max(ans, dp[m - 1][j]);
    }

    println!("BottomUp Tabulation: {}", ans);
}

fn main() {
    input! {
        t : usize
    }

    for _ in 0..t {
        solve();
    }
}
