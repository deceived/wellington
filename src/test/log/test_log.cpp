#include <iostream>

#include <boost/log/trivial.hpp>

void boost_trivial()
{
    BOOST_LOG_TRIVIAL( trace ) << "A trace message";
    BOOST_LOG_TRIVIAL( debug ) << "A debug message";
    BOOST_LOG_TRIVIAL( info ) << "A info message";
    BOOST_LOG_TRIVIAL( warning ) << "A warning message";
    BOOST_LOG_TRIVIAL( error ) << "A error message";
    BOOST_LOG_TRIVIAL( fatal ) << "A fatal message";
}


int main( int argc, char** argv )
{
    std::cout << "test log..." << std::endl;

    boost_trivial();
}
