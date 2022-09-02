// fn generate_subsets(p: usize, nums : &Vec<i32>, subset: Vec<i32>, power_set: &mut Vec<Vec<i32>>) {
//     if p == nums.len() {
//         power_set.push(subset);
//         return;
//     }

//     // Pick the nums[p]
//     let mut subset2 = subset.clone();
//     subset2.push(nums[p]);
//     generate_subsets(p + 1, nums, subset2, power_set);

//     // Not pick
//     generate_subsets(p + 1, nums, subset, power_set);
// }

// fn main() {
//     let nums: Vec<i32> = vec![1, 2, 3];

//     let mut power_set: Vec<Vec<i32>> = Vec::new();

//     generate_subsets(0, &nums, vec![], &mut power_set);

//     println!("{:?}", power_set);
// }

// -------------------------------------------------------------------------

fn generate_subsets(
    p: usize,
    nums: &Vec<i32>,
    subset: &mut Vec<i32>,
    power_set: &mut Vec<Vec<i32>>,
) {
    if p == nums.len() {
        let subset = subset.clone();
        power_set.push(subset);
        return;
    }

    // Pick the nums[p]
    // let mut subset2 = subset.clone();
    subset.push(nums[p]);
    generate_subsets(p + 1, nums, subset, power_set);
    subset.pop();

    // Not pick
    generate_subsets(p + 1, nums, subset, power_set);
}

fn main() {
    let nums: Vec<i32> = vec![1, 2, 3];

    let mut empty = Vec::new();
    let mut power_set: Vec<Vec<i32>> = Vec::new();

    generate_subsets(0, &nums, &mut empty, &mut power_set);

    println!("{:?}", power_set);
}
