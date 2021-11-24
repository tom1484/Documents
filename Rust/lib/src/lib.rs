pub mod test1 {
    pub mod submod1 {
        pub fn submod_test1() {
            println!("{}", 123);
        }
        pub fn submod_test2() {

        }
    }
}

// pub use test1::submod1;

pub fn test_func() {
    // println!("{}", 123);
    // println!("{}", 123);
    test1::submod1::submod_test1();
}
