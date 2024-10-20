#include <iostream>
#include <assert.h>
#include <iomanip>


int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

std::pair<const char*, const char*> getColorPair(int colorNumber){
    //implement the logic and modify the return value.
    if(colorNumber <= 25 && colorNumber >= 0){
        return std::make_pair("MajorColor", "MinorColor");
    }
    return std::make_pair("Invalid", "Index");
}
// Test function to check expected color pairs
void testColorPair() {
    // Expected color pairs based on the index (index 0 -> White, Blue; index 24 -> Violet, Slate)
    assert(getColorPair(0) == std::make_pair("White", "Blue"));
    assert(getColorPair(1) == std::make_pair("White", "Orange"));
    assert(getColorPair(5) == std::make_pair("Red", "Blue"));
    assert(getColorPair(10) == std::make_pair("Black", "Blue"));
    assert(getColorPair(24) == std::make_pair("Violet", "Slate"));

     assert(getColorPair(240) == std::make_pair("Invalid", "Index"));
     assert(getColorPair(-24) == std::make_pair("Invalid", "Index"));
    std::cout << "All tests passed (but this should fail until the developer implements the function).\n";
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testColorPair();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
