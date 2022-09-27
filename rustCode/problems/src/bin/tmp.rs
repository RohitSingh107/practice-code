use proconio::input;
use std::cmp::max;

fn knapsack(i: usize, wl: i64, items: &Vec<(i64, i64)>, dp: &mut Vec<Vec<i64>>) -> i64 {

    if wl <= 0 {
        // println!("i is {}, wl is {}", i, wl);
        return -1 * 1000000000;
    }
    // println!("i is {}, wl is {}", i, wl);
    if i == 0 {
        if wl >= items[0].0 {
            println!("i is {}, wl is {}", i, wl);
            return items[0].1;
        }

        println!("i is {}, wl is {}", i, wl);
        return 0;
    }

    if wl <= 0 {
        // println!("i is {}, wl is {}", i, wl);
        return -1 * 1000000000;
    }

    let not_take = knapsack(i - 1, wl, items, dp) + 0;
    let take = knapsack(i - 1, wl - items[i].0, items, dp) + items[i].1;
    let tmp = max( take, not_take);
    println!("i is {}, wl is {}, take is {}, not_take is {}", i, wl, take, not_take);
    return tmp;
}

fn main() {
    input! {
        n : usize,
        w : usize,
        items : [(i64, i64) ; n],
    }

    let mut dp: Vec<Vec<i64>> = vec![vec![-1; w + 1]; n + 1];
    println!("{}", knapsack(n - 1, w as i64, &items, &mut dp));
}
