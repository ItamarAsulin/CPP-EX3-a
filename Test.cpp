//
// Created by itamarq on 06/04/2022.
//

#include "doctest.h"
#include <iostream>
#include "Matrix.hpp"
#include <vector>

TEST_CASE ("Bad input") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    CHECK_THROWS(zich::Matrix(identity, 1, 3));
    CHECK_THROWS(zich::Matrix(identity, 5, 8));
    CHECK_THROWS(zich::Matrix(identity, -3, -3));
    CHECK_THROWS(zich::Matrix(identity, 3, -3));
    CHECK_THROWS(zich::Matrix(identity, -3, 3));
}
TEST_CASE("Bad Sum"){
    std::vector<double> identity3By3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity4By4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    zich::Matrix mat1 = zich::Matrix(identity3By3, 3, 3);
    zich::Matrix mat2 = zich::Matrix(identity4By4,4,4);
    CHECK_THROWS(mat1 + mat2);
}

TEST_CASE("Bad Subtract"){
    std::vector<double> identity3By3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity4By4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    zich::Matrix mat1 = zich::Matrix(identity3By3, 3, 3);
    zich::Matrix mat2 = zich::Matrix(identity4By4,4,4);
            CHECK_THROWS(mat1 - mat2);
}

TEST_CASE("Bad Multiplication"){
    std::vector<double> identity3By3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity4By4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    zich::Matrix mat1 = zich::Matrix(identity3By3, 3, 3);
    zich::Matrix mat2 = zich::Matrix(identity4By4,4,4);
            CHECK_THROWS(mat1 * mat2);
}


TEST_CASE("Sum Check"){
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identityPlus1 = {2, 1, 1, 1, 2, 1, 1, 1, 2};
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    std::vector<double> identity3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> identity4 = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    zich::Matrix mat1 = zich::Matrix(identity, 3, 3);
    zich::Matrix mat2 = zich::Matrix(identity2, 3, 3);
    zich::Matrix mat3 = zich::Matrix(identity3, 3, 3);
    zich::Matrix mat4 = zich::Matrix(identity4, 3, 3);
    zich::Matrix mat1Plus1 = zich::Matrix(identityPlus1, 3, 3);

    CHECK((mat1 + mat2) == mat3);
    ++mat1;
    CHECK(mat1 == mat1Plus1);
    mat2 += mat2;
    CHECK(mat2 == mat4);
}

TEST_CASE("Subtract Check"){
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity1Minus1 = {0,-1,-1,-1,0,-1,-1,-1,0};
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    std::vector<double> identity0 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    zich::Matrix mat1 = zich::Matrix(identity, 3, 3);
    zich::Matrix mat2 = zich::Matrix(identity2, 3, 3);
    zich::Matrix mat0 = zich::Matrix(identity0, 3, 3);
    zich::Matrix mat1Minus1 = zich::Matrix(identity1Minus1, 3, 3);
    mat2 -= mat1;
            CHECK(mat2 == mat1);
    --mat1;
            CHECK(mat1 == mat1Minus1);
    mat2 -= mat2;
            CHECK(mat2 == mat0);
}

TEST_CASE("multiplication Check"){
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    std::vector<double> identity0 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> identity4 = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    zich::Matrix mat1 = zich::Matrix(identity, 3, 3);
    zich::Matrix mat2 = zich::Matrix(identity2, 3, 3);
    zich::Matrix mat0 = zich::Matrix(identity0, 3, 3);
    zich::Matrix mat4 = zich::Matrix(identity4, 3, 3);
    zich::Matrix mat2TimesMat1 = mat2 * mat1;
    CHECK( mat2TimesMat1== mat2);
    zich::Matrix mat2TimesMat0 = mat2 * mat0;
    CHECK(mat2TimesMat0 == mat0);
    mat2*= mat2;
    CHECK(mat2 == mat4);

}

TEST_CASE("Less Than Greater Than Check"){
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    std::vector<double> identity0 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> identity4 = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    zich::Matrix mat1 = zich::Matrix(identity, 3, 3);
    zich::Matrix mat2 = zich::Matrix(identity2, 3, 3);
    zich::Matrix mat0 = zich::Matrix(identity0, 3, 3);
    zich::Matrix mat4 = zich::Matrix(identity4, 3, 3);

    CHECK(mat0 < mat1);
    CHECK(mat2 < mat4);
    CHECK(mat1 < mat2);
    ++mat1;
    CHECK_FALSE(mat1 < mat2);
    CHECK(mat1 <= mat2);
}

TEST_CASE("Equal Check"){
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    std::vector<double> identity0 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> identity4 = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    zich::Matrix mat1 = zich::Matrix(identity, 3, 3);
    zich::Matrix mat2 = zich::Matrix(identity2, 3, 3);
    zich::Matrix mat0 = zich::Matrix(identity0, 3, 3);
    zich::Matrix mat4 = zich::Matrix(identity4, 3, 3);

    CHECK_FALSE(mat1 == mat2);
    ++mat1;
    CHECK(mat1 == mat2);
}
TEST_CASE("Not Equal Check"){
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    zich::Matrix mat1 = zich::Matrix(identity, 3, 3);
    zich::Matrix mat2 = zich::Matrix(identity2, 3, 3);
    CHECK(mat1 != mat2);
}