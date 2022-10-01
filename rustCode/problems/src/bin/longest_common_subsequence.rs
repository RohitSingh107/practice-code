fn f(
    i: usize,
    j: usize,
    text1: &[u8],
    text2: &[u8],
    dp: &mut Vec<Vec<i32>>,
    ans: &mut Vec<u8>,
) -> i32 {
    if dp[i][j] != -1 {
        return dp[i][j];
    }

    if i == 0 || j == 0 {
        if i == 0 && j == 0 {
            if text1[0] == text2[0] {
                ans.push(text1[i]);
                dp[i][j] = 1;
                return dp[i][j];
            }
            dp[i][j] = 0;
            return dp[i][j];
        }

        if text1[i] == text2[j] {
            ans.push(text1[i]);
            dp[i][j] = 1;
            return dp[i][j];
        }
        if i == 0 {
            dp[i][j] = f(i, j - 1, text1, text2, dp, ans);
            return dp[i][j];
        }

        dp[i][j] = f(i - 1, j, text1, text2, dp, ans);
        return dp[i][j];
    }

    if text1[i] == text2[j] {
        ans.push(text1[i]);
        dp[i][j] = 1 + f(i - 1, j - 1, text1, text2, dp, ans);
        return dp[i][j];
    }

    dp[i][j] = std::cmp::max(
        f(i, j - 1, text1, text2, dp, ans),
        f(i - 1, j, text1, text2, dp, ans),
    );

    return dp[i][j];
}

fn longest_common_subsequence(text1: String, text2: String) -> String {
    let m = text1.len();
    let n = text2.len();

    let t1 = text1.as_bytes();
    let t2 = text2.as_bytes();

//     // TopDown Recursion
//     let mut dp = vec![vec![-1; 1005]; 1005];
//     let mut ans: Vec<u8> = Vec::new();
//     let len_sub_seq = f(text1.len() - 1, text2.len() - 1, t1, t2, &mut dp, &mut ans);
//     println!("len is {}", len_sub_seq);
//     ans.reverse();
//     return String::from_utf8(ans).unwrap();

        // BottomUp Tabulation
        let mut dp = vec![vec![0; text2.len()]; text1.len()];
        for i in 0..text1.len() {
            for j in 0..text2.len() {
                if i == 0 || j == 0 {
                    if i == 0 && j == 0 {
                        if t1[0] == t2[0] {
                            dp[i][j] = 1;
                            continue;
                        }
                        dp[i][j] = 0;
                        continue;
                    }

                    if t1[i] == t2[j] {
                        dp[i][j] = 1;
                        continue;
                    }

                    if i == 0 {
                        dp[i][j] = dp[i][j - 1];
                        continue;
                    }

                    dp[i][j] = dp[i - 1][j];
                    continue;
                }

                if t1[i] == t2[j] {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    continue;
                }

                dp[i][j] = std::cmp::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        for v in dp.iter() {
            for k in v.iter() {
                print!("{} ", k);
            }
            println!("");
        }

        let mut i = m - 1;
        let mut j = n - 1;
        let mut ans: Vec<u8> = Vec::new();

        loop {
            if i == 0 || j == 0 {
                if i == 0 && j == 0 {
                    if t1[0] == t2[0] {
                        ans.push(t1[i]);
                    }
                    break;
                }

                if t1[i] == t2[j] {
                    ans.push(t1[i]);
                }

                if i == 0 {
                    j = j - 1;
                    continue;
                }

                if j == 0 {
                    i = i - 1;
                    continue;
                }
            }

            if t1[i] == t2[j] {
                ans.push(t1[i]);
                i = i - 1;
                j = j - 1;
            } else if dp[i][j - 1] < dp[i - 1][j] {
                i = i - 1;
            } else {
                j = j - 1;
            }
        }

        ans.reverse();

        return String::from_utf8(ans).unwrap();
}

fn main() {
    let text1 = String::from("bb");
    let text2 = String::from("cbc");

    println!("{}", longest_common_subsequence(text1, text2));
}
