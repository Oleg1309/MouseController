#pragma once
#ifndef GESTURETODATAGRIDVIEW_H
#define GESTURETODATAGRIDVIEW_H

#include <fstream>
#include <array>
#include <string>

void gestureListToTable(std::array <std::pair <std::string, std::string>, 10 > &gestureData, std::array <int, 10> &playSound);

#endif // !GESTURETODATAGRIDVIEW
