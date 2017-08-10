#[derive(Debug)]
struct Node<T> {
    next: Option<Box<Node<T>>>,
    data: Option<T>,
}

#[derive(Debug)]
struct List<T> {
    head: Option<Box<Node<T>>>,
    length: u32,
}

impl<T> Node<T> {
    fn new_with_data(d: T) -> Node<T> {
        Node {
            next: None,
            data: Some(d),
        }
    }
}

impl<T> List<T> {
    fn new() -> List<T> {
        List {
            head: None,
            length: 0,
        }
    }

    fn push(&mut self, d: T) {
        let mut node = Node::new_with_data(d);
        let head = self.head.take();
        match head {
            Some(t) =>
                { node.next = Some(t); self.head = Some(Box::new(node)); self.length += 1; }
            None => { self.head = Some(Box::new(node)); self.length += 1; }
        }
    }

    fn pop(&mut self) {
        self.head.take().map(|node| {
            self.head = node.next;
        });
        self.length -= 1;
    }
}

fn main() {
    let mut list = List::<i32>::new();
    list.push(1);
    list.push(2);
    list.push(3);
    list.pop();
    println!("{:?}", list)
}
