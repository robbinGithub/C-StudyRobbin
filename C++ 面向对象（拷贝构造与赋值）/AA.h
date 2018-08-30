#pragma once
class AA
{
public:
	AA(int a );
	AA(const AA & other);
	AA& operator = (const  AA &aa);
	~AA();
private:
	int a;
};

