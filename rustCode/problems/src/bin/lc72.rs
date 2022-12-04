fn f(w1: &Vec<u8>, w2: &Vec<u8>, i: usize, j: usize) -> i32 {
    if j == 0 {
        return i as i32;
    }
    if i == 0 {
        return j as i32;
    }

    if w1[i - 1] == w2[j - 1] {
        return f(w1, w2, i - 1, j - 1);
    }

    let insert_operation = 1 + f(w1, w2, i, j - 1);
    let delete_operation = 1 + f(w1, w2, i - 1, j);
    let replace_operation = 1 + f(w1, w2, i - 1, j - 1);

    std::cmp::min(
        insert_operation,
        std::cmp::min(delete_operation, replace_operation),
    )
}

fn min_distance(word1: String, word2: String) -> i32 {

    let m = word1.len();
    let n = word2.len();

    let w1 = word1.into_bytes();
    let w2 = word2.into_bytes();

    // // TopDown Recursion
    // f(&w1, &w2, m,n)

    // BottomUp Tabulation
    let mut dp = vec![vec![0; n + 1]; m + 1];

    for i in 0..=m {
        for j in 0..=n {
            if j == 0 {
                dp[i][j] = i;
                continue;
            }

            if i == 0 {
                dp[i][j] = j;
                continue;
            }

            if w1[i - 1] == w2[j - 1] {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }

            let insert_operation = 1 + dp[i][j - 1];
            let delete_operation = 1 + dp[i - 1][j];
            let replace_operation = 1 + dp[i - 1][j - 1];

            dp[i][j] = std::cmp::min(
                insert_operation,
                std::cmp::min(delete_operation, replace_operation),
            )
        }
    }

    dp[m][n] as i32
}

fn main() {
    println!(
        "ans is {}",
        min_distance("intention".to_string(), "execution".to_string())
    );
    // println!("ans is {}", min_distance("horse".to_string(), "ros".to_string()));
}
