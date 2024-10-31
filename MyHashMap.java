class MyHashMap {
    static class Node {
        int key, val;
        Node next;
        Node(int key, int val, Node next) {
            this.key = key;
            this.val = val;
            this.next = next;
        }
    }
    private int size = 1000, entries = 0;
    private Node[] map;
    final double load_factor = 0.75;

    public MyHashMap() {
        map = new Node[size];
    }

    private void grow() {
        Node[] map1 = map;
        size *= 2;
        map = new Node[size];
        entries = 0;
        for(Node node: map1) {
            while(node != null) {
                put(node.key, node.val);
                node = node.next;
            }
        }
    }

    public void put(int key, int value) {
        double cur_load_factor = (1.0 * entries) / size;
        if(cur_load_factor > load_factor) grow();
        int i = hash(key);
        Node x = find(map[i], key);
        if(x != null) {
            x.val = value;
        }
        else {
            map[i] = new Node(key, value, map[i]);
            entries++;
        }
    }

    public int get(int key) {
        int i = hash(key);
        Node x = find(map[i], key);
        if(x != null) {
            return x.val;
        }
        else{
            return -1;
        }
    }

    public void remove(int key) {
        int i = hash(key);
        map[i] = remove(map[i], key);
    }

    private Node remove(Node node, int key) {
        if(node == null) return null;
        if(node.key == key) {
            entries--;
            return node.next;
        }
        node.next = remove(node.next, key);
        return node;
    }

    public Node find(Node node, int key) {
        if(node == null) {
            return null;
        }
        if(node.key == key) return node;
        return find(node.next, key);
    }

    private int hash(int key) {
        return key%size;
    }
}
