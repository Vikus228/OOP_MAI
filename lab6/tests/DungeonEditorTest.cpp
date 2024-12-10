#include <gtest/gtest.h>
#include "../include/DungeonEditor.h"
#include "../include/Logger.h"
#include <vector>
#include <memory>

// Тест на добавление NPC
TEST(DungeonEditorTest, AddNPC)
{
    DungeonEditor editor;
    std::vector<std::unique_ptr<NPC>> expectedNPCs;
    expectedNPCs.push_back(NPCFactory::createNPC("Knight", "Sir Lancelot", 100, 100));
    expectedNPCs.push_back(NPCFactory::createNPC("Pegasus", "Pegasus", 200, 200));
    expectedNPCs.push_back(NPCFactory::createNPC("Dragon", "Dragon", 300, 300));

    editor.addNPC("Knight", "Sir Lancelot", 100, 100);
    editor.addNPC("Pegasus", "Pegasus", 200, 200);
    editor.addNPC("Dragon", "Dragon", 300, 300);

    ASSERT_EQ(editor.getNPCs().size(), expectedNPCs.size());
}

// Тест на сохранение и загрузку NPC
TEST(DungeonEditorTest, SaveAndLoadNPC)
{
    DungeonEditor editor;
    editor.addNPC("Knight", "Sir Lancelot", 100, 100);
    editor.addNPC("Pegasus", "Pegasus", 200, 200);
    editor.addNPC("Dragon", "Dragon", 300, 300);

    editor.saveToFile("test_save.txt");
    DungeonEditor loadedEditor;
    loadedEditor.loadFromFile("test_save.txt");

    size_t expectedSize = 0;
    ASSERT_EQ(loadedEditor.getNPCs().size(), expectedSize);
}

// Тест на запуск боевого режима
TEST(DungeonEditorTest, StartBattle)
{
    DungeonEditor editor;
    editor.addNPC("Knight", "Sir Lancelot", 100, 100);
    editor.addNPC("Pegasus", "Pegasus", 200, 200);
    editor.addNPC("Dragon", "Dragon", 300, 300);

    editor.startBattle(150);

    size_t expectedSize = 1;
    ASSERT_EQ(editor.getNPCs().size(), expectedSize);
}

TEST(DungeonEditorTest, BoundaryConditions)
{
    DungeonEditor editor;

    editor.addNPC("Knight", "Sir Lancelot", 0, 0);
    editor.addNPC("Pegasus", "Pegasus", 500, 500);

    size_t expectedSize = 2;
    ASSERT_EQ(editor.getNPCs().size(), expectedSize);
}

TEST(DungeonEditorTest, SaveAndLoadEmptyNPCList)
{
    DungeonEditor editor;

    editor.saveToFile("test_save_empty.txt");
    DungeonEditor loadedEditor;
    loadedEditor.loadFromFile("test_save_empty.txt");

    size_t expectedSize = 0;
    ASSERT_EQ(loadedEditor.getNPCs().size(), expectedSize);
}

TEST(DungeonEditorTest, StartBattleWithZeroRange)
{
    DungeonEditor editor;
    editor.addNPC("Knight", "Sir Lancelot", 100, 100);
    editor.addNPC("Pegasus", "Pegasus", 200, 200);
    editor.addNPC("Dragon", "Dragon", 300, 300);

    editor.startBattle(0);

    size_t expectedSize = 3;
    ASSERT_EQ(editor.getNPCs().size(), expectedSize);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}