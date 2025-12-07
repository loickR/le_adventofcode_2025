#include "catch.hpp"

#include <Exercise1.h>

TEST_CASE () {
    REQUIRE( 2 * 3 == 6 );
}

TEST_CASE ("Exercice1 partie1 - exemple") {
    Exercise1 exe1;
    exe1.run("../exercises/sample.txt");

    REQUIRE(exe1.readPassword() == 3);
}

/*
TEST_CASE ("Exercice1 partie2 - exemple") {
    Exercise1 exe1;
    exe1.run2("../exercises/sample.txt");

    REQUIRE(exe1.readPassword() == 6);
}*/

/*
TEST_CASE ("Exercice1 partie2 - exercice") {
    Exercise1 exe1;
    exe1.doExercice1P1();
}

TEST_CASE ("Exercice1 partie2 - exercice") {
    Exercise1 exe1;
    exe1.doExercice1P2();
}*/