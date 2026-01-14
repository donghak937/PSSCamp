#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<string> phone_book = {"119", "97674223", "1195524421"};

    sort(phone_book.begin(), phone_book.end());

    for(int i = 0; i < phone_book.size()-1; i++){
        if (phone_book[i+1].rfind(phone_book[i], 0) == 0) return false;   
    }

    return true;


}