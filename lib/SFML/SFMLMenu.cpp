/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLMenu
*/

/**
 * \file SFMLMenu.cpp
 * \brief Menu SFML
 */

#include "SFMLMenu.hpp"

SFMLMenu::SFMLMenu(SFMLLib *lib)
{
    this->graphics = lib;
}

SFMLMenu::~SFMLMenu()
{
}

void SFMLMenu::init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo)
{
    this->bgID = graphics->createImageFromFile("resources/background.png");
    this->fontID = graphics->createFontFromFile("resources/ARCADE_I.TTF");

    this->nibblerImgID = graphics->createImageFromFile("games/nibbler/preview.jpg");
    this->pacmanImgID = graphics->createImageFromFile("games/pacman/preview.png");

    // create play btn
    this->buttons.push_back(graphics->createText("PLAY", this->fontID));
    graphics->setTextCharSize(this->buttons[0], 50);
    graphics->setTextPos(this->buttons[0], 440, 760);

    // create highscore btn
    this->buttons.push_back(graphics->createText("Highscores", this->fontID));
    graphics->setTextCharSize(this->buttons[1], 20);
    graphics->setTextPos(this->buttons[1], 440, 860);

    // creates games btn
    for (int i = 0; i < gamesNames.size(); i++)
        this->buttons.push_back(graphics->createText(gamesNames[i], this->fontID));
    graphics->setTextColor(this->buttons[this->currentBtn], 230, 230, 0);

    graphics->setImagePos(this->pacmanImgID, 355, 590);
    graphics->setImagePos(this->nibblerImgID, 592, 590);
    
    int xPos = 335;
    for (int i = 2; i < gamesNames.size() + 2; i++) { // i = 2 bcs i=0 is the play btn and i=1 is highscores btn
        graphics->setTextPos(this->buttons[i], xPos, 548);
        xPos += 220;
    }

    // create high scores
    std::vector<std::vector<std::string>>::iterator it;
    xPos = 335;
    int yPos = 625;
    int j = 0;
    for (it = highScores.begin(); it < highScores.end(); it++) {
        this->scoreTextID.resize(j+1);
        for (int i = 0; i < it->size(); i++) {
            this->scoreTextID[j].push_back(graphics->createText(highScores[j][i], this->fontID));
            graphics->setTextPos(this->scoreTextID[j][i], xPos, yPos);
            graphics->setTextCharSize(this->scoreTextID[j][i], 13);
            yPos += 35;
        }
        j++;
        yPos = 625;
        xPos += 220;
    }

    // create libs texts
    xPos = 290;
    yPos = 1050;
    for (size_t i = 0; i < libsNames.size(); i++) {
        this->textLibsID.push_back(this->graphics->createText(libsNames[i], this->fontID));
        this->graphics->setTextCharSize(this->textLibsID[i], 20);
        this->graphics->setTextPos(this->textLibsID[i], xPos, yPos);
        if (libsNames[i] == "SFML" || libsNames[i] == "sfml")
            this->graphics->setTextColor(this->textLibsID[i], 0, 255, 0); // 30, 230, 30
        xPos += 200;
    }
    this->nextLibTxtID = this->graphics->createText("E ->", this->fontID);
    this->graphics->setTextCharSize(this->nextLibTxtID, 20);
    this->graphics->setTextPos(this->nextLibTxtID, 975, 1050);

    this->prevLibTxtID = this->graphics->createText("<- A", this->fontID);
    this->graphics->setTextCharSize(this->prevLibTxtID, 20);
    this->graphics->setTextPos(this->prevLibTxtID, 30, 1050);
}

int SFMLMenu::menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib)
{

    if (pseudo.empty())
        this->getPseudo(pgState, pseudo);

    // events
    while (graphics->events()) {
        if (graphics->closeWindowEvent())
            pgState = NOTHING;
        if (graphics->keyReleasedEvent())
            this->isKeyDown = false;
        graphics->nextGraphicLib(indexLib);
        graphics->prevGraphicLib(indexLib);
    }

    graphics->clearWindow();
    
    // check btn
    if (this->chosenGame == -1)
        this->chooseGame();
    else {
        if (!this->isHighscoresMenu)
            this->rechoose();
        if (this->chosenAction == -1) {
            this->chooseAction();
            if (this->chosenAction == 1)
                this->isHighscoresMenu = true;
        }
    }

    graphics->drawImage(this->bgID);
    if (this->chosenAction == -1) {
        // draw buttons
        for (int i = 0; i < this->buttons.size(); i++)
            graphics->drawText(this->buttons[i]);
        graphics->drawImage(this->pacmanImgID);
        graphics->drawImage(this->nibblerImgID);
    } else if (this->chosenAction == 0) {
        pgState = GAME;
        graphics->update();
        return (this->chosenGame);
    } else if (this->chosenAction == 1) {
        this->displayHighScores(this->buttons);
    }
    // draw libs texts
    this->graphics->drawText(this->nextLibTxtID);
    this->graphics->drawText(this->prevLibTxtID);
    for (size_t i = 0; i < this->textLibsID.size(); i++) {
        this->graphics->drawText(this->textLibsID[i]);
    }
    

    graphics->update();
    return (-1);
}

