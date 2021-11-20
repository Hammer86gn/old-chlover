//======== EntryPoint.cpp ========
// Purpose:
//=============================

#include <chlover/core/application/ChloverApplication.hpp>

extern chlover::ChloverApplication* chlover::createApplication(int argc, char** argv);

int main(int argc, char** argv) {
    auto game = chlover::createApplication(argc, argv);
    game->whileAlive();

    delete game;
    return 0;
}