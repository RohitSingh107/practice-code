fn fib(n: usize, dp : &mut Vec<i32>) -> i32 {
    if n == 1 {
        return 1;
    }
    if n == 0 {
        return 0;
    }

    if dp[n] != -1 {
        return dp[n];
    }

    // return fib(n -1, dp, counter) + fib(n-2, dp, counter);
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

fn main() {
    let n: usize = 10;

    // let mut dp: [i32; 100010] = [-1; 100010];
    // let mut dp : Vec<i32> = Vec::new();
    let mut dp : Vec<i32> = vec![-1; 10010];

    let res = fib(n, &mut dp);

    println!("Fibonacci at {} is {}", n, res);
}
