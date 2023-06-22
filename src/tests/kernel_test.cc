
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "gtest/gtest.h"

extern "C" {
#include "kernel.h"
}

#define SPACING 0.08186
#define M_MU_MEV 105.6583755
#define UNIT_MEV_FM 197.3270

namespace
{
    static std::vector<double> readTestValues(const std::string& fname)
    {
	std::vector<double> out;
	std::fstream f{ fname, f.in };
	try{
	    if(not f.is_open()){
		throw std::string("could not open test values file");
	    }
	
	    long n;
	    double val;
	    size_t cnt = 0;
	    while(f >> n >> val) {
		if(static_cast<long>(cnt) != n){
		    throw std::string("test values file corrupted");
		}
		++cnt;
	    }
	    const size_t fsize = cnt;
	    out.resize(fsize);
	    f.clear();
	    f.seekg(0);
	    while(f >> n >> val) {
		out[n] = val;
	    }

	    if(f.bad()){
		throw std::string("I/O error while reading test values");
	    }
	}
	catch(const std::string& e){
	    f.clear();
	    f.close();
	    throw e;
	}
	f.close();
	return out;
    }
    
    class KTest : public ::testing::Test
    {
    protected:
	KTest()
	{
	    m_mu = M_MU_MEV * SPACING / UNIT_MEV_FM;
	    values = readTestValues(TEST_VALUES_FILE_NAME);
	}

	double m_mu;
	std::vector<double> values;
    };

    TEST_F(KTest, small_large_match)
    {
	EXPECT_NEAR( mu2_ft_small(1.05), mu2_ft_large(1.05), 5e-6 );
    }

    TEST_F(KTest, compare_test_values)
    {
	for(size_t i = 0; i != values.size(); ++i){
	    const double x = Ktilde(static_cast<double>(i),m_mu);
	    EXPECT_NEAR( x, values[i], 4e-3 * x );
	}
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
