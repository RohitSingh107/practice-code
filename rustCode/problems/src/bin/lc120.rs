
fn f(i : usize, j : usize, triangle : &Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>) -> i32{

    if i == triangle.len() -1 {
        return triangle[i][j];
    }

    if dp[i][j] != -1 {
        return dp[i][j];
    }

    // Minimum of both ways + current value
    dp[i][j] = std::cmp::min(f(i + 1,j, triangle, dp) , f(i +1, j +1 , triangle, dp) ) + triangle[i][j];
    return dp[i][j];
}

fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {


//     // TopDown Recursion
//     let mut dp : Vec<Vec<i32>> = vec![vec![-1 ; 205] ; 205];
//     return f(0, 0, &triangle, &mut dp);
    
    // BottomUp Tabulation
    let n : usize = triangle.len();

    let mut dp = vec![vec![ 0 ; 205] ; 205];


    for i in (0..n).rev() {
        for j in (0..(triangle[i].len())).rev() {
            if i == n - 1 {
                dp[i][j] = triangle[i][j];
                continue;
            }

            dp[i][j] = std::cmp::min(dp[i+1][j], dp[i+1][j+1] ) + triangle[i][j];
        }
    }

    return dp[0][0];
}

fn main(){

    let triangle : Vec<Vec<i32>> = vec![vec![2],vec![3,4], vec![6,5,7], vec![4,1,8,3]];
    // let triangle : Vec<Vec<i32>> = vec![vec![-10]];

    println!("{}", minimum_total(triangle));

}
