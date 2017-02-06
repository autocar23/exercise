#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>
#include <vector>

class Screen;

class Window_mgr
{
public:
	Window_mgr();
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	Screen& get(ScreenIndex index);
private:
	std::vector<Screen> screens;
};

class Screen
{	
	/*������һ��������visual studio�༭����һ��bug https://www.zhihu.com/question/29139946
	 *Ϊ�˲������༭���ĺ����Ұ���������������һ���� ����c++ primer 5th ��ϰ7.32 Ӧ��ʹ����������*/
	//friend void Window_mgr::clear(Window_mgr::ScreenIndex);
	friend class Window_mgr;
	using pos = std::string::size_type;
public:
	Screen() = default;
	Screen(pos width, pos height) :
			_width(width), _height(height), _contents(width*height, ' '){}
	Screen(pos width, pos height, char c) :
			_width(width), _height(height), _contents(width*height, c){}
	char get() const;
	char get(pos x, pos y) const;
	Screen& move(pos r, pos c);
	Screen& set(char c);
	Screen& set(pos r, pos c, char ch);
	Screen& display(std::ostream& out);
	const Screen& display(std::ostream& out) const;
private:
	pos _cursor = 0;
	pos _width = 0, _height = 0;
	std::string _contents;
	void do_display(std::ostream &out) const { out << _contents; }
};

Window_mgr::Window_mgr():screens{Screen(24, 80, ' ')}
{

}

Screen& Window_mgr::get(ScreenIndex index)
{
	return screens[index];
}

void Window_mgr::clear(ScreenIndex index)
{
	Screen &s = screens[index];
	s._contents = std::string(s._height*s._width, ' ');
}

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

Screen& Screen::set(char c)
{
	_contents[_cursor] = c;
	return *this;
}

Screen& Screen::set(pos r, pos c, char ch)
{
	_contents[r*_width + c] = ch;
	return *this;
}

Screen& Screen::display(std::ostream& out) //��һ����Ա��������һ����Աʱ�� thisָ����������ʽ�ش���
{
	do_display(out);
	return *this;
}
const Screen& Screen::display(std::ostream& out) const
{
	do_display(out);
	return *this;
}

#endif