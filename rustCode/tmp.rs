fn main(){

    let mut v = Vec::new();

    v.push(5);


    if v.contains(&5) {
        println!("found");
    } else {
        println!("not found");
    }
    
    v.push(2);
    v.push(4);
    v.push(3);
    v.push(5);

    println!("{:?}", v);

    println!(" 2nd element is {}", v[2]);

}
