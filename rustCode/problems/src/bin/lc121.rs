// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

fn max_profit(prices: Vec<i32>) -> i32 {

    let mut ans = 0;
    let mut m = prices[0];

    for i in 1..prices.len() {
        ans = std::cmp::max(ans, prices[i] - m);
        m = std::cmp::min(m, prices[i]);
    }

        
    ans
}

fn main() {
    
}
