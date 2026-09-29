#include <fstream>
#include <iostream>

using namespace std;

int main() {
  cout << "Day 1 - Secret Entrance\n";
  ifstream input("input.txt");
  string line;
  int dialActualPos = 50;
  int countZeros = 0;

  // dial has numbers from 0 to 99
  // if dialActualPosition, the cycle must start at zero in case of L and dial
  // at 0, must start counting from 99 if R
  // PART 2
  // we need to track how many times the dial passes at 0.

  while (getline(input, line)) {
    int d = stoi(line.substr(1));
    if (line[0] == 'R') {
      countZeros += (dialActualPos + d) / 100;
      dialActualPos = (dialActualPos + d) % 100;
    } else if (line[0] == 'L') {
      if (dialActualPos == 0) {
        countZeros += d / 100;
      } else if (d >= dialActualPos) {
        countZeros += 1 + (d - dialActualPos) / 100;
      }
      dialActualPos = (dialActualPos - d) % 100;
      if (dialActualPos < 0) {
        dialActualPos += 100;
      }
    }
  }
  input.close();
  cout << countZeros << '\n';
  return 0;
}
