#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ManageData {
    private:
        string nameFile;
        // output file stream
        ofstream writeFile;
        // input file stream
        ifstream readFile;
        void CloseFiles();

    public:
        ManageData(string name);
        ~ManageData();
        void Save(string d);
        string Load();
};
