// https://leetcode.com/problems/rotting-oranges/

use std::collections::VecDeque;

fn bfs(grid: &mut Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>) -> i32 {
    let m = grid.len();
    let n = grid[0].len();

    let drow = [-1, 0, 1, 0];
    let dcol = [0, 1, 0, -1];

    let mut max_time = 0;

    let mut q: VecDeque<(usize, usize, usize)> = VecDeque::new();

    for i in 0..m {
        for j in 0..n {
            if grid[i][j] == 2 {
                visited[i][j] = true;
                q.push_back((i, j, 0));
            }
        }
    }

    while !q.is_empty() {
        let f = q.pop_front().unwrap();

        for k in 0..4 {
            let row = f.0 as i32 + drow[k];
            let col = f.1 as i32 + dcol[k];

            if row >= 0
                && col >= 0
                && row < m as i32
                && col < n as i32
                && grid[row as usize][col as usize] == 1
                && !visited[row as usize][col as usize]
            {
                visited[row as usize][col as usize] = true;
                grid[row as usize][col as usize] = 2;
                let t = f.2 + 1;
                max_time = std::cmp::max(t, max_time);
                q.push_back((row as usize, col as usize, t));
            }
        }
    }

    // println!("{:?}", grid);

    for i in 0..m {
        for j in 0..n {
            if grid[i][j] == 1 {
                return -1;
            }
        }
    }

    return max_time as i32;
}

fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {

    let mut visited: Vec<Vec<bool>> = vec![vec![false; 11]; 11];
    let mut m_grid = grid;

    return bfs(&mut m_grid, &mut visited);
}

fn main() {
    // let grid = vec![vec![2,1,1],vec![1,1,0],vec![0,1,1]];
    // let grid = vec![vec![0,2]];
    let grid = vec![vec![2, 1, 1], vec![0, 1, 1], vec![1, 0, 1]];

    println!("{}", oranges_rotting(grid));
}
