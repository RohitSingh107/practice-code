use proconio::input;
use std::cmp::*;

fn max_happiness(
    day: usize,
    today_task: usize,
    plan: &Vec<Vec<i32>>,
    dp: &mut Vec<Vec<i32>>,
) -> i32 {
    if day == 0 {
        let mut hd0 = 0;
        for i in 0..3 {
            if i != today_task {
                hd0 = max(hd0, plan[0][i]);
            }
        }
        return hd0;
    }

    if dp[day][today_task] != -1 {
        return dp[day][today_task];
    }

    let mut max_hap = 0;
    for i in 0..3 {
        if i != today_task {
            max_hap = max(max_hap, max_happiness(day - 1, i, plan, dp) + plan[day][i]);
        }
    }

    dp[day][today_task] = max_hap;

    return dp[day][today_task];
}

fn main() {
    input! {
        n : usize,
        plan : [[i32; 3]; n]
    }

    let mut dp: Vec<Vec<i32>> = vec![vec![-1; 3]; 100010];

    let mut max_hap = 0;
    max_hap = max(max_hap, max_happiness(n - 1, 0, &plan, &mut dp));
    max_hap = max(max_hap, max_happiness(n - 1, 1, &plan, &mut dp));
    max_hap = max(max_hap, max_happiness(n - 1, 2, &plan, &mut dp));

    println!("{}", max_hap);
}
