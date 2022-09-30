fn f(i: usize, t: usize, coins: &Vec<i32>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if t == 0 {
        return 1;
    }

    if i == 0 {
        if t as i32 % coins[0] == 0 {
            return 1;
        }

        return 0;
    }
    if dp[i][t] != -1 {
        return dp[i][t];
    }

    if t as i32 - coins[i] < 0 {
        dp[i][t] = f(i - 1, t, coins, dp);
        return dp[i][t];
    }

    dp[i][t] = f(i, t - coins[i] as usize, coins, dp) + f(i - 1, t, coins, dp);
    return dp[i][t];
}

fn change(amount: i32, coins: Vec<i32>) -> i32 {
//     // TopDown Recursion
//     let mut dp = vec![vec![-1; 5005]; 305];
//     return f(coins.len() - 1, amount as usize, &coins, &mut dp);

    // BottomUp Tabulation
    let mut dp = vec![vec![0; 5005]; 305];

    for i in 0..coins.len() {
        for t in 0..(amount as usize + 1) {
            if t == 0 {
                dp[i][t] = 1;
                continue;
            }
            if i == 0 {
                if t as i32 % coins[0] == 0 {
                    dp[i][t] = 1;
                    continue;
                }
                dp[i][t] = 0;
                continue;
            }

            if t as i32 - coins[i] < 0 {
                dp[i][t] = dp[i-1][t];
                continue;
            }
            dp[i][t] = dp[i][t- coins[i] as usize] + dp[i -1][t];
        }
    }
    return dp[coins.len() -1][amount as usize];
}

fn main() {
    let amount = 5;
    let coins = vec![1,2,5];
    println!("{}", change(amount, coins));
}
