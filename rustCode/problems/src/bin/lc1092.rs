
// https://leetcode.com/problems/shortest-common-supersequence/

fn shortest_common_supersequence(str1: String, str2: String) -> String {

    let m = str1.len();
    let n = str2.len();

    let s1 = str1.as_bytes();
    let s2 = str2.as_bytes();

    let mut dp = vec![vec![0 ; n+1] ; m+1];

    for i in 1..=m {
        for j in 1..=n {
            if i == 0 || j == 0 {
                dp[i][j] = 0;
                continue;
            }
            
            if s1[i-1] == s2[j-1] {
                dp[i][j] = 1 + dp[i-1][j-1];
                continue;
            }

            dp[i][j] = std::cmp::max(dp[i][j-1], dp[i-1][j]);
        }
    }

    println!("length is {}", dp[m][n]);


    let mut ans : Vec<u8> = Vec::new();

    let mut i = m;
    let mut j = n;

    loop {



        if s1[i-1] == s2[j-1] {

            ans.push(s1[i-1]);
            i -= 1;
            j -= 1;


        } else {
            if dp[i-1][j] >= dp[i][j-1] {
                ans.push(s1[i-1]);
                i -= 1;
            } else {
                ans.push(s2[j-1]);
                j -= 1;
            }
        }



        if i == 0 || j == 0 {

            if i == 0 {
                while j > 0 {
                    ans.push(s2[j-1]);
                    j -= 1;
                }
            } else {
                while i > 0 {
                    ans.push(s1[i-1]);
                    i -= 1;
                }

            }

            break;
        }


    }




    ans.reverse();

    String::from_utf8(ans).expect("Can't convert to string") 
}

fn main (){
    
    println!("ans is {}", shortest_common_supersequence("aaaaaaaa".to_string(), "aaaaaaaa".to_string()));


}
