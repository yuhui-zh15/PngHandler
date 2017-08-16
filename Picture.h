#ifndef PICTURE_H_
#define PICTURE_H_

#include <string>
#include <vector>

typedef std::vector<std::vector<int>> array;

class Picture
{
	enum {maxn = 750};
private:
    array r = array(maxn, std::vector<int>(maxn));
    array g = array(maxn, std::vector<int>(maxn));
    array b = array(maxn, std::vector<int>(maxn));
    int height;
    int width;
    int num;
    std::string picname;
public:
	Picture(const std::string picname, const int num);
	virtual ~Picture();
	int getR(const int &row, const int &column) const;
	int getG(const int &row, const int &column) const;
	int getB(const int &row, const int &column) const;
	int getHeight() const;
	int getWidth() const;
	void getPixel();
	std::string getPicname() const;
};

#endif