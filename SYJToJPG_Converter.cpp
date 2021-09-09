#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

const char JFIF_Header[] = "\xFF\xD8\xFF\xE0\x00\x10\x4A\x46\x49\x46";

void SYJToJPG(string file);

int main()
{
    string extension = ".syj";
    string path("./Textures");
    
    for (auto &p : fs::recursive_directory_iterator(path))
        if (p.path().extension() == extension)
            SYJToJPG(p.path());
}

void SYJToJPG(string file)
{
    ifstream input;
    ofstream output;

    input.open(file, ios::binary);
    string outputFile = fs::current_path().string() + file.substr(1, file.length() - 4) + "jpg";
    output.open(outputFile, ios::binary);

    output.write(JFIF_Header,10);
    output << input.rdbuf();

    input.close();
    output.close();

    fs::remove(file);
}