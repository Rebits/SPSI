#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

char frec_espanol[26] = {'E','A' ,'O', 'S', 'R', 'N', 'I', 'D', 'L', 'C', 'T', 'U', 'M', 'P', 'B', 'G', 'V', 'Y', 'Q', 'H', 'F', 'Z', 'J', 'X', 'W', 'K'};


 
void desencriptar(string text,string clav){
 string texto = text;
 string clave = clav;
 string desencriptar;
 int resultado;
  string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

 for(int i = 0; i < texto.size();i++){
	int k = i % clave.size();
		int y =  texto.at(i) - clave.at(k);
		if(y < 0){
			y = alfabeto.size() + y;
		}
		char pot = y + 65;
		desencriptar.push_back(pot );
}  
    cout << "\n\n\t\t Texto ";
    for (int i = 0 ; i  <  texto.size() ; i++){
        cout << desencriptar[i];
    }
}

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

	string clave ="";	
	int longitud_contra = 7;
	vector<double> frec_alfabeto;

	for(int i = 0; i< 26;i++){
		frec_alfabeto.push_back(0);
	}

	vector<string> cadenas;
	string temporal;		
	bool encontrado = false;

	for(int i = 0; i < total.size();i++){
		if( (i % longitud_contra  == 0) && i != 0){
			cadenas.push_back(temporal);
			temporal.clear();		
		}
		temporal.push_back(total.at(i)); 
	} 

	/*Calulamos frecuencia de cada uno de las letras en cada columna*/
	for(int i=0; i < longitud_contra ; i++){ // Para cada columna
		for(int w = 0; w< 26;w++){frec_alfabeto.at(w) = 0;}
		for(int j = 0; j < cadenas.size();j++){ // Contamos frecuencia de letras 
			int temp = cadenas.at(j).at(i);
			frec_alfabeto.at(temp - 65 ) += 1;

		} // Hasta aqui las letras contadas.


	for(int k = 0; k < 26;k++){frec_alfabeto.at(k) = frec_alfabeto.at(k)/cadenas.size();}
		
	for(int r = 0 ; r < frec_alfabeto.size();r++){
		char a = r + 65;

}
	/*Ordenooo*/
		vector<double> respaldo = frec_alfabeto;
		double temp;
		char cadena_ordenada[26];
		for(int u = 0 ; u < 26; u++){cadena_ordenada[u] = 65 + u;}









 		for (int w = 0; w < 25; w++) { 

    		for (int j = w+1; j < 26; j++) { 

      			if (respaldo[w] < respaldo[j]) {
       		 		temp = respaldo[w]; 
        			respaldo[w] = respaldo[j]; 
        			respaldo[j] = temp; 
					
					char temp = cadena_ordenada[w]; 
					cadena_ordenada[w] = cadena_ordenada[j];
					cadena_ordenada[j] = temp;

      			}
    		} 
  		}


		cout << "Columna " << i << endl;
	for(int b = 0 ; b < 26;b++){

		char pass = abs(cadena_ordenada[b] - frec_espanol[b]) + 65;
		cout << cadena_ordenada[b] << "   " <<  frec_espanol[b] << endl;
		}



	}
	
desencriptar(total,"YMGDAFM");




}

