import MaxHeap.MaxHeap;
import MinHeap.MinHeap;
class Main {
    public static void main(String[] args) {
        System.out.println("Min Heap");
        MinHeap h = new MinHeap(10);
        h.insertKey(3);
        h.insertKey(2);
        h.insertKey(15);
        h.deleteKey(1);
        h.insertKey(5);
        h.insertKey(4);
        h.insertKey(45);
        System.out.println(h.extractMin());
        System.out.println(h.getMin());
        h.decreaseKey(2, 1);
        h.insertKey(75);
        h.display();
        System.out.println(h.getMin());

        System.out.println("Max Heap");
        MaxHeap mxh = new MaxHeap(10);
        mxh.insertKey(3);
        mxh.insertKey(2);
        mxh.insertKey(15);
        mxh.deleteKey(1);
        mxh.insertKey(5);
        mxh.insertKey(4);
        mxh.insertKey(45);
        System.out.println(mxh.extractMax());
        System.out.println(mxh.getMax());
        mxh.increaseKey(1,21);
        mxh.insertKey(2);
        mxh.display();


    }
}