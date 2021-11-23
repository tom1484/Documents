fn i32_to_string(mut x: i32) -> String {
    let mut result = String::new();

    while x > 0 {
        let digit = (x % 10) as u32;
        let digit = char::from_u32(digit + 48);
        x /= 10;

        result.insert(0, match digit {
            None => '\0', 
            Some(c) => c, 
        });
    }

    return result;
}

fn fetch_n_word(s: &str, n: u32) -> &str {
    let mut st: usize = 0;
    let mut cnt: u32 = 0;

    for (i, &c) in s.as_bytes().iter().enumerate() {
        if c == b' ' || i == s.len() - 1 {
            cnt += 1;
            if cnt != n {
                st = i + 1;
            }
            else {
                return &s[st..i];
            }
        }
    }

    return &s[..];
}
