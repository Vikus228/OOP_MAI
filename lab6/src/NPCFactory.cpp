#include "NPCFactory.h"
#include "NPC.h"

std::unique_ptr<NPC> NPCFactory::createNPC(const std::string &type, const std::string &name, int x, int y)
{
    if (type == "Knight")
    {
        return std::make_unique<Knight>(name, x, y);
    }
    else if (type == "Pegasus")
    {
        return std::make_unique<Pegasus>(name, x, y);
    }
    else if (type == "Dragon")
    {
        return std::make_unique<Dragon>(name, x, y);
    }
    return nullptr;
}