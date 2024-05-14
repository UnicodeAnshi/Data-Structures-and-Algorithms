
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    // Define a vector of vectors
    std::vector<std::vector<int>> vec = {
        {1, 5},
        {3, 2},
        {2, 8},
        {4, 3}
    };
    //usinng custonm comaparator
    sort(vec.begin(),vec.end(),[](vector<int> &a,vector<int>&b){
        return a[1]> b[1];
    }) ;
    for(auto itr: vec){
        cout<<itr[0]<<" "<<itr[1]<<endl;
    }
}ṁ
// #include <iostream>
// #include <queue> // Include the priority_queue header
// using namespace std;
// int main() {
//     // Define a priority queue with a custom comparator for min heap
//     std::priority_queue<int, vector<int>, greater<int>> minHeap;

//     // Insert elements into the min heap
//     minHeap.push(3);
//     minHeap.push(7);
//     minHeap.push(1);
//     minHeap.push(10);
//     minHeap.push(5);

//     // Output the elements of the min heap
//     std::cout << "Min Heap: ";
//     while (!minHeap.empty()) {
//         std::cout << minHeap.top() << " "; // Output the top element
//         minHeap.pop(); // Remove the top element
//     }
//     std::cout << std::endl;

//     return 0;
// }
