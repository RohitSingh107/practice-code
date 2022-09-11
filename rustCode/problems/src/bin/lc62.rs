fn f(i: usize, j: usize, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == 0 && j == 0 {
        return 1;
    }

    // if i < 0 || j < 0 {
    if i == 0 {
        dp[i][j] = f(0, j - 1, dp);
        return dp[i][j];
    }
    if j == 0 {
        dp[i][j] =f(i - 1, 0, dp);
        return dp[i][j];
    }

    if dp[i][j] != -1 {
        return dp[i][j];
    }

    dp[i][j] = f(i - 1, j, dp) + f(i, j - 1, dp);

    return dp[i][j];
}

fn unique_paths(m: i32, n: i32) -> i32 {
    // // TopDown Recursion
    // let mut dp = vec![ vec![-1;100] ; 110];
    // return f((m - 1) as usize, (n - 1) as usize, &mut dp);

    // // // BottomUp Tabulation
    // let mut dp: Vec<Vec<i32>> = vec![vec![0; n as usize + 1]; m as usize + 1];

    // for i in 0..(m as usize) {
    //     for j in 0..(n as usize) {
    //         if i == 0 && j == 0 {
    //             dp[0][0] = 1;
    //             continue;
    //         }

    //         if i == 0 {
    //             dp[0][j] = dp[0][j - 1];
    //             continue;
    //         }

    //         if j == 0 {
    //             dp[i][0] = dp[i - 1][0];
    //             continue;
    //         }

    //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //     }
    // }
    // return dp[m as usize - 1][n as usize - 1];

    // // BottomUp Space Optimization

    let mut prev : Vec<i32> = vec![0;n as usize +1]; 

    for i in 0..(m as usize) {

        let mut curr : Vec<i32> = vec![0;n as usize +1]; 
        
        for j in 0..(n as usize) {
            if i == 0 && j == 0 {
                curr[j] = 1;
                continue;
            }

            if i == 0 {
                curr[j] = curr[j - 1];
                continue;
            }

            if j == 0 {
                curr[j] = prev[j];
                continue;
            }

            curr[j] = prev[j] + curr[j - 1];
        }

        prev = curr;
    }

    return prev[n as usize -1];
}

fn main() {
    let m = 3;
    let n = 7;

    println!("{}", unique_paths(m, n));
}
