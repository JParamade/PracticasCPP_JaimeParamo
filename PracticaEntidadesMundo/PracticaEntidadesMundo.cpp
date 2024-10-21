// practica4.cpp
//
#include <stdio.h>
#include "consola.h"

struct TEntity;
typedef void (*funcEntity)(TEntity*);

// ***************************************************************************************
// ENTIDAD
// ***************************************************************************************
struct TEntity
{
	int m_ix;
	int m_iy;
	funcEntity* m_funcs;
	TEntity(funcEntity* funcs, int x, int y)
	{
		m_ix = x;
		m_iy = y;
		m_funcs = funcs;
	}
};

void DrawA(TEntity* _pEntity) {
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("A");
}

void DrawB(TEntity* _pEntity) {
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("B");
}

void DrawC(TEntity* _pEntity) {
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("C");
}

void MoveUp(TEntity* _pEntity) {
	_pEntity->m_iy--;
	if (_pEntity->m_iy < 0) _pEntity->m_iy = 10;
}

void MoveDown(TEntity* _pEntity) {
	_pEntity->m_iy++;
	if (_pEntity->m_iy > 10) _pEntity->m_iy = 0;
}

void MoveLeft(TEntity* _pEntity) {
	_pEntity->m_ix--;
	if (_pEntity->m_ix < 0) _pEntity->m_ix = 10;
}

void MoveRight(TEntity* _pEntity) {
	_pEntity->m_ix++;
	if (_pEntity->m_ix > 10) _pEntity->m_ix = 0;
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main()
{
	TEntity* tEntities[3];
	unsigned int uEntitiesSize = sizeof(tEntities) / sizeof(TEntity*);

	funcEntity tMisFunciones1[2];
	tMisFunciones1[0] = &MoveRight;
	tMisFunciones1[1] = &DrawA;
	tEntities[0] = new TEntity(tMisFunciones1, 10, 4);

	funcEntity tMisFunciones2[2];
	tMisFunciones2[0] = &MoveDown;
	tMisFunciones2[1] = &DrawB;
	tEntities[1] = new TEntity(tMisFunciones2, 10, 4);

	funcEntity tMisFunciones3[2];
	tMisFunciones3[0] = &MoveUp;
	tMisFunciones3[1] = &DrawC;
	tEntities[2] = new TEntity(tMisFunciones3, 10, 4);

	while (true) {
		clear();

		for (unsigned int uIndex = 0; uIndex < uEntitiesSize; uIndex++) {
			(*tEntities[uIndex]->m_funcs[0])(tEntities[uIndex]);
			(*tEntities[uIndex]->m_funcs[1])(tEntities[uIndex]);
		}

		hidecursor();

		Sleep(50);
	}

	for (unsigned int uIndex = 0; uIndex < uEntitiesSize; uIndex++) delete tEntities[uIndex];
}