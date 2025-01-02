#include <stdio.h>
#include <random>
#include <chrono>
#include <list>
#include "consola.h"

const unsigned int MIN_SCREEN_SIZE = 1;
const unsigned int MAX_SCREEN_SIZE = 20;
const unsigned int MIN_ENTITIES = 5;

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
	funcEntity m_funcs[2];
	TEntity(funcEntity drawFunc, funcEntity moveFunc, int x, int y, int _iHealth)
	{
		m_ix = x;
		m_iy = y;
		m_iHealth = _iHealth;
		m_funcs[0] = drawFunc;
		m_funcs[1] = moveFunc;
	}
};

void DrawEntity(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("%c", _pEntity->m_iHealth + '0'); }

void MoveUp(TEntity* _pEntity) {
	_pEntity->m_iy--;
	if (_pEntity->m_iy < MIN_SCREEN_SIZE) _pEntity->m_iy = MAX_SCREEN_SIZE;
}

void MoveDown(TEntity* _pEntity) {
	_pEntity->m_iy++;
	if (_pEntity->m_iy > MAX_SCREEN_SIZE) _pEntity->m_iy = MIN_SCREEN_SIZE;
}

void MoveLeft(TEntity* _pEntity) {
	_pEntity->m_ix--;
	if (_pEntity->m_ix < MIN_SCREEN_SIZE) _pEntity->m_ix = MAX_SCREEN_SIZE;
}

void MoveRight(TEntity* _pEntity) {
	_pEntity->m_ix++;
	if (_pEntity->m_ix > MAX_SCREEN_SIZE) _pEntity->m_ix = MIN_SCREEN_SIZE;
}

void MoveDiagonal(TEntity* _pEntity) {
	_pEntity->m_ix++;
	_pEntity->m_iy++;
	if (_pEntity->m_ix > MAX_SCREEN_SIZE) _pEntity->m_ix = MIN_SCREEN_SIZE;
	if (_pEntity->m_iy > MAX_SCREEN_SIZE) _pEntity->m_iy = MIN_SCREEN_SIZE;
}

inline int RandomIntegerInRange(int _iMaxNumber, int _iOffset = 0) { return (rand() % _iMaxNumber + _iOffset); }

void GenerateRandomEntity(std::list<TEntity*>& _rEntities) {
	funcEntity tFunctions[6] = { &DrawEntity, &MoveUp, &MoveDown, &MoveRight, &MoveLeft, &MoveDiagonal };

	_rEntities.push_back(new TEntity(tFunctions[0],
		tFunctions[RandomIntegerInRange(5, 1)],
		RandomIntegerInRange(MAX_SCREEN_SIZE, 1),
		RandomIntegerInRange(MAX_SCREEN_SIZE, 1),
		RandomIntegerInRange(9, 1)));
}

// ***************************************************************************************
// MAIN
// ***************************************************************************************
int main() {
	bool bStop = false;
	
	std::list<TEntity*> lEntities;
	srand(time(NULL));

	for (unsigned int uIndex = 0; uIndex < MIN_ENTITIES; uIndex++) GenerateRandomEntity(lEntities);

	while (!bStop) {
		clear();
	
		for (std::list<TEntity*>::iterator it = lEntities.begin(); it != lEntities.end(); ++it) {
			((*it)->m_funcs[0])(*it);
			((*it)->m_funcs[1])(*it);
		}

		while(lEntities.size() < MIN_ENTITIES)
		
	
		hidecursor();
		bStop = (GetAsyncKeyState(VK_ESCAPE) & 0x01);
		Sleep(50);
	}

	for (std::list<TEntity*>::iterator it = lEntities.begin(); it != lEntities.end(); ++it) delete *it;
}