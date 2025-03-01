#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        throw runtime_error("Invalid Arguments");
    }
    cout << "FileName: " << argv[1];

    string fileName = argv[1];
    ifstream file(fileName);
    if (!file)
    {
        cerr << "Error: No such file found: " << argv[1] << endl;
        return 1;
    }

    char word;
    long count = 0;
    while (file >> word)
    {
        ++count;
    }

    cout << "Count: " << count << endl;

    file.close();
    return 0;
}