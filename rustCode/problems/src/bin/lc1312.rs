fn f(i: usize, j: usize, t1: &Vec<u8>, t2: &Vec<u8>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == 0 || j == 0 {
        return 0;
    }

    if dp[i][j] != -1 {
        return dp[i][j];
    }

    if t1[i - 1] == t2[j - 1] {
        dp[i][j] = 1 + f(i - 1, j - 1, t1, t2, dp);
        return dp[i][j];
    }

    dp[i][j] = std::cmp::max(f(i - 1, j, t1, t2, dp), f(i, j - 1, t1, t2, dp));
    return dp[i][j];
}

fn min_insertions(s: String) -> i32 {

    let n = s.len();

    let mut t1: Vec<u8> = Vec::new();
    let mut t2: Vec<u8> = Vec::new();

    for c in s.as_bytes() {
        t1.push(*c);
    }
    for c in t1.iter().rev() {
        t2.push(*c);
    }

    // // TopDown Recursion
    // let mut dp: Vec<Vec<i32>> = vec![vec![-1; n + 1]; n + 1];
    // return n as i32 - f(n, n, &t1, &t2, &mut dp);


    // BottomUp Tabulation
    let mut dp: Vec<Vec<i32>> = vec![vec![0; n + 1]; n + 1];
    for i in 1..=n {
        for j in 1..=n {
            if i == 0 || j == 0 {
                dp[i][j] = 0;
                continue;
            }
            if t1[i-1] == t2[j-1] {
                dp[i][j] = 1  + dp[i-1][j-1];
                continue;
            }

            dp[i][j] = std::cmp::max(dp[i-1][j], dp[i][j-1]);

        }
    }

    return n as i32 - dp[n][n];
}

fn main() {
    let s = String::from("leetcode");

    println!("{}", min_insertions(s));
}
