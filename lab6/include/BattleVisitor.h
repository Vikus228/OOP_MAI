#ifndef BATTLEVISITOR_H
#define BATTLEVISITOR_H

#include "NPC.h"
#include <vector>
#include <memory>

class BattleVisitor
{
public:
    BattleVisitor(int range);
    void visit(Knight &knight);
    void visit(Pegasus &pegasus);
    void visit(Dragon &dragon);

    void setNPCs(std::vector<std::unique_ptr<NPC>> &npcs);
    void battle();

private:
    int range;
    std::vector<std::unique_ptr<NPC>> *npcs;
};

#endif // BATTLEVISITOR_H