#include <ros/ros.h>
#include <ros/service_client.h>
#include <gtest/gtest.h>
#include <Calculator/AddTwoInts.h>

std::shared_ptr<ros::NodeHandle> nh;
//ros::NodeHandle nh;
TEST(AddTwoInts, AddTwoPositive_GetPositiveSum)
{
  //ros::NodeHandle nh;
  ros::ServiceClient client = nh->serviceClient<Calculator::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  Calculator::AddTwoInts srv;
  srv.request.a = 6;
  srv.request.b = 1;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(AddTwoInts, AddTwoNegative_GetNegativeSum)
{
  //ros::NodeHandle nh;
  ros::ServiceClient client = nh->serviceClient<Calculator::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  Calculator::AddTwoInts srv;
  srv.request.a = -6;
  srv.request.b = -1;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(AddTwoInts, AddPositiveNegative_GetNegativeSum)
{
  //ros::NodeHandle nh;
  ros::ServiceClient client = nh->serviceClient<Calculator::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  Calculator::AddTwoInts srv;
  srv.request.a = 2;
  srv.request.b = -7;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(AddTwoInts, AddPositiveNegative_GetPositiveSum)
{
  //ros::NodeHandle nh;
  ros::ServiceClient client = nh->serviceClient<Calculator::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  Calculator::AddTwoInts srv;
  srv.request.a = -7;
  srv.request.b = 9;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(AddTwoInts, AddZeroPositive_GetPositiveSum)
{
  //ros::NodeHandle nh;
  ros::ServiceClient client = nh->serviceClient<Calculator::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  Calculator::AddTwoInts srv;
  srv.request.a = 0;
  srv.request.b = 7;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}

TEST(AddTwoInts, AddZeroNegative_GetNegativeSum)
{
  //ros::NodeHandle nh;
  ros::ServiceClient client = nh->serviceClient<Calculator::AddTwoInts>(
      "add_two_ints");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);

  Calculator::AddTwoInts srv;
  srv.request.a = -7;
  srv.request.b = 0;
  client.call(srv);

  EXPECT_EQ(srv.response.sum, srv.request.a + srv.request.b);
}
/**

 * @brief 主函数

 * @param argc

 * @param argv

 * @return int

 */
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);// gtest 的初始化
  ros::init(argc, argv, "test_add_two_ints");
  //ros::NodeHandle nh;// ros 节点句柄
  nh.reset(new ros::NodeHandle);
  return RUN_ALL_TESTS();
}

