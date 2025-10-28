#include "EnvironmentInitializer.h"

EnvironmentInitializer::EnvironmentInitializer(string envFilePath) : envFilePath(envFilePath) {}

void EnvironmentInitializer::initEnv()
{
    ifstream f;
    f.open(envFilePath);
    if (!f.is_open()) {
        throw invalid_argument("Could not open file");
    }

    string line;
    while (getline(f, line)) {
    cout << "here" << endl;

        size_t pos = line.find('='); // std::string.find returns size_t

        if (pos != string::npos) { // If substr not found std::string::npos flag is set to true
            const string key = line.substr(0, pos);
            const string value = line.substr(pos + 1);
            if (setenv(&key[0], &value[0], 1) != 0) { // setenv C function, takes in const char*
                throw invalid_argument("setenv failed");
            }  
        } else {
            throw invalid_argument("Could not find `=` in env line");    
        }
    }

    f.close();
}