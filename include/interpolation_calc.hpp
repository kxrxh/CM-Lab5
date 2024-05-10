#ifndef DCD448C5_F0B2_4DE4_A579_7D0F39BFBF30
#define DCD448C5_F0B2_4DE4_A579_7D0F39BFBF30

#include <cmath>
#include <functional>
#include <numeric>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * @brief Class for calculating interpolation using various methods.
 */
class IntepolationCalculator {
public:
  /**
   * @brief Enum for different interpolation methods.
   */
  enum InterpolationMethod {
    Lagrange,        ///< Lagrange interpolation method.
    NewtonSeparated, ///< Newton's divided differences method (separated).
    NewtonFinite, ///< Newton's divided differences method (finite differences).
    Stirling,     ///< Stirling interpolation method.
    Bessel        ///< Bessel interpolation method.
  };

  static std::string method_to_string(InterpolationMethod method) {
    switch (method) {
      {
      case Lagrange:
        return "Lagrange";
      case NewtonSeparated:
        return "Newton Separated";
      case NewtonFinite:
        return "Newton Finite";
      case Stirling:
        return "Stirling";
      case Bessel:
        return "Bessel";
      default:
        return "Unknown";
      }
    }
  }

private:
  InterpolationMethod method; ///< The interpolation method to use.
  std::vector<double> x, y;   ///< Data points (x, y).

  /**
   * @brief Calculates the differences for interpolation.
   * @return Vector of differences.
   */
  std::vector<double> differences() const {
    std::vector<double> diff = y;
    for (int i = 1; i < y.size(); i++) {
      for (int j = static_cast<int>(y.size()) - 1; j >= i; j--) {
        diff[j] = (diff[j] - diff[j - 1]) / (x[j] - x[j - i]);
      }
    }
    return diff;
  }

  /**
   * @brief Calculates the Lagrange interpolation function.
   * @return Lagrange interpolation function.
   */
  std::function<double(double)> lagrange() const {
    return [this](double v) {
      double sum = 0;
      for (int i = 0; i < y.size(); i++) {
        double prod = 1;
        for (int j = 0; j < y.size(); j++) {
          if (i != j) {
            prod *= (v - x[j]) / (x[i] - x[j]);
          }
        }
        sum += y[i] * prod;
      }
      return sum;
    };
  }

  /**
   * @brief Calculates the Newton (separated) interpolation function.
   * @return Newton (separated) interpolation function.
   */
  std::function<double(double)> newton_separated() const {
    std::vector<double> diff = differences();

    return [this, diff](double v) {
      double sum = diff.front();
      for (int i = 1; i < x.size(); i++) {
        double prod = 1;
        for (int j = 0; j < i; j++) {
          prod *= (v - x[j]);
        }

        sum += diff[i] * prod;
      }
      return sum;
    };
  }

  /**
   * @brief Calculates the Newton (finite differences) interpolation function.
   * @return Newton (finite differences) interpolation function.
   */
  std::function<double(double)> newton_finite() const {
    int n = x.size() - 1;
    std::vector<std::vector<double>> defy = difference_table();

    return [this, n, defy](double v) {
      double result = defy.front().front();
      double term = 1;

      for (int i = 1; i <= n; i++) {
        term *= v - x[i - 1];
        result += term * defy.front()[i] / factorial(i);
      }

      return result;
    };
  }

  /**
   * @brief Calculates the Stirling interpolation function.
   * @return Stirling interpolation function.
   */
  std::function<double(double)> stirling() const {
    int n = x.size() - 1;
    int center = n / 2;
    double a = x[center];
    std::vector<std::vector<double>> defy = difference_table();

    return [this, n, center, a, defy](double v) {
      double h = x[center + 1] - x[center];
      double t = (v - a) / h;

      double result = defy[center].front() +
                      t * (defy[center - 1][1] + defy[center][1]) / 2 +
                      std::pow(t, 2) / 2 * defy[center - 1][2];
      double term = std::pow(t, 2) / 2;

      for (int k = 3; k < n; k++) {
        if (k % 2 == 0) {
          term *= t / k;
          result += term * defy[center - k / 2][k];
        } else {
          term *= (std::pow(t, 2) - std::pow(k / 2, 2)) / (k * t);
          result += term *
                    (defy[center - k / 2 - 1][k] + defy[center - k / 2][k]) / 2;
        }
      }

      return result;
    };
  }

