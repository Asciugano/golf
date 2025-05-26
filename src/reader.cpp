#include "reader.h"

std::string Reader::GetFile(std::string path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Errore nell'apertura del file!" << std::endl;
        return NULL;
    }

    std::string res = "";
    std::string riga = "";
    while (std::getline(file, riga))
    {
        res += riga;
    }

    file.close();
    return res;
}