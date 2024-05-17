#include <iostream>
#include <sstream>
#include <vector>

using std::pair, std::vector;

class DotRun {
 private:
  std::pair<double, double> current_position{0, 0};
  std::vector<pair<double, double>> history;

 public:
  DotRun& go_w(double distance) {
    history.push_back(pair<double, double>{-distance, 0});
    current_position.first -= distance;
    return *this;
  }

  DotRun& go_e(double distance) {
    history.push_back(pair<double, double>{distance, 0});
    current_position.first += distance;
    return *this;
  }

  DotRun& go_n(double distance) {
    history.push_back(pair<double, double>{0, distance});
    current_position.second += distance;
    return *this;
  }

  DotRun& go_s(double distance) {
    history.push_back(pair<double, double>{0, -distance});
    current_position.second -= distance;
    return *this;
  }

  DotRun& go_r(double x) {
    std::pair<double, double> initial_position{x, 0};
    history.push_back(pair<double, double>{x, 0});
    current_position.first += x;
    print_position();
    return *this;
  }

  DotRun& rev(int value) {
    if (history.empty()) {
      std::cout << "No history to reverse" << std::endl;
      return *this;
    }
    while (value > 0) {
      auto last = history.back();
      current_position.first -= last.first;
      current_position.second -= last.second;
      history.pop_back();
      value--;
    }
    return *this;
  }

  std::pair<double, double> get_position() const { return current_position; }
  void print_position() const {
    std::cout << "Current position: (" << current_position.first << ", "
              << current_position.second << ")" << std::endl;
  }
};

#include <iostream>
#include <string>

int main() {
  std::string line;
  DotRun dot_run;
  std::string command;
  double value;

  std::cout
      << "Enter commands (GOW, `GOE, `GON, GOS, GOW, REV) and distance (e.g. "
         "GOW 10):"
      << std::endl;
  while (std::getline(std::cin, line)) {
    std::cout << "You entered: " << line << std::endl;
    if (line == "") {
      dot_run.print_position();
      return 0;
    }

    std::istringstream stream(line);
    stream >> command >> value;
    if (command == "GOW") {
      dot_run.go_w(value);
    } else if (command == "GOE") {
      dot_run.go_e(value);
    } else if (command == "GON") {
      dot_run.go_n(value);
    } else if (command == "GOS") {
      dot_run.go_s(value);
    } else if (command == "REV") {
      dot_run.rev(value);
    } else if (command == "GOR") {
      dot_run.go_r(value);
    } else {
      std::cout << "Invalid command" << std::endl;
    }
    dot_run.print_position();
  }

  return 0;
}