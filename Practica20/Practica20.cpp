#include <stdio.h>
#include <list>
#include <random>
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
	char cRepresentation;
	TEntity(funcEntity _fDrawFunc, funcEntity _fMoveFunc, int x, int y, int _iHealth)
		: cRepresentation(' ')
	{
		m_ix = x;
		m_iy = y;
		m_iHealth = _iHealth;
		m_funcs[0] = _fDrawFunc;
		m_funcs[1] = _fMoveFunc;
	}
};

inline int RandomIntegerInRange(int _iMaxNumber, int _iOffset = 0) { return (rand() % _iMaxNumber + _iOffset); }

void DrawA(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("A"); _pEntity->cRepresentation = 'A';}
void DrawB(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("B"); _pEntity->cRepresentation = 'B';}
void DrawC(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("C"); _pEntity->cRepresentation = 'C';}
void DrawD(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("D"); _pEntity->cRepresentation = 'D';}
void DrawE(TEntity* _pEntity) { gotoxy(_pEntity->m_ix, _pEntity->m_iy); printf("E"); _pEntity->cRepresentation = 'E';}

void DrawHealth(TEntity* _pEntity, int _iHeight) { gotoxy(MIN_SCREEN_SIZE, MAX_SCREEN_SIZE + _iHeight); printf("Entity %c: %d", _pEntity->cRepresentation, _pEntity->m_iHealth); }

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

void CheckCollisions(std::list<TEntity*>& _rEntities) {
	std::list<TEntity*> lEntitiesToDelete;

	for (std::list<TEntity*>::iterator it = _rEntities.begin(); it != _rEntities.end(); ++it) {
		std::list<TEntity*>::iterator it2 = it; 
		++it2; 

		while (it2 != _rEntities.end()) {
			if ((*it)->m_ix == (*it2)->m_ix && (*it)->m_iy == (*it2)->m_iy) {
				(*it)->m_iHealth--;
				(*it2)->m_iHealth--;

				if ((*it)->m_iHealth <= 0) {
					lEntitiesToDelete.push_back(*it);
					it = _rEntities.erase(it);
					if (it == _rEntities.end()) break;
				}

				if ((*it2)->m_iHealth <= 0) {
					lEntitiesToDelete.push_back(*it2);
					it2 = _rEntities.erase(it2);
				}
				else ++it2;
			}
			else ++it2;
		}
	}

	for (TEntity* pEntity : lEntitiesToDelete) delete pEntity;
}

void GenerateRandomEntity(std::list<TEntity*>& _rEntities) {
	funcEntity tFunctions[5][2] = {{&DrawA, &MoveUp}, 
								   {&DrawB, &MoveDown},
								   {&DrawC, &MoveRight},
								   {&DrawD, &MoveLeft},
								   {&DrawE, &MoveRandom}};

	_rEntities.push_back(new TEntity(
		tFunctions[RandomIntegerInRange(5, 1)][0],
		tFunctions[RandomIntegerInRange(5, 1)][1],
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
	
		unsigned int uEntityIndex = 0;

		for (std::list<TEntity*>::iterator it = lEntities.begin(); it != lEntities.end(); ++it) {
			((*it)->m_funcs[0])(*it);
			((*it)->m_funcs[1])(*it);

			DrawHealth(*it, uEntityIndex + 2);
			
			uEntityIndex++;
		}

		CheckCollisions(lEntities);

		while (lEntities.size() < MIN_ENTITIES) GenerateRandomEntity(lEntities);
		
		hidecursor();
		bStop = (GetAsyncKeyState(VK_ESCAPE) & 0x01);
		Sleep(50);
	}

	for (TEntity* pEntity : lEntities) delete pEntity;
}