#include "DungeonEditor.h"
#include "Logger.h"
#include <iostream>

int main()
{
    DungeonEditor editor;

    editor.attach(std::make_unique<FileLogger>());
    editor.attach(std::make_unique<ConsoleLogger>());

    editor.addNPC("Knight", "Sir Lancelot", 100, 100);
    editor.addNPC("Pegasus", "Pegasus", 200, 200);
    editor.addNPC("Dragon", "Dragon", 300, 300);

    editor.printNPCs();

    editor.startBattle(150);

    editor.printNPCs();

    return 0;
}