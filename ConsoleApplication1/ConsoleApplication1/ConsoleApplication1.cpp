#include <iostream>
#include <Windows.h>

int main() {
	Beep(1000, 1000);
	for (int i = 9000; i < 10000; i += 100)
		Beep(i, 500);
	return 0;
}