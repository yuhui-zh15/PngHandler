#include "Picture.h"
#include "PictureHandler.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<Picture> SmallPic;

const std::vector<Picture>& PictureHandler::libPic=SmallPic;
void HandleSmallPic()
{	
    ifstream fin("./library/listlib.txt");
    string libName;
	int libCnt = 1;
    while(getline(fin, libName))
    {
        string wopen = "./library/"+libName;
        Picture tmpPic(wopen, libCnt);
        SmallPic.push_back(tmpPic);
    }
    fin.close();
}

void HandleLargePic()
{
    ifstream ein("./example/examlist.txt");
    string examName;
    int examCnt = 1;
    while(getline(ein, examName))
    {
        string wopen = "./example/"+examName;
        string wclose = wopen;
        wclose.resize(wopen.length()-4);
        wclose += ".txt";
        freopen(wclose.c_str(), "w", stdout);
        PictureHandler tmpPicHandler(wopen, examCnt++, 3, 5);
        string tmpRet = tmpPicHandler.matchPic();
        std::cout<<tmpRet<<std::endl;
        fclose(stdout);
    }
    ein.close();
}

int main()
{
    HandleSmallPic();
    HandleLargePic();
    return 0;
}
