#ifndef DUNGEONEDITOR_H
#define DUNGEONEDITOR_H

#include "NPC.h"
#include "NPCFactory.h"
#include "BattleVisitor.h"
#include "Observer.h"
#include <vector>
#include <memory>
#include <fstream>

class DungeonEditor
{
public:
    void addNPC(const std::string &type, const std::string &name, int x, int y);
    void saveToFile(const std::string &filename);
    void loadFromFile(const std::string &filename);
    void printNPCs();
    void startBattle(int range);
    void attach(std::unique_ptr<Observer> observer);

    const std::vector<std::unique_ptr<NPC>> &getNPCs() const { return npcs; }

private:
    std::vector<std::unique_ptr<NPC>> npcs;
    std::vector<std::unique_ptr<Observer>> observers;
};

#endif