  /**
   * @brief Calculates the Bessel interpolation function.
   * @return Bessel interpolation function.
   */
  std::function<double(double)> bessel() const {
    int n = x.size() - 1;
    int center = n / 2;
    double a = x[center];

    std::vector<std::vector<double>> defy = difference_table();

    return [this, n, center, a, defy](double v) {
      double h = x[center + 1] - x[center];
      double t = (v - a) / h;
      double result =
          (defy[center].front() + defy[center + 1].front()) / 2 +
          (t - 0.5) * defy[center][1] +
          t * (t - 1) / 2 * (defy[center - 1][2] + defy[center][2]) / 2;
      double term = t * (t - 1) / 2;

      for (int k = 3; k <= n; k++) {
        if (k % 2 == 0) {
          term /= t - 0.5;
          term *= (t + ((k / 2.0 - 1))) * (t - (k / 2.0)) / k;
          result += term *
                    (defy[center - 1 - (k / 2 - 1)][k] +
                     defy[center - (k / 2 - 1)][k]) /
                    2;
        } else {
          term *= (t - 0.5) / k;
          result += term * defy[center - k / 2][k];
        }
      }

      return result;
    };
  }

  std::string lagrange_latex() const {
    std::vector<std::string> terms;

    for (int i = 0; i < this->x.size(); i++) {
      std::vector<std::string> term_parts;
      for (int j = 0; j < this->x.size(); j++) {
        if (i != j) {
          term_parts.push_back("(x - " + std::to_string(x[j]) + ")");
        }
      }

      std::string term;
      if (!term_parts.empty()) {
        term =
            std::to_string(y[i]) + " * " +
            std::accumulate(term_parts.begin(), term_parts.end(), std::string(),
                            [](const std::string &a, const std::string &b) {
                              return a.empty() ? b : a + " * " + b;
                            });
      } else {
        term = std::to_string(y[i]);
      }

      terms.push_back(term);
    }

    return std::accumulate(terms.begin(), terms.end(), std::string(),
                           [](const std::string &a, const std::string &b) {
                             return a.empty() ? b : a + " + " + b;
                           });
  }
  std::string newton_separated_latex() const {
    std::vector<double> diff(y);
    for (int i = 1; i < static_cast<int>(y.size()); i++) {
      for (int j = static_cast<int>(y.size()) - 1; j >= i; j--) {
        diff[j] = (diff[j] - diff[j - 1]) / (x[j] - x[j - i]);
      }
    }

    std::vector<std::string> terms = {std::to_string(diff[0])};

    for (int i = 1; i < static_cast<int>(x.size()); i++) {
      std::vector<std::string> term_parts;
      for (int j = 0; j < i; j++) {
        term_parts.push_back("(x - " + std::to_string(x[j]) + ")");
      }

      std::string term =
          std::to_string(diff[i]) + " * " +
          std::accumulate(term_parts.begin(), term_parts.end(), std::string(),
                          [](const std::string &a, const std::string &b) {
                            return a.empty() ? b : a + " * " + b;
                          });
      terms.push_back(term);
    }

    return std::accumulate(terms.begin(), terms.end(), std::string(),
                           [](const std::string &a, const std::string &b) {
                             return a.empty() ? b : a + " + " + b;
                           });
  }
  std::string newton_finite_latex() const {
    std::vector<double> diff(y);
    for (int i = 1; i < static_cast<int>(y.size()); i++) {
      for (int j = static_cast<int>(y.size()) - 1; j >= i; j--) {
        diff[j] = (diff[j] - diff[j - 1]) / (x[j] - x[j - i]);
      }
    }

    std::vector<std::string> terms = {std::to_string(diff[0])};

    for (int i = 1; i < static_cast<int>(x.size()); i++) {
      std::vector<std::string> term_parts;
      for (int j = 0; j < i; j++) {
        term_parts.push_back("(x - " + std::to_string(x[j]) + ")");
      }

      std::string term =
          std::to_string(diff[i]) + " * " +
          std::accumulate(term_parts.begin(), term_parts.end(), std::string(),
                          [](const std::string &a, const std::string &b) {
                            return a.empty() ? b : a + " * " + b;
                          });
      terms.push_back(term);
    }

    return std::accumulate(terms.begin(), terms.end(), std::string(),
                           [](const std::string &a, const std::string &b) {
                             return a.empty() ? b : a + " + " + b;
                           });
  }

public:
  /**
   * @brief Calculates the difference table for interpolation.
   * @return Difference table.
   */
  std::vector<std::vector<double>> difference_table() const {
    std::vector<std::vector<double>> defy(y.size(),
                                          std::vector<double>(y.size(), 0));

    for (int i = 0; i < y.size(); i++) {
      defy[i][0] = y[i];
    }

    for (int i = 1; i < y.size(); i++) {
      for (int j = 0; j < y.size() - 1; j++) {
        defy[i][j] = defy[j + 1][i - 1] - defy[j][i - 1];
      }
    }

    return defy;
  }
  /**
   * @brief Constructs an InterpolationCalculator object.
   * @param method The interpolation method to use.
   * @param x The x-coordinates of the data points.
   * @param y The y-coordinates of the data points.
   */
  IntepolationCalculator(InterpolationMethod method,
                         const std::vector<double> &x,
                         const std::vector<double> &y)
      : method(method), x(x), y(y) {}

