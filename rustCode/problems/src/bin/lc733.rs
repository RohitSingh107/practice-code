use std::collections::VecDeque;

fn bfs(
    source: (usize, usize),
    color: i32,
    image: &mut Vec<Vec<i32>>,
    visited: &mut Vec<Vec<bool>>,
) {
    let m = image.len();
    let n = image[0].len();

    let mut q: VecDeque<(usize, usize)> = VecDeque::new();

    visited[source.0][source.1] = true;
    q.push_back(source);

    while !q.is_empty() {
        let fv = q.pop_front().unwrap();

        let x = fv.0;
        let y = fv.1;

        let ol = image[x][y];

        image[x][y] = color;

        if x as i32 - 1 >= 0 && image[x - 1][y] == ol && !visited[x - 1][y] {
            visited[x - 1][y] = true;
            q.push_back((x - 1, y));
        }

        if y + 1 < n && image[x][y + 1] == ol && !visited[x][y + 1] {
            visited[x][y + 1] = true;
            q.push_back((x, y + 1));
        }
        if x + 1 < m && image[x + 1][y] == ol && !visited[x + 1][y] {
            visited[x + 1][y] = true;
            q.push_back((x + 1, y));
        }
        if y as i32 - 1 >= 0 && image[x][y - 1] == ol && !visited[x][y - 1] {
            visited[x][y - 1] = true;
            q.push_back((x, y - 1));
        }
    }
}

fn flood_fill(image: Vec<Vec<i32>>, sr: i32, sc: i32, color: i32) -> Vec<Vec<i32>> {

    let mut m_image = image;

    let mut visited: Vec<Vec<bool>> = vec![vec![false; 55]; 55];

    println!("Before BFS");
    println!("{:?}", m_image);

    bfs(
        (sr as usize, sc as usize),
        color,
        &mut m_image,
        &mut visited,
    );

    println!("Before BFS");
    println!("{:?}", m_image);

    return m_image;
}

fn main() {
    let sr = 1;
    let sc = 1;
    let color = 2;
    let image: Vec<Vec<i32>> = vec![vec![1, 1, 1], vec![1, 1, 0], vec![1, 0, 1]];

    flood_fill(image, sr, sc, color);
}
