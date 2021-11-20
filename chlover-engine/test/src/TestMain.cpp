//======== TestMain.cpp ========
// Purpose:
//=============================

#include <chlover/core/application/ChloverApplication.hpp>

class TestMain : public chlover::ChloverApplication {
  public:
    TestMain(std::string name) : ChloverApplication(name) {
        onInitialize();
    }

    ~TestMain() {
        onEnd();
    }

    void onInitialize() override {
        std::printf("Hello, World!!\n");
    }

    void whileAlive() override {
        int i = 0;

        while (i < 10) {
            std::printf("Now running for the %ith time\n", i);
            i++;
        }
    }

    void onEnd() override {
        std::printf("Goodbye, World!\n");
    }
};

chlover::ChloverApplication* chlover::createApplication(int argc, char** argv) {
    return new TestMain("a");
}


