#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

// Clase para manejo archivos
class FileManager{

    public:
        // Método para leer un archivo
        std::vector<std::string> readFile(const std::string &filename)
        {
            std::cout << "Leyendo el archivo: " << filename << std::endl;

            std::ifstream archive(filename.c_str());

            std::vector<std::string> data;

            if (archive.is_open())
            {
                std::string line;
                while (std::getline(archive, line))
                {
                    data.push_back(line);
                }
                archive.close();
            }
            else
            {
                std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            }

            return data;
        }

        // Método para guardar un archivo
        void saveFile(const std::string &filename, const std::vector<std::string> data)
        {
            std::cout << "Guardando datos en el archivo: " << filename << std::endl;

            std::ofstream outFile(filename);

            if (outFile.is_open())
            {
                for (const std::string &line : data)
                {
                    outFile << line << std::endl; // Escribir cada línea de datos en el archivo
                }
                outFile.close();
            }
            else
            {
                std::cerr << "Error al abrir el archivo: " << filename << std::endl;
            }
        }

        //Método para imprimir los datos
        void printData(const std::vector<std::string> &data)
        {
            // Código para imprimir los datos
            std::cout << "Imprimiendo datos" << std::endl;
            std::cout << "-----------------" << std::endl;
            std::cout << "Datos: " << std::endl;

            for (int i = 0; i < data.size(); ++i)
            {
                std::cout << data[i] << std::endl;
            }
            std::cout << "-----------------" << std::endl;
        }

        //Método para contar palabras
        int countWordsInText(const std::string &data)
        {   
            int count = 0;
            std::stringstream ss(data);
            std::string word;

            while (ss >> word)
            {
                count++;
            }

            return count;
        }
    };


class TextManipulator{
    public:
    //Método para imprimir los datos
        void printData(const std::vector<std::string> &data)
        {
            // Código para imprimir los datos
            std::cout << "Imprimiendo datos" << std::endl;
            std::cout << "-----------------" << std::endl;
            std::cout << "Datos: " << std::endl;

            for (int i = 0; i < data.size(); ++i)
            {
                std::cout << data[i] << std::endl;
            }
            std::cout << "-----------------" << std::endl;
        }

int countWordsInText(const std::string &data)
        {   
            int count = 0;
            std::stringstream ss(data);
            std::string word;

            while (ss >> word)
            {
                count++;
            }

            return count;
        }
      
};

using namespace std;

int main()
{
    FileManager fileManager;
    vector<string> data;
    string added;

    data = fileManager.readFile("datos.txt");
    fileManager.printData(data);

    cout << "Agregar al documento: " << endl;
    getline(cin, added);
    cout << "agregaste " << fileManager.countWordsInText(added) << " palabras" << endl;

    data.push_back(added);
    fileManager.saveFile("datosmodificados.txt", data);
    fileManager.printData(data);

    return 0;
}
