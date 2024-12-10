#include "BattleVisitor.h"
#include <cmath>
#include <algorithm>

BattleVisitor::BattleVisitor(int range) : range(range), npcs(nullptr) {}

void BattleVisitor::setNPCs(std::vector<std::unique_ptr<NPC>> &npcs)
{
    this->npcs = &npcs;
}

void BattleVisitor::visit(Knight &knight)
{
    for (auto &npc : *npcs)
    {
        if (npc.get() != &knight)
        {
            int dx = npc->getX() - knight.getX();
            int dy = npc->getY() - knight.getY();
            if (std::sqrt(dx * dx + dy * dy) <= range)
            {
                if (dynamic_cast<Dragon *>(npc.get()))
                {
                    npcs->erase(std::remove_if(npcs->begin(), npcs->end(), [&](const auto &n)
                                               { return n.get() == &knight || n.get() == npc.get(); }),
                                npcs->end());
                    break;
                }
            }
        }
    }
}

void BattleVisitor::visit(Pegasus &pegasus)
{
}

void BattleVisitor::visit(Dragon &dragon)
{
    for (auto &npc : *npcs)
    {
        if (npc.get() != &dragon)
        {
            int dx = npc->getX() - dragon.getX();
            int dy = npc->getY() - dragon.getY();
            if (std::sqrt(dx * dx + dy * dy) <= range)
            {
                if (dynamic_cast<Pegasus *>(npc.get()))
                {
                    npcs->erase(std::remove_if(npcs->begin(), npcs->end(), [&](const auto &n)
                                               { return n.get() == &dragon || n.get() == npc.get(); }),
                                npcs->end());
                    break;
                }
            }
        }
    }
}

void BattleVisitor::battle()
{
    for (auto &npc : *npcs)
    {
        npc->accept(*this);
    }
}