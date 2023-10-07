
#include <cstdint>
#include <iostream>

int main() {
  uint32_t intValue = 123456; // Replace with your integer value

  // Create a byte array of size 32 to store the integer as bytes
  uint8_t byteArray[32];

  // Copy the integer value into the byte array
  for (int i = 0; i < 32; ++i) {
    byteArray[i] = (intValue >> (i * 8)) & 0xFF;
  }

  // Now, byteArray contains the integer as a byte array
  // You can access byteArray to work with the individual bytes

  // For example, print the bytes in hexadecimal format
  for (int i = 0; i < 32; ++i) {
    std::cout << std::dec << static_cast<int>(byteArray[i]) << " ";
  }
  std::cout << std::dec << std::endl;

  // Convert the byte array back to an integer
  uint32_t intValueReconstructed = 0;

  // uint8_t byteArray2[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  //                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  //
  for (int i = 0; i < 32; ++i) {
    intValueReconstructed |= static_cast<uint32_t>(byteArray[i]) << (i * 8);
  }

  std::cout << "Integer value: " << intValueReconstructed << std::endl;

  return 0;
}
