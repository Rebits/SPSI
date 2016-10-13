#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


vector <int> div(int distancia){
	vector<int> divi;
	for(int i = 2 ; i < distancia;i++){
		if(distancia % i == 0 )
			divi.push_back(i);
	}
	divi.push_back(distancia);
	return divi;
}
			



int main(){
	fstream ficheroEntrada;
    string nombre;
    string frase;
	string total;

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

	string buf="";
	vector<string> cadenas;
	vector< vector <int> > distancias;
	vector< vector<int> > indices;
	vector <int> ultima;

	for(int i = 0 ; i < total.size();i++){
		buf.push_back(total.at(i));
		for(int j = i + 1; j < total.size();j++){
			if(total.at(j) == total.at(i)){
				if( (i + 1 !=	j) && (j+1 < total.size())){			
					int i_0 = i+1;
					int j_0 = j+1;
					bool ter = false;
					while(total.at(j_0) == total.at(i_0) && !ter){
						buf.push_back(total.at(i_0));	
						if(i_0 + 1 != j && j_0 + 1 < total.size()){		
							j_0++;
							i_0++;
						}
						else{
							ter = true;
						}
					}
					if(buf.size() > 1){ 
						bool b = false;					
						for(int i = 0 ; (i < cadenas.size()) && !b ; i++){
							b = false;	

							if(cadenas.at(i) == buf){
								b = true;
								int distancia = j_0 - ultima.at(i) ;
								ultima.at(i) = j_0; 
						 		distancias.at(i).push_back(distancia);
							}	
													
						}
						if(!b){

							cadenas.push_back(buf);
							int distancia = j_0 - i_0 ;
							ultima.push_back(j_0);
							vector <int> ve;
							ve.push_back(distancia);
						 	distancias.push_back(ve);
							
					}
				}
			}
			buf.clear();
			buf.push_back(total.at(i));
		}

	}

	buf.clear();
}
for(int i = 0; i < distancias.size();i++){
	vector <int> por;
	indices.push_back(por);
	for(int j = 0; j < distancias.at(i).size();j++){
		vector <int> ve = div(distancias.at(i).at(j));
		indices.at(i).insert(indices.at(i).end(),ve.begin(),ve.end());
		
 	}
}

vector <int> contador;
for(int i = 0 ; i < 100000; i++)
	contador.push_back(0);

for(int j = 0; j < indices.size();j++){
	for(int i = 0 ; i < indices.at(j).size();i++){
		if(indices.at(j).at(i) < 5000 && indices.at(j).at(i) > 0 )
			contador.at(indices.at(j).at(i)) += 1;
	}
}

int maximo = -1;
int maximo_2 = -1;
int maximo_3 = -1;
int maximo_4 = -1;
int indice = -1;
int indice_2 = -1;
int indice_3 = -1;
int indice_4 = -1;


for(int i = 0 ; i < contador.size(); i++){

	if(contador.at(i) > maximo){
		maximo_4 = maximo_3;
		maximo_3 = maximo_2;
		maximo_2 = maximo;
		maximo = contador.at(i);
 		indice_4 = indice_3;	
 		indice_3 = indice_2;
 		indice_2 = indice;	
		indice = i;
	}
	else if(contador.at(i) > maximo_2){
		maximo_4 = maximo_3;
		maximo_3 = maximo_2;
		maximo_2 = contador.at(i);

 		indice_4 = indice_3;	
 		indice_3 = indice_2;
 		indice_2 = i;	
	}

	else if(contador.at(i) > maximo_3){
		maximo_4 = maximo_3;
		maximo_3 =contador.at(i);

 		indice_4 = indice_3;	
 		indice_3 = i;
 	
	}

	else if(contador.at(i) > maximo_4){
		maximo_4 = contador.at(i);

 		indice_4 = i;	

 	
	}


}

	cout << "Tamanio de contraseña más probable: " <<  indice << endl;

	
	cout << "Otras opciones:";
	if(indice_2 > 0)
		cout << indice_2 << "  " ;
	if(indice_3 > 0)
 		cout << indice_3 << "  ";
	if(indice_4 > 0)
		cout << indice_4 << endl;
    

ficheroEntrada.close();

    return 0;

}
