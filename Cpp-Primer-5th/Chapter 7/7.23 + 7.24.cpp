#pragma once
#include <string>
class Screen
{
	using pos = std::string::size_type;
public:
	Screen() = default;
	Screen(pos width, pos height) :
		_width(width), _height(height), _contents(width*height, ' ') {}
	Screen(pos width, pos height, char c) :
		_width(width), _height(height), _contents(width*height, c) {}
	char get() const;
	char get(pos x, pos y) const;
	Screen& move(pos r, pos c);
private:
	pos _cursor = 0;
	pos _width = 0, _height = 0;
	std::string _contents;
};

inline char Screen::get() const
{
	return _contents[_cursor];
}

inline char Screen::get(pos r, pos c) const
{
	if (r < _width&&c < _height) {
		return _contents[r*_width + c];
	} else {
		return ' ';
	}
}

inline Screen& Screen::move(pos r, pos c)
{
	if (r < _width&&c < _height) {
		_cursor = r*_width + c;
	}
	return *this;
}

int main()
{
	return 0;
}