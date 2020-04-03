/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include <iostream>
#include "PacmanGame.hpp"

PacmanGame::PacmanGame()
{
    this->map = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 0 = empty -> black
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 1 = wall
                 {1, 2, 5, 1, 1, 6, 2, 5, 1, 1, 1, 6, 2, 1, 1, 2, 5, 1, 1, 1, 6, 2, 5, 1, 1, 6, 2, 1}, 
                 {1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 1}, // 5 = angle 
                 {1, 2, 7, 1, 1, 8, 2, 7, 1, 1, 1, 8, 2, 7, 8, 2, 7, 1, 1, 1, 8, 2, 7, 1, 1, 8, 2, 1}, // 6 = angle 
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}, // 7 = angle
                 {1, 2, 5, 1, 1, 6, 2, 5, 6, 2, 5, 1, 1, 1, 1, 1, 1, 6, 2, 5, 6, 2, 5, 1, 1, 6, 2, 1}, // 8 = angle
                 {1, 2, 7, 1, 1, 8, 2, 1, 1, 2, 7, 1, 1, 6, 5, 1, 1, 8, 2, 1, 1, 2, 7, 1, 1, 8, 2, 1}, 
                 {1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1}, // 2 = small coin
                 {1, 1, 1, 1, 1, 1, 2, 1, 7, 1, 1, 6, 0, 1, 1, 0, 5, 1, 1, 8, 1, 2, 1, 1, 1, 1, 1, 1}, // 3 = big coin
                 {4, 4, 4, 4, 4, 1, 2, 1, 5, 1, 1, 8, 0, 7, 8, 0, 7, 1, 1, 6, 1, 2, 1, 4, 4, 4, 4, 4}, // 4 = unaccessible for player
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 1, 1, 1, 4, 4, 1, 1, 1, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {1, 1, 1, 1, 1, 1, 2, 7, 8, 0, 1, 4, 4, 4, 4, 4, 4, 1, 0, 7, 8, 2, 1, 1, 1, 1, 1, 1},
                 {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 4, 4, 4, 4, 4, 4, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1, 1, 2, 5, 6, 0, 1, 4, 4, 4, 4, 4, 4, 1, 0, 5, 6, 2, 1, 1, 1, 1, 1, 1},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {4, 4, 4, 4, 4, 1, 2, 1, 1, 0, 5, 1, 1, 1, 1, 1, 1, 6, 0, 1, 1, 2, 1, 4, 4, 4, 4, 4},
                 {1, 1, 1, 1, 1, 1, 2, 7, 8, 0, 7, 1, 1, 6, 5, 1, 1, 8, 0, 7, 8, 2, 1, 1, 1, 1, 1, 1},
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                 {1, 2, 5, 1, 1, 6, 2, 5, 1, 1, 1, 6, 2, 1, 1, 2, 5, 1, 1, 1, 6, 2, 5, 1, 1, 6, 2, 1},
                 {1, 2, 7, 1, 6, 1, 2, 7, 1, 1, 1, 8, 2, 7, 8, 2, 7, 1, 1, 1, 8, 2, 1, 5, 1, 8, 2, 1},
                 {1, 3, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 3, 1},
                 {1, 1, 6, 2, 1, 1, 2, 5, 6, 2, 5, 1, 1, 1, 1, 1, 1, 6, 2, 5, 6, 2, 1, 1, 2, 5, 1, 1},
                 {1, 1, 8, 2, 7, 8, 2, 1, 1, 2, 7, 1, 1, 6, 5, 1, 1, 8, 2, 1, 1, 2, 7, 8, 2, 7, 1, 1},
                 {1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1},
                 {1, 2, 5, 1, 1, 1, 1, 8, 7, 1, 1, 6, 2, 1, 1, 2, 5, 1, 1, 8, 7, 1, 1, 1, 1, 6, 2, 1},
                 {1, 2, 7, 1, 1, 1, 1, 1, 1, 1, 1, 8, 2, 7, 8, 2, 7, 1, 1, 1, 1, 1, 1, 1, 1, 8, 2, 1},
                 {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    this->mapSpritesID = std::vector<std::vector<Entity>>(this->map.size(), std::vector<Entity>(this->map[0].size()));
    this->deltaTime = 0.0;
    this->seconds = 0.0;
    this->frameRate = 30;
    this->frames = 0;
}

PacmanGame::~PacmanGame()
{
}

void PacmanGame::setLib(std::shared_ptr<ILibs> &lib)
{
    this->graphics = lib;
}

void PacmanGame::initGameData()
{
    for (size_t y = 0; y < this->map.size(); y++) {
        for (size_t x = 0; x < this->map[y].size(); x++) {
            this->mapSpritesID[y][x].setLibPtr(this->graphics);
            this->mapSpritesID[y][x].setPosition(92 + x*32, 44 + y*32);
        }
    }
    this->player = std::make_unique<Pacman>(this->graphics);
}

bool PacmanGame::isAdjacentCellForbidden(int x, int y)
{
    // check if any of the 8 surrounding cells are forbiden for PacMan to walk in
    if (x == 0 || x == this->map[0].size() -1 || y == 0 || y == this->map.size() -1)
        return (true);
    if (this->map[y - 1][x] == 4 || this->map[y + 1][x] == 4 || this->map[y - 1][x - 1] == 4 || this->map[y - 1][x +1] == 4 \
        || this->map[y + 1][x - 1] == 4 || this->map[y + 1][x + 1] == 4 || this->map[y][x - 1] == 4 || this->map[y][x + 1] == 4)
        return true;
    return false;
}

