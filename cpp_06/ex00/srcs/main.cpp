#include <ScalarConverter.hpp>
#include <iostream> //cout, endl

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: <scalar_type_to_convert>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	// testConvert("a");
	// testConvert("f");
	// testConvert(" f");
	// testConvert("");
	// testConvert(" ");
	// testConvert("  ");
	// testConvert("0");
	// testConvert("00.00");
	// testConvert(" +");
	// testConvert("++1");
	// testConvert("  42");
	// testConvert("  42.0");
	// testConvert("  42f");
	// testConvert("-9223372a");
	// testConvert("-2147483648"); //INT_MIN
	// testConvert("-2147483648.f");
	// testConvert("-2147483648.0f");
	// testConvert("-2147483649"); 
	// testConvert("2147483647"); //INT_MAX
	// testConvert("2147483648");
	// testConvert("3.4028235e+38f");
	// testConvert("1e+40");
	// testConvert("-3.4028235e+38f");
	// testConvert("-1e+40");
	// testConvert("1.7976931348623157e+308");
	// testConvert("1e+309");
	// testConvert("-1e+309");
	// testConvert("inf");
	// testConvert("infinity");
	// testConvert("+inf");
	// testConvert("++inf");
	// testConvert("-inf");
	// testConvert("- inf");
	// testConvert("inff");
	// testConvert("-inff");
	// testConvert("++inff");
	// testConvert("nan");
	// testConvert("+nanf");
	// testConvert(" -nanf");
	// testConvert("11111111111111111111111111111111111111111111");
	// testConvert("-11111111111111111111111111111111111111111111");

	return 0;
}
