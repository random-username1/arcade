/**
 * \file SDLLib.hpp
 * \brief SDL Lib
 */
#ifndef SDL_HPP
#define SDL_HPP

#include <memory>
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "../ILibs.hpp"

/*! \class SDLLib
   * \brief class of SDL Library
   *
   */
class SDLLib : public ILibs
{
private:
    SDL_Window *gWindow = NULL;
    SDL_Surface * gScreenSurface = NULL;
    std::vector<SDL_Surface *> gTextSurface;
    SDL_Renderer *gRenderer = NULL;
    SDL_Surface *gHelloWorld = NULL;
    SDL_Event e;
    std::string text = "";
    std::string name = "";
    int indexGame = 0;
    int indexGameReturn = -1;
    int sizeGamesName = 0;
    bool rendertext = false;
    bool quit; 
    std::vector<SDL_Texture *> gTexture;
    std::vector<TTF_Font *> gFont;
    std::vector<SDL_Color> gColor;
    std::vector<SDL_Rect> gRect;
    SDL_Color color = {255, 255, 255};
    SDL_Color yellowColor = {255, 255, 0};
    SDL_Surface *surfacePseudo = NULL;
    SDL_Texture *texturePseudo = NULL;
    SDL_Surface *surfaceEnterPseudo = NULL;
    SDL_Texture *textureEnterPseudo = NULL;
    SDL_Surface *surfaceNextLib = NULL;
    SDL_Texture *textureNextLib = NULL;
    SDL_Surface *surfacePrevLib = NULL;
    SDL_Texture *texturePrevLib = NULL;
    SDL_Surface *surfaceYourName = NULL;
    SDL_Texture *textureYourName = NULL;
    std::vector<SDL_Surface *> gamesSurface;
    std::vector<SDL_Texture *> gamesTexture;
    std::vector<SDL_Rect> gamesRect;
    std::vector<SDL_Surface *> libsSurface;
    std::vector<SDL_Texture *> libsTexture;
    std::vector<SDL_Rect> libsRect;
    TTF_Font *font = NULL;
    int texW = 1000;
    int texH = 200;
    int count = 0;
    SDL_Rect rectPseudo = {240, 540, 100, 100};
    SDL_Rect rectEnterPseudo = {10, 100, texW, texH};
    SDL_Rect rectNextLib = {0, 200, 500, 100};
    SDL_Rect rectPrevLib = {0, 300, 500, 100};
    SDL_Rect rectYourName = {10, 10, 300, 50};
    std::vector<SDL_Rect> shapeRect;
    std::vector<ShapeType> shapeType;
    std::vector<SDL_Texture *> textureImage;
    std::vector<SDL_Rect> rectImage;

public : 
/**
 * \fn SDLLib()
 * \brief Constructor
 */
    SDLLib(/* args */);
    /**
 * \fn ~SDLLib();
 * \brief Destructor
 */
    ~SDLLib();
    /* ------------------------------- RELATED TO SHAPES ------------------------------- */
    // explicit. if rectangle -> use $width and $height, if sphere -> $width = radius
    // returns the index of the newly created shape in a std::vector of shapes
    int createShape(ShapeType, int width, int height = 0);
    // draws the shape contained at $index of the vector of shapes
    void drawShape(int index);
    // sets the position of the shape contained at $index of the vector of shapes
    void setShapePos(int index, float x, float y);
    // sets the color of the shape contained at $index of the vector of shapes
    void setShapeColor(int index, int r, int g, int b, int a = 255);
    // deletes the shape contained at $index of the vector of shapes
    void deleteShape(int index);

    /* ------------------------------- RELATED TO SPRITES ------------------------------- */
    // creates a sprite from an image and return its ID to later modify it
    int createImageFromFile(std::string filename);
    // draws the sprite contained at $ImageId of the vector of shapes
    void drawImage(int ImageId);
    // sets the position of the sprite contained at $ImageId of the vector of shapes
    void setImagePos(int ImageId, float x, float y);
    // deletes the sprite contained at $ImageId of the vector of sprites
    void deleteImage(int ImageId);

    /* ------------------------------- RELATED TO TEXT ------------------------------- */
    // creates a texture from the image file given as parameter
    // returns the index of the newly created texture
    int createFontFromFile(const std::string filename);
    // creates a text and sets if font according to the id returned by createFontFromFile()
    // returns the index of the newly created text
    int createText(std::string text, int fontId);
    // draws the text contained at $textId of the vector of shapes
    void drawText(int textId);
    // sets the string of a text element
    void setTextString(int textId, std::string str);
    // sets the position of the sprite contained at $spriteId of the vector of shapes
    void setTextPos(int textId, float x, float y);
    // sets the size of the text to $charSize
    void setTextCharSize(int textId, int charSize);
    // changes the color of the text
    void setTextColor(int textId, int r, int g, int b, int a = 255);
    // deletes the text contained at $textId of the vector of texts
    void deleteText(int TextId);
    // deletes the font contained at $fontId of the vector of fonts
    void deleteFont(int FontId);

    /* ------------------------------- RELATED TO WINDOWS ------------------------------- */
    // creates a window of size ($width * $height) and named $name
    void createWindow(int width, int height, std::string name);
    // returns true if the window is open
    bool isWindowOpen(void);
    // refreshes the window
    void clearWindow(void);
    // updates the display
    void update(void);
    // resizes window to ($width * $height)
    void resizeWindow(int width, int height);
    // renames the window to $name
    void renameWindow(std::string name);
    // deletes the window
    void deleteWindow(void);

    /* ------------------------------- RELATED TO EVENTS ------------------------------- */
    // handle events occuring in the window
    bool events(void);
    // closes the window in case of such an event
    bool closeWindowEvent(void);
    bool keyReleasedEvent(void);
    void nextGraphicLib(int &indexLib);
    void prevGraphicLib(int &indexLib);
    bool upArrow();
    bool downArrow();
    bool leftArrow();
    bool rigthArrow();
    void nextGameLib(int &indexGame);
    void prevGameLib(int &indexGame);
    void goToMenu(state &pgState);
    bool restartGame();
    /* ------------------------------- MENU ------------------------------- */
    // menu for selecting the graphical lib. returns 0 if nCurses is selected, 2 for SFML and 3 for SDL -1 for errors
    int libSelectionMenu(state &pgState, bool close, std::vector<std::string> &libsNames);
    // menu to select the game. returns 0 for game 0 if $gamesNames, 1 for game 2 if $gamesNames, etc...
    int gameSelectionMenu(state &pgState, bool close, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores);
    // menu to enter the name. returns string with the name
    std::string enterName(state &pgState, bool close);
    /**
     * \fn void eventMenu(int &indexLib)
     * \brief Check the events in the menu
     * 
     * \param indexLib of vector 
     */
    void eventMenu(int &indexLib);
    void init_menu(std::vector<std::string> &libsNames, std::vector<std::string> &gamesNames, std::vector<std::vector<std::string>> highScores, std::string &pseudo);
    int menu(state &pgState, bool close, std::vector<std::string> &libsNames, std::vector<std::string> &gamesName, std::vector<std::vector<std::string>> highScores, std::string &pseudo, int &indexLib);
};

#endif