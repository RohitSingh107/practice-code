// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

fn f(i: usize, buy: bool, tt: usize, prices: &Vec<i32>) -> i32 {
    if i == prices.len() || tt == 2 {
        return 0;
    }

    if buy {
        return std::cmp::max(
            f(i + 1, false, tt, prices) - prices[i],
            f(i + 1, true, tt, prices) - 0,
        );
    } else {
        return std::cmp::max(
            f(i + 1, true, tt + 1, prices) + prices[i],
            f(i + 1, false, tt, prices) + 0,
        );
    }
}

// fn max_profit(prices: Vec<i32>) -> i32 {
//     // // TopDown Recursion
//     // f(0, true, 0, &prices)

//     // BottomUp Tabulation
//     let n = prices.len();
//     let mut dp = vec![vec![vec![0; 3]; 2]; n + 1];

//     for i in (0..n).rev() {
//         for b in 0..=1 {
//             for t in (0..=2).rev() {
//                 if t == 2 {
//                     dp[i][b][t] = 0;
//                     continue;
//                 }
//                 if b == 1 {
//                     dp[i][b][t] = std::cmp::max(dp[i + 1][0][t] - prices[i], dp[i + 1][1][t]);
//                 } else {
//                     dp[i][b][t] = std::cmp::max(dp[i + 1][1][t + 1] + prices[i], dp[i+1][0][t]);
//                 }
//             }
//         }
//     }

//     dp[0][1][0]
// }

fn max_profit(prices: Vec<i32>) -> i32 {
    // // TopDown Recursion
    // f(0, true, 0, &prices)

    // BottomUp SpaceOptimization
    let n = prices.len();
    // let mut dp = vec![vec![vec![0; 3]; 2]; n + 1];
    let mut curr = vec![vec![0;3 ] ; 2];
    let mut ahead = vec![vec![0; 3]; 2];

  
    for i in (0..n).rev() {
        for b in 0..=1 {
            for t in (0..=2).rev() {
                if t == 2 {
                    continue;
                }
                if b == 1 {
                    curr[b][t] = std::cmp::max(ahead[0][t] - prices[i], ahead[1][t]);
                } else {
                    curr[b][t] = std::cmp::max(ahead[1][t + 1] + prices[i], ahead[0][t]);
                }

                ahead = curr.clone();
            }
        }
    }
 

    curr[1][0]
}

fn main() {
    // let prices = vec![3, 3, 5, 0, 0, 3, 1, 4];
    // let prices = vec![7,6,4,3,1];
    let prices = vec![1, 2, 3, 4, 5];

    println!("ans is {}", max_profit(prices));
}
