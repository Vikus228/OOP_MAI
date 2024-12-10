#include "DungeonEditor.h"
#include "Logger.h"
#include <iostream>
#include <sstream>

void DungeonEditor::addNPC(const std::string &type, const std::string &name, int x, int y)
{
    npcs.push_back(NPCFactory::createNPC(type, name, x, y));
}

void DungeonEditor::saveToFile(const std::string &filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (const auto &npc : npcs)
        {
            file << npc->getName() << " " << npc->getX() << " " << npc->getY() << std::endl;
        }
    }
}

void DungeonEditor::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string name;
        int x, y;
        while (file >> name >> x >> y)
        {
            npcs.push_back(NPCFactory::createNPC(name, name, x, y));
        }
    }
}

void DungeonEditor::printNPCs()
{
    for (const auto &npc : npcs)
    {
        std::cout << npc->getName() << " at (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
    }
}

void DungeonEditor::startBattle(int range)
{
    BattleVisitor visitor(range);
    visitor.setNPCs(npcs);
    visitor.battle();

    for (const auto &observer : observers)
    {
        std::ostringstream oss;
        oss << "Battle finished. Remaining NPCs: " << npcs.size();
        observer->update(oss.str());
    }
}

void DungeonEditor::attach(std::unique_ptr<Observer> observer)
{
    observers.push_back(std::move(observer));
}