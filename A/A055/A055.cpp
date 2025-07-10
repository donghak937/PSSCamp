#include <iostream>
using namespace std;

int main() {
    string answer = "";
    int i = 0;
    int left = 0;
    int right = 0;
    int leftPos = 0;
    int rightPos = 0;
    string s = "(()())(())";
    while(i < s.size()){
        if(s[i] == '('){
            left = 0;
            leftPos = i;

            do {
                if (s[i] == '(') left++;

                else right++; 

                #ifdef Debug
                cout << "left : " << left << " right : " << right << endl;
                #endif
                
                i++;
                
            } while (left != right);

            right = 0;
            left = 0;
            rightPos = i - 1;
        }

        #ifdef Debug
        cout << "leftPos : " << s[leftPos]  << " " << leftPos << " rightPos : " << s[rightPos] << " " << rightPos << endl;
        #endif

        s.erase(rightPos, 1);
        s.erase(leftPos, 1); 

        #ifdef Debug
        cout << s << endl;
        #endif

        i -= 2;
    }
    cout << "answer : " << s;
}