#include<iostream>
#include<fstream>
#include<set>

using namespace std;

int main(int argc, char * argv[]) {

	if(argc != 3) {
		cout << "Error argumentos: <fichero><salida>" << endl;
		exit(0);
	}


	ifstream fich;
	ofstream salida;
	fich.open(argv[1]);
	salida.open(argv[2]);


	set<string> datos;

	while (!fich.eof()) {
        string a;
        getline(fich, a);
        datos.insert(a);     
    }

    for (auto it = datos.begin(); it != datos.end(); ++it) {
    	salida << *it << endl;
    }

  	fich.close();
  	salida.close();
}