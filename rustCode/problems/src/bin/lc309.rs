// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

fn f(prices: &Vec<i32>, i: usize, buy: bool) -> i32 {
    if i == prices.len() - 1 && buy {
        return 0;
    }

    if i == prices.len() - 1 && !buy {
        return prices[i];
    }

    if buy {
        return std::cmp::max(
            f(prices, i + 1, false) - prices[i],
            f(prices, i + 1, true) - 0,
        ); // buy and not buy
    } else {
        return std::cmp::max(
            f(prices, i + 1, true) + prices[i],
            f(prices, i + 1, false) + 0,
        ); // sell and not sell
    }
}

fn max_profit(prices: Vec<i32>) -> i32 {
    // // TopDown Recursion
    // f(&prices, 0, true)

    // BottomUp Tabulation
    let mut dp = vec![vec![0; 2]; prices.len() +2];

    for i in (0..prices.len()).rev() {
        for b in 0..=1 {
            println!("i is {}, b is {}", i, b);
            if i == prices.len() - 1 && b == 1 {
                dp[i][b] = 0;
                continue;
            }
            if i == prices.len() - 1 && b == 0 {
                dp[i][b] = prices[i];
                continue;
            }
            if b == 1 {
                println!("block 1 Before: dp is {}, price is {}", dp[i][b], prices[i]);
                dp[i][b] = std::cmp::max(dp[i + 1][0] - prices[i], dp[i + 1][1] - 0);
                println!("block 1 After: dp is {}, price is {}", dp[i][b], prices[i]);
            // buy and not buy
            } else {
                println!("block Before: dp is {}, price is {}", dp[i][b], prices[i]);
                dp[i][b] = std::cmp::max(dp[i + 2][1] + prices[i], dp[i + 1][0]);
                println!("block After: dp is {}, price is {}", dp[i][b], prices[i]);
            }
        }
    }
    println!("{:?}", dp);
    dp[0][1]
}

// fn max_profit(prices: Vec<i32>) -> i32 {
//     // BottomUp Space Optimization

//     let mut ahead_buy = 0;
//     let mut ahead_sell = 0;
//     let mut curr_buy = 0;
//     let mut curr_sell = 0;

//     for i in (0..prices.len()).rev() {
//         curr_buy = std::cmp::max(ahead_sell - prices[i], ahead_buy - 0); // buy and not buy
//         curr_sell = std::cmp::max(ahead_buy + prices[i], ahead_sell); // sell and not sell

//         ahead_sell = curr_sell;
//         ahead_buy = curr_buy;
//     }
//     curr_buy
// }

fn main() {
    let prices = vec![1, 2, 3, 0, 2];
    // let prices = vec![7, 6, 4, 3, 1];

    println!("ans  is {}", max_profit(prices));
}
