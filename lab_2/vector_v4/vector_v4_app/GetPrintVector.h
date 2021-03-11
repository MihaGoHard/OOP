#pragma once
#include <iostream>
#include <optional>
#include <vector>
#include <iomanip>  

std::optional<std::vector<double>> GetVectorFromStream(std::istream& inputStream);
void PrintVector(const std::vector<double>& numVector);