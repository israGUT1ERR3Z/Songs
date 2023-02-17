#include <vector>
#include <string>
#include <iostream>
#include "Cancion.h"
#include "Artista.h"
#include "Album.h"
#include <cstdlib>
using namespace std;

int main()
{
	int opc,anio,cont;
	string nombreCancion,nombreArtista,duracion,nombreAlbum;
	vector<Cancion*>rola; vector<Cancion*>::iterator iteRola;
	vector<Album*>disco; vector<Album*>::iterator iteDisco;
	vector<Artista*>cantante; vector<Artista*>::iterator iteCantante;
    do{
		cout<<"\n\nElegir cualquier opcion:\n\t1. Registrar cancion\n\t2. Filtrar albumes\n\t3. Ver artistas\n\t4. Salir";
		cout<<"\n\n\tOpcion: ";
		cin>>opc;
		system("cls");
		switch(opc){
			case 1:
				{
					cont++;
					cout<<"\n\nFavor de llenar los siguientes datos:\n\n\tNombre de la cancion: ";
					fflush(stdin);
					getline(cin,nombreCancion);
					cout<<"\tArtista: ";
					fflush(stdin);
					getline(cin,nombreArtista);
					cout<<"\tNombre del album: ";
					fflush(stdin);
					getline(cin,nombreAlbum);
					cout<<"\tA\164o de publicacion: ";
					cin>>anio;
					cout<<"\tDuracion: ";
					fflush(stdin);
					getline(cin,duracion);
					Cancion *song=new Cancion(nombreCancion,duracion,nombreAlbum,nombreArtista,cont);
					if(rola.size()==0){
						rola.push_back(song);
						cout<<"\n\n\tCancion registrada con exito\n\n";
					}else{
						for(iteRola=rola.begin(); iteRola!=rola.end(); iteRola++){
							if((*iteRola)->getNombreC()==nombreCancion&&(*iteRola)->getNombreAlbum()==nombreAlbum
									&&(*iteRola)->getArtista()==nombreArtista&&rola.size()>=1){
								cout<<"\n\nCANCION YA EXISTENTE\n\n";
								break;
							}
						}
						if(iteRola==rola.end()){
							rola.push_back(song);
							cout<<"\n\n\tCancion registrada con exito\n\n";
						}
					}
					Album *cd=new Album(rola,iteRola,nombreAlbum,anio,nombreArtista);
					if(disco.size()==0){
						disco.push_back(cd);
					}else{
						for(iteDisco=disco.begin(); iteDisco!=disco.end(); iteDisco++){
							if((*iteDisco)->getNombreAl()==nombreAlbum&&disco.size()>=1){
								break;
							}
						}
						if(iteDisco==disco.end()){
							disco.push_back(cd);
						}
					}
					Artista *singer=new Artista(iteDisco,disco,nombreArtista);
					if(cantante.size()==0){
						cantante.push_back(singer);
					}else{
						for(iteCantante=cantante.begin(); iteCantante!=cantante.end(); iteCantante++){
							if((*iteCantante)->getArtista()==nombreArtista&&cantante.size()>=1){
								break;
							}
						}
						if(iteCantante==cantante.end()){
							cantante.push_back(singer);
						}
						cont++;
					}
					system("pause");
					system("cls");
				}
				break;

			case 2:
				cout<<"\n\nEscribe el nombre del album: ";
				fflush(stdin);
				getline(cin,nombreAlbum);
				cout<<endl<<endl;
				for(iteDisco=disco.begin(); iteDisco!=disco.end(); iteDisco++){
					if(nombreAlbum==(*iteDisco)->getNombreAl()){
						(*iteDisco)->getTracklist(rola,iteRola,nombreAlbum);
						break;
					}
				}
				if(iteDisco==disco.end()){
					cout<<"\n\nNO SE HALLÓ EL DISCO SOLICITADO\n\n";
				}
				cout<<endl<<endl;
				system("pause");
				system("cls");
			break;

			case 3:
				{
					cont=1;
					char oo,oo2;
					cout<<"\n\nLista de artistas: \n";
					for(iteCantante=cantante.begin(); iteCantante!=cantante.end(); iteCantante++){
						cout<<cont<<". "<<(*iteCantante)->getArtista()<<endl;
						cont++;
					}
					cout<<"\n\nQuieres elegir alguno de ellos para ver algun disco o album? [S/N]: ";
					cin>>oo;
					if(oo=='S'){
						cout<<"\nEscribe su nombre: ";
						fflush(stdin);
						getline(cin,nombreArtista);
						cout<<endl<<endl;
						for(iteCantante=cantante.begin(); iteCantante!=cantante.end(); iteCantante++){
							if(nombreArtista==(*iteCantante)->getArtista()){
								(*iteCantante)->getDiscos(disco,iteDisco,nombreArtista);
								break;
							}
						}
						cout<<"\n\nQuieres elegir el nombre de un disco o album para ver el tracklist? [S/N]: ";
						cin>>oo2;
						if(oo2=='S'){
							cout<<"\n\nEscribe el nombre del album: ";
							fflush(stdin);
							getline(cin,nombreAlbum);
							cout<<endl<<endl;
							for(iteDisco=disco.begin(); iteDisco!=disco.end(); iteDisco++){
								if(nombreAlbum==(*iteDisco)->getNombreAl()){
									(*iteDisco)->getTracklist(rola,iteRola,nombreAlbum);
									break;
								}
							}
							if(iteDisco==disco.end()){
								cout<<"\n\nNO SE HALLÓ EL DISCO SOLICITADO\n\n";
							}
							cout<<endl<<endl;
							system("pause");
							system("cls");
						}else if(oo2=='N'){
							cout<<endl<<endl;
							system("pause");
							system("cls");
						}
					}else if(oo=='N'){
						cout<<endl<<endl;
						system("pause");
						system("cls");
					}
				}
			break;

			case 4:
				system("cls");
			break;

		}
    }while(opc!=4);
    return 0;
}
