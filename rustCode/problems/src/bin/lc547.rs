fn dfs(v: usize, is_connected: &Vec<Vec<i32>>, visited: &mut Vec<bool>) {
    visited[v] = true;

    for i in 0..(is_connected.len()) {
        if is_connected[v][i] == 1 {
            if !visited[i] {
                dfs(i, is_connected, visited);
            }
        }
    }
}

fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {

    let m = is_connected.len();

    let mut c = 0;
    let mut visited: Vec<bool> = vec![false; m + 1];
    for v in 0..(m) {
        if !visited[v] {
            dfs(v, &is_connected, &mut visited);
            c = c + 1;
        }
    }
    return c;
}

fn main() {
    let is_connected = vec![vec![1, 0, 0], vec![0, 1, 0], vec![0, 0, 1]];
    println!("{}", find_circle_num(is_connected));
}
