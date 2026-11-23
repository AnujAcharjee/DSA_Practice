package DSA_Practice.Graph.TopoSort_Khans;

// Topological Sort (DFS & Kahn's Algorithm / BFS approach)

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;
import java.util.Queue;

public class TopoSort {

    // Function that performs topological sort using DFS and returns the result as an array
    public static int[] topoSort(int v, List<List<Integer>> adj) {
        if (v <= 0 || adj == null) {
            return new int[0];
        }

        boolean[] visited = new boolean[v];
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, stack);
            }
        }

        // Convert stack to result array
        int[] result = new int[v];
        int idx = 0;
        while (!stack.isEmpty()) {
            result[idx++] = stack.pop();
        }

        return result;
    }

    private static void dfs(int node, List<List<Integer>> adj, boolean[] visited, Deque<Integer> stack) {
        visited[node] = true;

        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, stack);
            }
        }

        stack.push(node);
    }

    // Kahn's Algorithm: Topological Sort using BFS (in-degree array + queue)
    public static int[] kahnsAlgo(int v, List<List<Integer>> adj) {
        if (v <= 0 || adj == null) {
            return new int[0];
        }

        // Step 1: Calculate in-degree of all vertices
        int[] inDegree = new int[v];
        for (int i = 0; i < v; i++) {
            for (int neighbor : adj.get(i)) {
                inDegree[neighbor]++;
            }
        }

        // Step 2: Push all nodes with in-degree 0 into the queue
        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < v; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        // Step 3: Process the queue using BFS
        int[] result = new int[v];
        int idx = 0;
        while (!queue.isEmpty()) {
            int node = queue.poll();
            result[idx++] = node;

            for (int neighbor : adj.get(node)) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.offer(neighbor);
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int v = 6;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }

        // Directed Acyclic Graph (DAG):
        // 5 -> 0, 5 -> 2
        // 4 -> 0, 4 -> 1
        // 2 -> 3
        // 3 -> 1
        adj.get(5).add(0);
        adj.get(5).add(2);
        adj.get(4).add(0);
        adj.get(4).add(1);
        adj.get(2).add(3);
        adj.get(3).add(1);

        // Calling DFS approach
        int[] resultDFS = topoSort(v, adj);
        System.out.println("Topological Sort (DFS): " + Arrays.toString(resultDFS));

        // Calling Kahn's BFS approach
        int[] resultBFS = kahnsAlgo(v, adj);
        System.out.println("Topological Sort (Kahn's BFS): " + Arrays.toString(resultBFS));
    }
}
