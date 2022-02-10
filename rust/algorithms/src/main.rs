use std::cmp::Ordering::*;

fn linear_search<T>(haystack: &[T], needle: &T) -> Option<usize>
where
    T: Ord,
{
    haystack.iter().position(|elem| elem >= needle)
}

fn binary_search<T>(haystack: &[T], needle: &T) -> Option<usize>
where
    T: Ord,
{
    let mut l = 0;
    let mut r = haystack.len();

    while l < r {
        let m = (r + l) / 2;
        match needle.cmp(&haystack[m]) {
            Equal => return Some(m),
            Less => r = m,
            Greater => l = m + 1,
        }
    }
    None
}

fn bubble_sort<T>(list: &mut [T])
where
    T: Ord,
{
    loop {
        let mut swapped = false;
        for i in 0..list.len() - 1 {
            if list[i] > list[i + 1] {
                list.swap(i, i + 1);
                swapped = true
            }
        }
        if !swapped {
            break;
        }
    }
}

fn selection_sort<T>(list: &mut [T])
where
    T: Ord,
{
    for i in 0..list.len() - 1 {
        let rest = list[i + 1..].iter().enumerate();
        if let Some((j, _)) = rest.min_by_key(|&(_, item)| item) {
            list.swap(i, i + j + 1);
        }
    }
}

fn main() {
    let list: Vec<u32> = vec![10, 8, 2, 3, 1, 5];
    println!("Initial: {:?}", list);

    let mut sel = list.clone();
    selection_sort(&mut sel);
    println!("After selection sort: {:?}", sel);

    let mut bubble = list.clone();
    bubble_sort(&mut bubble);
    println!("After bubble sort: {:?}", bubble);

    const NUM_STDS: usize = 4;
    const NUM_TESTS: usize = 3;
    let scores: [[usize; NUM_TESTS]; NUM_STDS] =
        [[90, 80, 50], [50, 90, 100], [60, 60, 80], [80, 80, 80]];
    let mut student_averages: Vec<usize> = scores
        .iter()
        .map(|students| students.iter().sum::<usize>() / NUM_TESTS)
        .collect();
    bubble_sort(&mut student_averages);
    if let Some(pos) = linear_search(&student_averages, &80) {
        println!("Found a student with at least 80 avg at pos {}", pos);
    } else {
        println!("Didn't find a student with at least 80 avg");
    }
    if let Some(pos) = binary_search(&student_averages, &80) {
        println!("Found a student with at least 80 avg at pos {}", pos);
    } else {
        println!("Didn't find a student with at least 80 avg");
    }
    let mut test_averages: Vec<usize> = (0..NUM_TESTS)
        .map(|test| {
            (0..NUM_STDS)
                .map(|student| scores[student][test])
                .sum::<usize>()
                / NUM_STDS
        })
        .collect();
    bubble_sort(&mut test_averages);
    if let Some(pos) = linear_search(&test_averages, &80) {
        println!("Found a test with at least 80 avg at pos {}", pos);
    } else {
        println!("Didn't find a test with at least 80 avg");
    }
    if let Some(pos) = binary_search(&test_averages, &80) {
        println!("Found a test with at least 80 avg at pos {}", pos);
    } else {
        println!("Didn't find a test with at least 80 avg");
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_binary_search() {
        let sorted_array = Vec::from_iter(0..10);
        for i in 0..10 {
            assert_eq!(Some(i), binary_search(&sorted_array, &i));
        }
        assert_eq!(None, binary_search(&sorted_array, &10));
        assert_eq!(None, binary_search(&[], &10));
    }
}
