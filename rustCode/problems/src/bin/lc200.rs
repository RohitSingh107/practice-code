// extern crate queues;
// use queues::*;
use std::collections::VecDeque;

fn bfs(source: (usize, usize), grid: &Vec<Vec<char>>, visited: &mut Vec<Vec<bool>>) {
    let m = grid.len();
    let n = grid[0].len();

    let mut q: VecDeque<(usize, usize)> = VecDeque::new();

    visited[source.0][source.1] = true;

    q.push_back(source);

    while !q.is_empty() {
        let fv = q.pop_front().unwrap();


        // println!("x is {}, y is {}", fv.0, fv.1);

        // // For in All 8 directions
        // for i in -1..2 {
        //     for j in -1..2 {
        //         let x = fv.0 as i32 + i;
        //         let y = fv.1 as i32 + j;
        //         if x >= 0 && y >= 0 && x < m as i32 && y < n as i32 {
        //             let x = x as usize;
        //             let y = y as usize;
        //             if grid[x][y] == '1' && !visited[x][y] {
        //                 visited[x][y] = true;
        //                 q.push_back((x, y));
        //             }
        //         }
        //     }
        // }

        let x = fv.0;
        let y = fv.1;

        if x as i32 - 1 >= 0 && grid[x-1][y] == '1' && !visited[x-1][y] {
            visited[x-1][y] = true;
            q.push_back((x -1, y));
        }

        if y + 1 < n  && grid[x][y+1] == '1' && !visited[x][y+1] {
            visited[x][y+1] = true;
            q.push_back((x, y + 1));
        }
        if x + 1 < m  && grid[x+1][y] == '1' && !visited[x+1][y] {
            visited[x+1][y] = true;
            q.push_back((x + 1, y));
        }
        if y as i32 - 1 >= 0 && grid[x][y -1] == '1' && !visited[x][y-1]  {
            visited[x][y-1] = true;
            q.push_back((x, y - 1));
        }


        
    }
}
fn num_islands(grid: Vec<Vec<char>>) -> i32 {
    let mut visited: Vec<Vec<bool>> = vec![vec![false; 305]; 305];

    let mut c = 0;
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            if !visited[i][j] && grid[i][j] == '1' {
                c = c + 1;
                // println!("Calling for {}, {} ", i, j);
                bfs((i, j), &grid, &mut visited);
            }
        }
    }

    return c;
}

fn main() {
    // let grid = vec![
    //     vec!['1', '1', '1', '1', '0'],
    //     vec!['1', '1', '0', '1', '0'],
    //     vec!['1', '1', '0', '0', '0'],
    //     vec!['0', '0', '0', '0', '0'],
    // ];
    let grid = vec![
        vec!['1', '1', '0', '0', '0'],
        vec!['1', '1', '0', '0', '0'],
        vec!['0', '0', '1', '0', '0'],
        vec!['0', '0', '0', '1', '1'],
    ];

    println!("{}", num_islands(grid));
}
