#include <filesystem>
#include <iostream>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

void JPGToSYJ(string file);

int main()
{
    string extension = ".jpg";
    string path("./Textures");
    
    for (auto &p : fs::recursive_directory_iterator(path))
        if (p.path().extension() == extension)
            JPGToSYJ(p.path());
}

void JPGToSYJ(string file)
{
    ifstream input;
    ofstream output;

    input.open(file, ios::binary);
    string outputFile = fs::current_path().string() + file.substr(1, file.length() - 4) + "syj";
    output.open(outputFile, ios::binary);

    input.ignore(10);
    output << input.rdbuf();

    input.close();
    output.close();

    fs::remove(file);
}