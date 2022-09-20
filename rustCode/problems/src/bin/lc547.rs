
fn dfs(i : usize, j : usize, is_connected : &Vec<Vec<i32>>, visited : &mut Vec<Vec<bool>> ){



}

fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {

    let mut c = 0;

    let m = is_connected.len();
    let n = is_connected[0].len();

    let mut visited : Vec<Vec<bool>> = vec![ vec![false ; n+1]; m+1];

    for i in 0..m {
        for j in 0..n {

            if !visited[i][j] {
                dfs(i,j, &is_connected, &mut visited);
                c = c+1;
            }

        }
    }
    return c;
        
}

fn main() {

}
