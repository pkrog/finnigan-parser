#include <msfinnigan.hpp>
#include <boost/test/included/unit_test.hpp>
#include <string>

using namespace boost::unit_test;
using namespace org::openscience::ms::finnigan;

////////////////////////////
// GET RESOURCE FILE PATH //
////////////////////////////

std::string get_resource_file_path(const std::string& filename) {

	// Get resource folder
	int argc = framework::master_test_suite().argc;
	const char* argv[] = framework::master_test_suite().argv;
	if (argc != 2) {
		// error and exit
		exit(1);
	}
	boost::filesystem::path boost_path(argv[1]);


	// Build file path

	return file;
}

////////////////////////
// WRONG MAGIC NUMBER //
////////////////////////

BOOST_AUTO_TEST_CASE(test_wrong_magic_number) {
	std::string file = get_resource_file_path(L"wrong_magic_number.raw");
	BOOST_REQUIRE_THROW(Reader reader(file), WrongMagicNumber);
}
