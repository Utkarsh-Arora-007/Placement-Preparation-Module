// Implement Stack using 1 queue:
// Below is the idea to solve the problem:

// Using only one queue and make the queue act as a Stack in modified way of the above discussed approach.

// Follow the below steps to implement the idea: 

// The idea behind this approach is to make one queue and push the first element in it. 
// After the first element, we push the next element and then push the first element again and finally pop the first element. 
// So, according to the FIFO rule of the queue, the second element that was inserted will be at the front and then the first element as it was pushed again later and its first copy was popped out. 
// So, this acts as a Stack and we do this at every step i.e. from the initial element to the second last element, and the last element will be the one that we are inserting and since we will be pushing the initial elements after pushing the last element, our last element becomes the first element.


// Below is the implementation for the above approach:

#include <bits/stdc++.h>
using namespace std;
 
// Stack Class that acts as a queue
class Stack {
 
    queue<int> q;
 
public:
    void push(int data);
    void pop();
    int top();
    int size();
    bool empty();
};
 
// Push operation
void Stack::push(int data)
{
    //  Get previous size of queue
    int s = q.size();
 
    // Push the current element
    q.push(data);
 
    // Pop all the previous elements and put them after
    // current element
 
    for (int i = 0; i < s; i++) {
        // Add the front element again
        q.push(q.front());
 
        // Delete front element
        q.pop();
    }
}
 
// Removes the top element
void Stack::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}
 
// Returns top of stack
int Stack::top() { return (q.empty()) ? -1 : q.front(); }
 
// Returns true if Stack is empty else false
bool Stack::empty() { return (q.empty()); }
 
int Stack::size() { return q.size(); }
 
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "current size: " << st.size() << "\n";
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    cout << "current size: " << st.size();
    return 0;
}


