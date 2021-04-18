//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST_F(LeapTestCase, TestYear)
{
  ASSERT_THROW(IsLeap(-2020), std::invalid_argument);
  ASSERT_EQ(IsLeap(4000), true);
  ASSERT_EQ(IsLeap(1000), false);
  ASSERT_EQ(IsLeap(2011), false);
  ASSERT_EQ(IsLeap(2020), true);
}

TEST_F(LeapTestCase, TestMonth)
{
  ASSERT_THROW(GetMonthDays(2020, 13), std::invalid_argument);
  ASSERT_EQ(GetMonthDays(2020, 2), 29);
  ASSERT_EQ(GetMonthDays(2021, 2), 28);
  ASSERT_EQ(GetMonthDays(11, 9), 30);
  ASSERT_EQ(GetMonthDays(8, 8), 31);
}


