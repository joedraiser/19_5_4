#include <iostream>
#include <fstream>

int main() {
    std::cout << "Input PNG file path: ";
    std::string PNGPath;
    std::cin >> PNGPath;

    std::ifstream PNGFile;

    PNGFile.open(PNGPath, std::ios::binary);



    if(!PNGFile.is_open())
    {
        std::cout << "File is not opened";
        exit(EXIT_FAILURE);
    }

    std::string extension=PNGPath.substr(PNGPath.size()-3, PNGPath.size()-1);
    for(int i=0;i<3;i++)
    {
        extension[i]=tolower(extension[i]);
    }

    if(extension!="png")
    {
        std::cout << "File has no png extension.";
        exit(EXIT_FAILURE);
    }

    char check[]={(char)(-119),'P', 'N', 'G'};
    char* temp=new char;

    for(int i=0;i<4&&!PNGFile.eof();i++)
    {
        PNGFile.read(temp, sizeof(char));
        if((*temp)!=check[i])
        {
            std::cout << "Invalid PNG file";
            exit(EXIT_FAILURE);
        }
    }

    std::cout << "It is proper PNG file";

    return 0;
}
