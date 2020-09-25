#pragma once
#include "Objeto.h"
using namespace System::Threading::Tasks;

class Adversario : public Objeto {
private:
	bool golpeado;
public:
	Adversario();
	Adversario(int);
	void mover(Direccion direccion, Graphics^ g);
	void moveradversario1(Graphics^ g);
	void moveradversario2(Graphics^ g);
	void mostrar(Graphics^ canvas, Bitmap^ sprite);
	void setestadogolpe();
	bool getestadogolpe();
	~Adversario();
};

Adversario::Adversario() {
	x = 0;
	y = 200;
	dx = dy = 6;
	columna = fila = 0;
	golpeado = false;
}
Adversario::Adversario(int n) {
	Random r;
	System::Threading::Thread::Sleep(20);
	x = r.Next(0, 820);
	System::Threading::Thread::Sleep(30);
	y = r.Next(200, 590);
	System::Threading::Thread::Sleep(10);
	dx = dy = r.Next(6,8);
	columna = fila = 0;
	golpeado = false;
}
Adversario::~Adversario(){
}
void Adversario::mover(Direccion direccion, Graphics^ g) {
	switch (direccion)
	{
	case Arriba:
		if (!(y - dy <  g->VisibleClipBounds.Top)) { y -= dy; }
		fila = (golpeado) ? 5 : 1 ;
		break;
	case Abajo:
		if (!(y + alto + dy > g->VisibleClipBounds.Bottom)) { y += dy; }
		fila = (golpeado) ? 4 : 0;
		break;
	case Izquierda:
		if (!(x - dx <  g->VisibleClipBounds.Left)) { x -= dx; }
		fila = (golpeado) ? 7 : 3;
		break;
	case Derecha:
		if (!(x + ancho + dx > g->VisibleClipBounds.Right)) { x += dx; }
		fila = (golpeado) ? 6 : 2;
		break;
	}
}
void Adversario::moveradversario1(Graphics^ g ){
	if (x >= 0 && x+ dx<100 && y==200) {
		mover(Direccion::Derecha, g);
	} else if (y + dy > 550 && x - dx >0) {
		mover(Direccion::Izquierda, g);
	} else if (x + dx > 100 && y+ dy<550) {
		mover(Direccion::Abajo,g);
	} else if (x -dx <= 0 && y > 202) {
		mover(Direccion::Arriba, g);
	} 
	 
}
void Adversario::moveradversario2(Graphics^ g) {
	Random r;
	System::Threading::Thread::Sleep(20);
	Direccion d = (Direccion)r.Next(0, 4);
	mover(d, g);
}
void Adversario::mostrar(Graphics^ canvas, Bitmap^ sprite) {
	alto = sprite->Height / 8;
	ancho = sprite->Width / 4;
	Rectangle molde = Rectangle(columna*ancho, fila*alto, ancho, alto);
	canvas->DrawImage(sprite, x, y, molde, GraphicsUnit::Pixel);
	columna++;
	if (columna == 4) {
		columna = 0;
	}
}
void Adversario::setestadogolpe() {
	golpeado = true;
}
bool Adversario::getestadogolpe() {
	return golpeado;
}