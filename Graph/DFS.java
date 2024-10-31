package Graph;

import java.util.*;

class DFS {
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

        public void DFS(int start) {
            boolean[] visited = new boolean[vertices];
            DFSUtil(start, visited);
        }

        private void DFSUtil(int current, boolean[] visited) {
            visited[current] = true;
            System.out.print(current + " ");

            for (int neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    DFSUtil(neighbor, visited);
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

        System.out.println("Depth-First Search (DFS) traversal starting from vertex 0:");
        graph.DFS(0);
    }
}