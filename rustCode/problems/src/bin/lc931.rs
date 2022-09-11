
fn f(i: usize, j: usize, grid: &Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == 0 {
        return grid[0][j];
    }

    if dp[i][j] != -1 {
        return dp[i][j];
    }

    if j == 0 {
        dp[i][0] = std::cmp::min(f(i - 1, 0, grid, dp), f(i - 1, 0 + 1, grid, dp)) + grid[i][j];
        return dp[i][0];
    }
    if j == grid[0].len() - 1 {
        dp[i][j] = std::cmp::min(f(i - 1, j - 1, grid, dp), f(i - 1, j, grid, dp)) + grid[i][j];
        return dp[i][j];
    }

    dp[i][j] = std::cmp::min(
        std::cmp::min(f(i - 1, j - 1, grid, dp), f(i - 1, j, grid, dp)),
        f(i - 1, j + 1, grid, dp),
    ) + grid[i][j];
    return dp[i][j];
}

  
fn min_falling_path_sum(matrix: Vec<Vec<i32>>) -> i32 {

    let m  = matrix.len();
    let n = matrix[0].len();

//     // TopDown Recursion
//     let mut dp: Vec<Vec<i32>> = vec![vec![-1; n]; m];

//     let mut ans = i32::MAX;

//     for j in 0..n {
//         ans = std::cmp::min(ans, f(m - 1, j, &matrix, &mut dp));
//     }

//     return ans;


//     // BottomUp Tabulation

    let mut dp: Vec<Vec<i32>> = vec![vec![0; n]; m];

    for i in 0..m {
        for j in 0..n {
            if i == 0 {
                dp[0][j] = matrix[0][j];
                continue;
            }

            if j == 0 {
                dp[i][0] = std::cmp::min(dp[i - 1][0], dp[i - 1][1]) + matrix[i][j];
                continue;
            }

            if j == n - 1 {
                dp[i][j] = std::cmp::min(dp[i - 1][j - 1], dp[i - 1][j]) + matrix[i][j];
                continue;
            }

            dp[i][j] = std::cmp::min(std::cmp::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i][j];
        }
    }

    let mut ans = i32::MAX;
    for j in 0..n {
        ans = std::cmp::min(ans, dp[m - 1][j]);
    }

    return ans;


      
}

fn main() {

    let matrix : Vec<Vec<i32>> = vec![ vec![2,1,3], vec![6,5,4], vec![7,8,9]];

    println!("{}", min_falling_path_sum(matrix));


}
