#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cassert>

#include "core.h"

using namespace std;

void PrintOutput_32F(const char* pRequest, void* pData, void* &pOutput, int N) {
    cout << pRequest << ":";
    if (pOutput == nullptr) {
        cout << " error\n";
        return;
    }
    float *pF = (float*)pOutput;
    for (int i = 0; i < N; ++i) {
        cout << ' ' << *pF++;
    }
    cout << '\n';
}

int main() {
    Initialization();

    void*   pData = nullptr;
    void*   pOutput = nullptr;
    int     N;

    LoadData("diabetes.csv", pData);

    cout << fixed << setprecision(5);
    string req;
    while (true) {
        req = "";
        getline(cin, req);
        if (cin.bad()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (req == "Exit") {
            //clog << "Exit\n";
            break;
        }
        ProcessRequest(req.data(), pData, pOutput, N);
        if (strncmp(req.data(), "CR", 2) == 0 && req.size() == 2) {
            PrintOutput(req.data(), pData, pOutput, 1);
            delete (int*)pOutput;
        }
        else if (strncmp(req.data(), "DI ", 3) == 0) {
            PrintOutput_32F(req.data(), pData, pOutput, N);
            delete (float*)pOutput;
        }
        else if (req.compare(0, 3, "HI ") == 0) {
            PrintOutput(req.data(), pData, pOutput, N);
            delete (int*)pOutput;
        }
        else if (req.compare(0, 2, "FR") == 0) {
            PrintOutput(req.data(), pData, pOutput, N);
            delete (int*)pOutput;
        }
        else {
            // do nothing
        }
        pOutput = nullptr;
    }

    ReleaseData(pData);
    Finalization();
    return 0;
}
