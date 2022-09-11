fn f(i: usize, j: usize, grid: &Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == 0 && j == 0 {
        return grid[0][0];
    }

    if dp[i][j] != -1 {
        return dp[i][j];
    }

    //     if i < 0 || j< 0 {
    //         return i32::MAX;
    //     }

    if i == 0 {
        dp[i][j] = f(0, j - 1, grid, dp) + grid[i][j];
        return dp[i][j];
    }
    if j == 0 {
        dp[i][j] = f(i - 1, 0, grid, dp) + grid[i][j];
        return dp[i][j];
    }

    dp[i][j] = std::cmp::min(f(i - 1, j, grid, dp), f(i, j - 1, grid, dp)) + grid[i][j];
    return dp[i][j];
}

fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    // // TopDown Recursion
    // let mut dp: Vec<Vec<i32>> = vec![vec![-1; 205]; 205];
    // return f(m - 1, n - 1, &grid, &mut dp);

    // // BottomUp Tabulation
    // let mut dp: Vec<Vec<i32>> = vec![vec![0; n + 1]; m + 1];

    // for i in 0..m {
    //     for j in 0..n {
    //         if i == 0 && j == 0 {
    //             dp[0][0] = grid[0][0];
    //             continue;
    //         }

    //         if i == 0 {
    //             dp[i][j] = dp[i][j - 1] + grid[i][j];
    //             continue;
    //         }

    //         if j == 0 {
    //             dp[i][j] = dp[i - 1][j] + grid[i][j];
    //             continue;
    //         }

    //         dp[i][j] = std::cmp::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    //     }
    // }
    // return dp[m - 1][n - 1];


    // BottomUp Space Optimized
    
    let mut prev : Vec<i32> = vec![0; n+1];

    for i in 0..m {
    
        let mut curr : Vec<i32> = vec![0; n+1];
        
        for j in 0..n {
            if i == 0 && j == 0 {
                curr[0] = grid[0][0];
                continue;
            }

            if i == 0 {
                curr[j] = curr[j - 1] + grid[i][j];
                continue;
            }

            if j == 0 {
                curr[j] = prev[j] + grid[i][j];
                continue;
            }

            curr[j] = std::cmp::min(prev[j], curr[j - 1]) + grid[i][j];
        }
        prev = curr;
    }
    return prev[n-1];
}

fn main() {
    let grid: Vec<Vec<i32>> = vec![vec![1, 3, 1], vec![1, 5, 1], vec![4, 2, 1]];
    // let grid: Vec<Vec<i32>> = vec![vec![1, 2, 3], vec![4, 5, 6]];

    println!("{}", min_path_sum(grid));
}
