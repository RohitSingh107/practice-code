use std::collections::VecDeque;

fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let m = mat.len();
    let n = mat[0].len();

    let mut visited = vec![vec![false; n]; m];
    let mut new_mat = vec![vec![0; n]; m];

    let mut q: VecDeque<(usize, usize, i32)> = VecDeque::new();

    let drow = [-1, 0, 1, 0];
    let dcol = [0, 1, 0, -1];

    for i in 0..m {
        for j in 0..n {
            if mat[i][j] == 0 {
                new_mat[i][j] = 0;
                visited[i][j] = true;
                q.push_back((i, j, 0));
            }
        }
    }

    while !q.is_empty() {
        let f = q.pop_front().unwrap();

        for i in 0..4 {
            let x = f.0 as i32 + drow[i];
            let y = f.1 as i32 + dcol[i];

            if x >= 0
                && y >= 0
                && x < m as i32
                && y < n as i32
                && !visited[x as usize][y as usize]
                && mat[x as usize][y as usize] == 1
            {
                let x = x as usize;
                let y = y as usize;

                let d = f.2 + 1;
                new_mat[x][y] = d;
                visited[x][y] = true;
                q.push_back((x, y, d));
            }
        }
    }

    return new_mat;
}

fn main() {
    let mat = vec![vec![0, 0, 0], vec![0, 1, 0], vec![1, 1, 1]];

    let ans = update_matrix(mat);

    for v in ans.iter() {
        for e in v.iter() {
            print!("{} ", e);
        }
        println!("");
    }
}
