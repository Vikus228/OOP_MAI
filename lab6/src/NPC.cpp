#include "NPC.h"
#include "BattleVisitor.h"

NPC::NPC(const std::string &name, int x, int y) : name(name), x(x), y(y) {}

const std::string &NPC::getName() const
{
    return name;
}

int NPC::getX() const
{
    return x;
}

int NPC::getY() const
{
    return y;
}

Knight::Knight(const std::string &name, int x, int y) : NPC(name, x, y) {}

void Knight::accept(BattleVisitor &visitor)
{
    visitor.visit(*this);
}

Pegasus::Pegasus(const std::string &name, int x, int y) : NPC(name, x, y) {}

void Pegasus::accept(BattleVisitor &visitor)
{
    visitor.visit(*this);
}

Dragon::Dragon(const std::string &name, int x, int y) : NPC(name, x, y) {}

void Dragon::accept(BattleVisitor &visitor)
{
    visitor.visit(*this);
}