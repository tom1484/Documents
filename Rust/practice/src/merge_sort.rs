fn sort_array(v: &mut Vec<i32>, lt: usize, rt: usize) {
    if rt - lt <= 1 {
        return;
    }

    let m = (lt + rt) / 2;
    sort_array(v, lt, m);
    sort_array(v, m, rt);

    let mut tmp: Vec<i32> = Vec::new();
    let (mut p1, mut p2) = (lt, m);
    while !(p1 == m && p2 == rt) {
        if p1 == m || (p2 != rt && v[p2] < v[p1]) {
            tmp.push(v[p2]);
            p2 += 1;
        }
        else {
            tmp.push(v[p1]);
            p1 += 1;
        }
    }

    for n in lt..rt {
        v[n] = tmp[n - lt];
    }
}


fn main() {
    let mut v = vec![5, 3, 4, 1, 2];
    let (lt, rt) = (0, v.len());
    sort_array(&mut v, lt, rt);
    println!("{:?}", v);
}





