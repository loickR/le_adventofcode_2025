#include "catch.hpp"

#include <Exercise2.h>

TEST_CASE() {
    REQUIRE( 2 * 5 == 10);
}

TEST_CASE() {
    Exercise2 exe2;
    exe2.run("../exercises/sample2.txt");
    REQUIRE( exe2.readWrongIdsCount() == 1227775554 );
}

TEST_CASE() {
    Exercise2 exe2;
    exe2.run("../exercises/exercice2.txt");
    REQUIRE( exe2.readWrongIdsCount() == 19128774598 );
}

TEST_CASE() {
    Exercise2 exe2;
    exe2.run2("../exercises/exercice2.txt");
    REQUIRE( exe2.readWrongIdsCount() == 4174379265 );
}

/*
TEST_CASE() {
    Exercise2 exe2;
    exe2.run2("../exercises/exercice2.txt");
}*/