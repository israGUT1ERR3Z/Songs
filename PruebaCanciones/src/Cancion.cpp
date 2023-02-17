#include "Cancion.h"
#include <string>
using namespace std;

Cancion::Cancion(string n, string d, string al, string ar, int po)
{
	nombre=n;
	duracion=d;
	nombreAlbum=al;
	artista=ar;
	p=po;
}

string Cancion::getNombreC(){
	return nombre;
}

string Cancion::getDuracion(){
	return duracion;
}

string Cancion::getNombreAlbum(){
	return nombreAlbum;
}

string Cancion::getArtista(){
	return artista;
}

int Cancion::getPos(){
	return p;
}

Cancion::~Cancion()
{
	//dtor
}
