#include <iostream>
#include <Windows.h>
#include <vector>
#include <utility>
#include <fstream>
//#include "Form_1.h"
#include <msclr\marshal_cppstd.h>
#include <string>

void filling(std::vector <std::pair <int, int> >& cursor) {
	POINT point;
	POINT tmp;
	while (true) {
		GetCursorPos(&point);
		GetCursorPos(&tmp);
		if (point.x - tmp.x != 0 && point.y - point.x != 0)
			break;
	}
	while (true) {
		GetCursorPos(&point);
		cursor.insert(cursor.begin(), std::make_pair(point.x, point.y));
		cursor.resize(150);
		Sleep(10);
		if (cursor[149].first != -1) {
			//Beep(2000, 400);
			return;
		}
	}
	return;
}

void moving(std::vector <std::pair <int, int> >& cursor) {
	int counter_x(10000), counter_y(10000);

	for (int i = 0; i < 150; ++i) {
		if (cursor[i].first < counter_x && cursor[i].first != -1)
			counter_x = cursor[i].first;
		if (cursor[i].second < counter_y && cursor[i].second != -1)
			counter_y = cursor[i].second;
	}
	for (int i = 0; i < 150; ++i) {
		cursor[i].first -= floor(counter_x) - 1;
		cursor[i].second -= floor(counter_y) - 1;
	}

}

void multimpicating(std::vector <std::pair <int, int> >& cursor) {
	double mult_coeff = 0.00000001;
	for (int i = 0; i < 150; ++i) {
		if (double(cursor[i].first) / double(100) > mult_coeff && cursor[i].first / 100 > 0)
			mult_coeff = double(cursor[i].first) / double(98);
		if (double(cursor[i].second) / double(100) > mult_coeff && cursor[i].second / 100 > 0)
			mult_coeff = double(cursor[i].second) / double(98);
	}
	for (int i = 0; i < 150; ++i) {
		cursor[i].first /= mult_coeff;
		cursor[i].second /= mult_coeff;
	}
}

void precedencing(std::vector <std::pair <int, int> >& cursor, std::string& path) {

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
	std::ofstream fout(path, std::ios_base::out);
	std::cout << "Add a description" << std::endl;//////////////////////

	//std::cin.ignore();
	std::string description;
	//description = msclr::interop::marshal_as<std::string>(textBox2->Text);
	getline(std::cin, description);
	fout << description << std::endl;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			fout << proh[i][j] << " ";
		fout << std::endl;
	}

	fout.close();
}

void increasing(std::vector <std::pair <int, int> >& cursor) {		//заполняем пропуски, делая сплошную линию
	while (true) {
		bool answer = true;
		for (int i = 0; i < cursor.size() - 1; ++i) {
			if (abs(cursor[i].first - cursor[i + 1].first) > 1 || abs(cursor[i].second - cursor[i + 1].second) > 1) {
				cursor.insert(cursor.begin() + i + 1, std::make_pair((cursor[i].first + cursor[i + 1].first) / 2, (cursor[i].second + cursor[i + 1].second) / 2));
				++i;
				answer = false;
			}
		}
		if (answer)
			return;
	}
}

int obt(std::string path = "C:\\1.txt") {
	std::vector <std::pair <int, int> > cursor;
	if (!GetKeyState(VK_LBUTTON) & 0x8000)
		return 0;
	for (int i = 0; i < 150, GetKeyState(VK_LBUTTON) & 0x8000; ++i)
		cursor.push_back(std::make_pair(-1, -1));

	filling(cursor);
	moving(cursor);
	multimpicating(cursor);

	for (int i = 0; i < 150; ++i) {
		if (cursor[i].first > 100 || cursor[i].second > 100) {
			multimpicating(cursor);
			i = 0;
		}
	}
	increasing(cursor);
	precedencing(cursor, path);
	return 1;
}