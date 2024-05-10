#ifndef CBB2EA86_08B9_4952_BF85_D67124FC4973
#define CBB2EA86_08B9_4952_BF85_D67124FC4973
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

struct ParsingResult {
  bool status = false;
  double firstValue = 0.0;
  std::vector<double> x_values;
  std::vector<double> y_values;
};

inline ParsingResult parse_file(const std::string &filename) {
  double firstValue;
  std::vector<double> x_values;
  std::vector<double> y_values;
  std::ifstream file(filename);
  if (!file.is_open()) {
    return ParsingResult{false, 0.0, {}, {}};
  }
  std::string line;
  // Read the first line separately to get the first value
  if (std::getline(file, line)) {
    std::istringstream iss(line);
    if (!(iss >> firstValue)) {
      return ParsingResult{false, 0.0, {}, {}};
    }
  } else {
    return ParsingResult{false, 0.0, {}, {}};
  }
  // Read the rest of the file for x and y values
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    double x, y;
    if (!(iss >> x >> y)) {
      return ParsingResult{false, 0.0, {}, {}};
    }
    x_values.push_back(x);
    y_values.push_back(y);
  }
  file.close();
  return ParsingResult{true, firstValue, x_values, y_values};
}

#endif /* CBB2EA86_08B9_4952_BF85_D67124FC4973 */
