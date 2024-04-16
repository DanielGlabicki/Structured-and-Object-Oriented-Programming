#include "gtest/gtest.h"

#include "matlab.hpp"

TEST(MatlabVectorTest, add) {
    /*MatVect v1(3);
    v1.set_elem(0, 3);
    v1.set_elem(1, 4);
    v1.set_elem(2, 5);

    MatVect v2(3);
    v2.set_elem(0, 5);
    v2.set_elem(1, 4);
    v2.set_elem(2, 3); */

    MatVect v_sum = add_vectors(MatVect{{3,4,5}}, MatVect {{5,4,3}});
///dobrze?
    ASSERT_EQ(v_sum.size(), 3);
    EXPECT_EQ(v_sum[0], 8);
    EXPECT_EQ(v_sum[1], 8);
    EXPECT_EQ(v_sum[2], 8);
}

TEST(MatlabVectorTest, norm){
    MatVect v(3); ///musi byc 3U?
    v[0] = 3;
    v[1] = 4;

    EXPECT_EQ(v.norm(), 5);
}

TEST(MatlabVectorTest, createWithSize) {
    MatVect v(2U);

    ASSERT_EQ(v.size(), 2U);  // przyrostek "U" oznacza wartoœæ bez znaku (ang. unsigned)
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 0);
}

TEST(MatlabVectorTest, to_string){
    const std::vector<int> v = {1, 2, 3};
    MatVect v1 (v);

    //ASSERT_EQ(v.size(), 3);///nie to chce testowac
    EXPECT_EQ(to_string(v1), "1 2 3 ");
}
//assert konczy program, expect tylko zglasza blad i idzie dalej
// assert jak cos by sie mialo dalej wykonac a nie powinno po bledzie
