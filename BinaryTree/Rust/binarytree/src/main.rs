type TreeNode<K, V> = Option<Box<Node<K, V>>>;

#[derive(Debug)]
struct Node<K, V: std::fmt::Display> {
    left: TreeNode<K, V>,
    right: TreeNode<K, V>,
    key: K,
    value: V,
}

trait BinaryTree<K, V> {
    fn pre_order(&self);
    fn in_order(&self);
    fn pos_order(&self);
}

trait BinarySerchTree<K:PartialOrd, V> : BinaryTree<K, V> {
    fn insert(&mut self, key: K, value: V);
}

impl<K, V: std::fmt::Display> Node<K, V> {
    fn new(key: K, value: V) -> Self {
        Node {
            left: None,
            right: None,
            value: value,
            key: key,
        }
    }
}

impl<K: PartialOrd, V:std::fmt::Display> BinarySerchTree<K, V> for Node<K, V> {
    fn insert(&mut self, key: K, value: V) {
        if self.key < key {
            if let Some(ref mut right) = self.right {
                right.insert(key, value);
            } else {
                self.right = Some(Box::new(Node::new(key,value)));
            }
        } else {
            if let Some(ref mut left) = self.left {
                left.insert(key, value);
            } else {
                self.left = Some(Box::new(Node::new(key,value)));
            }
        }
    }
}

impl<K, V:std::fmt::Display> BinaryTree<K, V> for Node<K, V> {
    fn pre_order(&self) {
        println!("{}", self.value);

        if let Some(ref left) = self.left {
            left.pre_order();
        }

        if let Some(ref right) = self.right {
            right.pre_order();
        }
    }

    fn in_order(&self) {
        if let Some(ref left) = self.left {
            left.in_order();
        }

        println!("{}", self.value);

        if let Some(ref right) = self.right {
            right.in_order();
        }
    }

    fn pos_order(&self) {
        if let Some(ref left) = self.left {
            left.pos_order();
        }

        if let Some(ref right) = self.right {
            right.pos_order();
        }

        println!("{}", self.value);
    }
}

fn main() {
    test_insert();
}

fn test_insert() {
    let mut root = Node::<i32, i32>::new(3,4);
    root.insert(2,3);
    root.insert(4,6);
    root.insert(5,5);
    root.insert(6,6);
    root.insert(1,8);
    if let Some(ref left) = root.left {
        assert_eq!(left.value, 3);
    }

    if let Some(ref right) = root.right {
        assert_eq!(right.value, 6);
        if let Some(ref right) = right.right {
            assert_eq!(right.value, 5);
        }
    }

    println!("Pre Order traversal");
    root.pre_order();
    println!("In Order traversal");
    root.in_order();
    println!("Pos Order traversal");
    root.pos_order();
}
