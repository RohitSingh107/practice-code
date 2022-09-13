fn f(i: usize, j: usize, mgrid: &mut Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>) -> i32 {

    if i == mgrid.len() {
        // let ans = f(0, j - 1, mgrid, dp) + mgrid[i][j];
        // mgrid[i][j] = 0;
        return -1 * 1000000000;
    }

    if j == mgrid[0].len() {
        // let ans = f(i - 1, 0, mgrid, dp) + mgrid[i][j];
        // mgrid[i][j] = 0;
        return -1 * 1000000000;
    }

    if i == mgrid.len() - 1 && j == mgrid[0].len() -1 && mgrid[i][j] != -1 {
        let ans = mgrid[i][j];
        mgrid[i][j] = 0;
        return ans;
    }

    if mgrid[i][j] == -1 {
        return -1 * 1000000000;
    }


    let ans = std::cmp::max(f(i, j + 1, mgrid, dp), f(i + 1, j, mgrid, dp)) + mgrid[i][j];

    mgrid[i][j] = 0;

    return ans;
}

fn b(i: usize, j: usize, mgrid: &mut Vec<Vec<i32>>, dp: &mut Vec<Vec<i32>>) -> i32 {
    if i == 0 && j == 0 && mgrid[i][j] != -1 {
        let ans = mgrid[i][j];
        mgrid[i][j] = 0;
        return ans;
    }

    if mgrid[i][j] == -1 {
        return -1 * 1000000000;
    }

    if i == 0 {
        let ans = b(0, j - 1, mgrid, dp) + mgrid[i][j];
        mgrid[i][j] = 0;
        return ans;
    }

    if j == 0 {
        let ans = b(i - 1, 0, mgrid, dp) + mgrid[i][j];
        mgrid[i][j] = 0;
        return ans;
    }

    let ans = std::cmp::max(b(i, j - 1, mgrid, dp), b(i - 1, j, mgrid, dp)) + mgrid[i][j];

    mgrid[i][j] = 0;

    return ans;
}

fn cherry_pickup(grid: Vec<Vec<i32>>) -> i32 {
    let mut mgrid: Vec<Vec<i32>> = grid;

    let m = mgrid.len();
    let n = mgrid[0].len();

    // TopDown Recursion
    let mut dp: Vec<Vec<i32>> = vec![vec![-1; n]; m];

    let sr = b(m-1, n-1, &mut mgrid, &mut dp);
    let fr = f(0, 0, &mut mgrid, &mut dp);
    println!("{:?}", mgrid);

    println!("fr is {}, sr is {}", fr , sr);
    return fr + sr;

}

fn main() {
    let grid = vec![vec![0, 1, -1], vec![1, 0, -1], vec![1, 1, 1]];
    // let grid = vec![vec![1,1,-1],vec![1,-1,1],vec![-1,1,1]];

    println!("{}", cherry_pickup(grid));
}
