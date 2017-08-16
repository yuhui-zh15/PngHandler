#include "PictureHandler.h"
#include <cmath>
#include<cstdio>
PictureHandler::PictureHandler(const std::string picname, const int num, const int diviHeight, const int diviWidth)
:Picture(picname, num), diviHeight(diviHeight), diviWidth(diviWidth)
{
	this->yHeight = this->getHeight() / this->diviHeight;
	this->xWidth = this->getWidth() / this->diviWidth;
	this->INF = 1000000000000.0;
}

int PictureHandler::getDiviHeight() const
{
	return this->diviHeight;
}

int PictureHandler::getDiviWidth() const
{
	return this->diviWidth;
}

int PictureHandler::getYHeight() const
{
  	return this->yHeight;
}

int PictureHandler::getXWidth() const
{
	return this->xWidth;
}

double PictureHandler::calcDet(const int starty, const int startx, const Picture& matchedPic)
{
	double det = 0.0;
    for(int i=7; i<=matchedPic.getHeight()/2; i++)
    {
        for(int j=7; j+6<=matchedPic.getWidth(); j++)
        {
            int dR = matchedPic.getR(i, j) - this->getR(starty+i, startx+j);
            int dG = matchedPic.getG(i, j) - this->getG(starty+i, startx+j);
            int dB = matchedPic.getB(i, j) - this->getB(starty+i, startx+j);
            det += sqrt( dR*dR + dG*dG + dB*dB );
        }
    }
    return det;
}

std::string PictureHandler::matchPic()
{
    std::string retStr = "";	
   	for(int now_row=1; now_row<=diviHeight; now_row++)
    {
        for(int now_column=1; now_column<=diviWidth; now_column++)
        {//进入小图
            double all_min = INF;
            std::string picName;
            for(Picture const &this_pic: libPic)
            {//进入对应lib
                double this_min = INF;
                for(int dy=0; dy<=10; dy++)
                {
                    for(int dx=0; dx<=10; dx++)
                    {//将lib小图移动位置匹配
                        double tmp_det = calcDet((now_row-1)*yHeight+dy, (now_column-1)*xWidth+dx, this_pic);
                        this_min = std::min(this_min, tmp_det);
                    } 
                }
                if(this_min<all_min)
                {
                    all_min = this_min;
                    picName = this_pic.getPicname();
                }
            }
            retStr += picName.substr(picName.find_last_of('/')+1,3);
            retStr += ' ';

        }
        retStr += '\n';
    }
    return retStr;
}