#include <stdio.h>
#include <random>
#include <list>
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
	int m_iHealth;
	funcEntity* m_funcs;
	TEntity(funcEntity* funcs, int x, int y, int _iHealth)
	{
		m_ix = x;
		m_iy = y;
		m_iHealth = _iHealth;
		m_funcs = funcs;
	}
};

inline int RandomIntegerInRange(int _iMaxNumber, int _iOffset = 0) {
	return (rand() % _iMaxNumber + _iOffset);
}

void CheckHealth(TEntity* _pEntity) {

}

void DrawEntity(TEntity* _pEntity) {
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("%c", _pEntity->m_iHealth + '0');
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

void MoveDiagonal(TEntity* _pEntity) {
	_pEntity->m_ix++;
	_pEntity->m_iy++;
	if (_pEntity->m_ix > 10) _pEntity->m_ix = 0;
	if (_pEntity->m_iy > 10) _pEntity->m_iy = 0;
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main() {
	bool bStop = false;
	
	std::list<TEntity*> lEntities;
	srand(time(NULL));

	funcEntity tMyFunctions1[2];
	tMyFunctions1[0] = &MoveRight;
	tMyFunctions1[1] = &DrawEntity;
	lEntities.push_back(new TEntity(tMyFunctions1, 10, 4, RandomIntegerInRange(10, 1)));

	funcEntity tMyFunctions2[2];
	tMyFunctions2[0] = &MoveDown;
	tMyFunctions2[1] = &DrawEntity;
	lEntities.push_back(new TEntity(tMyFunctions2, 10, 8, RandomIntegerInRange(10, 1)));

	funcEntity tMyFunctions3[2];
	tMyFunctions3[0] = &MoveUp;
	tMyFunctions3[1] = &DrawEntity;
	lEntities.push_back(new TEntity(tMyFunctions3, 2, 12, RandomIntegerInRange(10, 1)));

	funcEntity tMyFunctions4[2];
	tMyFunctions4[0] = &MoveDiagonal;
	tMyFunctions4[1] = &DrawEntity;
	lEntities.push_back(new TEntity(tMyFunctions4, 15, 2, RandomIntegerInRange(10, 1)));

	while (!bStop) {
		clear();

		for (std::list<TEntity*>::iterator it = lEntities.begin(); it != lEntities.end(); ++it) {
			((*it)->m_funcs[0])(*it);
			((*it)->m_funcs[1])(*it);
		}

		hidecursor();

		Sleep(50);
		bStop = (GetAsyncKeyState(VK_ESCAPE) & 0x01);
	}

	for (std::list<TEntity*>::iterator it = lEntities.begin(); it != lEntities.end(); ++it) delete *it;
}