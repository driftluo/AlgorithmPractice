#[derive(Debug)]
struct Node {
    next: Option<Box<Node>>,
    data: Option<i32>,
}

#[derive(Debug)]
struct List {
    head: Option<Box<Node>>,
    length: u32,
}

impl Node {
    fn new() -> Node {
        Node {
            next: None,
            data: None,
        }
    }

    fn new_with_data(d: i32) -> Node {
        Node {
            next: None,
            data: Some(d),
        }
    }
}

impl List {
    fn new() -> List {
        List {
            head: None,
            length: 0,
        }
    }

    fn push(&mut self, d: i32) {
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
    let mut list = List::new();
    list.push(1);
    list.push(2);
    list.push(3);
    list.pop();
    println!("{:?}", list)
}
