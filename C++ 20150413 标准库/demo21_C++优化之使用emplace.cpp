#include <vector>
#include <set>
#include <iostream>
#include <algorithm>   // sort����ģ�塢for_each����ģ��
#include<string>

using namespace std;

// Book�ṹ�������鱾��Ϣ

// @see https://blog.csdn.net/windpenguin/article/details/75581552
struct SBook
{
	SBook() : bookName(""), price(0)
	{
		std::cout << "default construct: " << bookName << std::endl;
	}
	SBook(std::string bookName_, int price_) : bookName(bookName_), price(price_)
	{
		std::cout << "construct: " << bookName << std::endl;
	};
	SBook(SBook& rhs) : bookName(rhs.bookName), price(rhs.price)
	{
		std::cout << "copy construct: " << bookName << std::endl;
	}
	~SBook()
	{
		std::cout << "deconstruct: " << bookName << std::endl;
	}

	bool operator <(const SBook& rhs) const
	{
		return bookName < rhs.bookName;
	}
	std::string bookName;
	int price;
};

int main()
{

	// ����vector
	vector<SBook> books;
	// Ԥ�ȷ��䣬��������vector��������������������·����ڴ�
	books.reserve(100);

	std::cout << "test push_back:" << endl;
	books.push_back(SBook("C++�����ŵ�����", 1));
	std::cout << endl;

	std::cout << "test emplace_back:" << endl;
	books.emplace_back("ˮ䰴�", 2);
	std::cout << endl;

	std::cout << "test emplace_back default:" << endl;
	books.emplace_back();
	auto& book = books.back();
	book.bookName = "��¥��";
	book.price = 5;
	std::cout << endl;

	std::cout << "test emplace:" << endl;
	auto it = books.emplace(books.end());
	it->bookName = "���μ�";
	it->price = 3;
	std::cout << endl;

	std::cout << "output all books: " << endl;
	for_each(books.begin(), books.end(), [](const SBook& book)->void
	{
		std::cout << book.bookName.c_str() << endl;
	});
	std::cout << endl;


	// ����set
	set<SBook> bookSet;

	std::cout << "test bookSet insert:" << endl;
	bookSet.insert(SBook("ʮ���Ϊʲô", 1));
	std::cout << endl;

	std::cout << "test bookSet emplace:" << endl;
	bookSet.emplace("�»��ֵ�", 2);
	std::cout << endl;

	std::cout << "output bookset: " << endl;
	for_each(bookSet.begin(), bookSet.end(), [](const SBook&book)->void
	{
		std::cout << book.bookName.c_str() << endl;
	});
	std::cout << endl;

	return 0;
}
