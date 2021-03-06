/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/
/**
 * \file Entity.cpp
 * \brief Entity
 */
#include "Entity.hpp"

Entity::Entity()
{
    this->currentShape = 0;
}

Entity::~Entity()
{
}

void Entity::move(float xOffset, float yOffset)
{
    this->posX += xOffset;
    this->posY += yOffset;
    for (size_t i = 0; i < this->shapes.size(); i++) {
        if (this->type == SHAPE)
            this->graphics->setShapePos(this->shapes[i], this->posX, this->posY);
        else if (this->type == SPRITE)
            this->graphics->setImagePos(this->shapes[i], this->posX, this->posY);
    }
}

void Entity::updatePosition()
{
    for (size_t i = 0; i < this->shapes.size(); i++) {
        if (this->type == SHAPE)
            this->graphics->setShapePos(this->shapes[i], this->posX, this->posY);
        else if (this->type == SPRITE)
            this->graphics->setImagePos(this->shapes[i], this->posX, this->posY);
    }
}

void Entity::addShape(int height, int width, int r, int g, int b)
{
    if (this->type == SHAPE) {
        this->shapes.push_back(this->graphics->createShape(RECTANGLE, width, height));
        this->graphics->setShapeColor(this->shapes[this->shapes.size() - 1], r, g, b);
    }
}

void Entity::addImage(std::string file)
{
    if (this->type == SPRITE)
        this->shapes.push_back(this->graphics->createImageFromFile(file));
}

void Entity::resetGraphics()
{
    this->shapes.clear();
    this->shapes.shrink_to_fit();
    this->currentShape = 0;
}

void Entity::nextShape()
{
    if (this->currentShape >= this->shapes.size() - 1)
        this->currentShape = 0;
    else
        this->currentShape++;
}

void Entity::prevShape()
{
    if (this->currentShape <= 0)
        this->currentShape = this->shapes.size() - 1;
    else
        this->currentShape--;
}

void Entity::changeColor(int r, int g, int b)
{
    if (this->type == SHAPE) {
        for (size_t i = 0; i < this->shapes.size(); i++)
            this->graphics->setShapeColor(this->shapes[i], r, g, b);
    }
}

void Entity::draw()
{
    if (this->type == SHAPE)
        this->graphics->drawShape(this->shapes[this->currentShape]);
    if (this->type == SPRITE)
        this->graphics->drawImage(this->shapes[this->currentShape]);
}

void Entity::setPosition(float x, float y)
{
    this->posX = x;
    this->posY = y;
    for (size_t i = 0; i < this->shapes.size(); i++) {
        if (this->type == SHAPE)
            this->graphics->setShapePos(this->shapes[i], this->posX, this->posY);
        else if (this->type == SPRITE)
            this->graphics->setImagePos(this->shapes[i], this->posX, this->posY);
    }
}

const float &Entity::getXposition() const
{
    return this->posX;
}

const float &Entity::getYposition() const
{
    return this->posY;
}

const std::vector<int> &Entity::getVectorOfShape() const
{
    return this->shapes;
}

void Entity::setLibPtr(std::shared_ptr<ILibs> lib)
{
    this->graphics = lib;
}

void Entity::setType(entityType type)
{
    this->type = type;
}