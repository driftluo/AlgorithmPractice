#[derive(Debug, Clone)]
struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

#[derive(Debug)]
struct Stack<T> {
    top: Option<Box<Node<T>>>,
    lengh: u32,
}

impl<T> Node<T> {
    fn new_with_data(data: T) -> Node<T> {
        Node{ data: data, next: None }
    }
}

impl<T> Stack<T> {
    fn new() -> Stack<T> {
        Stack{ top: None, lengh: 0 }
    }

    fn push(&mut self, data: T) {
        let mut node = Node::new_with_data(data);
        let next = self.top.take();
        node.next = next;
        self.top = Some(Box::new(node));
        self.lengh += 1;
    }

    fn pop(&mut self) -> Option<T> {
        let val = self.top.take();
        match val {
            None => None,
            Some(mut x) => {
                self.top = x.next.take();
                self.lengh -= 1;
                Some(x.data)
            },
        }
    }

    fn len(&self) -> u32 {
        self.lengh
    }
}

fn main() {
    #[derive(PartialEq,Eq,Debug)]
    struct TestStruct {
        a: i32,
    }

    let a = TestStruct{ a: 5 };
    let b = TestStruct{ a: 9 };

    let mut stack = Stack::<&TestStruct>::new();
    assert_eq!(stack.pop(), None);

    stack.push(&a);
    stack.push(&b);
    println!("{:?} {}", stack, stack.len());

    assert_eq!(stack.pop(), Some(&b));
    println!("{:?} {}", stack, stack.len());

    assert_eq!(stack.pop(), Some(&a));
    println!("{:?} {}", stack, stack.len());

    assert_eq!(stack.pop(), None);
    println!("{:?} {}", stack, stack.len());
}
