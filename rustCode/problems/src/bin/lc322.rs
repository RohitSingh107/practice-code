// https://leetcode.com/problems/coin-change/

fn f(i: usize, t: usize, coins: &Vec<i32>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == 0 {
        if t as i32 % coins[0] == 0 {
            return t as i32 / coins[0];
        }

        return 1000000000 + 1;
    }

    if t == 0 {
        return 0;
    }

    if dp[i][t] != -1 {
        return dp[i][t];
    }

    if t < coins[i] as usize {
        dp[i][t] = f(i - 1, t, coins, dp);
        return dp[i][t];
    }

    dp[i][t] = std::cmp::min(
        f(i, t - coins[i] as usize, coins, dp) + 1,
        f(i - 1, t, coins, dp),
    );
    return dp[i][t];
}

fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
    //     // TopDown Recursion
    //     let mut dp = vec![vec![-1; amount as usize + 1]; coins.len() + 1];
    //     let ans = f(coins.len() - 1, amount as usize, &coins, &mut dp);
    //     if ans == 1000000000 + 1 {
    //         return -1;
    //     }
    //     return ans;

    // BottomUp Tabulation
    let mut dp = vec![vec![0; amount as usize + 1]; coins.len() + 1];

    for i in 0..coins.len() {
        for t in 0..(amount as usize + 1) {
            if i == 0 {
                if t as i32 % coins[0] == 0 {
                    dp[0][t] = t as i32 / coins[0];
                    continue;
                }
                dp[i][t] = 1000000000 + 1;
                continue;
            }
            if t == 0 {
                dp[i][0] = 0;
                continue;
            }

            if t < coins[i] as usize {
                dp[i][t] = dp[i - 1][t];
                continue;
            }

            dp[i][t] = std::cmp::min(dp[i][t - coins[i] as usize] + 1, dp[i - 1][t]);
        }
    }
    if dp[coins.len() - 1][amount as usize] == 1000000000 + 1 {
        return -1;
    }
    return dp[coins.len() - 1][amount as usize];
}

fn main() {
    let coins = vec![2];
    let amount = 3;
    println!("{}", coin_change(coins, amount));
}
