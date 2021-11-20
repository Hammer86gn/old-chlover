//======== ChloverApplication.hpp ========
//Purpose:
//=============================

#include <string>

#ifndef CHLOVER_ENGINE_CHLOVERAPPLICATION_HPP
#define CHLOVER_ENGINE_CHLOVERAPPLICATION_HPP

namespace chlover {
    class ChloverApplication {
    public:
        explicit ChloverApplication(std::string name);
        ~ChloverApplication();

        virtual void onInitialize();

        virtual void whileAlive();

        virtual void onEnd();

    protected:
        std::string name;
    };

    extern ChloverApplication* createApplication(int argc, char** argv);
}

#endif
