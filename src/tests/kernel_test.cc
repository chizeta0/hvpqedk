
#include <cstdlib>
#include "gtest/gtest.h"

extern "C" {
#include "kernel.h"
}

namespace
{
    class KTest : public ::testing::Test
    {
    protected:
	KTest() {}
    };

    TEST_F(KTest, small_large_match)
    {
	EXPECT_NEAR( mu2_ft_small(1.05), mu2_ft_large(1.05), 5e-6 );
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
