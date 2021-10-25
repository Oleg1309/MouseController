#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <string>
#include <utility>
#include "GestureToFile.h"

void precedencing(std::vector <std::pair <int, int> >& cursor, std::string& path, std::string &filepath, std::string& description, bool playSound) {

	int proh[100][100];
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			proh[i][j] = 0;

	for (int i = 0; i < cursor.size(); ++i) {
		proh[cursor[i].first][cursor[i].second] = 10;
	}

	proh[99][0] = 0;
	for (int z = 18; z > 0; z--) {

		std::vector <std::pair<int, int> > tmp;
		for (int i = 1; i < 99; ++i) {
			for (int j = 1; j < 99; ++j) {
				if (proh[i + 1][j] != 0 || proh[i][j + 1] != 0 || proh[i - 1][j] != 0 || proh[i][j - 1] != 0)
					tmp.push_back(std::make_pair(i, j));
			}
		}

		for (int i = 1; i < 99; ++i)
			if (proh[i + 1][0] != 0 || proh[i - 1][0] != 0)
				tmp.push_back(std::make_pair(i, 0));
		for (int i = 1; i < 99; ++i)
			if (proh[i + 1][99] != 0 || proh[i - 1][99] != 0)//
				tmp.push_back(std::make_pair(i, 100));
		for (int j = 1; j < 99; ++j)
			if (proh[0][j + 1] != 0 || proh[0][j - 1] != 0)
				tmp.push_back(std::make_pair(0, j));
		for (int j = 1; j < 99; ++j)
			if (proh[99][j + 1] != 0 || proh[99][j - 1] != 0)
				tmp.push_back(std::make_pair(100, j));
		for (int i = 0; i < tmp.size(); ++i) {
			if (proh[tmp[i].first][tmp[i].second] == 0) {
				if (z >= 15)
					proh[tmp[i].first][tmp[i].second] = 10;
				else if (z >= 12)
					proh[tmp[i].first][tmp[i].second] = 9;
				else if (z >= 10)
					proh[tmp[i].first][tmp[i].second] = 8;
				else if (z >= 8)
					proh[tmp[i].first][tmp[i].second] = 7;
				else if (z >= 6)
					proh[tmp[i].first][tmp[i].second] = 6;
				else if (z >= 5)
					proh[tmp[i].first][tmp[i].second] = 5;
				else if (z >= 4)
					proh[tmp[i].first][tmp[i].second] = 4;
				else if (z >= 3)
					proh[tmp[i].first][tmp[i].second] = 3;
				else if (z >= 2)
					proh[tmp[i].first][tmp[i].second] = 2;
				else
					proh[tmp[i].first][tmp[i].second] = 1;
			}
		}
		tmp.clear();
	}
	/*
	HDC hdc_ = GetDC(GetDesktopWindow());
	while (true) {
		for (int z = 1; z <= 15; ++z) {
			for (int h = 0; h < 100; ++h) {
				for (int i = 0; i < 100; ++i) {
					for (int j = 0; j < 100; ++j) {

						if (proh[i][j] == z)
							SetPixel(hdc_, i + 300, j + 300, 255);
					}

				}
			}
		}
		break;
	}
	*/
	std::ofstream fout(filepath, std::ios_base::out);
	//std::cout << "Add a description" << std::endl;
	//std::cin.ignore();
	//std::string description;
	//getline(std::cin, description);
	fout << description << std::endl;
	fout << path << std::endl;
	if (playSound)
		fout << "1" << std::endl;
	else
		fout << "0" << std::endl;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			fout << proh[i][j] << " ";
		fout << std::endl;
	}

	fout.close();
	//std::cout << "SUCCESS!";
}
