/*Realizar el siguiente ejercicio utilizando funciones, estructuras y punteros:
La Unicef desea obtener información estadística sobre las guarderias ubicadas en el territorio guatemalteco, dado que por cada niño se ingresa la siguiente información: 
Nombre, 
Sexo, 
Edad, 
Nombre de Guarderia, 
Departamento (ubicacion geográfica)
Para lo cual se debe generar los siguientes reportes:
a) Porcentaje de niños ubicados en el departamento de guatemala, respecto al total del país.
b) Número de niños por grupo, los cuales se definen con base en la edad, teniendo en cuenta lo siguiente:
Grupo 1: Edad menor a 1 año
Grupo 2: Edad comprendida entre 1 y 3 años
Grupo 3: Edad comprendida entre 4 y 6 años
Grupo 4: Edad mayor de 6 años
c) Establecer el grupo que tiene la mayor cantidad de niños.*/

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <regex>
#include <conio.h>
#include <clocale>


void Menu();
void ingresar();
void Porcentaje();
void Ninogrupedad();

using namespace std;
int op;
struct Data
{
	string Nombre;
	char Sexo;
	int edad;
	string Nombreguar;
	string Departamento;
}Datos;

int main(){
	 Menu();
system("pause");
}

void Menu()
{
do{
	system("cls");
	cout<<"Menu"<<endl;
	cout<<"1. Ingresar Datos"<<endl;
	cout<<"2. Porcentaje Por Departamentos"<<endl;
	cout<<"3. Agrupacion Por Edad"<<endl;
	cout<<"4. Salir"<<endl;
	cin>>op;
	switch(op)
	{
	case(1):
	{
		system("cls");
		ingresar();
		Menu();
		break;
	}	
	case(2):
	{
		system("cls");
		Porcentaje();
		Menu();
		break;
	}

case(3):
	{
		system("cls");
		Ninogrupedad();
		Menu();
		break;
	}
	}
}while(op>=5);		
}

void ingresar(){
	
	setlocale(LC_CTYPE,"Spanish");
	Data*ingdata;
	ingdata = new Data;
	cout<<"ingrese Nombre"<<endl;
	cin>>ingdata->Nombre;
	do{
	cout<<"ingrese Sexo M/F"<<endl;
	cin>>ingdata->Sexo;
	if((ingdata->Sexo!='F')&&(ingdata->Sexo!='M')){
		cout<<"Letra No Permitida "<<endl;
		cout<<"Valores Permitidos M=Masculino F=Femenino"<<endl;
	}
	}while((ingdata->Sexo!='F')&&(ingdata->Sexo!='M'));
	fflush(stdin);
	do{
	cout<<"Ingrese Edad"<<endl;
	cin>>ingdata->edad;
	if(ingdata->edad>=11){
		cout<<"Edad Incorrecta"<<endl;
		cout<<"Edad Permitida de 0 a 10 Años"<<endl;
	}
	}while(ingdata->edad>=11);
	
	cout<<"Ingrese Nombre Guarderia"<<endl;
	cin>>ingdata->Nombreguar;
	cout<<"Ingrese Departamento"<<endl;
	cin>>ingdata->Departamento;
	
	ofstream Archivocre;
	try {
	Archivocre.open("Datos Guarderia.txt",ios::app);
	Archivocre<<ingdata->Nombre<<" "<<ingdata->Sexo<<" "<<ingdata->edad<<" "<<ingdata->Nombreguar<<" "<<ingdata->Departamento<<endl;
	Archivocre.close();
	cout<<setw(30)<<"Datos Guardados"<<endl;
	}
	catch(exception X)
	{
	cout<<setw(20)<<"Error al Guardar"<<endl;
	system("PAUSE");}
}


void Porcentaje(){
	setlocale(LC_CTYPE,"Spanish");
	ifstream archivoabrpo;
	Data*Pordata;
	Pordata = new Data;
	int Salto=0,Cont=0,por=0;	
	try{	
		archivoabrpo.open("Datos Guarderia.txt",ios::in);
		while (archivoabrpo>>Pordata->Nombre>>Pordata->Sexo>>Pordata->edad>>Pordata->Nombreguar>>Pordata->Departamento){	
				cout<<Pordata->Nombre<<"\t\t"<<Pordata->Sexo<<"\t\t"<<Pordata->edad<<"\t\t"<<Pordata->Nombreguar<<"\t\t"<<Pordata->Departamento<<endl;
				Salto++;			
				if("Guatemala"==Pordata->Departamento)
						Cont++;
					}	
				por=(Cont*100)/Salto;

			cout<<endl<<"Los niños de La Capital Representan el "<<por<<"% de niños en Guarderias del Pais."<<endl<<endl;
			
			archivoabrpo.close();
		}		
		
	catch (exception X)
	{		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
		}
		
	system("pause");			
}


void Ninogrupedad(){
	setlocale(LC_CTYPE,"Spanish");
	ifstream archivoabrpo;
	Data*Pordata;
	Pordata = new Data;
	int Salto=0,Cont=0,Grupo1=0,Grupo2=0,Grupo3=0,Grupo4=0,Grupo5=0;	
	try{	
		archivoabrpo.open("Datos Guarderia.txt",ios::in);
		while (archivoabrpo>>Pordata->Nombre>>Pordata->Sexo>>Pordata->edad>>Pordata->Nombreguar>>Pordata->Departamento){	
		//	cout<<Pordata->Nombre<<" "<<Pordata->Sexo<<" "<<Pordata->edad<<" "<<Pordata->Nombreguar<<" "<<Pordata->Departamento<<endl;
			//	Salto++;			
				if((Pordata->edad>=0)&&(Pordata->edad<=1)){
				Grupo1++;
				}
				else if((Pordata->edad>1)&&(Pordata->edad<=3)){
				Grupo2++;
				}
				else if((Pordata->edad>3)&&(Pordata->edad<=6)){
				Grupo3++;
				}
				else if(Pordata->edad>=7){
				Grupo4++;
				}
				}
			cout<<"Grupo 1: Menores de 1 año  con "<<Grupo1<<" niños "<<endl;
			cout<<"Grupo 2: Menores de 3 años con "<<Grupo2<<" niños "<<endl;
			cout<<"Grupo 3: Menores de 6 años con "<<Grupo3<<" niños "<<endl;
			cout<<"Grupo 4: Mayores de 6 años con "<<Grupo4<<" niños "<<endl<<endl;
	int Comple;		
			
			cout<<"el Grupo con mayor niños es el "<<endl<<endl;
			
			
			Grupo5=((Grupo1>Grupo2)?(Grupo1>Grupo3 ? Grupo1:Grupo3):(Grupo2>Grupo3 ? Grupo2:Grupo3));
		
	Comple=(Grupo5>Grupo4 ? Grupo5:Grupo4);
			
			if(Comple==Grupo1){
			cout<<"\nGrupo 1  con "<<Comple<<" Niños"<<endl;
		}
		else if(Comple==Grupo2){
			cout<<"\nGrupo 2 con "<<Comple<<" Niños"<<endl;
		}
		else if(Comple==Grupo3){
			cout<<"\nGrupo 3  con "<<Comple<<" Niños"<<endl;
		}
		else if(Comple==Grupo4){
			cout<<"\nGrupo 4 con "<<Comple<<" Niños"<<endl<<endl;
		}
			

		archivoabrpo.close();
		
		
		}		
	
		
	catch (exception X)
	{		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
		}
		
	system("pause");			
}

