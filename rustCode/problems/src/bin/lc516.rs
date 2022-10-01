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

fn longest_palindrome_subseq(s: String) -> i32 {


    let mut t1 : Vec<u8> = Vec::new();
    let mut t2 : Vec<u8> = Vec::new();

    for c in s.as_bytes() {
        t1.push(*c);
    }
    for c in t1.iter().rev() {
        t2.push(*c);
    }

    // println!("strings are {:?} and {:?}", String::from_utf8(t1), String::from_utf8(t2));
    // return 0;

 


    // // TopDown Recursion
    // let mut dp = vec![vec![-1; 1005]; 1005];
    // return f(s.len() - 1, s.len() - 1, t1, t2, &mut dp);

    // BottomUp Tabulation
    let mut dp = vec![vec![-1; 1005]; 1005];
    for i in 0..s.len() {
        for j in 0..s.len() {
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

                dp[i][j] = dp[i - 1][ j];
                continue;
            }

            if t1[i] == t2[j] {
                dp[i][j] = 1 + dp[i - 1][ j - 1];
                continue;
            }

            dp[i][j] = std::cmp::max(dp[i][ j - 1], dp[i - 1][ j]);
        }
    }
    return dp[s.len() -1][s.len() - 1];
}

fn main() {
    let s = String::from("cbbd");
    println!("{}", longest_palindrome_subseq(s));

}
