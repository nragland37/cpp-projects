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
}
