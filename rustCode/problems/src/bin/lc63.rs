fn f(i: usize, j: usize, obstacle_grid: &Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == 0 && j == 0 && obstacle_grid[i][j] == 1 {
        return 0;
    }

    if i == 0 && j == 0 {
        return 1;
    }

    if obstacle_grid[i][j] == 1 {
        return 0;
    }

    // if i < 0 || j < 0 {
    if i == 0 {
        
        dp[i][j] =  f(0, j - 1, obstacle_grid, dp);
        return dp[i][j];
    }
    if j == 0 {
        dp[i][j] = f(i - 1, 0, obstacle_grid, dp);
        return dp[i][j];
    }

    if dp[i][j] != -1 {
        return dp[i][j];
    }

    dp[i][j] = f(i - 1, j, obstacle_grid, dp) + f(i, j - 1, obstacle_grid, dp);

    return dp[i][j];
}

fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
    let m = obstacle_grid.len();
    let n = obstacle_grid[0].len();

    // TopDown Recursion
    let mut dp = vec![vec![-1; 100]; 110];
    return f((m - 1) as usize, (n - 1) as usize, &obstacle_grid, &mut dp);

//     // BottomUp Tabulation
//     let mut dp: Vec<Vec<i32>> = vec![vec![0; n as usize + 1]; m as usize + 1];

//     for i in 0..(m as usize) {
//         for j in 0..(n as usize) {
//             if i == 0 && j == 0 && obstacle_grid[i][j] == 1 {
//                 dp[0][0] = 0;
//                 continue;
//             }

//             if i == 0 && j == 0 {
//                 dp[0][0] = 1;
//                 continue;
//             }

//             if obstacle_grid[i][j] == 1 {
//                 dp[i][j] = 0;
//                 continue;
//             }

//             if i == 0 {
//                 dp[0][j] = dp[0][j - 1];
//                 continue;
//             }

//             if j == 0 {
//                 dp[i][0] = dp[i - 1][0];
//                 continue;
//             }

//             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         }
//     }
//     return dp[m as usize - 1][n as usize - 1];
}

fn main() {
    let obstacle_grid: Vec<Vec<i32>> = vec![vec![0, 0, 0], vec![0, 1, 0], vec![0, 0, 0]];
    // let obstacle_grid : Vec<Vec<i32>> = vec![ vec![0,1], vec![0,0]];
    println!("{}", unique_paths_with_obstacles(obstacle_grid));
}
