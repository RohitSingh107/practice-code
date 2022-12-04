// https://leetcode.com/problems/distinct-subsequences/

fn count_subsequences(s: &Vec<u8>, t: &Vec<u8>, i: usize, j: usize) -> i32 {
    // println!("i is {}, j is {}", i, j);

    if i == 0 || j == 0 {
        if j == 0 {
            return 1;
        }

        return 0;
    }

    if s[i - 1] == t[j - 1] {
        return count_subsequences(s, t, i - 1, j - 1) + count_subsequences(s, t, i - 1, j);
        // Match + Not Match
    }

    return count_subsequences(s, t, i - 1, j);
}

fn num_distinct(s: String, t: String) -> i32 {
    let m = s.len();
    let n = t.len();

    let t1 = s.into_bytes();
    let t2 = t.into_bytes();

    // // TopDown Recursion
    // count_subsequences(&t1, &t2, m, n)

    // BottomUp Tabulation
    let mut dp = vec![vec![0; n + 1]; m + 1];
    for i in 0..=m {
        for j in 0..=n {
            if i == 0 || j == 0 {
                if j == 0 {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
                continue;
            }

            if t1[i - 1] == t2[j - 1] {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                continue;
            }

            dp[i][j] = dp[i - 1][j];
        }
    }

    // println!("{:?}", dp);
    dp[m][n]
}

fn main() {
    println!(
        "ans is {}",
        num_distinct("rabbbit".to_string(), "rabbit".to_string())
    );
}
