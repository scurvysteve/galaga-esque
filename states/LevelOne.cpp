/*
 * LevelOne.cpp
 *
 *  Created on: Feb 20, 2013
 *      Author: joe
 */

#include "LevelOne.h"

LevelOne::LevelOne() {
	playerShip = PlayerEntity(200, 350);
	background = Image();
	background.loadImage("background.png");
	backgroundY = -400;

	enemies = std::vector<GenericEnemy*>();


	initStats();
	scoreboardShip = Image();
	scoreboardShip.loadImage("playerShip.png");

	initPauseMenu();

	nextState = STATE_NULL;

	enemySpawnTimer = 0;
}

LevelOne::~LevelOne() {
	// TODO Auto-generated destructor stub
}

GameState* LevelOne::getNextState(){
	if(nextState==STATE_NULL){
		return this;
	}
	else if(nextState==STATE_EXIT){
		return NULL;
	}
	else{
		return this;
	}
}



void LevelOne::spawnEnemies(){
	if(enemySpawnTimer==10){
		enemies.push_back(new StraightDownEnemy(210, 10));
	}
	if(enemySpawnTimer==50){
		enemies.push_back(new StraightDownEnemy(180, 10));
		enemies.push_back(new StraightDownEnemy(240, 10));
	}
	if(enemySpawnTimer==100){
		enemies.push_back(new StraightDownEnemy(180, 10));
		enemies.push_back(new StraightDownEnemy(240, 10));
	}
	if(enemySpawnTimer==120){
		enemies.push_back(new StraightDownEnemy(140, 10));
	}
	if(enemySpawnTimer==125){
		enemies.push_back(new StraightDownEnemy(160, 10));
	}
	if(enemySpawnTimer==130){
		enemies.push_back(new StraightDownEnemy(180, 10));
	}
	if(enemySpawnTimer==180){
		enemies.push_back(new LevelOneBoss(140, 10, LEVEL_WIDTH));
	}
	enemySpawnTimer++;
}
