#include "gtest/gtest.h"
#include "../pieces.h"

TEST(Pieces, Constructor) {
    Pieces test(ColorPed::black,TypePed::torre,0,2);
    EXPECT_EQ(test.getColor(),ColorPed::black);
    EXPECT_EQ(test.getTypePed(),TypePed::torre);
    EXPECT_EQ(test.getX(),0);
    EXPECT_EQ(test.getY(),2);
}

TEST(Pieces, DefaultConstructor){
    Pieces test;
    EXPECT_EQ(test.getTypePed(),TypePed::none);
    EXPECT_EQ(test.getColor(),ColorPed::none);
}


