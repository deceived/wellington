#include <iostream>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

void init()
{
    boost::log::core::get()->set_filter
    (
        boost::log::trivial::severity >= boost::log::trivial::info
    );
}


void boost_trivial_init()
{
    init();

    BOOST_LOG_TRIVIAL( trace ) << "A trace message";
    BOOST_LOG_TRIVIAL( debug ) << "A debug message";
    BOOST_LOG_TRIVIAL( info ) << "A info message";
    BOOST_LOG_TRIVIAL( warning ) << "A warning message";
    BOOST_LOG_TRIVIAL( error ) << "A error message";
    BOOST_LOG_TRIVIAL( fatal ) << "A fatal message";
}

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

    std::cout << "\n\n";

    boost_trivial_init();

    return 0;
}
