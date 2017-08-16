#include "Picture.h"
#include "lodepng.h"
#include <vector>
#include <iostream>


Picture::Picture(const std::string picname, const int num)
: num(num), picname(picname)
{
	this->getPixel();
}

Picture::~Picture()
{

}

int Picture::getR(const int &row, const int &column) const
{
	return r[row][column];
}

int Picture::getG(const int &row, const int &column) const
{
	return g[row][column];
}

int Picture::getB(const int &row, const int &column) const
{
	return b[row][column];
}

int Picture::getHeight() const
{
	return height;
}

int Picture::getWidth() const
{
	return width;
}

std::string Picture::getPicname() const
{
	return picname;
}

void Picture::getPixel()
{
    std::vector<unsigned char> image; //the raw pixels
    unsigned height, width;
    unsigned error = lodepng::decode(image, width, height, picname.c_str());
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    int cnt = 0;
    //std::cout<<"h:"<<height<<",w:"<<width<<std::endl;
    for(unsigned i=1; i<=height; i++)
        for(unsigned j=1; j<=width; j++)
        {
            r[i][j] = (int)image[cnt++];
            g[i][j] = (int)image[cnt++];
            b[i][j] = (int)image[cnt++];
            cnt++;
        }
    this->height = height;
    this->width = width;
}