  /**
   * @brief Gets the data points used for interpolation.
   * @return Vector of vectors representing the data points (x, y).
   */
  std::vector<std::pair<double, double>> get_nodes() const {
    std::vector<std::pair<double, double>> result;
    for (int i = 0; i < x.size(); i++) {
      result.push_back({x[i], y[i]});
    }
    return result;
  }

  /**
   * @brief Interpolates the function.
   * @return Interpolated function.
   */
  std::function<double(double)> interpolate() const {
    switch (method) {
    case IntepolationCalculator::InterpolationMethod::Lagrange:
      return lagrange();
    case IntepolationCalculator::InterpolationMethod::NewtonFinite:
      return newton_finite();
    case IntepolationCalculator::InterpolationMethod::NewtonSeparated:
      return newton_separated();
    case IntepolationCalculator::InterpolationMethod::Stirling:
      return stirling();
    case IntepolationCalculator::InterpolationMethod::Bessel:
      return bessel();
    default:
      throw std::invalid_argument("Unknown interpolation method");
    }
  }

  std::string to_latex() const {
    switch (method) {
    case IntepolationCalculator::InterpolationMethod::Lagrange:
      return this->lagrange_latex();
    case IntepolationCalculator::InterpolationMethod::NewtonSeparated:
      return this->newton_separated_latex();
    case IntepolationCalculator::InterpolationMethod::NewtonFinite:
      return this->newton_finite_latex();
    default:
      return "Unknown";
    }
  }

  /**
   * @brief Calculates the factorial of a number.
   * @param x The number.
   * @return The factorial of x.
   */
  static double factorial(double x) {
    double f = 1;
    for (int i = 1; i <= static_cast<int>(x); i++) {
      f *= i;
    }
    return f;
  }

  /**
   * @brief Generates function values for a given function within a range.
   * @param func The function.
   * @param start The start of the range.
   * @param end The end of the range.
   * @param nodes The number of nodes to generate.
   * @return A pair of vectors representing the x and y coordinates of the
   * generated function values.
   */
  static std::pair<std::vector<double>, std::vector<double>>
  generate_func_values(std::function<double(double)> func, double start,
                       double end, int nodes) {
    double step = (end - start) / (nodes - 1);

    std::vector<double> x(nodes), y(nodes);
    for (auto i = 0; i < nodes; i++) {
      double x_values = start + step * i;
      x[i] = x_values;
      y[i] = func(x_values);
    }
    return {x, y};
  }
};

#endif /* DCD448C5_F0B2_4DE4_A579_7D0F39BFBF30 */
