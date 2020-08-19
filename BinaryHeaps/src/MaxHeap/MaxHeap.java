package MaxHeap;

public class MaxHeap {
    int arr[];
    int capacity;
    int heap_size;

    public MaxHeap(int capacity){
        this.capacity = capacity;
        this.heap_size = 0;
        this.arr = new int[capacity];
    }

    private int left(int i) { return (2*i + 1); }

    private int right(int i) { return (2*i + 2); }

    private int parent(int i) { return (i-1)/2; }

    public int getMax() { return this.arr[0]; }

    private void swap(int i, int j){
        int t = this.arr[i];
        this.arr[i] = this.arr[j];
        this.arr[j] = t;
    }

    public void insertKey(int key){
        if (this.heap_size == this.capacity)
            System.out.println("Heap is full!");
        else {
            int i = ++this.heap_size - 1;
            this.arr[i] = key;
            while (i != 0 && this.arr[parent(i)] < this.arr[i]) {
                swap(i, parent(i));
                i = parent(i);
            }
        }
    }

    public int extractMax() {
        if (this.heap_size <= 0)
            return Integer.MAX_VALUE;
        if (this.heap_size == 1) {
            this.heap_size--;
            return this.arr[0];
        }
        int root = this.arr[0];
        this.arr[0] = this.arr[heap_size-1];
        this.heap_size--;
        maxHeapify(0);

        return root;
    }

    private void maxHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int greatest = i;
        if (l < this.heap_size && this.arr[l] > this.arr[i])
            greatest = l;
        if (r < this.heap_size && this.arr[r] > this.arr[greatest])
            greatest = r;

        if (greatest != i) {
            swap(i, greatest);
            maxHeapify(greatest);
        }
    }

    public void increaseKey(int key, int new_val){
        this.arr[key] = new_val;
        while (key != 0 && this.arr[parent(key)] < this.arr[key]) {
            swap(key, parent(key));
            key = parent(key);
        }
    }

    public void display(){
        for (int i = 0; i <this.heap_size ; i++)
            System.out.print(this.arr[i]+" ");
    }

    public void deleteKey(int key) {
        increaseKey(key, Integer.MAX_VALUE);
        extractMax();
    }
}
