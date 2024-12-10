#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <memory>

class NPC
{
public:
    NPC(const std::string &name, int x, int y);
    virtual ~NPC() = default;

    const std::string &getName() const;
    int getX() const;
    int getY() const;

    virtual void accept(class BattleVisitor &visitor) = 0;

protected:
    std::string name;
    int x, y;
};

class Knight : public NPC
{
public:
    Knight(const std::string &name, int x, int y);
    void accept(BattleVisitor &visitor) override;
};

class Pegasus : public NPC
{
public:
    Pegasus(const std::string &name, int x, int y);
    void accept(BattleVisitor &visitor) override;
};

class Dragon : public NPC
{
public:
    Dragon(const std::string &name, int x, int y);
    void accept(BattleVisitor &visitor) override;
};

#endif // NPC_H