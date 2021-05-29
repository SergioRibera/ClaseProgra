#include <exception>
#include <iostream>
#include <fstream>
#include "ManageData.h"

using namespace std;

ManageData::ManageData(string name){
    nameFile = name;
}
ManageData::~ManageData(){
    CloseFiles();
}
void ManageData::CloseFiles(){
    writeFile.close();
    readFile.close();
}

void ManageData::Save(string data){
    CloseFiles();
    writeFile.open(nameFile);
    if (writeFile.is_open())
        writeFile << data;
    else
        cout << "No se pudo leer el archivo \""<< nameFile << "\"" << endl;
}
string ManageData::Load(){
    CloseFiles();
    readFile.open(nameFile);
    string allText = "", line = "";
    if (readFile.is_open())
        while (getline(readFile, line))
            allText += line + '\n';
    else {
        cout << "No se pudo leer el archivo \""<< nameFile << "\"" << endl;
        return "";
    }
    return allText;
}
