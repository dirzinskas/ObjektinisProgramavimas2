#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "studentas.h"
#include "zmogus.h"

TEST_CASE("Studento sukurimo defaultai", "[studentas]"){
    Studentas s;

    REQUIRE(s.egz_() == 0);
    REQUIRE(s.vidurkis_() == 0.0);
    REQUIRE(s.mediana_() == 0.0);
    REQUIRE(s.nd_().empty());
}