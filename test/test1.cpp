//Link to Boost
#define BOOST_TEST_DYN_LINK
//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "BaseClassModule"
//VERY IMPORTANT - include this last
#include <iostream>
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(TestName){
    for (int i =0;i<5;i++){
        int z = i;
        std::cout<<i<<"  "<<z<<std::endl;
        if (z == 2) z++;
        BOOST_CHECK_EQUAL(i,z);
    }
}