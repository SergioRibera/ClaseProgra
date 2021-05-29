#include <iostream>
#include <fstream>
#include <string.h>
#include "ManageData.h"

using namespace std;

const string NAMEFILE = "datos.dat";

struct DataExample {
    int regCode;
    string name;
    int age;
};

// DataExample => string
//
//      regCodigo|name|age\n
//      regCodigo|name|age\n
//
string SerializeData(DataExample datas[], int n){
    string output = "";
    for (size_t i = 0; i < n; i++) {
        output += to_string(datas[i].regCode) + "|";
        output += datas[i].name + "|";
        output += to_string(datas[i].age) + ";";
    }
    return output;
}
DataExample DeserializeDatas(string strData, int indexBuscar){
    cout << strData << endl;
    DataExample data;
    string strTmp;
    int indexValue = 0, currentIndex = -1;

    for (string::size_type i = 0; i < strData.size(); ++i){
        char c = strData[i];
        if(c != '|' || c != ';')
            strTmp += c;
        if (c == '|' || c == ';'){
            switch (indexValue) {
                case 0:
                    data.regCode = stoi(strTmp);
                    indexValue++;
                    strTmp = "";
                    break;
                case 1:
                    data.name = strTmp;
                    indexValue++;
                    strTmp = "";
                    break;
                case 2:
                    data.age = stoi(strTmp);
                    indexValue = 0;
                    currentIndex++;
                    strTmp = "";
                    break;
            }
            if (currentIndex == indexBuscar)
                break;
        }
    } 
    return data;
}

int main(int argc, const char** argv) {
    ManageData managerData(NAMEFILE);

    // Simulamos Escritura de datos
    DataExample userDatas[3];

    if (argc > 0){
        if (strcmp(argv[1], "l") == 0) {
            string dataFile = managerData.Load();

            if (dataFile == "") {
                cout << "The loaded data is empty" << endl;
                return 1;
            }
            for (int i = 0; i < 3; i++) {
                //int i = 1;
                DataExample loaded = DeserializeDatas(dataFile, i);
                //cout << i << endl;
                userDatas[i].regCode = loaded.regCode;
                userDatas[i].name = loaded.name;
                userDatas[i].age = loaded.age;
            }
            for (int i = 0; i < 3; i++) {
                cout << userDatas[i].regCode << " ";
                cout << userDatas[i].name << " ";
                cout << userDatas[i].age << endl;
            }
        } else {
            userDatas[0].name = "Alexis";
            userDatas[0].regCode = 100;
            userDatas[0].age = 19;
            userDatas[1].name = "Victor";
            userDatas[1].regCode = 101;
            userDatas[1].age = 19;
            userDatas[2].name = "Daniel";
            userDatas[2].regCode = 102;
            userDatas[2].age = 19;
            string serializableData = SerializeData(userDatas, 3);
            cout << "Datos Serializados:" << endl;
            cout << "Codigo | Nombre | Edad" << endl;
            cout << serializableData << endl;
            managerData.Save(serializableData);

            return 0;
        }
    } else {
        cout << "This program required one paramater" << endl;
        return 1;
    }
    return 1;
}

/*int main () {
//
//      Write File
//
ofstream myfile (NAMEFILE);
if (myfile.is_open()) {
myfile << "This is a line.\n";
myfile << "This is another line.\n";
myfile.close();
}
else
cout << "Unable to open file; Creating File";

//
//      Read File
//

ifstream readFile (NAMEFILE);
string line;
if (readFile.is_open()) {
while (getline(readFile, line))
cout << line << '\n';
readFile.close();
}
else cout << "Unable to open file"; 
return 0;
}*/
