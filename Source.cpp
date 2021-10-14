#include <iostream>
#include <Windows.h>
#include <vector>
#include <utility>
#include <fstream>
#include <string>

int ret() {
	std::vector<int> vect;
	return 0;

}

/*
void filling() {
	POINT point; std::vector <std::pair <int, int> > cursor;
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

void obt(std::string path, std::vector <std::pair <int, int> > &cursor) {
	for (int i = 0; i < 150; ++i) {
		if (!GetKeyState(VK_LBUTTON) & 0x8000)
			break;
		cursor.push_back(std::make_pair(-1, -1));
	}

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
}
*/