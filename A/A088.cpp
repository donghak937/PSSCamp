#include <vector>

class MinStack {
    std::vector<int> real;
    std::vector<int> fake;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        real.push_back(val);
        if (fake.empty() || fake.back() >= val){
            fake.push_back(val);
        }
    }
    
    void pop() {
        if (real.back() == fake.back()) fake.pop_back();
        real.pop_back();
    }
    
    int top() {
        return real.back();
    }
    
    int getMin() {
        return fake.back();
    }
};