void SFMLMenu::chooseGame()
{
    graphics->setTextColor(this->buttons[this->currentBtn], 255, 255, 255);
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->isKeyDown = true;
        if (this->currentBtn < this->buttons.size() - 1)
            this->currentBtn++;
        else
            this->currentBtn = 2;
    }
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->isKeyDown = true;
        if (this->currentBtn > 2)
            this->currentBtn--;
        else
            this->currentBtn = this->buttons.size() - 1;
    }
    graphics->setTextColor(this->buttons[this->currentBtn], 230, 230, 0);
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        graphics->setTextColor(this->buttons[this->currentBtn], 30, 230, 30);
        this->isKeyDown = true;
        this->chosenGame = this->currentBtn - 2;
        this->currentBtn = 0;
        graphics->setTextColor(this->buttons[this->currentBtn], 230, 230, 0);
        return;
    }
    this->chosenGame = -1;
}

void SFMLMenu::rechoose()
{
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && this->chosenGame != -1) {
        this->isKeyDown = true;
        graphics->setTextColor(this->buttons[this->currentBtn], 255, 255, 255);
        graphics->setTextColor(this->buttons[2 + this->chosenGame], 230, 230, 0);
        this->currentBtn = 2 + chosenGame;
        this->chosenGame = -1;
    }
}

void SFMLMenu::chooseAction()
{
    graphics->setTextColor(this->buttons[this->currentBtn], 255, 255, 255);
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->isKeyDown = true;
        if (this->currentBtn < 1)
            this->currentBtn++;
        else
            this->currentBtn = 0;
    }
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->isKeyDown = true;
        if (this->currentBtn > 0)
            this->currentBtn--;
        else
            this->currentBtn = 1;
    }
    graphics->setTextColor(this->buttons[this->currentBtn], 230, 230, 0);
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        this->isKeyDown = true;
        this->graphics->setTextColor(this->buttons[this->currentBtn], 30, 230, 30);
        this->chosenAction = this->currentBtn;
        return;
    }
    this->chosenAction = -1;
}

void SFMLMenu::displayHighScores(std::vector<int> gamesNamesID)
{
    // draw games high scores
    int i = 0;
    
    graphics->drawText(gamesNamesID[this->chosenGame + 2]);
    for (i = 0; i != this->chosenGame && i < this->scoreTextID.size(); i++);
    for (int j = 0; j < this->scoreTextID[i].size(); j++) {
        graphics->drawText(this->scoreTextID[i][j]);
    }
    if (!this->isKeyDown && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
        this->isKeyDown = true;
        graphics->setTextColor(gamesNamesID[1], 230, 230, 0);
        this->chosenAction = -1;
        this->isHighscoresMenu = false;
    }
}

void SFMLMenu::getPseudo(state pgState, std::string &pseudo)
{
    sf::Event event;
    int textID = graphics->createText("enter your name :", this->fontID);
    int pseudoID = graphics->createText(pseudo, this->fontID);

    graphics->setTextPos(textID, 380, 660);
    graphics->setTextCharSize(textID, 20);
    graphics->setTextPos(pseudoID, 440, 700);

    while (graphics->isWindowOpen()) {
        while (graphics->events()) {
            if (graphics->closeWindowEvent())
                pgState = NOTHING;
            event = graphics->getEvt();
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128 && !this->isKeyDown) {
                    this->isKeyDown = true;
                    if (event.text.unicode == 13 || event.text.unicode == 10) { // enter key
                        return;
                    } else if (event.text.unicode == 8) { // backspace
                        if (pseudo.size() > 0) 
                            pseudo.resize(pseudo.size() - 1);
                    } else {
                        pseudo += static_cast<char>(event.text.unicode);
                    }
                }
            } else if (event.type == sf::Event::KeyReleased) {
                this->isKeyDown = false;
            }
        }
        graphics->clearWindow();

        graphics->setTextString(pseudoID, pseudo);
        graphics->drawImage(this->bgID);
        graphics->drawText(textID);
        graphics->drawText(pseudoID);

        graphics->update();
    }
}