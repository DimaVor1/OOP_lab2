#include "pch.h"
#include "C:\Users\User\source\repos\oop_2\Libary1\astro.h"
using namespace P2;

TEST(Constructor, DefaultConstructor) {
	astroid astro1;
	ASSERT_EQ(1, astro1.getR());
 }
TEST(Constructor, MainConstructor) {
	astroid astro2(5);
	ASSERT_EQ(5, astro2.getR());
}
TEST(Constructor, MainConstructorException) {
	ASSERT_ANY_THROW(astroid(-5));
}
TEST(Setter, Setter) {
	astroid astro3;
	astro3.setR(5);
	ASSERT_EQ(5, astro3.getR());
}
TEST(Setter, SetterException) {
	astroid astro4;
	ASSERT_ANY_THROW(astro4.setR(-5));	
}
TEST(Method, ArcLen) {
	astroid astro5(2);
	ASSERT_EQ(12, astro5.arcLen(90));
	ASSERT_NEAR(6, astro5.arcLen(45), 0.0001);
	ASSERT_NEAR(3.3698, astro5.arcLen(32), 0.0001);
}
TEST(Method, ArcLenException) {
	astroid astro5(2);
	ASSERT_ANY_THROW(astro5.arcLen(120));
}
TEST(Method, AllLen) {
	astroid astro6(2);
	ASSERT_EQ(48, astro6.allLen());
	astro6.setR(1);
	ASSERT_EQ(24, astro6.allLen());
}
TEST(Method, CurvRad) {
	astroid astro7(2);
	ASSERT_EQ(0, astro7.curvRad(0));
	ASSERT_EQ(12, astro7.curvRad(45));
	ASSERT_EQ(12, astro7.curvRad(-45));
	ASSERT_NEAR(10.7855, astro7.curvRad(32), 0.0001);
	ASSERT_NEAR(10.7855, astro7.curvRad(-148), 0.0001);
	ASSERT_NEAR(5.2605, astro7.curvRad(77), 0.0001);
}
TEST(Method, astroidArea) {
	astroid astro8(2);
	ASSERT_NEAR(75.398, astro8.astroidArea(), 0.001);
	astro8.setR(1);
	ASSERT_NEAR(18.85, astro8.astroidArea(), 0.01);
}
TEST(Method, Coordinates) {
	astroid astro9(2);
	ASSERT_EQ(8, astro9.coordX(0)); 
	ASSERT_EQ(0, astro9.coordY(0));
	ASSERT_NEAR(5.1962, astro9.coordX(30), 0.0001);
	ASSERT_NEAR(1, astro9.coordY(30), 0.0001);
	ASSERT_NEAR(2.8284, astro9.coordX(45), 0.0001);
	ASSERT_NEAR(2.8284, astro9.coordY(45), 0.0001);
	ASSERT_NEAR(2.8284, astro9.coordX(-45), 0.0001);
	ASSERT_NEAR(-2.8284, astro9.coordY(-45), 0.0001);
}

TEST(Method, YfromX) {
	astroid astro10(2);
	ASSERT_EQ(0, astro10.YfromX(8));
	ASSERT_EQ(0, astro10.YfromX(-8));
	ASSERT_NEAR(8, astro10.YfromX(0), 0.0001);
	ASSERT_NEAR(2.8284, astro10.YfromX(2.8284), 0.0001);
	ASSERT_NEAR(3.7474, astro10.YfromX(2), 0.0001);
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
