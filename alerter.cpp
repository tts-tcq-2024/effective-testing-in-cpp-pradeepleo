#include <iostream>
#include <assert.h>

int alertFailureCount = 0;
bool mockNetworkFailure = false;
int failureOccured = 0;

typedef int (*NetworkAlertFunc)(float);// to use the same code in Production without much changes. 


int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(mockNetworkFailure){ 
        failureOccured += 1;
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit, NetworkAlertFunc networkAlert) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

void testAlertFailureCount(){
    mockNetworkFailure = false;
    alertInCelcius(400.5,networkAlertStub);
    assert(alertFailureCount == failureOccured);
      

     mockNetworkFailure = true;
    alertInCelcius(303.6,networkAlertStub);
    assert(alertFailureCount == failureOccured);    

    mockNetworkFailure = true;
    alertInCelcius(320.6,networkAlertStub);
    assert(alertFailureCount == failureOccured);

}


int main() {
    testAlertFailureCount();

    std::cout << "All is well (maybe!)\n";
    return 0;
}
