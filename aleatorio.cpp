#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main(int argc, char * argv[]) {

	if (argc <= 2) {
		cout << "Error en los argumentos: participante_1 participante_2 .... participante_N" << endl;
		cout << "Mínimo 2 participantes" << endl;
		return -1;
	}

    vector<string> candidatos;
    for (int i = 1; i < argc; i++) {
        candidatos.push_back(argv[i]);
    }

    cout << "Participantes: ";
    for (int i = 0; i < candidatos.size(); i++) {
        cout << candidatos[i] << " ";
    }
    cout << endl;

    srand(time(NULL));
    for (int i = 1; i < argc; i++) {
        int n = rand()%(candidatos.size());
        cout << "El elegido " << i << ": " << candidatos[n] << endl;
        candidatos[n] = candidatos[candidatos.size()-1];
        candidatos.pop_back();
    }
}