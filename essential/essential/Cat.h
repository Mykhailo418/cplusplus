#pragma once
#include "Mammal.h"
#include "Domestic.h"
#include "Pedigreed.h"

class Cat : public Mammal, // public, protected,  private
			public Domestic,
			public Pedigreed
{
public:
	Cat();
	Cat(uint paws);
	~Cat();

	void say() override;
	string get_current_class();
	static void set_statWord(string _statWord) {
		word = _statWord;
	};
	static string get_statWord() {
		return word;
	};

private:
	int paws = 2;
	int vibr = 6;
	static string word;
};

