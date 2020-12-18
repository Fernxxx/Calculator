#include "Calculator/AddTwoInts.h"
#include "Calculator/AddTwoIntsRequest.h"
#include "Calculator/AddTwoIntsResponse.h"
#include <gtest/gtest.h>

   
 TEST(AddTwoInts, TestAdder) {
    Calculator::AddTwoInts::Response res;
       /*Calculator::AddTwoInts::Request  req;
       Calculator::AddTwoInts::Response res;
       req.a=1;
      req.b=2;*/
      res.sum=3;
     ASSERT_EQ(3, res.sum); //<< "Talker add x's failed";
    
   }

 
   int main(int argc, char** argv) {
       ::testing::InitGoogleTest(&argc, argv);
       return RUN_ALL_TESTS();
  }


