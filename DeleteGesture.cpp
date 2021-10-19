#include "DeleteGesture.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

void exchangeGestures(int gesture1, int gesture2) {

	std::string path1 = "C:\\MouseController\\G";
	path1 += std::to_string(gesture1 + 1);
	path1 += ".txt";

	std::string path2 = "C:\\MouseController\\G";
	path2 += std::to_string(gesture2 + 1);
	path2 += ".txt";

	int a = rename(path1.c_str(), "C:\\MouseController\\G0.txt");
	int b = rename(path2.c_str(), path1.c_str());
	int c = rename("C:\\MouseController\\G0.txt", path2.c_str());

}

void deleteGesture(int gestureNumber) {
	std::ifstream fin("C:\\MouseController\\GestureList.txt");
	std::string gestureList[10];

	for (int i = 0; i < 10; ++i)
		fin >> gestureList[i];

	fin.close();
	if (gestureNumber == 9)
		gestureList[gestureNumber] = "NO";
	else {
		int exchangedGesture = 0;
		for (int i = 9; i >= gestureNumber; --i) {
			if (i == gestureNumber) {
				gestureList[i] = "NO";
				break;
			}
			if (gestureList[i] == "YES") {
				exchangeGestures(gestureNumber, i);
				gestureList[i] = "NO";
				gestureList[gestureNumber] = "YES";
				break;
			}

		}
	}

	//gestureList[gestureNumber] = "NO";

	std::ofstream fout("C:\\MouseController\\GestureList.txt");
	for (int i = 0; i < 10; ++i)
		fout << gestureList[i] << std::endl;
	fout.close();

}