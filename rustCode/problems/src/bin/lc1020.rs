fn dfs(i: usize, j: usize, grid: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>) {
    visited[i][j] = true;

    let drow = [-1, 0, 1, 0];
    let dcol = [0, 1, 0, -1];

    for k in 0..4 {
        let row = i as i32 + drow[k];
        let col = j as i32 + dcol[k];

        if row >= 0
            && col >= 0
            && (row as usize) < grid.len()
            && (col as usize) < grid[0].len()
            && !visited[row as usize][col as usize]
            && grid[row as usize][col as usize] == 1
        {
            dfs(row as usize, col as usize, grid, visited);
        }
    }
}

fn num_enclaves(grid: Vec<Vec<i32>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    let mut visited = vec![vec![false; n + 1]; m + 1];

    for i in 0..m {
        // println!("Here i is {}, n is {}, mark is {}", i, n, grid[i][0]);
        if !visited[i][0] && grid[i][0] == 1 {
            dfs(i, 0, &grid, &mut visited);
        }
        if !visited[i][n - 1] && grid[i][n - 1] == 1 {
            dfs(i, n, &grid, &mut visited);
        }
    }

    for j in 0..n {
        if !visited[0][j] && grid[0][j] == 1 {
            dfs(0, j, &grid, &mut visited);
        }
        // println!("Here m is {}, j is {}, mark is {}", m, j, board[m-1][j-1]);
        if !visited[m - 1][j] && grid[m - 1][j] == 1 {
            dfs(m, j, &grid, &mut visited);
        }
    }

    let mut ans = 0;

    for i in 0..m {
        for j in 0..n {
            if grid[i][j] == 1 && !visited[i][j] {
                ans = ans + 1;
            }
        }
    }

    //     for v in visited.iter() {
    //         for e in v.iter() {
    //             print!("{} ", e);
    //         }
    //         println!("");
    //     }

    return ans;
}

fn main() {
    let grid = vec![
        vec![0, 0, 0, 0],
        vec![1, 0, 1, 0],
        vec![0, 1, 1, 0],
        vec![0, 0, 0, 0],
    ];

    // let grid = vec![vec![0,1,1,0],vec![0,0,1,0],vec![0,0,1,0],vec![0,0,0,0]];

    println!("{}", num_enclaves(grid));
}
