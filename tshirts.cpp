#include <iostream>
#include <assert.h>

char size(int shoulderSize_cms) {
    char sizeName = '\0';
    if(shoulderSize_cms < 38) {
        sizeName = 'S';
    } else if(shoulderSize_cms > 38 && shoulderSize_cms < 42) {
        sizeName = 'M';
    } else if(shoulderSize_cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    assert(size(38) != '\0'); 
    assert(size(42) == 'L');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
