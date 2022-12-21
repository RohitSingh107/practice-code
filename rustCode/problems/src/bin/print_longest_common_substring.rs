fn longest_common_substring(text1: String, text2: String) -> String {
    let m = text1.len();
    let n = text2.len();

    let t1 = text1.as_bytes();
    let t2 = text2.as_bytes();

    // BottomUp Tabulation
    let mut dp = vec![vec![0; n + 1]; m + 1];
    let mut ans: (usize, usize, i32) = (0, 0, 0);

    for i in 1..=m {
        for j in 1..=n {
            if t1[i - 1] == t2[j - 1] {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if dp[i][j] > ans.2 {
                    ans.2 = dp[i][j];
                    ans.0 = i;
                    ans.1 = j;
                }
            }
        }
    }

    //     for v in dp.iter() {
    //         for k in v.iter() {
    //             print!("{} ", k);
    //         }
    //         println!("");
    //     }

    let mut i = ans.0;
    let mut j = ans.1;
    let mut length = ans.2;
    let mut ans: Vec<u8> = Vec::new();

    loop {
        if length == 0 {
            break;
        }

        ans.push(t1[i - 1]);
        i = i - 1;
        j = j - 1;
        length = length - 1;
    }

    ans.reverse();

    return String::from_utf8(ans).unwrap();
}

fn main() {
    let text1 = String::from("wfycpc");
    let text2 = String::from("cpcyfw");

    println!("{}", longest_common_substring(text1, text2));
}
