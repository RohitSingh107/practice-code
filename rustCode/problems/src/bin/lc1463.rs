fn f(i: usize, j1: usize, j2: usize, grid: &Vec<Vec<i32>>, dp: &mut Vec<Vec<Vec<i32>>>) -> i32 {
    if i == grid.len() - 1 {
        if j1 == j2 {
            return grid[i][j1];
        } else {
            return grid[i][j1] + grid[i][j2];
        }
    }

    if dp[i][j1][j2] != -1 {
        return dp[i][j1][j2];
    }

    for x in (j1 as i32 - 1)..(j1 as i32 + 2) {
        for y in (j2 as i32 - 1)..(j2 as i32 + 2) {
            if x == -1 || y == -1 {
                continue;
            }

            if x as usize == grid[0].len() || y as usize == grid[0].len() {
                continue;
            }

            dp[i][j1][j2] = std::cmp::max(
                dp[i][j1][j2],
                f(i + 1, x as usize, y as usize, grid, dp)
                    + if j1 == j2 {
                        grid[i][j1]
                    } else {
                        grid[i][j1] + grid[i][j2]
                    },
            );
        }
    }

    return dp[i][j1][j2];
}

fn cherry_pickup(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    // // TopDown Recursion
    // let mut dp: Vec<Vec<Vec<i32>>> = vec![vec![vec![-1; n]; n]; m];
    // return f(0, 0, n - 1, &grid, &mut dp);

    // BottomUp Tabulation
    let mut dp: Vec<Vec<Vec<i32>>> = vec![vec![vec![0; n]; n]; m];

    for i in (0..m).rev() {
        for j1 in (0..n).rev() {
            for j2 in (0..n).rev() {
                if i == m - 1 {
                    if j1 == j2 {
                        dp[i][j1][j2] = grid[i][j1];
                    } else {
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                    }
                    continue;
                }
                for x in (j1 as i32 - 1)..(j1 as i32 + 2) {
                    for y in (j2 as i32 - 1)..(j2 as i32 + 2) {
                        if x == -1 || y == -1 {
                            continue;
                        }

                        if x as usize == n || y as usize == n {
                            continue;
                        }

                        dp[i][j1][j2] = std::cmp::max(
                            dp[i][j1][j2],
                            dp[i + 1][x as usize][y as usize]
                                + if j1 == j2 {
                                    grid[i][j1]
                                } else {
                                    grid[i][j1] + grid[i][j2]
                                },
                        );
                    }
                }
            }
        }
    }
    return dp[0][0][n - 1];
}

fn main() {
    // let grid: Vec<Vec<i32>> = vec![vec![3, 1, 1], vec![2, 5, 1], vec![1, 5, 5], vec![2, 1, 1]];
    let grid: Vec<Vec<i32>> = vec![
        vec![1, 0, 0, 0, 0, 0, 1],
        vec![2, 0, 0, 0, 0, 3, 0],
        vec![2, 0, 9, 0, 0, 0, 0],
        vec![0, 3, 0, 5, 4, 0, 0],
        vec![1, 0, 2, 3, 0, 0, 6],
    ];

    println!("{}", cherry_pickup(grid));
}
