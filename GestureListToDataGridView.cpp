#include "GestureListToDataGridView.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <array>
#include <string>

void gestureListToTable(std::array <std::pair <std::string, std::string>, 10 > &gestureData, std::array <int, 10> &playSound) {

	std::string data1, data2;


	for (int i = 1; i < 11; ++i) {
		std::string filePath = "C:\\MouseController\\G";
		filePath += std::to_string(i);
		filePath += ".txt";
		std::ifstream fin(filePath);
		getline(fin, data1);
		getline(fin, data2);
		fin >> playSound[i - 1];
		gestureData[i - 1] = std::make_pair(data1, data2);
		fin.close();
	}
	
	std::ifstream finl("C:\\MouseController\\GestureList.txt");
	std::string tmp;
	for (int i = 0; i < 10; ++i) {
		finl >> tmp;
		if (tmp == "NO") {
			gestureData[i].first = "";
			gestureData[i].second = "";
			playSound[i] = 0;
		}

	}
	finl.close();
}