#include <iostream>
#include <cmath>
using namespace std;
#define defaultSize 1
// functions

/*
 * Insert(x): Inserts an element into the priority queue according to the priority of its key.
 * FindMax(): Returns the element with largest key but does not remove it.
 * ExtractMax(): Returns the element with largest key and delete it from the heap.
 * IncreaseKey(i, newKey): Increase the key of the ith element to newKey, and relocate it to maintain heap property.
 * DecreaseKey(i, newKey): Decrease the key of the ith element to newKey, and relocate it to maintain heap property.
 * Print(): Print the heap.
 * Sort(): Sort the elements of the heap in non-dreceasing order in-place, i.e., you are not allowed to use more than O(1) additional memory.
 */

template <typename T>
class priorityQueue
{
    T *heap;
    int heapSize;
    int maxSize;

    void Swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int rightChild(int i)
    {
        return 2 * i + 2;
    }

    void maxHeapify(T *heap, int i)
    {
        int l = leftChild(i);
        int r = rightChild(i);
        int largest = i;
        if (heap[largest] < heap[l] && l < heapSize)
        {
            largest = l;
        }
        if (heap[largest] < heap[r] && r < heapSize)
        {
            largest = r;
        }
        if (largest != i)
        {
            Swap(heap[largest], heap[i]);
            maxHeapify(heap, largest);
        }
    }

    int height(int i)
    {
        if (heapSize == 0)
            return -1;
        if (i >= heapSize)
            return 0;

        int leftHeight = height(leftChild(i));
        int rightHeight = height(rightChild(i));

        return 1 + max(leftHeight, rightHeight);
    }

    void reallocate_heap_size(int size)
    {
        maxSize = 2 * size;
        T *new_heap = new T[maxSize]();
        for (int i = 0; i < size; i++)
        {
            new_heap[i] = heap[i];
        }
        delete[] heap;
        heap = new_heap;
    }

    void IncreaseKeyHelp(T *heap, int i, T key)
    {
        if (key < heap[i])
        {
            cout << "New key is not larger than the previous key" << endl;
            return;
        }
        cout << "Key increased!" << endl;
        heap[i] = key;
        while (i > 0 && heap[parent(i)] < heap[i])
        {
            Swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    // bool lessCompare(T &a, T &b)
    // {
    //     return a<b;
    // }

public:
    priorityQueue(int max = defaultSize)
    {
        heap = new T[defaultSize]();
        heapSize = 0;
    }

    ~priorityQueue()
    {
        delete[] heap;
    }

    T FindMax()
    {
        return heap[0];
    }

    T ExtractMax()
    {

        T max = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        maxHeapify(heap, 0);
        // cout << "Max: " << max << " has been extracted." << endl;
        return max;
    }

    void IncreaseKey(int i, T newKey)
    {
        i = i - 1;
        IncreaseKeyHelp(heap, i, newKey);
    }

    void Insert(T newKey)
    {
        if (heapSize >= maxSize)
        {
            reallocate_heap_size(heapSize);
        }
        heapSize++;
        int i = heapSize - 1;
        heap[i] = newKey;
        while (i > 0 && heap[parent(i)] < heap[i])
        {
            Swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void DecreaseKey(int i, T newKey)
    {
        i = i - 1;
        if (heap[i] < newKey)
        {
            cout << "New key is not smaller than the previous key" << endl;
            return;
        }
        cout << "Key decreased!" << endl;
        heap[i] = newKey;
        maxHeapify(heap, i);
    }

    void Print()
    {
        int h = height(0);
        int index = 0;
        cout << "No of elements: " << heapSize << endl;
        for (int level = 0; level <= h; level++)
        {
            for (int j = 0; j < (1 << level); j++)
            {
                if (index >= heapSize)
                {
                    break;
                }
                cout << heap[index++];
                if (level != 0)
                    cout << "\t";
            }
            cout << endl;
            if (index >= heapSize)
            {
                break;
            }
        }
    }

    void Sort()
    {
        int size = heapSize;
        for (int i = heapSize - 1; i > 0; i--)
        {
            Swap(heap[0], heap[i]);
            heapSize--;
            maxHeapify(heap, 0);
        }

        // print
        heapSize = size;
        Print();
    }

    void buildMaxHeap(T *arr, int length)
    {
        heapSize = length;
        delete heap;
        heap = new T[heapSize]();
        maxSize=heapSize+1;
        // cout<<maxSize<<endl;
        for (int i = 0; i < length; i++)
        {
            heap[i] = arr[i];
        }
        // for (int i = 0; i < heapSize; i++)
        // {
        //     cout << heap[i] << " ";
        // }
        // cout << endl;
        for (int i = heapSize / 2; i >= 0; i--)
        {
            maxHeapify(heap, i);
        }
    }

    int getSize() { return heapSize; }
};