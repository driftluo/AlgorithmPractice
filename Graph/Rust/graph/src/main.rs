#[derive(Debug, Clone)]
struct Node {
    x: usize,
    y: usize,
    value: String,
}

#[derive(Debug, Clone)]
struct Edge {
    edge: bool,
    node: Option<String>,
}

#[derive(Debug)]
struct Graphadj {
    nodenums: usize,
    graphadj: Vec<Vec<Edge>>,
}

impl Node {
    fn new(x: usize, y:usize, value: String) -> Self {
        Node{
            x: x,
            y: y,
            value: value,
        }
    }
}

impl Edge {
    fn new() -> Self {
        Edge { edge: false, node: None }
    }

    fn have_edge(value: String) -> Self {
        Edge { edge: true, node: Some(value) }
    }
}

impl Graphadj {
    fn new(nums: usize) -> Self {
        Graphadj {
            nodenums: nums,
            graphadj: vec![vec![Edge::new();nums];nums]
        }
    }

    fn insert_edge(&mut self, v: Node) {
        match v.x < self.nodenums && v.y < self.nodenums {
            true => {
                self.graphadj[v.x][v.y] = Edge::have_edge(v.value.clone());
                self.graphadj[v.y][v.x] = Edge::have_edge(v.value);
            }
            false => {
                panic!("your nodeid is bigger than nodenums!")
            }
        }
    }
}

fn main() {
    let mut g = Graphadj::new(2);
    let v1 = Node::new(0, 1,"v1".to_string());
    g.insert_edge(v1);
    println!("{:?}", g);
}
