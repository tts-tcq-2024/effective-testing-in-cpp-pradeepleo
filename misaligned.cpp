#include <iostream>
#include <assert.h>
#include <iomanip>

std::make_pair getColorPair(const char* majorColor, const char* minorColor);
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

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(getColorPair(0) == std::make_pair("White", "Blue"));
    assert(getColorPair(12) == std::make_pair("Black", "Green"));
    assert(getColorPair(24) == std::make_pair("Violet", "Slate"));
    std::cout << "All is well (maybe!)\n";
    return 0;
}
