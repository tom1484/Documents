use std::collections::HashMap;

fn main() {
    let mut map = HashMap::new();

    map.insert(String::from("123"), 123);
    map.insert(String::from("123"), 123);
    println!("{:?}", map);

    let keys = vec![String::from("key1"), String::from("key2")];
    let values = vec![1, 2];
    let map: HashMap<_, _> = 
        keys.into_iter().zip(values.into_iter()).collect();

    println!("{:?}", map);
}





