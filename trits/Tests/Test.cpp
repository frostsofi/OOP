#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../TritSet.h"

TEST(TritSetTests, TestCapasity){
    TritSet set(1000);
    EXPECT_GE(set.capacity(), 1000*2/8/sizeof(unsigned int));
    size_t allocLength = set.capacity();
   set[1000000000] = Unknown;

   EXPECT_EQ(allocLength, set.capacity());
   if(set[2000000000]==True){}
    EXPECT_EQ(allocLength, set.capacity());
   set[1000000000] = True;

   EXPECT_LT(allocLength, set.capacity());
    allocLength = set.capacity();
    set[1000000000] = Unknown;
    set[1000000] = False;

   EXPECT_EQ(allocLength, set.capacity());
}

TEST(TritSetTests, TestShrink){
    TritSet set(1000);
    set[1000000] = False;
    size_t allocLength = set.capacity();
    set.shrink();
    EXPECT_GT(allocLength, set.capacity());
}

TEST(TritSetTests, TestCardinality){
     TritSet set(8);
    set[1] = True;
    set[2] = False;
    set[3] = True;
    set[5] = True;
    EXPECT_EQ(3, set.cardinality(True));
    EXPECT_EQ(1, set.cardinality(False));
    EXPECT_EQ(4, set.cardinality(Unknown));
}

TEST(TritSetTests, TestTrim){
    TritSet set(8);
    set[1] = True;
    set[2] = False;
    set[3] = True;
    set[5] = True;
    set.trim(3);
    EXPECT_EQ(static_cast<int>(Unknown), static_cast<int>(set[5]));
    EXPECT_EQ(static_cast<int>(Unknown), static_cast<int>(set[3]));
}

TEST(TritSetTests, TestLength){
    TritSet set(8);
    set[1] = True;
    set[2] = False;
    set[3] = True;
    set[5] = True;
    EXPECT_EQ(5, set.length());
}

TEST(TritSetTests, operator_index){
    TritSet set(10);
    set[9] = Unknown;
    set[8] = False;
    set[2] = True;
    Trit a;
    a = set[2];
    EXPECT_EQ(a, Trit::True);
    a = set[8];
    EXPECT_EQ(a, Trit:: False);
    a = set[9];
    EXPECT_EQ(a, Trit:: Unknown);
}

TEST(TritSetTests, operator_eq){
    TritSet set(10);
    set[2] = True;
    Trit a = set[2];
  EXPECT_EQ(a, Trit::True);
    set[8] = False;
    a = set[8];
    EXPECT_EQ(a, Trit::False);
    set[9] = Unknown;
    a = set[9];
    EXPECT_EQ(a, Trit::Unknown);
}

TEST(TritSetTests, operator_and){
    TritSet set1(9);
    TritSet set2(10);
    set1[0] = Trit :: False;
    set1[1] = Trit ::False;
    set1[2] = Trit :: False;
    set1[3] = Trit ::Unknown;
    set1[4] = Trit ::Unknown;
    set1[5] = Trit ::Unknown;
    set1[6] = Trit ::True;
    set1[7] = Trit ::True;
    set1[8] = Trit ::True;

    set2[0] = Trit :: False;
    set2[1] = Trit ::Unknown;
    set2[2] = Trit :: True;
    set2[3] = Trit ::False;
    set2[4] = Trit ::Unknown;
    set2[5] = Trit ::True;
    set2[6] = Trit ::False;
    set2[7] = Trit ::Unknown;
    set2[8] = Trit ::True;

    TritSet set3 = set1 & set2;
    size_t allocLength = set3.capacity();
    EXPECT_EQ(allocLength, 9);
    Trit a = set3[0];
    EXPECT_EQ(a, Trit:: False);
    a = set3[1];
    EXPECT_EQ(a, Trit::False);
    a = set3[2];
    EXPECT_EQ(a, Trit:: False);
    a = set3[3];
    EXPECT_EQ(a, Trit:: False);
    a = set3[4];
    EXPECT_EQ(a, Trit:: Unknown);
    a = set3[5];
    EXPECT_EQ(a, Trit:: Unknown);
    a = set3[6];
    EXPECT_EQ(a, Trit:: False);
    a = set3[7];
    EXPECT_EQ(a, Trit:: Unknown);
    a = set3[8];
    EXPECT_EQ(a, Trit:: True);
}

TEST(TritSetTests, operator_or){
    TritSet set1(9);
    TritSet set2(10);
    set1[0] = Trit :: False;
    set1[1] = Trit ::False;
    set1[2] = Trit :: False;
    set1[3] = Trit ::Unknown;
    set1[4] = Trit ::Unknown;
    set1[5] = Trit ::Unknown;
    set1[6] = Trit ::True;
    set1[7] = Trit ::True;
    set1[8] = Trit ::True;

    set2[0] = Trit :: False;
    set2[1] = Trit ::Unknown;
    set2[2] = Trit :: True;
    set2[3] = Trit ::False;
    set2[4] = Trit ::Unknown;
    set2[5] = Trit ::True;
    set2[6] = Trit ::False;
    set2[7] = Trit ::Unknown;
    set2[8] = Trit ::True;

    TritSet set3 = set1 | set2;
    size_t allocLength = set3.capacity();
    EXPECT_EQ(allocLength, 9);
    Trit a = set3[0];
    EXPECT_EQ(a, Trit:: False);
    a = set3[1];
    EXPECT_EQ(a, Trit::Unknown);
    a = set3[2];
    EXPECT_EQ(a, Trit:: True);
    a = set3[3];
    EXPECT_EQ(a, Trit:: Unknown);
    a = set3[4];
    EXPECT_EQ(a, Trit:: Unknown);
    a = set3[5];
    EXPECT_EQ(a, Trit:: True);
    a = set3[6];
    EXPECT_EQ(a, Trit:: True);
    a = set3[7];
    EXPECT_EQ(a, Trit:: True);
    a = set3[8];
    EXPECT_EQ(a, Trit:: True);
}

TEST(TritSetTests, operator_not){
    TritSet set1(4);
    set1[0] = Trit :: False;
    set1[1] = Trit ::Unknown;
    set1[2] = Trit :: True;

    TritSet set3 = ~set1;
    size_t allocLength = set3.capacity();
    EXPECT_EQ(allocLength, 3);
    Trit a = set3[0];
    EXPECT_EQ(a, Trit:: True);
    a = set3[1];
    EXPECT_EQ(a, Trit::Unknown);
    a = set3[2];
    EXPECT_EQ(a, Trit:: False);
}








