#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <map>

void part1()
{
	std::ifstream in_file( "input/day1.txt" );
	std::string line;
	std::regex re( "(\\d)" );
	int sum = 0;
	while ( std::getline(in_file, line ))
	{
		std::vector<std::string> matches;
		std::copy( std::sregex_token_iterator( line.begin(), line.end(), re, 1 ), std::sregex_token_iterator(), std::back_insert_iterator( matches ) );
		sum += std::stoi( matches[0] ) * 10 + std::stoi( matches[matches.size() - 1] );
	}

	std::cout << sum << '\n';
}

void part2()
{
	const std::map<std::string, int> word_to_value{ {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9} };
	std::ifstream in_file( "input/day1.txt" );
	std::regex re( "(?=(\\d|one|two|three|four|five|six|seven|eight|nine))" );
	std::string line;
	int sum = 0;
	while ( std::getline( in_file, line ) )
	{
		std::vector<std::string> matches;
		std::copy( std::sregex_token_iterator( line.begin(), line.end(), re, 1 ), std::sregex_token_iterator(), std::back_insert_iterator( matches ) );
		
		int num;
		auto first = matches[0];
		auto last = matches[matches.size() - 1];

		if ( isdigit( first[0] ) )
		{
			num = (first[0] - '0') * 10;
		}
		else
		{
			num = word_to_value.find( first )->second * 10;
		}

		if ( isdigit( last[0] ) )
		{
			num += last[0] - '0';
		}
		else
		{
			num += word_to_value.find( last )->second;
		}

		sum += num;
	}

	std::cout << sum << '\n';
}

int main()
{
	part1();
	part2();
	return 0;
}