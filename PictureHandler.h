#ifndef PICTUREHANDLER_H_
#define PICTUREHANDLER_H_

#include "Picture.h"
#include <vector>

class PictureHandler : public Picture
{
	enum {maxn = 2000};
private:
	int diviHeight;
	int diviWidth;
	int yHeight;
	int xWidth;
	double INF;
	static const std::vector<Picture>& libPic;
public:
	PictureHandler(const std::string picname, const int num, const int diviHeight, const int diviWidth);
	int getDiviHeight() const;
	int getDiviWidth() const;
	int getYHeight() const;
	int getXWidth() const;
	double calcDet(const int starty, const int startx, const Picture& matchedPic);
	std::string matchPic();
};

#endif