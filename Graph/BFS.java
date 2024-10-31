package Graph;

import java.util.*;

class BFS {
    static class Graph {
        private int vertices;
        private LinkedList<Integer>[] adjacencyList;

        public Graph(int vertices) {
            this.vertices = vertices;
            this.adjacencyList = new LinkedList[vertices];
            for (int i = 0; i < vertices; i++) {
                this.adjacencyList[i] = new LinkedList<>();
            }
        }

        public void addEdge(int from, int to) {
            adjacencyList[from].add(to);
        }

        public void BFS(int start) {
            boolean[] visited = new boolean[vertices];
            Queue<Integer> queue = new LinkedList<>();

            visited[start] = true;
            queue.add(start);

            while (!queue.isEmpty()) {
                int current = queue.poll();
                System.out.print(current + " ");

                for (int neighbor : adjacencyList[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue.add(neighbor);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph(7);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 5);
        graph.addEdge(2, 6);

        System.out.println("Breadth-First Search (BFS) traversal starting from vertex 0:");
        graph.BFS(0);
    }
}