// https://leetcode.com/problems/wildcard-matching/

fn f(s: &Vec<u8>, p: &Vec<u8>, i: usize, j: usize) -> bool {
    if i == 0 && j == 0 {
        return true;
    }

    if j == 0 {
        // println!("1 Returning false");
        return false;
    }

    if i == 0 {
        for k in (1..=j).rev() {
            if p[k - 1] != "*".as_bytes()[0] {
                // println!("2 Returning false");
                return false;
            }
        }

        return true;
    }

    if s[i - 1] == p[j - 1] {
        return f(s, p, i - 1, j - 1);
    } else if p[j - 1] == "?".as_bytes()[0] {
        return f(s, p, i - 1, j - 1);
    } else if p[j - 1] == "*".as_bytes()[0] {
        return f(s, p, i, j - 1) || f(s, p, i - 1, j - 1) || f(s, p, i - 1, j);
    } else {
        return false;
    }
}

fn is_match(s: String, p: String) -> bool {

    let m = s.len();
    let n = p.len();

    let s1 = s.into_bytes();
    let p1 = p.into_bytes();

    // // TopDown Recursion
    // f(&s1, &p1, m, n)

    // BottomUp Tabulation
    let mut dp = vec![vec![false; n + 1]; m + 1];

    for i in 0..=m {
        for j in 0..=n {
            if i == 0 && j == 0 {
                dp[i][j] = true;
                continue;
            }
            if j == 0 {
                dp[i][j] = false;
                continue;
            }

            if i == 0 {
                dp[i][j] = true;
                for k in (1..=j).rev() {
                    if p1[k - 1] != "*".as_bytes()[0] {
                        dp[i][j] = false;
                        break;
                    }
                }

                // dp[i][j] = true;
                continue;
            }

            if s1[i - 1] == p1[j - 1] {
                dp[i][j] = dp[i - 1][j - 1];
            } else if p1[j - 1] == "?".as_bytes()[0] {
                dp[i][j] = dp[i - 1][j - 1];
            } else if p1[j - 1] == "*".as_bytes()[0] {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j];
            } else {
                dp[i][j] = false;
            }
        }
    }

    dp[m][n]
}

fn main() {
    println!(
        "ans is {}",
        is_match("abdejcd".to_string(), "ab*cd".to_string())
    );
    // println!(
    //     "ans is {}",
    //     is_match("aa".to_string(), "*".to_string())
    // );
}
