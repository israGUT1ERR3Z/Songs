#ifndef CANCION_H
#define CANCION_H
#include <string>
using namespace std;

class Cancion
{
	public:
		Cancion(string n, string d, string al, string ar, int po);
		string getNombreC(),getDuracion(),getNombreAlbum(),getArtista();
		int getPos();
		virtual ~Cancion();

	protected:

	private:
		string nombre,duracion,nombreAlbum,artista;
		int p;
};

#endif // CANCION_H
