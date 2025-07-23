#include<stdexcept>
#include<map>

using namespace std;

class LengthChecker {

public:
	int getLengthScore(const string& str1, const string& str2) {
		int result = 0;

		assertInvalidArgument(str1, str2);

		int A = std::max(str1.length(), str2.length());
		int B = std::min(str1.length(), str2.length());
		if (A == B) return LENGTH_MAX_SCORE;
		if (isDoubleLength(A, B)) return LENGTH_MIN_SCORE;

		return getLengthPartitionScore(A, B);
	}

	

	

	

private:
	const int LENGTH_MAX_SCORE = 60;
	const int LENGTH_MIN_SCORE = 0;

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

	int getLengthPartitionScore(int A, int B)
	{
		int Gap = A - B;
		return (LENGTH_MAX_SCORE - (LENGTH_MAX_SCORE * Gap) / B);
	}

	bool isDoubleLength(int A, int B)
	{
		return A >= B * 2;
	}
};