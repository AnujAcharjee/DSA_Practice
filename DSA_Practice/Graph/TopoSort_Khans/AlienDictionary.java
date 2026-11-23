package DSA_Practice.Graph.TopoSort_Khans;

import java.util.*;

/**
 * Alien Dictionary (LeetCode 269)
 * 
 * Problem: Given a sorted dictionary of an alien language, derive the order of characters.
 * Approach:
 * 1. Build a Directed Graph where an edge u -> v means character 'u' appears before 'v'.
 * 2. Compare adjacent words to find the first differing character to add directed edges.
 * 3. Handle invalid prefix case (e.g., ["abc", "ab"] is invalid because "abc" cannot come before "ab").
 * 4. Apply Kahn's Algorithm (BFS Topological Sort) to find the valid character ordering.
 * 5. If a cycle is detected (sorted length != total unique characters), return "" as no valid order exists.
 */
public class AlienDictionary {

    public static String alienOrder(List<String> words) {
        if (words == null || words.isEmpty()) {
            return "";
        }

        // Adjacency list: character -> set of next characters
        Map<Character, Set<Character>> graph = new HashMap<>();
        // In-degree map: character -> count of incoming edges
        Map<Character, Integer> indegree = new HashMap<>();

        // Step 1: Initialize graph and in-degree for all unique characters present in all words
        for (String word : words) {
            for (char c : word.toCharArray()) {
                graph.putIfAbsent(c, new HashSet<>());
                indegree.putIfAbsent(c, 0);
            }
        }

        // Step 2: Build the graph by comparing adjacent words
        // Fix: Loop runs up to words.size() - 1 to avoid IndexOutOfBoundsException
        for (int i = 0; i < words.size() - 1; i++) {
            String first = words.get(i);
            String second = words.get(i + 1);
            int minLength = Math.min(first.length(), second.length());

            // Edge Case: If second word is a strict prefix of first word, it's invalid (e.g., "abc" before "ab")
            if (first.length() > second.length() && first.startsWith(second)) {
                return "";
            }

            // Find the first differing character between first and second word
            for (int pos = 0; pos < minLength; pos++) {
                char from = first.charAt(pos);
                char to = second.charAt(pos);

                if (from != to) {
                    // Directed edge: from -> to (from comes before to)
                    if (graph.get(from).add(to)) {
                        indegree.put(to, indegree.get(to) + 1);
                    }
                    break; // Only the first differing character gives ordering information
                }
            }
        }

        // Step 3: Perform Topological Sort using Kahn's Algorithm (BFS)
        return topoSort(graph, indegree);
    }

    private static String topoSort(Map<Character, Set<Character>> graph, Map<Character, Integer> indegree) {
        Queue<Character> queue = new LinkedList<>();

        // Add all source nodes (characters with in-degree 0, meaning no character comes before them)
        for (char c : indegree.keySet()) {
            if (indegree.get(c) == 0) {
                queue.offer(c);
            }
        }

        StringBuilder sortedOrder = new StringBuilder();

        // Process characters in topological order
        while (!queue.isEmpty()) {
            char current = queue.poll();
            sortedOrder.append(current);

            // Decrement in-degree for all dependent characters
            for (char neighbor : graph.get(current)) {
                indegree.put(neighbor, indegree.get(neighbor) - 1);
                // When in-degree becomes 0, all preceding characters have been processed
                if (indegree.get(neighbor) == 0) {
                    queue.offer(neighbor);
                }
            }
        }

        // If cycle exists (e.g., 'a' -> 'b' and 'b' -> 'a'), not all characters can be sorted
        if (sortedOrder.length() != indegree.size()) {
            return "";
        }

        return sortedOrder.toString();
    }

    public static void main(String[] args) {
        List<String> dictionary = List.of("wrt", "wrf", "er", "ett", "rftt");

        String alienOrderString = alienOrder(dictionary);
        System.out.println("Alien dictionary order: " + alienOrderString);
    }
}
