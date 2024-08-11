#include <iostream>
/**
 * Problem Input
        miles distance in miles
•   Problem Output
        kms distance in kilometers
• Algorithm will use Conversion Formula
1 mile = 1.609 kilometers
 */
#define CONVERTION 1.609  // preprocessor
int main() {
  float miles;
  constexpr float CONVERT = 1.609;  // compiler

  std::cout << "Please enter speed in miles\n";
  std::cin >> miles;
  std::cout << miles << std::endl;

  float kilometes = CONVERTION * miles;

  std::cout << kilometes << std::endl;
}