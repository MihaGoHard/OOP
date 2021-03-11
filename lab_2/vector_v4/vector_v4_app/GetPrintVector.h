#pragma once
#include <iostream>
#include <optional>
#include <vector>
#include <iomanip>  

std::optional<std::vector<double>> GetVectorFromStream(std::istream& inputStream);
bool PrintVector(const std::vector<double>& numVector);