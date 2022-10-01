fn f(i: usize, j: usize, text1: &[u8], text2: &[u8], dp: &mut Vec<Vec<i32>>) -> i32 {
    println!("i is {} j is {}", i, j);
    if dp[i][j] != -1 {
        return dp[i][j];
    }

    if i == 0 || j == 0 {
        if i == 0 && j == 0 {
            if text1[0] == text2[0] {
                return 1;
            }
            return 0;
        }

        if text1[i] == text2[j] {
            return 1;
        }

        if i == 0 {
            dp[i][j] = f(i, j - 1, text1, text2, dp);
            return dp[i][j];
        }

        dp[i][j] = f(i - 1, j, text1, text2, dp);
        return dp[i][j];
    }

    if text1[i] == text2[j] {
        dp[i][j] = 1 + f(i - 1, j - 1, text1, text2, dp);
        return dp[i][j];
    }

    dp[i][j] = std::cmp::max(f(i, j - 1, text1, text2, dp), f(i - 1, j, text1, text2, dp));
    return dp[i][j];
}

fn longest_common_subsequence(text1: String, text2: String) -> i32 {
    let t1 = text1.as_bytes();
    let t2 = text2.as_bytes();

    // TopDown Recursion
    let mut dp = vec![vec![-1; 1005]; 1005];
    return f(text1.len() - 1, text2.len() - 1, t1, t2, &mut dp);

//     // BottomUp Tabulation
//     let mut dp = vec![vec![-1; 1005]; 1005];
//     for i in 0..text1.len() {
//         for j in 0..text2.len() {
//             if i == 0 || j == 0 {
//                 if i == 0 && j == 0 {
//                     if t1[0] == t2[0] {
//                         dp[i][j] = 1;
//                         continue;
//                     }
//                     dp[i][j] = 0;
//                     continue;
//                 }

//                 if t1[i] == t2[j] {
//                     dp[i][j] = 1;
//                     continue;
//                 }

//                 if i == 0 {
//                     dp[i][j] = dp[i][j - 1];
//                     continue;
//                 }

//                 dp[i][j] = dp[i - 1][ j];
//                 continue;
//             }

//             if t1[i] == t2[j] {
//                 dp[i][j] = 1 + dp[i - 1][ j - 1];
//                 continue;
//             }

//             dp[i][j] = std::cmp::max(dp[i][ j - 1], dp[i - 1][ j]);
//         }
//     }
//     return dp[text1.len() -1][text2.len() - 1];
}

fn main() {
    let text1 = String::from("bb");
    let text2 = String::from("yby");

    println!("{}", longest_common_subsequence(text1, text2));
}
