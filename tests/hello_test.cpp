#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE("Basic Gradebook Tests") {
    Gradebook gb;

    gb.addStudent("Alan", "Guerrero", "1001");
    gb.addStudent("Malenia", "Maliketh", "1002");

    REQUIRE(gb.giveGrade("1001", "HW1", 95) == true);
    REQUIRE(gb.giveGrade("1002", "HW1", 88.5) == true);
    REQUIRE(gb.giveGrade("9999", "HW1", 90) == false);
    REQUIRE(gb.giveGrade("1001", "HW2", -5) == false);

    auto report = gb.printReport();
    REQUIRE(report.find("Alan Guerrero") != std::string::npos);
    REQUIRE(report.find("Malenia Maliketh") != std::string::npos);
    REQUIRE(report.find("HW1: 95") != std::string::npos);
    REQUIRE(report.find("HW1: 88.5") != std::string::npos);
}







