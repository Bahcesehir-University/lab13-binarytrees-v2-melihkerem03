/************************************************************
CMP2003 – Lab: Sorting (Student Skeleton)
 
Implement the TODO parts only.
Do NOT change function signatures.
 
Tasks:
1) SinglyLinkedList::selectionSort()
2) insertionSort(int arr[], int n)
3) partition(vector<int>&, int, int)  + kThSmallestItem(vector<int>, int)
4) heapify(int arr[], int n, int i) + heapSort(int arr[], int n)
 
Notes:
- main() is for manual testing only.
- Autograding will compile with -DCATCH_TESTING so main() will be disabled.
************************************************************/
 
#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
 
using namespace std;
 
// ============================================================
// SINGLY LINKED LIST
// ============================================================
 
class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
 
    Node* head;
 
public:
    SinglyLinkedList() : head(nullptr) {}
 
    void insertEnd(int value) {
        Node* newNode = new Node{value, nullptr};
 
        if (head == nullptr) {
            head = newNode;
            return;
        }
 
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
 
        temp->next = newNode;
    }
 
    // Helper for grading (do not modify)
    std::vector<int> toVector() const {
        std::vector<int> out;
        Node* temp = head;
        while (temp != nullptr) {
            out.push_back(temp->data);
            temp = temp->next;
        }
        return out;
    }
 
    // Print list (manual check)
    void print() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data;
            if (temp->next) std::cout << " -> ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
 
    // ========================================================
    // TASK 1: Selection Sort (Linked List)
    // ========================================================
    void selectionSort() {
        // TODO:
        // Use selection sort by swapping node->data values
       for(Node* i = head; i != nullptr; i = i->next){
           Node* minNode = i;
           for(Node* j = i->next; j != nullptr; j = j->next){
               if(j->data < minNode->data) minNode = j;
           }
           swap(i->data,minNode->data);
       }
    }
};
 
// ============================================================
// TASK 2: INSERTION SORT (ARRAY)
// ============================================================
 
void insertionSort(int arr[], int n) {
    // TODO:
    // Standard insertion sort
    for(int i = 1; i< n; i++){
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}
 
// ============================================================
// TASK 3: QUICKSELECT (k-th smallest)
// ============================================================
 
int partition(vector<int>& v, int low, int high) {
    // TODO:
    int pivot = v[high];
    int i = low;
    for (int j = low ; j < high ; j++){
        if(v[j] <= pivot){
            swap(v[i] , v[j]);
            i++;
        }
    }
    swap(v[i] , v[high]);
    return i; 
}
 
int kThSmallestItem(vector<int> v, int k) {
    // TODO:
    // MUST throw on invalid k:
     if (k < 0 || k >= (int)v.size()){ throw out_of_range("k out of range");}
 
    // Then do quickselect loop:
    int low = 0, high = (int)v.size()-1;
    while (low <= high){
      int p = partition(v, low, high);
      if (p == k) return v[p];
      else if (k < p) high = p - 1;
      else low = p + 1;
}
    return -1; // placeholder
}
 
// ============================================================
// TASK 4: HEAP SORT
// ============================================================
 
void heapify(int arr[], int n, int i) {
    // TODO:
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
     if (left < n && arr[left] > arr[largest] ) largest = left;
     if (right < n && arr[right] > arr[largest])  largest = right;
     if (largest != i){
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // TODO:
    // Build max heap:
     for (int i = n/2 - 1; i >= 0; i--) {
         heapify(arr, n, i);
     }
    // Extract max:
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
     }
}
 
// ============================================================
// MAIN (manual testing only)
// ============================================================
#ifndef CATCH_TESTING
int main() {
    SinglyLinkedList list;
    int listVals[] = {5, 2, 9, 1, 3};
    for (int x : listVals) list.insertEnd(x);
 
    list.print();
    list.selectionSort();
    list.print();
 
    int arr[] = {8, 4, 7, 2, 9};
    insertionSort(arr, 5);
    for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
 
    vector<int> v = {10, 4, 6, 2, 8, 1};
    std::cout << kThSmallestItem(v, 3) << "\n";
 
    int h[] = {12, 3, 17, 8, 34, 25, 1};
    heapSort(h, 7);
    for (int i = 0; i < 7; i++) std::cout << h[i] << " ";
    std::cout << "\n";
 
    return 0;
}
#endif
