#include<iostream>
#include<fstream>
#include<set>

using namespace std;

/**
 * @brief Busca las líneas que se repiten en un mismo archivo e imprime ĺa posición de las que se repiten.
 *
 */

int main(int argc, char * argv[]) {

	if(argc != 2) {
		cout << "Error argumentos: <fichero>" << endl;
		exit(0);
	}


	ifstream fich;
	fich.open(argv[1]);

	set<string> datos;
	int linea = 0;

	while (!fich.eof()) {
        linea++;
        string a;
        getline(fich, a);
        if(!datos.insert(a).second) {
        	cout << linea << endl;
        }        
    }
}