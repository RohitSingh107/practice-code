fn dfs(
    i: usize,
    j: usize,
    board: &Vec<Vec<char>>,
    visited: &mut Vec<Vec<bool>>,
    marks: &mut Vec<Vec<bool>>,
) {
    // println!("i is {}, j is {}", i, j);
    if i == 0
        || j == 0
        || i > board.len()
        || j > board[0].len()
        || board[i - 1][j - 1] == 'X'
        || visited[i][j]
    {
        return;
    }

    visited[i][j] = true;
    marks[i][j] = true;

    dfs(i - 1, j, board, visited, marks);
    dfs(i, j + 1, board, visited, marks);
    dfs(i + 1, j, board, visited, marks);
    dfs(i, j - 1, board, visited, marks);
}

fn solve(board: &mut Vec<Vec<char>>) {
    let m = board.len();
    let n = board[0].len();

    let mut visited = vec![vec![false; n + 1]; m + 1];
    let mut marks = vec![vec![false; n + 1]; m + 1];

    for i in 1..=m {
        println!("Here i is {}, n is {}, mark is {}", i, n, board[i - 1][0]);
        if !visited[i][1] && board[i - 1][0] == 'O' {
            println!("Here2 i is {}, n is {}, mark is {}", i, n, board[i - 1][0]);

            dfs(i, 1, &board, &mut visited, &mut marks);
        }
        if !visited[i][n] && board[i - 1][n - 1] == 'O' {
            dfs(i, n, &board, &mut visited, &mut marks);
        }
    }

    for j in 1..=n {
        if !visited[1][j] && board[0][j - 1] == 'O' {
            dfs(1, j, &board, &mut visited, &mut marks);
        }
        // println!("Here m is {}, j is {}, mark is {}", m, j, board[m-1][j-1]);
        if !visited[m][j] && board[m - 1][j - 1] == 'O' {
            dfs(m, j, &board, &mut visited, &mut marks);
        }
    }

    for i in 1..=m {
        for j in 1..=n {
            if !marks[i][j] {
                board[i - 1][j - 1] = 'X';
            }
        }
    }

    for v in marks.iter() {
        for e in v.iter() {
            print!("{} ", e);
        }
        println!("");
    }
    println!("\n");

    for v in board.iter() {
        for e in v.iter() {
            print!("{} ", e);
        }
        println!("");
    }
}

fn main() {
    let mut board = vec![
        vec!['X', 'O', 'X'],
        vec!['O', 'X', 'O'],
        vec!['X', 'O', 'X'],
    ];
    solve(&mut board);
}
