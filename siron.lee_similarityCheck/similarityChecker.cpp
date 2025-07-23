#include<stdexcept>
#include<map>

using namespace std;

class LenghChecker {

public:
	int getPoint(const string& str1, const string& str2) {
		int result = 0;

		assertInvalidArgument(str1, str2);

		result += getLengthScore(str1, str2);

		


		return result;
	}

	

private:

	void assertInvalidArgument(const std::string& str1, const std::string& str2)
	{
		if (str1 == "" || str2 == "") {
			throw std::invalid_argument("No parameter");
		}
		for (char ch : str1) {
			if (ch >= 'A' && ch <= 'Z') continue;
			throw std::invalid_argument("Must be string");
		}
		for (char ch : str2) {
			if (ch >= 'A' && ch <= 'Z') continue;
			throw std::invalid_argument("Must be string");
		}
	}

	int getLengthScore(const std::string& str1, const std::string& str2)
	{
		int str1Length = str1.length();
		int str2Length = str2.length();
		if (str1Length == str2Length) return 60;
		if (str1Length < str2Length) {
			swap(str1Length, str2Length);
		}
		if (str1Length >= str2Length * 2) return 0;
		return 60 * (str2Length - (str1Length - str2Length)) / str2Length;
	}
};