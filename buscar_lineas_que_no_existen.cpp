#include <iostream>
#include <fstream> 

using namespace std;
/*
 * Programa que recibe un archivo de texto y lo comparara línea 
 * por línea con otro archivo de texto.
 * 
 * Principal utilidad: Busca si cada línea del primer archivo existe en el segundo archivo y en caso de no existir la imprime.
 * De esta forma conseguimos obtener la lista en la salida de las líneas que no se repiten.
 */

int main(int argc, char ** argv) {

    if(argc != 3) {
        cout << "Error argumentos: <fichero1><fichero2>" << endl;
        exit(0);
    }


    ifstream File1;
    File1.open(argv[1]);
    if (File1.fail()) {
        cout << "Error al abrir el archivo 1" << endl;
        exit(1);
    }
  

    while (!File1.eof()) {
        bool encontrado = false;
        string a, b;
        getline(File1, a);

        ifstream File2;
        File2.open(argv[2]);
        if (File2.fail()) {
            cout << "Error al abrir el archivo 2" << endl;
            exit(1);
        }

        while (!File2.eof()) {
            getline(File2, b);
            if(a == b) {
                encontrado = true;
            }
        }
        File2.close();
        
        if (!encontrado) {
            cout << "Línea: " << a << endl;
        }
    }


    File1.close();
    

}