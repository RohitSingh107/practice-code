fn max_profit(k : i32, prices: Vec<i32>) -> i32 {

    // BottomUp SpaceOptimization
    let k = k as usize;
    let n = prices.len();
    let mut curr = vec![vec![0; k+1]; 2];
    let mut ahead = vec![vec![0; k+1]; 2];

    for i in (0..n).rev() {
        for b in 0..=1 {
            for t in (0..=k).rev() {
                if t == k {
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
    let k = 2;
    let prices = vec![3,2,6,5,0,3];

    println!("ans is {}", max_profit(k, prices));
}
