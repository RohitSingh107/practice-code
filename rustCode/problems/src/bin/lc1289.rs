fn f(i: usize, j: usize, grid: &Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == 0 {
        return grid[i][j];
    }

    for k in 0..grid[0].len() {
        if k == j {
            continue;
        }

        dp[i][j] = std::cmp::min(dp[i][j], f(i - 1, k, grid, dp) + grid[i][j]);
    }

    return dp[i][j];
}

fn min_falling_path_sum(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    // // TopDown Recursion
    // let mut dp: Vec<Vec<i32>> = vec![vec![i32::MAX; n]; m];

    // let mut ans = i32::MAX;

    // for j in 0..n {
    //     ans = std::cmp::min(ans, f(m - 1, j, &matrix, &mut dp));
    // }

    // return ans;

    //     // BottomUp Tabulation

    let mut dp: Vec<Vec<i32>> = vec![vec![i32::MAX; n]; m];

    for i in 0..m {
        for j in 0..n {
            if i == 0 {
                dp[i][j] = grid[i][j];
                continue;
            }
            for k in 0..n {
                if k == j {
                    continue;
                }
                dp[i][j] = std::cmp::min(dp[i][j], dp[i - 1][k] + grid[i][j]);
            }
        }
    }
    let mut ans = i32::MAX;

    for j in 0..n {
        ans = std::cmp::min(ans, dp[m-1][j]);
    }

    return ans;
}

fn main() {
    // let matrix: Vec<Vec<i32>> = vec![vec![1, 2, 3], vec![4, 5, 6] ];
    // let matrix: Vec<Vec<i32>> = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
    let matrix: Vec<Vec<i32>> = vec![
        vec![-73, 61, 43, -48, -36],
        vec![3, 30, 27, 57, 10],
        vec![96, -76, 84, 59, -15],
        vec![5, -49, 76, 31, -7],
        vec![97, 91, 61, -46, 67],
    ];

    println!("{}", min_falling_path_sum(matrix));
}
