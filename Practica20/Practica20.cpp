#include <stdio.h>
#include <random>
#include <chrono>
#include <list>
#include "consola.h"

struct TEntity;
typedef void (*funcEntity)(TEntity*);

// ***************************************************************************************
// ENTITY
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

TEntity* GenerateEntity(funcEntity* _tFuncs, int _iX, int _iY, int _iHealth) {
	return new TEntity(_tFuncs, _iX, _iY, _iHealth);
}

void CheckHealth(TEntity* _pEntity) {

}

void DrawEntity(TEntity* _pEntity) {
	gotoxy(_pEntity->m_ix, _pEntity->m_iy);
	printf("%c", _pEntity->m_iHealth + '0');
}

void MoveUp(TEntity* _pEntity) {
	_pEntity->m_iy--;
	if (_pEntity->m_iy < 0) _pEntity->m_iy = 20;
}

void MoveDown(TEntity* _pEntity) {
	_pEntity->m_iy++;
	if (_pEntity->m_iy > 20) _pEntity->m_iy = 0;
}

void MoveLeft(TEntity* _pEntity) {
	_pEntity->m_ix--;
	if (_pEntity->m_ix < 0) _pEntity->m_ix = 20;
}

void MoveRight(TEntity* _pEntity) {
	_pEntity->m_ix++;
	if (_pEntity->m_ix > 20) _pEntity->m_ix = 0;
}

void MoveDiagonal(TEntity* _pEntity) {
	_pEntity->m_ix++;
	_pEntity->m_iy++;
	if (_pEntity->m_ix > 20) _pEntity->m_ix = 0;
	if (_pEntity->m_iy > 20) _pEntity->m_iy = 0;
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main() {
	bool bStop = false;
	
	std::list<TEntity*> lTotalEntities;
	std::list<TEntity*> lAliveEntities;
	std::list<funcEntity*> lFuncs;
	srand(time(NULL));

	for (unsigned int uIndex = 0; uIndex < 5; uIndex++) {
		funcEntity* tMyFunctions = new funcEntity[2];
		lFuncs.push_back(tMyFunctions);

		int iRandomNumber = RandomIntegerInRange(4);
		if (iRandomNumber == 0) tMyFunctions[0] = &MoveUp;
		else if (iRandomNumber == 1) tMyFunctions[0] = &MoveDown;
		else if (iRandomNumber == 2) tMyFunctions[0] = &MoveRight;
		else if (iRandomNumber == 3) tMyFunctions[0] = &MoveLeft;
		else if (iRandomNumber == 4) tMyFunctions[0] = &MoveDiagonal;

		tMyFunctions[1] = &DrawEntity;

		lTotalEntities.push_back(GenerateEntity(tMyFunctions, RandomIntegerInRange(20, 1), RandomIntegerInRange(20, 1), RandomIntegerInRange(9, 1)));
	}

	while (!bStop) {
		clear();
	
		for (std::list<TEntity*>::iterator it = lTotalEntities.begin(); it != lTotalEntities.end(); ++it) {
			((*it)->m_funcs[0])(*it);
			((*it)->m_funcs[1])(*it);
		}
	
		hidecursor();
	
		Sleep(50);
		bStop = (GetAsyncKeyState(VK_ESCAPE) & 0x01);
	}

	for (std::list<TEntity*>::iterator it = lTotalEntities.begin(); it != lTotalEntities.end(); ++it) delete *it;
	for (std::list<funcEntity*>::iterator it = lFuncs.begin(); it != lFuncs.end(); ++it) delete[] *it;
}