#include "catch.hpp"

#include <Exercise3.h>

TEST_CASE() {
    REQUIRE( 3 * 4 == 12 );
}

TEST_CASE() {
    Exercise3 exe3;
    exe3.run("../exercises/sample4.txt");

    REQUIRE(exe3.readJoltage() == 357);
}