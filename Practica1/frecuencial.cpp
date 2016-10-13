#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;



int main(){
	fstream ficheroEntrada;
    string nombre;
    string frase;
	string total;
 //criptograma21
    ficheroEntrada.open ( "criptograma21.txt" , ios::in);
    if (ficheroEntrada.is_open()) {
        while (! ficheroEntrada.eof() ) {
            getline (ficheroEntrada,frase);
			total += frase;
        }


    }
    else{
		cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;  
		return 0;
	}

	
	int longitud_contra;
	vector<int> alfabeto;
	string clave ="";
	double indice = 0;
	for(int i = 0; i< 26;i++){
		alfabeto.push_back(0);
	}

	vector<string> cadenas;
	string temporal;		
	bool encontrado = false;


	for(int q = 2; q < 20 && !encontrado ;q++){
		encontrado = true;
		cadenas.clear();
		temporal.clear();
		for(int i = 0; i < total.size();i++){
			if( (i % q == 0) && i != 0){
				cadenas.push_back(temporal);
				temporal.clear();		
			}
			temporal.push_back(total.at(i)); 
		} // Tenenmos el criptograma dispuesto en q columnas en la variable cadenas. Partimos de q=2.
		/* Analizamos el IC. CUando todas las columnas tengan un IC elevado obtendremos la contraseña.*/



		
		for(int i=0; i < q; i++){ // Para cada columna
			for(int w = 0; w< 26;w++){alfabeto.at(w) = 0;}
			for(int j = 0; j < cadenas.size();j++){ // Contamos frecuencia de letras 
				int temp = cadenas.at(j).at(i);
				alfabeto.at(temp- 65 ) += 1;
			} // Hasta aqui las letras contadas.

			indice = 0;
			for(int e = 0 ; e < 26; e++){
				indice = indice + (double) (alfabeto.at(e)*(alfabeto.at(e) - 1))/(cadenas.size()*(cadenas.size() - 1));	
			}
			// SI algun indice es menos o mayor al indice de Friedman, la longitud sera descartada . 0754976
			if(indice >  0.08 || indice < 0.05) 
				encontrado = false;
			}

		if(encontrado == true)
			longitud_contra = q;
			

		}

		cout << "La clave tiene una longitud de  " << longitud_contra << endl;

}
