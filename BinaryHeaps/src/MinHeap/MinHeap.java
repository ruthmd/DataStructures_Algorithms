package MinHeap;

public class MinHeap {
    int arr[];
    int capacity;
    int heap_size;

    public MinHeap(int capacity){
        this.capacity = capacity;
        this.heap_size = 0;
        this.arr = new int[capacity];
    }

    private int left(int i) { return (2*i + 1); }

    private int right(int i) { return (2*i + 2); }

    private int parent(int i) { return (i-1)/2; }

    public int getMin() { return this.arr[0]; }

    private void swap(int arr[], int i, int j){
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    public void insertKey(int key){
        if (this.heap_size == this.capacity)
            System.out.println("Heap is full!");
        else {
            int i = ++this.heap_size - 1;
            this.arr[i]=key;
            while (i != 0 && this.arr[parent(i)] > this.arr[i]) {
                swap(this.arr, i, parent(i));
                i = parent(i);
            }
        }
    }

    private void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < this.heap_size && this.arr[l] < this.arr[i])
            smallest = l;
        if (r < this.heap_size && this.arr[r] < this.arr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(this.arr, i, smallest);
            minHeapify(smallest);
        }
    }

    public void decreaseKey(int key, int new_val) {
        this.arr[key] = new_val;
        while (key != 0 && this.arr[parent(key)] > this.arr[key]) {
            swap(this.arr, key, parent(key));
            key = parent(key);
        }
    }


    public int extractMin() {
        if (this.heap_size <= 0)
            return Integer.MAX_VALUE;
        if (this.heap_size == 1) {
            this.heap_size--;
            return this.arr[0];
        }

        // Store the minimum value, and remove it from heap
        int root = this.arr[0];
        this.arr[0] = this.arr[heap_size-1];
        this.heap_size--;
        minHeapify(0);

        return root;
    }

    public void deleteKey(int key) {
        decreaseKey(key, Integer.MIN_VALUE);
        extractMin();
    }

    public void display(){
        for(int i=0; i<this.heap_size; i++)
            System.out.print(this.arr[i]+" ");
    }
}