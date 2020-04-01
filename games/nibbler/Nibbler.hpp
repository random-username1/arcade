#ifndef NIBBLER_HPP
#define NIBLLER_HPP

#include <vector>
#include <memory>
#include "../../lib/ILibs.hpp"
#include "../IGames.hpp"
#include "../Entity.hpp"

enum Direction {
    RIGTH,
    LEFT,
    UP,
    DOWN
};

class Nibbler : public Igames
{
private:
    Direction dir;
    int speed;
    std::unique_ptr<Entity> food;
    std::vector<int> indexSnake;
    std::vector<std::unique_ptr<Entity>> snake;
    std::unique_ptr<ILibs> Lib;
    int prevPosx;
    int prevPosy;
    int indexFood;
public:
    Nibbler();
    void keyPressed();
    void moove();
    void eatFood();
    void setPos();
    void initGameData();
    void initGraphics();
    void runGame();
};

#endif