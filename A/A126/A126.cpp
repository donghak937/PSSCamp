#include <iostream>

int count(int n) {
	int hansu = 0;
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		if (i < 100) hansu++;
		else if (i < 1000) {
			a = i % 10;					//일의 자리
			b = (((i % 100) - a) / 10); //십의 자리
			c = i / 100;				//백의 자리

			if ((a + c) / (float)2 == (float)b) {
				hansu++;
			}
		}
	}
	return hansu;
}

int main() {
	int a = 0; 
	cin >> a;
	cout << count(a);
}