fn longest_common_substring(text1: String, text2: String) -> i32 {
    let t1 = text1.as_bytes();
    let t2 = text2.as_bytes();

    // BottomUp Tabulation
    let mut ans = 0;
    let mut dp = vec![vec![-1; text2.len()]; text1.len()];
    for i in 0..text1.len() {
        for j in 0..text2.len() {
            if i == 0 || j == 0 {
                if i == 0 && j == 0 {
                    if t1[0] == t2[0] {
                        dp[i][j] = 1;
                        ans = std::cmp::max(ans, dp[i][j]);
                        continue;
                    }
                    dp[i][j] = 0;
                    continue;
                }

                if t1[i] == t2[j] {
                    dp[i][j] = 1;
                    ans = std::cmp::max(ans, dp[i][j]);
                    continue;
                }

                if i == 0 {
                    dp[i][j] = 0;
                    continue;
                }

                dp[i][j] = 0;
                continue;
            }

            if t1[i] == t2[j] {
                dp[i][j] = 1 + dp[i - 1][ j - 1];
                ans = std::cmp::max(ans, dp[i][j]);
                continue;
            }

            dp[i][j] = 0; 
        }
    }

    for v in dp.iter() {
        for e in v.iter() {
            print!("{} ", e);
        }
        println!("");
    }

    return ans;
}

fn main() {
    let text1 = String::from("opablbd");
    let text2 = String::from("opabclbd");

    println!("{}", longest_common_substring(text1, text2));
}
