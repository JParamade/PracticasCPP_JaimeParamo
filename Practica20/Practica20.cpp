#include <stdio.h>
#include <list>
#include <random>
#include <tuple>
#include <algorithm>
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
	TEntity(funcEntity _fDrawFunc, funcEntity _fMoveFunc, int x, int y, int _iHealth)
	{
		m_ix = x;
		m_iy = y;
		m_iHealth = _iHealth;
		m_funcs[0] = _fDrawFunc;
		m_funcs[1] = _fMoveFunc;
	}
};

inline int RandomIntegerInRange(int _iMaxNumber, int _iOffset = 0) { return (rand() % _iMaxNumber + _iOffset); }

void DrawEntity(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("%c", _pEntity->m_iHealth + '0'); }

void MoveUp(TEntity* _pEntity) {
	_pEntity->m_iy--;
	if (_pEntity->m_iy < MIN_SCREEN_SIZE) _pEntity->m_iy = MAX_SCREEN_SIZE;
}

void MoveDown(TEntity* _pEntity) {
	_pEntity->m_iy++;
	if (_pEntity->m_iy > MAX_SCREEN_SIZE) _pEntity->m_iy = MIN_SCREEN_SIZE;
}

void MoveRight(TEntity* _pEntity) {
	_pEntity->m_ix++;
	if (_pEntity->m_ix > MAX_SCREEN_SIZE) _pEntity->m_ix = MIN_SCREEN_SIZE;
}

void MoveLeft(TEntity* _pEntity) {
	_pEntity->m_ix--;
	if (_pEntity->m_ix < MIN_SCREEN_SIZE) _pEntity->m_ix = MAX_SCREEN_SIZE;
}

void MoveRandom(TEntity* _pEntity)
{
	_pEntity->m_ix += RandomIntegerInRange(2) * (RandomIntegerInRange(2) ? 1 : -1);
	_pEntity->m_iy += RandomIntegerInRange(2) * (RandomIntegerInRange(2) ? 1 : -1);

	if (_pEntity->m_iy < MIN_SCREEN_SIZE) _pEntity->m_iy = MAX_SCREEN_SIZE;
	if (_pEntity->m_iy > MAX_SCREEN_SIZE) _pEntity->m_iy = MIN_SCREEN_SIZE;
	if (_pEntity->m_ix > MAX_SCREEN_SIZE) _pEntity->m_ix = MIN_SCREEN_SIZE;
	if (_pEntity->m_ix < MIN_SCREEN_SIZE) _pEntity->m_ix = MAX_SCREEN_SIZE;
}

void CheckCollisions(std::list<TEntity*>& _lEntities) {
	std::list<std::tuple<int, int, TEntity*>> lEntityTuple;

	for (TEntity* pEntity : _lEntities) lEntityTuple.push_back(std::make_tuple(pEntity->m_ix, pEntity->m_iy, pEntity));

	sort(lEntityTuple.begin(), lEntityTuple.end(), );

	for ()
}

void GenerateRandomEntity(std::list<TEntity*>& _rEntities) {
	funcEntity tFunctions[6] = {&DrawEntity, &MoveUp, &MoveDown, &MoveRight, &MoveLeft, &MoveRandom};

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

		CheckCollisions(lEntities);

		while (lEntities.size() < MIN_ENTITIES) GenerateRandomEntity(lEntities);
		
		hidecursor();
		bStop = (GetAsyncKeyState(VK_ESCAPE) & 0x01);
		Sleep(50);
	}

	for (TEntity* pEntity : lEntities) delete pEntity;
}