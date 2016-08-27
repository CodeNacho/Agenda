
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace std;

//Prototipos
void menu();




class contactos{
	public:

	contactos(){}

	contactos(string nombre,string numero,string email){
		this->nombre=nombre;
		this->numero=numero;
		this->email=email;
	}

	string getNombre(){return this->nombre;}

	void setNombre(string nombre){this->nombre=nombre;}


	string getNumero(){ return this->numero;}
	void setNumero(string numero){this->numero=numero;}

	string getEmail(){ return this->email;}
	void setEmail(string email){this->email=email;}




	private:
	   string nombre,email,numero;


};


class Agenda{
	private:
		vector<contactos> listaDeContactos;
		vector<string> tempDatos;
	public:
		Agenda(){}
		void add(){
			string numero;
			cout<<"Introduzca su nombre: ";
			ingresarDato();
			cout<<"Introduzca su numero: ";
			cin>>numero;
			tempDatos.push_back(numero);
			cout<<"Introduzca su E-mail: ";
			ingresarDato();		

			tempDatos=verificarDatos(tempDatos);

			
			listaDeContactos.push_back(contactos(tempDatos[0],tempDatos[1],tempDatos[2]));
			tempDatos.clear();
		}

		void ingresarDato(){
			string dato;

			fflush(stdin);
			cin.get();
			getline(cin,dato);
			tempDatos.push_back(dato);
		}

		void mostrar(){
			int i;

			for (i = 0; i <listaDeContactos.size(); ++i)
			{	
				cout<<i+1<<") "<<listaDeContactos[i].getNombre()<<endl;
			}

			if(i==0){
				cout<<"\tNO TIENES NINGUN CONTACTO"<<endl;
			}
		}

		vector<string> verificarDatos(vector<string> tempDatos){
			//Verificar Nombre
			bool isValid;
			string tmpnom;	
			
			do{
				cout<<"LENGTH: "<<tempDatos[1].length()<<endl<<"Nombre: "<<tempDatos[1]<<endl;
				if(tempDatos[1].length()>10 || tempDatos[1].length()<9){
					cout<<"El numero es incorrecto"<<endl<<endl;
					isValid=false;
					cout<<"Por favor vuelva a intentarlo: ";
					fflush(stdin);
					cin>>tmpnom;
					tempDatos[1]=tmpnom;
				}else{
					isValid=true;
				}



			}while(!isValid);



			return tempDatos;
		}

		void findContact(){
			string occ;
			int size=0,cmp=0;
			bool aux=false;

		

			cout<<"Buscar contacto: ";
			fflush(stdin);
			cin.get();
			getline(cin,occ);
			size=-occ.size();
			


			for(int i=0;i<listaDeContactos.size() && !aux;i++){
				cmp=listaDeContactos[i].getNombre().compare(occ);

				//cmp<=0 && cmp>=size

				if(cmp==0){
					system("clear");

					//cout<<listaDeContactos[i].getNombre()<<"<<><><>"<<occ<<endl<<endl<<listaDeContactos.size()<<endl;
					cout<<"\tINFORMACION DEL CONTACTO: "<<endl<<endl<<
					"\tNombre: "<<listaDeContactos[i].getNombre()<<endl<<
					"\tNumero: "<<listaDeContactos[i].getNumero()<<endl<<
					"\tE-mail: "<<listaDeContactos[i].getEmail()<<endl<<endl;
					aux=true;
				}else{
					cout<<listaDeContactos[i].getNombre()<<"<<><><>"<<occ<<endl<<endl;
					aux=false;
				}
			}

			if(!aux){
				
				cout<<occ<<" NO se encontro"<<endl;
			}

		
		}

		void remove(){
			int op;
			if(listaDeContactos.size()>0){
				for (int i = 0; i <listaDeContactos.size(); ++i){	
					cout<<i+1<<") "<<listaDeContactos[i].getNombre()<<endl;
				}

				cout<<"Ingrese el numero del contacto a eliminar: ";
				cin>>op;
				listaDeContactos.erase((listaDeContactos.begin()+op)-1);
			}else{
				cout<<"NO TIENES NINGUN CONTACTO"<<endl;
			}
		}


};

int main(){
	menu();

	return 0;
}


void menu(){
	int op;
	char key;
	Agenda agenda;

	do{
	   do{
		cout<<"\t\tMENU PRINCIPAL"<<endl;
		cout<<"\t1) Agregar un contacto"<<endl;
		cout<<"\t2) Buscar un contacto"<<endl;
		cout<<"\t3) Lista de contactos"<<endl;
		cout<<"\t4) Eliminar un contacto"<<endl;
		cout<<"\t5) Salir"<<endl;
		cout<<"\tEliga una opcion: ";
		cin>>op;
		system("clear");

	   }while(op>5);

	   switch(op){
	   		case 1:{

	   			agenda.add();
	   			break;
	   		} 	

	   		case 2:{
	   			agenda.findContact();
				break;
	   		}	
			case 3:{
	   			agenda.mostrar();
				break;
	   		}

	   		case 4:{
	   			agenda.remove();
				break;
	   		}

	   		case 5:{
	   			cout<<"Salir"<<endl;
	   			exit(-1); 
	   		}


	   }
	   fflush(stdin);
	   cout<<"Desea volver al menu[S/N]: ";
	   cin>>key;
	   system("clear");

	}while(key =='s' || key == 'S');

}


