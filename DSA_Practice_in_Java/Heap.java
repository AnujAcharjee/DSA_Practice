package DSA_Practice_in_Java;

import java.util.Arrays;

// ============================================================================
// Heap Data Structure
// ============================================================================
// A Heap is a Complete Binary Tree represented sequentially using an array.
//
// Array Indexing Rules (0-based indexing):
// - Root:                      index 0
// - Parent of node at index i: (i - 1) / 2
// - Left child of index i:     2 * i + 1
// - Right child of index i:    2 * i + 2
// - Internal nodes range:      0 to (n / 2) - 1
// - Leaf nodes range:          n / 2 to n - 1
//
// Types of Heaps:
// 1. Max-Heap: Value of parent node >= values of children. (Root holds maximum)
// 2. Min-Heap: Value of parent node <= values of children. (Root holds minimum)
//
// Time & Space Complexities:
// - Heapify (min/max):      O(log N) time, O(1) auxiliary space (iterative)
// - Build Heap from array:  O(N) time
// - Insert:                 O(log N) time
// - Extract (Min/Max):      O(log N) time
// - Peek (Min/Max):         O(1) time
// - Heap Sort:              O(N log N) time, O(1) auxiliary space
// ============================================================================

public class Heap {

    private int[] heap;
    private int size;
    private int capacity;
    private boolean isMinHeap; // true = Min-Heap, false = Max-Heap

    private static final int DEFAULT_CAPACITY = 10;

    // Default constructor: creates an empty Min-Heap with default capacity
    public Heap() {
        this(DEFAULT_CAPACITY, true);
    }

    // Constructor specifying heap type
    public Heap(boolean isMinHeap) {
        this(DEFAULT_CAPACITY, isMinHeap);
    }

    // Constructor specifying capacity and heap type
    public Heap(int capacity, boolean isMinHeap) {
        this.capacity = Math.max(capacity, 1);
        this.size = 0;
        this.isMinHeap = isMinHeap;
        this.heap = new int[this.capacity];
    }

    // Construct a Heap from an existing array in O(N) time
    public Heap(int[] arr, boolean isMinHeap) {
        if (arr == null) {
            this.capacity = DEFAULT_CAPACITY;
            this.size = 0;
            this.isMinHeap = isMinHeap;
            this.heap = new int[this.capacity];
            return;
        }

        this.capacity = Math.max(arr.length * 2, DEFAULT_CAPACITY);
        this.size = arr.length;
        this.isMinHeap = isMinHeap;
        this.heap = new int[this.capacity];

        // Copy array elements
        System.arraycopy(arr, 0, this.heap, 0, arr.length);

        // Build heap bottom-up in O(N) time
        if (isMinHeap) {
            buildMinHeap(this.heap, this.size);
        } else {
            buildMaxHeap(this.heap, this.size);
        }
    }

    // ========================================================================
    // Static Heapify & Build Operations (Array-based)
    // ========================================================================

