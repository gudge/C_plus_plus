#include <iostream>
#include <functional>
#include <vector>
#include <ctime>
#include <chrono>

class Button
{
  	public:
		Button(std::function<void(void)> click); 
		void on_click() const;
	private:	
		std::function<void(void)> on_click_{};
};

Button::Button(std::function<void(void)> click)
: on_click_(click)  
{
}

void Button::on_click() const
{
	on_click_();
}

auto make_buttons()
{
	auto beep_button = Button([beep_count = 0] 
		() mutable
		{
			std::cout << "Beep: " << beep_count << "!";
			++beep_count;
		}
		);
	auto bop_button = Button([]
		()
		{
        	std::cout << "Bop "; 
		}
		);
	auto silent_button = Button([]
		() {});

	auto buttons = std::vector<Button>{
	  		beep_button,
			bop_button,
			silent_button
		};
	return buttons;
}


void foo()
{
	auto buttons = make_buttons();
	for (const auto& b : buttons)
	{
    	b.on_click();
	}

	buttons.front().on_click();
}

auto test_direct_lamda()
{
	auto lbd = [](int32_t v) 
	{
    	return v * 3;
	};

	using L = decltype(lbd);

	auto fs = std::vector<L>{};
	const int64_t vecsize = 1000000;
	fs.reserve(vecsize); 
	for (int i = 0; i < vecsize; ++i)
	{
    	fs.push_back(lbd);
	}

	int32_t res = 0;

	for (const auto& f: fs)
	{
    	res = f(res);
	}

	return res;
}


void foo2()
{
  	auto begin = std::chrono::high_resolution_clock::now();
	test_direct_lamda();
	auto end_time = std::chrono::high_resolution_clock::now();
	std::cout << "Time(seconds) : "  << 
	std::chrono::duration_cast<std::chrono::seconds>(end_time - begin).count() << " ";
}


void polymorphic_lambda()
{

}

int
main()
{
	//foo();
	//foo2();
	polymorphic_lambda();
    return 0;
}
