//#include "gmock/gmock.h"
#include "gtest/gtest.h"

extern "C" {
#include "tasks.h"
}

TEST(TasksTest, ChooseMoreImportantTask) {
    // TODO: Zaimplementuj logikę poniższego scenariusza testowego:
    //   (1) Zdefiniuj dwa zadania: zadanie #1 o niskim priorytecie oraz
    //         zadanie #2 o średnim priorytecie.
    Task t1 = {1, LOW};
    Task t2 = {2, MEDIUM};
    //   (2) Upewnij się, że wywołanie funkcji choose_more_important_task() dla
    //         zadań #1 i #2 zwróciło uchwyt do zadania #2.
    const Task* important_task = choose_more_important_task(&t1, &t2);
    EXPECT_EQ(important_task, &t2);
    //   (3) Zmień priorytet zadania #1 na wysoki.
    t1.priority = HIGH;
    //   (4) Upewnij się, że wywołanie funkcji choose_more_important_task() dla
    //         zadań #1 i #2 zwróciło uchwyt do zadania #1.
    important_task = choose_more_important_task(&t1, &t2);
    EXPECT_EQ(important_task, &t1);
}

TEST(TasksTest, LastTwoBits) {
    // TODO: Zaimplementuj logikę poniższego scenariusza testowego:
    //   (1) Zdefiniuj zadanie o niskim priorytecie.
    Task t = {3, LOW};
    //   (2) Upewnij się, że wywołanie funkcji transform_task() dla
    //         tego zadania i z uchwytem do funkcji increase_priority()
    //         zmieniło priorytet zadania na wysoki.
    transform_task(&t, increase_priority);
    EXPECT_EQ(t.priority, HIGH);
    //   (3) Zmień priorytet zadania na średni.
    t.priority = MEDIUM;
    //   (4) Upewnij się, że wywołanie funkcji transform_task() dla
    //         tego zadania i z uchwytem do funkcji increase_priority()
    //         zmieniło priorytet zadania na wysoki.
    transform_task(&t, increase_priority);
    EXPECT_EQ(t.priority, HIGH);
}
