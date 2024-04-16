#include "gtest/gtest.h"

#include "matlab.hpp"

TEST(MatlabVectorTest, add) {
    MatVect v1(3);
    v1.set_elem(0, 3);
    v1.set_elem(1, 4);
    v1.set_elem(2, 5);

    MatVect v2(3);
    v2.set_elem(0, 5);
    v2.set_elem(1, 4);
    v2.set_elem(2, 3);

    MatVect v_sum = add_vectors(v1, v2);

    ASSERT_EQ(v_sum.size(), 3);
    EXPECT_EQ(v_sum.get_elem(0), 8);
    EXPECT_EQ(v_sum.get_elem(1), 8);
    EXPECT_EQ(v_sum.get_elem(2), 8);
}

TEST(MatlabVectorTest, norm){
    MatVect v(3); ///musi byc 3U?
    v.set_elem(0, 3);
    v.set_elem(1, 4);

    EXPECT_EQ(v.norm(), 5);
}

TEST(MatlabVectorTest, createWithSize) {
    MatVect v(2U);

    ASSERT_EQ(v.size(), 2U);  // przyrostek "U" oznacza wartość bez znaku (ang. unsigned)
    EXPECT_EQ(v.get_elem(0), 0);
    EXPECT_EQ(v.get_elem(1), 0);
}
