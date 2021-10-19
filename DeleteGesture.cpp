#include "DeleteGesture.h"
#include <fstream>
#include <iostream>
#include <string>

void deleteGesture(int gestureNumber) {
	std::ifstream fin("C:\\MouseController\\GestureList.txt");
	std::string gestureList[10];

	for (int i = 0; i < 10; ++i)
		fin >> gestureList[i];

	fin.close();
	gestureList[gestureNumber] = "NO";

	std::ofstream fout("C:\\MouseController\\GestureList.txt");
	for (int i = 0; i < 10; ++i)
		fout << gestureList[i] << std::endl;
	fout.close();

}