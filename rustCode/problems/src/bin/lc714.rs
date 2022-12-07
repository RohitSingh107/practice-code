// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

fn max_profit(prices: Vec<i32>, fee: i32) -> i32 {

    // BottomUp Space Optimization

    let mut ahead_buy = 0;
    let mut ahead_sell = 0;
    let mut curr_buy = 0;
    let mut curr_sell = 0;

    for i in (0..prices.len()).rev() {
        curr_buy = std::cmp::max(ahead_sell - prices[i], ahead_buy - 0); // buy and not buy
        curr_sell = std::cmp::max(ahead_buy + prices[i] - fee, ahead_sell); // sell and not sell

        ahead_sell = curr_sell;
        ahead_buy = curr_buy;
    }
    curr_buy
}

fn main() {
    let prices = vec![1, 3,2,8,4,9];
    // let prices = vec![7, 6, 4, 3, 1];

    println!("ans  is {}", max_profit(prices, 2));

}
