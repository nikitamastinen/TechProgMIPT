//
// Created by Nikita Mastinen on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

class Fixture: public::testing::Test {
public:
  std::string test_path;
  std::string path_to_test_file;

  void SetUp() final {
    auto current_path = boost::filesystem::current_path().string();
    test_path = current_path + "/testdir";
    boost::filesystem::create_directory(test_path);
    boost::filesystem::create_directory(test_path + "/testdir2");
    path_to_test_file = test_path + "/test.txt";
    std::ofstream file(path_to_test_file);
    file.close();
  }

  void TearDown() final {
    boost::filesystem::remove_all(test_path);
  }
};

TEST_F(Fixture, TestGetTree)
{
  ASSERT_THROW(GetTree(Fixture::test_path + "/kukareku", true), std::invalid_argument);
  ASSERT_THROW(GetTree(Fixture::path_to_test_file, true), std::invalid_argument);
  ASSERT_EQ(GetTree(Fixture::test_path, true), GetTree(Fixture::test_path, true));
  ASSERT_TRUE(GetTree(Fixture::test_path, false) == GetTree(Fixture::test_path, false));
  ASSERT_NO_THROW(FilterEmptyNodes(GetTree(Fixture::test_path, true), Fixture::test_path));
}


