#include "gtest/gtest.h"

#include "matlab.hpp"

TEST(MatlabVectorTest, add) {

    Matlab::Vector v_sum = Matlab::add_vectors(Matlab::Vector{{3,4,5}}, Matlab::Vector {{5,4,3}});
    ASSERT_EQ(v_sum.size(), 3);
    EXPECT_EQ(v_sum[0], 8);
    EXPECT_EQ(v_sum[1], 8);
    EXPECT_EQ(v_sum[2], 8);
}

TEST(MatlabVectorTest, norm){
    Matlab::Vector v(3);
    v[0] = 3;
    v[1] = 4;

    EXPECT_EQ(v.norm(), 5);
}

TEST(MatlabVectorTest, createWithSize) {
    Matlab::Vector v(2U);

    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 0);
}

TEST(MatlabVectorTest, toString){
    const std::vector<int> v = {1, 2, 3};
    Matlab::Vector v1 (v);

    EXPECT_EQ(Matlab::to_string(v1), "[ 1, 2, 3 ]");
}

TEST(MatlabVectorTest1, add) {
    Matlab::Vector v1(std::vector<int>{1, 2});
    Matlab::Vector v2(std::vector<int>{4, 5});

    Matlab::Vector v_sum = Matlab::add_vectors(v1, v2);

    ASSERT_EQ(v_sum.size(), 2U);
    EXPECT_EQ(v_sum[0], 5);
    EXPECT_EQ(v_sum[1], 7);
}


TEST(MatrixTest, add) {
    Matlab::Matrix m1(std::vector<std::vector<int>>{
            std::vector<int>{1, 2},
            std::vector<int>{4, 5}
    });

    Matlab::Matrix m2(std::vector<std::vector<int>>{
            std::vector<int>({0, 1}),
            std::vector<int>({2, 3})
    });

    auto m_sum = Matlab::add_matrices(m1, m2);

    ASSERT_EQ(m_sum.size(), 2U);

    ASSERT_EQ(m_sum[0].size(), 2U);
    EXPECT_EQ(m_sum[0][0], 1);
    EXPECT_EQ(m_sum[0][1], 3);

    ASSERT_EQ(m_sum[1].size(), 2U);
    EXPECT_EQ(m_sum[1][0], 6);
    EXPECT_EQ(m_sum[1][1], 8);
}

TEST(MatrixTest, toString) {
    Matlab::Matrix m(std::vector<std::vector<int>>{
            std::vector<int>{1, 2},
            std::vector<int>{3, 4}
    });

    auto m_str = Matlab::to_string(m);
    auto r1_str = Matlab::to_string(m[0]);
    auto r2_str = Matlab::to_string(m[1]);

    std::string m_str_expect = std::string("")
                               + "[\n"
                               + "  " + r1_str + ",\n"
                               + "  " + r2_str + "\n"
                               + "]";

    ASSERT_EQ(m_str, m_str_expect);
}

TEST(MatlabVectorAuxTest, exceptionCatchingWhenAddingVectorsOfSameSizes) {
    Matlab::Vector v1(std::vector<int> { 1 });
    Matlab::Vector v2(std::vector<int> { 1 });

    EXPECT_EQ(Matlab::was_exception_raised_when_adding_vectors(v1, v2), "");
}

TEST(MatlabVectorAuxTest, exceptionCatchingWhenAddingVectorsOfDifferentSizes) {
    Matlab::Vector v1(std::vector<int> { 1 });
    Matlab::Vector v2(std::vector<int> { 1, 2 });

    EXPECT_EQ(Matlab::was_exception_raised_when_adding_vectors(v1, v2), "Vectors have unequal size (1 and 2)");
}
