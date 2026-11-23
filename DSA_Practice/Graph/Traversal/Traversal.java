package DSA_Practice.Graph.Traversal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * Graph Traversals: Breadth-First Search (BFS) & Depth-First Search (DFS)
 * 
 * BFS: Explores neighbors level by level using a Queue (FIFO).
 * DFS: Explores as far down a path as possible before backtracking using Recursion/Stack.
 */
public class Traversal {

    // --- Breadth-First Search (BFS) ---
    // Time Complexity: O(V + E)
    // Space Complexity: O(V)
    public static List<Integer> bfs(int v, List<List<Integer>> adj) {
        List<Integer> result = new ArrayList<>();
        if (v <= 0 || adj == null) {
            return result;
        }

        boolean[] visited = new boolean[v];

        // Loop handles both connected and disconnected graph components
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                Queue<Integer> queue = new LinkedList<>();

                visited[i] = true;
                queue.offer(i);

                while (!queue.isEmpty()) {
                    int node = queue.poll();
                    result.add(node);

                    for (int neighbor : adj.get(node)) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            queue.offer(neighbor);
                        }
                    }
                }
            }
        }

        return result;
    }

    // --- Depth-First Search (DFS) ---
    // Time Complexity: O(V + E)
    // Space Complexity: O(V) (recursion stack + visited array)
    public static List<Integer> dfs(int v, List<List<Integer>> adj) {
        List<Integer> result = new ArrayList<>();
        if (v <= 0 || adj == null) {
            return result;
        }

        boolean[] visited = new boolean[v];

        // Loop handles both connected and disconnected graph components
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfsHelper(i, adj, visited, result);
            }
        }

        return result;
    }

    private static void dfsHelper(int node, List<List<Integer>> adj, boolean[] visited, List<Integer> result) {
        visited[node] = true;
        result.add(node);

        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }

    public static void main(String[] args) {
        int v = 5;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }

        // Example Undirected Graph:
        // 0 --- 1 --- 3
        // |     |
        // 2 --- 4
        adj.get(0).add(1);
        adj.get(0).add(2);

        adj.get(1).add(0);
        adj.get(1).add(3);
        adj.get(1).add(4);

        adj.get(2).add(0);
        adj.get(2).add(4);

        adj.get(3).add(1);

        adj.get(4).add(1);
        adj.get(4).add(2);

        System.out.println("BFS Traversal: " + bfs(v, adj));
        System.out.println("DFS Traversal: " + dfs(v, adj));
    }
}
