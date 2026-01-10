#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main() {
    vector<int> numbers = {1, 1, 2, 2, 3, 4};
    int target = 2;
    vector<int> a;
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            a.push_back(left + 1);
            a.push_back(right + 1);
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
}
