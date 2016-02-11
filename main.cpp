#include "Rshell.h"

int main(int argc, char** argv){
    Rshell shell;
    Parser p;
    TreeCreator tc;
    shell.setParser(&p);
    shell.setTreeCreator(&tc);
    shell.run();

    return 0;
}
