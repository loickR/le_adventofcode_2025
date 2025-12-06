#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../../sources/Exercise2.h"

TEST_CASE() {
    REQUIRE( 2 * 5 == 10);
}

TEST_CASE() {
    Exercise2 exe2;
    exe2.run("../exercises/sample2.txt");
    REQUIRE( exe2.readWrongIdsCount() == 1227775554 );
}