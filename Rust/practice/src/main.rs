use std::fs::File;
use std::io::{self, Read};

fn read_username_from_file() -> Result<String, io::Error> {
    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();

    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

fn main() {
    // let s1 = String::from("tic");
    // let s2 = String::from("tac");
    // let s3 = String::from("toe");

    // let s = format!("{}-{}-{}", s1, s2, s3);
    // println!("{}", s);

    // let chars = s.chars();
    // for c in chars {
    //     println!("{}", c);
    // }

    // let t = 0;
    let name = match read_username_from_file() {
        Ok(s) => s, 
        Err(_) => String::new(),
    };

    println!("{}", name);
    
}





