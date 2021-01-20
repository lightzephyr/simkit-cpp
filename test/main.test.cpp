#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

int addDemo( int i, int j ) { return i+j; }

BOOST_AUTO_TEST_CASE( my_first_test )
{
    // seven ways to detect and report the same error:
    BOOST_CHECK( addDemo( 2,2 ) == 4 );        // #1 continues on error

    BOOST_REQUIRE( addDemo( 2,2 ) == 4 );      // #2 throws on error

    if( addDemo( 2,2 ) != 4 )
      BOOST_ERROR( "Ouch..." );            // #3 continues on error

    if( addDemo( 2,2 ) != 4 )
      BOOST_FAIL( "Ouch..." );             // #4 throws on error

    if( addDemo( 2,2 ) != 4 ) throw "Ouch..."; // #5 throws on error

    BOOST_CHECK_MESSAGE( addDemo( 2,2 ) == 4,  // #6 continues on error
                         "addDemo(..) result: " << addDemo( 2,2 ) );

    BOOST_CHECK_EQUAL( addDemo( 2,2 ), 4 );	  // #7 continues on error
}
