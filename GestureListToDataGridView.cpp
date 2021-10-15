#include "GestureListToDataGridView.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <array>
#include <string>

void gestureListToTable() {

	std::string data1, data2;
	
	std::array <std::pair <std::string, std::string>, 10 > gestureData;

	for (int i = 1; i < 11; ++i) {
		std::string filePath = "C:\\MouseController\\G";
		filePath += std::to_string(i);
		filePath += ".txt";
		std::ifstream fin(filePath);
		getline(fin, data1);
		getline(fin, data2);
		gestureData[i - 1] = std::make_pair(data1, data2);
		fin.close();
	}
}