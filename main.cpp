#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <chrono> 
#include <stack>
using namespace std;
using namespace std::chrono;

class Node{
public:
    int data;
    Node* next;
    Node(int _data)
    {
        data = _data;
        next=nullptr;
    }
};
void Push(Node*& head, int _data)
{
    Node* p = new Node(_data);
    if(head == nullptr)
        head = p;
    else
    {
        p->next=head;
        head = p;
    }
}
void Pop(Node*& head)
{
    Node* nodeToPop =head;
    if(head == nullptr)
        return;
    else
    {
        
        head=nodeToPop->next;
        nodeToPop->next = nullptr;
        cout<<"Pop stack:"<<nodeToPop->data<<endl;
    }
    delete(nodeToPop);
    
}

void Display(Node* head)
{
    
    Node* current=head;
    while(current != nullptr)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
Node* swapPairs(Node* head)
{
    if(head == nullptr || head->next == nullptr){
            return head;
        }
        Node* temp=head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
}
Node* mergeTwoLists(Node* l1, Node* l2)
{
    if(l1 == nullptr)
        return l2;
    if(l2 == nullptr)
        return l1;
    
    if(l1->data <= l2->data)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}
Node* mergeSort(int start, int end, vector<Node*>& lists) {

    if(start > end) {
        return NULL;
    }

    if(start == end) {
        return lists[start];
    }

    int mid = (start + end) / 2;

    Node* left = mergeSort(start, mid, lists);
    Node* right = mergeSort(mid+1, end, lists);

    return mergeTwoLists(left, right);

}
bool Emtpy(Node* head)
{
    return !head ? true : false;
}
Node* CreateListNode(vector<int> arr)
{
    Node* head=NULL;
    for(int i : arr)
        Push(head,i);
    return head;
}
Node* reverse(Node* head,Node*& last) {

    Node* prev = NULL;  
    Node* curr = head;
    last = head;
    while(curr) {
        Node* tmp = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = tmp;
    } 

    return prev; 
}
Node* reverseKGroup(Node* head, int k)
{
    
    Node* last = head;
    int i=0;
    while (i<k-1 && last)
    {
        i++;
        last= last->next;
    }
    if(!last)
        return head;
    Node* newlast = last->next;
    last->next = nullptr;
    head = reverse(head,last);
    last->next = reverseKGroup(newlast,k);
    return head;

    
}
void ShowArray(int* arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout<< arr[i] << " ";
    }
    cout<<endl;

}
void BubbleSort(int* arr,int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] =temp;
            }
        }
        
    }
}
void InsertionSort(int* arr,int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && key < arr[j])
        {
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}
void SelectionSort(int*  arr, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int min =i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[min])
            {
                int temp = arr[min];
                arr[min] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    
}
void QuickSort(int* arr, int size)
{

}
void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l1[n1],l2[n2];

    for (int i = 0; i < n1; i++)
        l1[i]=arr[i+left];
    for (int i = 0; i < n2; i++)
        l2[i] = arr[mid + 1 + i];
    
    int i=0,j=0,k = left;

    while(i < n1 && j < n2)
    {
        if(l1[i] <= l2[j])
        {
            arr[k]=l1[i];
            i++;
        }
        else
        {
            arr[k] = l2[j];
            j++;
        }
        k++;
    }

    while(i < n1)
        arr[k++] = l1[i++];
    
    
    while(j < n2)
        arr[k++]= l2[j++];

        
}
void mergeSort(int* arr, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid +1, right);

        merge(arr, left, mid, right);
    }
}
int fibo(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;

    return n * fibo(n-1);
}
void Swap(int& a,int& b)
{
    int temp= a;
    a=b;
    b=temp;
}
// Định nghĩa cặp giá trị (đỉnh, trọng số)
typedef pair<int, int> pii;

// Hàm Dijkstra
void dijkstra(int start, vector<vector<pii>>& graph, vector<int>& distances) {
    // Số lượng đỉnh
    int n = graph.size();
    
    // Khởi tạo mảng khoảng cách ban đầu là vô cùng lớn
    distances.assign(n, INT_MAX);
    distances[start] = 0;

    // Tạo hàng đợi ưu tiên (ưu tiên đỉnh có khoảng cách nhỏ nhất)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        // Nếu khoảng cách lớn hơn giá trị trong distances, bỏ qua
        if (current_distance > distances[current_vertex]) {
            continue;
        }

        // Duyệt tất cả các đỉnh kề
        for (const auto& neighbor : graph[current_vertex]) {
            int next_vertex = neighbor.first;
            int weight = neighbor.second;

            // Tính khoảng cách mới
            int new_distance = current_distance + weight;

            // Nếu khoảng cách mới nhỏ hơn khoảng cách đã lưu
            if (new_distance < distances[next_vertex]) {
                distances[next_vertex] = new_distance;
                pq.push({new_distance, next_vertex});
            }
        }
    }
}


int main() {
    
    // Số đỉnh và cạnh
    int n, m;
    cout << "Nhập số đỉnh và số cạnh: ";
    cin >> n >> m;

    // Đồ thị dưới dạng danh sách kề
    vector<vector<pii>> graph(n);

    cout << "Nhập các cạnh (đỉnh u, đỉnh v, trọng số w):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Nếu là đồ thị vô hướng
    }

    // Đỉnh xuất phát
    int start;
    cout << "Nhập đỉnh xuất phát: ";
    cin >> start;

    // Mảng lưu khoảng cách
    vector<int> distances;

    // Gọi hàm Dijkstra
    dijkstra(start, graph, distances);

    // Hiển thị kết quả
    cout << "Khoảng cách ngắn nhất từ đỉnh " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Đỉnh " << i << ": ";
        if (distances[i] == INT_MAX) {
            cout << "Không thể tiếp cận\n";
        } else {
            cout << distances[i] << "\n";
        }
    }
    return 0;
}