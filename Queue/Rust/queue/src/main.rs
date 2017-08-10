use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug, Clone)]
struct Node<T> {
    next: Option<Rc<RefCell<Node<T>>>>,
    element: T,
}

#[derive(Debug)]
struct Queue<T> {
    head: Option<Rc<RefCell<Node<T>>>>,
    tail: Option<Rc<RefCell<Node<T>>>>,
    len: u32,
}

impl<T> Node<T> {
    fn new_with_data(data: T) -> Rc<RefCell<Self>> {
        Rc::new(RefCell::new(Node { next: None, element: data }))
    }
}

impl<T> Queue<T> {
    fn new() -> Queue<T> {
        Queue {
            head: None,
            tail: None,
            len: 0,
        }
    }

    fn push(&mut self, data: T) {
        let node = Node::new_with_data(data);
        match self.tail.take() {
            None => {
                self.tail = Some(node.clone());
                self.head = Some(node);
            }
            Some(old_tail) => {
                old_tail.borrow_mut().next = Some(node.clone());
                self.tail = Some(node);
            }
        }
        self.len += 1;
    }

    fn pop(&mut self) -> Option<T> {
        if self.len == 0 {
            return None;
        }
        self.head.take().map(|old_head| {
            match old_head.borrow_mut().next.take() {
                Some(new_head) => {
                    self.head = Some(new_head);
                    self.len -= 1;
                }
                None => {
                    self.tail.take();
                    self.len -= 1;
                }
            }
            Rc::try_unwrap(old_head).ok().unwrap().into_inner().element
        })
    }
}

fn main() {
    #[derive(PartialEq,Eq,Debug)]
    struct TestStruct {
        a: i32,
    }

    let a = TestStruct{ a: 5 };
    let b = TestStruct{ a: 9 };

    let mut queue = Queue::<&TestStruct>::new();
    assert_eq!(queue.pop(), None);

    queue.push(&a);
    queue.push(&b);
    println!("{:?} {}", queue, queue.len);

    assert_eq!(queue.pop(), Some(&a));
    println!("{:?} {}", queue, queue.len);

    assert_eq!(queue.pop(), Some(&b));
    println!("{:?} {}", queue, queue.len);

    assert_eq!(queue.pop(), None);
    println!("{:?} {}", queue, queue.len);
}
