use proconio::input;
use std::cmp::*;

fn main() {
    input! {
        n : usize,
        plan : [[i32; 3]; n]
    }

    // let mut dp: Vec<Vec<i32>> = vec![vec![0; 3]; n +1];

    let mut p0 = plan[0][0];
    let mut p1 = plan[0][1];
    let mut p2 = plan[0][2];

    let mut c0 = 0;
    let mut c1 = 0;
    let mut c2 = 0;

    for i in 1..n {

        c0 = max(c0, max(p1 + plan[i][0], p2 + plan[i][0]));
        c1 = max(c1, max(p0 + plan[i][1], p2 + plan[i][1]));
        c2 = max(c2, max(p1 + plan[i][2], p0 + plan[i][2]));

        p0 = c0;
        p1 = c1;
        p2 = c2;

    }

    println!("{}", max(p0, max(p1, p2)));
}
