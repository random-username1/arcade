#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <dlfcn.h>
#include <memory>
#include <vector>
#include <dirent.h>
#include <regex>
#include "../lib/ILibs.hpp"

class Core
{
private:
    void *m_handle;
    char *m_arg;
    int indexLib;
    bool isMenuInit=false;
    std::vector<std::string> m_libs;
    std::vector<std::string> m_games;
    std::unique_ptr<ILibs> Lib;

public : Core(char *arg);
    ~Core();
    const std::vector<std::string> &getLibs() const;
    const std::vector<std::string> &getGames() const;
    void nextLib(std::string libName);
    void indexLibFill();
    void changeLib();
    void fillLibVector();
    void fillGamesVector();
    void laodLib();

    void loop();

};

#endif