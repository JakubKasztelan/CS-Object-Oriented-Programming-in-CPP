#include "Map.h"
#include "Employee.h"
#include "Book.h"

#include <gtest/gtest.h>
#include <string>
#include <sstream>

typedef unsigned int ID;
typedef Map<ID, Employee> Database;

TEST(MapTest, AddAndFindEmployees) {
    Database db;
    db.add(761028073, Employee("Jan Kowalski", "salesman", 28));
    db.add(510212881, Employee("Adam Nowak", "storekeeper", 54));
    db.add(730505129, Employee("Anna Zaradna", "secretary", 32));

    Employee* e1 = db.find(761028073);
    Employee* e2 = db.find(510212881);
    Employee* e3 = db.find(730505129);
    Employee* e4 = db.find(123456789);

    EXPECT_NE(e1, nullptr);
    EXPECT_EQ(e1->name, "Jan Kowalski");
    EXPECT_EQ(e1->position, "salesman");
    EXPECT_EQ(e1->age, 28);

    EXPECT_NE(e2, nullptr);
    EXPECT_EQ(e2->name, "Adam Nowak");
    EXPECT_EQ(e2->position, "storekeeper");
    EXPECT_EQ(e2->age, 54);

    EXPECT_NE(e3, nullptr);
    EXPECT_EQ(e3->name, "Anna Zaradna");
    EXPECT_EQ(e3->position, "secretary");
    EXPECT_EQ(e3->age, 32);

    EXPECT_EQ(e4, nullptr);
}

TEST(MapTest, UpdateExistingEmployee) {
    Database db;
    db.add(761028073, Employee("Jan Kowalski", "salesman", 28));
    db.add(761028073, Employee("Jan Kowalski", "manager", 29));

    Employee* e1 = db.find(761028073);
    EXPECT_NE(e1, nullptr);
    EXPECT_EQ(e1->position, "manager");
    EXPECT_EQ(e1->age, 29);
}

TEST(MapTest, CopyConstructor) {
    Database db;
    db.add(761028073, Employee("Jan Kowalski", "salesman", 28));
    db.add(510212881, Employee("Adam Nowak", "storekeeper", 54));

    Database copyDb = db;
    Employee* e1 = copyDb.find(761028073);
    Employee* e2 = copyDb.find(510212881);

    EXPECT_NE(e1, nullptr);
    EXPECT_NE(e2, nullptr);
    EXPECT_EQ(e1->name, "Jan Kowalski");
    EXPECT_EQ(e2->name, "Adam Nowak");

    e1->age = 30;
    EXPECT_EQ(db.find(761028073)->age, 28);
}

TEST(MapTest, AssignmentOperator) {
    Database db;
    db.add(761028073, Employee("Jan Kowalski", "salesman", 28));

    Database newDb;
    newDb.add(510212881, Employee("Adam Nowak", "storekeeper", 54));

    newDb = db;
    Employee* e1 = newDb.find(761028073);
    Employee* e2 = newDb.find(510212881);

    EXPECT_NE(e1, nullptr);
    EXPECT_EQ(e1->name, "Jan Kowalski");
    EXPECT_EQ(e1->age, 28);

    EXPECT_EQ(e2, nullptr);
}

TEST(MapTest, LibraryExample) {
    Map<std::string, Book> library;
    library.add("C++", Book("Kowalski", "Programming", 300, "on shelf"));
    library.add("Mathematics 1", Book("Nowak", "Mathematics", 250, "borrowed"));

    Book* l1 = library.find("C++");
    Book* l2 = library.find("Mathematics 1");
    Book* l3 = library.find("Java");

    EXPECT_NE(l1, nullptr);
    EXPECT_NE(l2, nullptr);
    EXPECT_EQ(l3, nullptr);

    EXPECT_EQ(l1->author, "Kowalski");
    EXPECT_EQ(l1->category, "Programming");
    EXPECT_EQ(l1->status, "on shelf");

    EXPECT_EQ(l2->author, "Nowak");
    EXPECT_EQ(l2->category, "Mathematics");
    EXPECT_EQ(l2->status, "borrowed");
}
