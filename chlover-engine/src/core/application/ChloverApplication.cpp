//======== ChloverApplication.cpp ========
//Purpose:
//=============================

#include <chlover/core/application/ChloverApplication.hpp>

chlover::ChloverApplication::ChloverApplication(std::string name) {
    this->name = name;

    this->onInitialize();
}

chlover::ChloverApplication::~ChloverApplication() {
    this->onEnd();
}

void chlover::ChloverApplication::onInitialize() {

}

void chlover::ChloverApplication::whileAlive() {

}

void chlover::ChloverApplication::onEnd() {

}
