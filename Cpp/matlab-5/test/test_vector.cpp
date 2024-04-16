#include "gtest/gtest.h"

#include "matlab.hpp"

TEST(MatlabVectorTest, add) {

    MatVect v_sum = add_vectors(MatVect{{3,4,5}}, MatVect {{5,4,3}});
    ASSERT_EQ(v_sum.size(), 3);
    EXPECT_EQ(v_sum[0], 8);
    EXPECT_EQ(v_sum[1], 8);
    EXPECT_EQ(v_sum[2], 8);
}

TEST(MatlabVectorTest, norm){
    MatVect v(3);
    v[0] = 3;
    v[1] = 4;

    EXPECT_EQ(v.norm(), 5);
}

TEST(MatlabVectorTest, createWithSize) {
    MatVect v(2U);

    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 0);
}

TEST(MatlabVectorTest, to_string){
    const std::vector<int> v = {1, 2, 3};
    MatVect v1 (v);

    EXPECT_EQ(to_string(v1), "[ 1, 2, 3 ]");
}

TEST(MatlabVectorTest1, add) {
    MatVect v1(std::vector<int>{1, 2});
    MatVect v2(std::vector<int>{4, 5});

    MatVect v_sum = add_vectors(v1, v2);

    ASSERT_EQ(v_sum.size(), 2U);
    EXPECT_EQ(v_sum[0], 5);
    EXPECT_EQ(v_sum[1], 7);
}


TEST(MatlabMatrixTest, add) {
    Matrix m1(std::vector<std::vector<int>>{
            std::vector<int>{1, 2},
            std::vector<int>{4, 5}
    });

    Matrix m2(std::vector<std::vector<int>>{
            std::vector<int>({0, 1}),
            std::vector<int>({2, 3})
    });

    auto m_sum = add_matrices(m1, m2);

    ASSERT_EQ(m_sum.size(), 2U);

    ASSERT_EQ(m_sum[0].size(), 2U);
    EXPECT_EQ(m_sum[0][0], 1);
    EXPECT_EQ(m_sum[0][1], 3);

    ASSERT_EQ(m_sum[1].size(), 2U);
    EXPECT_EQ(m_sum[1][0], 6);
    EXPECT_EQ(m_sum[1][1], 8);
}

TEST(MatlabMatrixTest, toString) {
    Matrix m(std::vector<std::vector<int>>{
            std::vector<int>{1, 2},
            std::vector<int>{3, 4}
    });

    auto m_str = to_string(m);
    auto r1_str = to_string(m[0]);
    auto r2_str = to_string(m[1]);

    std::string m_str_expect = std::string("")
                               + "[\n"
                               + "  " + r1_str + ",\n"
                               + "  " + r2_str + "\n"
                               + "]";

    ASSERT_EQ(m_str, m_str_expect);
}