void PacmanGame::initMapBorder(int x, int y)
{
    if (y == 0 && x == 0) { // top left corner
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    } else if (y == this->map.size() - 1 && x == this->map[0].size() - 1) { // bot right corner
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    } else if (y == 0 && x == this->map[0].size() - 1) { // top right corner
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    } else if (y == this->map.size() - 1 && x == 0) { // bot left corner
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    } else if (y == 0) { // top row
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("pacman/resources/border_4.png");
    } else if (y == this->map.size() - 1) { // bot row
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("pacman/resources/border_3.png");
    } else if (x == 0) { // first column
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("pacman/resources/border_2.png");
    } else if (x == this->map[0].size() - 1) { // last column
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("pacman/resources/border_1.png");
    } else {
        this->mapSpritesID[y][x].setType(SHAPE);
        this->mapSpritesID[y][x].addShape(32, 32, 30, 30, 230);
    }
}

void PacmanGame::initMapCell(int x, int y)
{
    if (this->map[y][x] == 1) {
        if (y > 0 && y < this->map.size() && x > 0 && x < this->map[0].size() && !this->isAdjacentCellForbidden(x, y)) {
            this->mapSpritesID[y][x].setType(SPRITE);
            if (this->map[y - 1][x] == 1 && this->map[y + 1][x] == 1 && this->map[y][x - 1] == 1 && this->map[y][x + 1] == 1)
                this->mapSpritesID[y][x].addImage("pacman/resources/empty.png");
            else if (this->map[y - 1][x] == 2 || this->map[y - 1][x] == 3 || this->map[y - 1][x] == 0)
                this->mapSpritesID[y][x].addImage("pacman/resources/wall_horizontal_up.png");
            else if (this->map[y + 1][x] == 2 || this->map[y + 1][x] == 3 || this->map[y + 1][x] == 0)
                this->mapSpritesID[y][x].addImage("pacman/resources/wall_horizontal_down.png");
            else if (this->map[y][x - 1] == 2 || this->map[y][x - 1] == 3 || this->map[y][x - 1] == 0)
                this->mapSpritesID[y][x].addImage("pacman/resources/wall_vertical_left.png");
            else if (this->map[y][x + 1] == 2 || this->map[y][x + 1] == 3 || this->map[y][x + 1] == 0)
                this->mapSpritesID[y][x].addImage("pacman/resources/wall_vertical_right.png");
        } else {
            this->initMapBorder(x, y);
        }
    } else if (this->map[y][x] == 5) {
        if (this->map[y + 1][x + 1] != 1 && this->map[y + 1][x + 1] != 5) {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("pacman/resources/inward_coner_4.png");
        } else {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("pacman/resources/turn_up_right.png");
        }
    } else if (this->map[y][x] == 6) {
        if (this->map[y + 1][x - 1] != 1 && this->map[y + 1][x - 1] != 6) {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("pacman/resources/inward_coner_3.png");
        } else {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("pacman/resources/turn_up_left.png");
        }
    } else if (this->map[y][x] == 7) {
        if (this->map[y - 1][x + 1] != 1 && this->map[y - 1][x + 1] != 7) {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("pacman/resources/inward_coner_1.png");
        } else {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("pacman/resources/turn_down_right.png");
        }
    } else if (this->map[y][x] == 8) {
        if (this->map[y - 1][x - 1] != 1 && this->map[y - 1][x - 1] != 8) {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("pacman/resources/inward_coner_2.png");
        } else {
            this->mapSpritesID[y][x].setType(SPRITE);
            this->mapSpritesID[y][x].addImage("pacman/resources/turn_down_left.png");
        }
    } else if (this->map[y][x] == 2) {
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("pacman/resources/small_coin.png");
    } else if (this->map[y][x] == 3) {
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("pacman/resources/big_coin_1.png");
    } else if (this->map[y][x] == 0 || this->map[y][x] == 4) {
        this->mapSpritesID[y][x].setType(SPRITE);
        this->mapSpritesID[y][x].addImage("pacman/resources/empty.png");
    }
    this->mapSpritesID[y][x].updatePosition();
}

void PacmanGame::initGraphics()
{
    for (size_t y = 0; y < this->map.size(); y++) {
        for (size_t x = 0; x < this->map[y].size(); x++) {
            this->initMapCell(x, y);
        }
    }
    this->player->initGraphics();
}

double PacmanGame::getFPS()
{
    frameRate = (double)frames*0.5 +  frameRate*0.5; //more stable
    std::cout << "FPS:" << frames << std::endl;
    frames = 0;
    this->seconds -= CLOCKS_PER_SEC;
    double averageFrameTimeMilliseconds  = 1000.0 / (frameRate == 0 ? 0.001 : frameRate);

    std::cout << "CPU time was:" << averageFrameTimeMilliseconds << std::endl;
}

void PacmanGame::runGame()
{
    this->beginFrame = std::clock();
    while (this->graphics->events()) {
        this->graphics->closeWindowEvent();
        if (this->graphics->rigthArrow())
            this->player->goRight();
        if (this->graphics->leftArrow())
            this->player->goLeft();
        if (this->graphics->upArrow())
            this->player->goUp();
        if (this->graphics->downArrow())
            this->player->goDown();
    }

    for (size_t y = 0; y < this->map.size(); y++) {
        for (size_t x = 0; x < this->map[y].size(); x++) {
            this->mapSpritesID[y][x].draw();
        }
    }
    this->player->draw();
    this->endFrame = std::clock();
    this->deltaTime = this->endFrame - this->beginFrame;
    this->frames++;
    this->seconds += this->deltaTime;

    if ((this->seconds / (double)CLOCKS_PER_SEC) * 1000 > 1000.0) // to have deltaTime in sec
        this->getFPS();
}

// extern "C" std::shared_ptr<Pacman> create_object()
// {
//     return std::make_shared<Pacman>();
// }