    /*
     * Max Heapify: Maintains the Max-Heap property for a subtree rooted at index i.
     * Assumes binary trees rooted at left and right children are valid Max-Heaps.
     * TC: O(log N)
     * SC: O(1) (Iterative to avoid recursion stack overhead)
     */
    public static void maxHeapify(int[] arr, int n, int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right < n && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest != i) {
                swap(arr, i, largest);
                i = largest; // Move down to affected child
            } else {
                break;
            }
        }
    }

    /*
     * Min Heapify: Maintains the Min-Heap property for a subtree rooted at index i.
     * Assumes binary trees rooted at left and right children are valid Min-Heaps.
     * TC: O(log N)
     * SC: O(1) (Iterative)
     */
    public static void minHeapify(int[] arr, int n, int i) {
        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] < arr[smallest]) {
                smallest = left;
            }
            if (right < n && arr[right] < arr[smallest]) {
                smallest = right;
            }

            if (smallest != i) {
                swap(arr, i, smallest);
                i = smallest; // Move down to affected child
            } else {
                break;
            }
        }
    }

    // Build Max-Heap from an arbitrary array: TC: O(N)
    public static void buildMaxHeap(int[] arr) {
        if (arr == null || arr.length <= 1)
            return;
        buildMaxHeap(arr, arr.length);
    }

    public static void buildMaxHeap(int[] arr, int n) {
        // Start from last non-leaf node: (n / 2) - 1 down to 0
        for (int i = (n / 2) - 1; i >= 0; i--) {
            maxHeapify(arr, n, i);
        }
    }

    // Build Min-Heap from an arbitrary array: TC: O(N)
    public static void buildMinHeap(int[] arr) {
        if (arr == null || arr.length <= 1)
            return;
        buildMinHeap(arr, arr.length);
    }

    public static void buildMinHeap(int[] arr, int n) {
        // Start from last non-leaf node: (n / 2) - 1 down to 0
        for (int i = (n / 2) - 1; i >= 0; i--) {
            minHeapify(arr, n, i);
        }
    }

    // Heap Sort (Ascending using Max-Heap): TC: O(N log N), SC: O(1)
    public static void heapSort(int[] arr) {
        if (arr == null || arr.length <= 1)
            return;

        int n = arr.length;

        // Step 1: Build max heap
        buildMaxHeap(arr, n);

        // Step 2: Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            // Move current root (largest) to end
            swap(arr, 0, i);

            // Restore max heap property on reduced heap
            maxHeapify(arr, i, 0);
        }
    }

    // Heap Sort (Descending using Min-Heap): TC: O(N log N), SC: O(1)
    public static void heapSortDescending(int[] arr) {
        if (arr == null || arr.length <= 1)
            return;

        int n = arr.length;

        // Step 1: Build min heap
        buildMinHeap(arr, n);

        // Step 2: Extract elements from heap one by one
        for (int i = n - 1; i > 0; i--) {
            // Move current root (smallest) to end
            swap(arr, 0, i);

            // Restore min heap property on reduced heap
            minHeapify(arr, i, 0);
        }
    }

    // ========================================================================
    // Instance Methods (Dynamic Priority Queue Operations)
    // ========================================================================

    // Insert an element into the heap: TC: O(log N)
    public void insert(int val) {
        ensureCapacity();
        heap[size] = val;
        size++;
        heapifyUp(size - 1);
    }

    // Peek root element: TC: O(1)
    public int peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }
        return heap[0];
    }

    // Extract root element (Min or Max): TC: O(log N)
    public int poll() {
        if (isEmpty()) {
            throw new IllegalStateException("Heap is empty");
        }

        int rootVal = heap[0];
        heap[0] = heap[size - 1]; // Move last element to root
        size--;

        if (size > 0) {
            heapifyDown(0);
        }

        return rootVal;
    }

    // Delete value at a specific index: TC: O(log N)
    public void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
        }

        heap[index] = heap[size - 1];
        size--;

        if (index < size) {
            heapifyDown(index);
            heapifyUp(index);
        }
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isMinHeap() {
        return isMinHeap;
    }

    // Print array representation of the heap
    public void printHeap() {
        System.out.print("[");
        for (int i = 0; i < size; i++) {
            System.out.print(heap[i] + (i < size - 1 ? ", " : ""));
        }
        System.out.println("]");
    }

    // ========================================================================
    // Internal Helper Methods
    // ========================================================================

    private void heapifyUp(int index) {
        if (isMinHeap) {
            while (hasParent(index) && heap[index] < heap[parent(index)]) {
                swap(heap, index, parent(index));
                index = parent(index);
            }
        } else {
            while (hasParent(index) && heap[index] > heap[parent(index)]) {
                swap(heap, index, parent(index));
                index = parent(index);
            }
        }
    }

    private void heapifyDown(int index) {
        if (isMinHeap) {
            minHeapify(heap, size, index);
        } else {
            maxHeapify(heap, size, index);
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private void ensureCapacity() {
        if (size == capacity) {
            capacity *= 2;
            heap = Arrays.copyOf(heap, capacity);
        }
    }

    private int parent(int i) {
        return (i - 1) / 2;
    }

    private int leftChild(int i) {
        return 2 * i + 1;
    }

    private int rightChild(int i) {
        return 2 * i + 2;
    }

    private boolean hasParent(int i) {
        return i > 0;
    }

    private boolean hasLeftChild(int i) {
        return leftChild(i) < size;
    }

    private boolean hasRightChild(int i) {
        return rightChild(i) < size;
    }

    // ========================================================================
    // Driver / Main Method for Verification
    // ========================================================================
    public static void main(String[] args) {
        System.out.println("========================================");
        System.out.println("   HEAP DATA STRUCTURE DEMONSTRATION    ");
        System.out.println("========================================\n");

        // 1. Static Max-Heapify and Build Max Heap
        int[] arr1 = { 4, 10, 3, 5, 1 };
        System.out.println("Original array: " + Arrays.toString(arr1));
        buildMaxHeap(arr1);
        System.out.println("After buildMaxHeap: " + Arrays.toString(arr1));

        // 2. Static Min-Heapify and Build Min Heap
        int[] arr2 = { 10, 20, 15, 30, 40 };
        System.out.println("\nOriginal array: " + Arrays.toString(arr2));
        buildMinHeap(arr2);
        System.out.println("After buildMinHeap: " + Arrays.toString(arr2));

        // 3. Heap Sort (Ascending & Descending)
        int[] sortArr = { 12, 11, 13, 5, 6, 7 };
        System.out.println("\n--- Heap Sort Test ---");
        System.out.println("Before Heap Sort: " + Arrays.toString(sortArr));
        heapSort(sortArr);
        System.out.println("After Heap Sort (Ascending):  " + Arrays.toString(sortArr));

        int[] sortArrDesc = { 12, 11, 13, 5, 6, 7 };
        heapSortDescending(sortArrDesc);
        System.out.println("After Heap Sort (Descending): " + Arrays.toString(sortArrDesc));

        // 4. Instance Min-Heap Test
        System.out.println("\n--- Min-Heap Instance Operations ---");
        Heap minHeap = new Heap(true);
        minHeap.insert(30);
        minHeap.insert(10);
        minHeap.insert(20);
        minHeap.insert(5);
        minHeap.insert(15);

        System.out.print("Min-Heap array: ");
        minHeap.printHeap();
        System.out.println("Min-Heap Peek (min): " + minHeap.peek());

        System.out.print("Polling all elements from Min-Heap: ");
        while (!minHeap.isEmpty()) {
            System.out.print(minHeap.poll() + " ");
        }
        System.out.println();

        // 5. Instance Max-Heap Test
        System.out.println("\n--- Max-Heap Instance Operations ---");
        Heap maxHeap = new Heap(false);
        maxHeap.insert(10);
        maxHeap.insert(50);
        maxHeap.insert(30);
        maxHeap.insert(100);
        maxHeap.insert(40);

        System.out.print("Max-Heap array: ");
        maxHeap.printHeap();
        System.out.println("Max-Heap Peek (max): " + maxHeap.peek());

        System.out.print("Polling all elements from Max-Heap: ");
        while (!maxHeap.isEmpty()) {
            System.out.print(maxHeap.poll() + " ");
        }
        System.out.println();

        // 6. Build from Array Constructor
        System.out.println("\n--- Constructor from Array Test ---");
        int[] rawData = { 9, 4, 7, 1, -2, 6, 5 };
        Heap fromArrayMin = new Heap(rawData, true);
        System.out.print("Min-Heap built from array: ");
        fromArrayMin.printHeap();

        Heap fromArrayMax = new Heap(rawData, false);
        System.out.print("Max-Heap built from array: ");
        fromArrayMax.printHeap();
    }
}
