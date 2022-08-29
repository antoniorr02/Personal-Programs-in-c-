#include <iostream>
#include <fstream> 

using namespace std;
/*
 * Programa que recibe un archivo de texto y lo comparara línea 
 * por línea con otro archivo de texto.
 * 
 * Principal utilidad: Comparar respuestas con el archivo de las soluciones
 * en los ejercicio o preguntas tipo test.
 */

int main() {

    ifstream File1;
    ifstream File2;
    File1.open("archivo1.txt");
    File2.open("archivo2.txt");
    if (File1.fail() || File2.fail()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
  
    int cont = 0, linea = 0;

    cout << "Fallos: \n";

    while (!File1.eof() && !File2.eof()) {
        linea++;
        string a, b;
        getline(File1, a);
        getline(File2, b);
        if (a != b) {
            cont++;
            cout << "Pregunta: " << linea << endl;
        }
    }

    cout << endl << "Nº Preguntas: " << linea << endl;
    cout << "Nº Aciertos: " << linea - cont << endl;
    cout << "Nº Errores: " << cont << endl << endl;

    File1.close();
    File2.close();

}