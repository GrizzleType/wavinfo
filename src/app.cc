# include <fstream>
# include <iostream>

int main(int argc, char* args[])
{
    std::ifstream file(args[1]);
    if ( !file.is_open() )
    {
        std::cerr << ("File could not be opened");
        return 1;
    }
    
    {
        char block[4];
        file.read(block, 4);
        
        if ( strncmp(block, "RIFF", 4) != 0 )
        {
                std::cerr << ("File is not WAV!!!");
        }
    }

    file.seekg(12, std::ios::beg);

    {
        char block[4];

        int fmt;

        do
        {
            file.read(block, 4);
            fmt = strncmp(block, "fmt ", 4);
        }
        while (fmt != 0);
    }
}