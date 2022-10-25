//---------------------------------------- onnx��dnn����-----------------------------------------
#include <iostream>
#include<windows.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;



HBITMAP	BitMap, hOld;
Mat img, img0, blob;     //img0�������洢Bitλͼ��,����ռ��,����ͼƬһֱ�����.img��bitת��������,blod�����������



int main(int argc, char** argv)
{
    //��ȡԭ����
    int x = 0;
    int y = 0;
    int width = 640;
    int height = 640;


    //1.��ȡ��Ļ���
    HWND hwnd = GetDesktopWindow();
    //2.��ȡ��ĻDC
    HDC hdc = GetWindowDC(hwnd);
    //3.��������DC(�ڴ�DC)
    HDC	mfdc = CreateCompatibleDC(hdc);
    //5.����λͼBitmap����
    BitMap = CreateCompatibleBitmap(hdc, width, height);
    //6.��λͼ��������ڴ�dc(Ҳ�����ǰ�)
    SelectObject(mfdc, BitMap);
    //7.����һ���̶�ά�ȵĿվ���,
    img0.create(Size(width, height), CV_8UC4);
    while (true)
    {

        //��ͼ
        BitBlt(mfdc, 0, 0, width, height, hdc, x, y, SRCCOPY);
        //��BitBlt��λͼ��Ϣ����
        GetBitmapBits(BitMap, height * width * 4, img0.data);//λͼ������,�ֽ���,��Ҫ�������ĵط�
        cvtColor(img0, img, COLOR_BGRA2BGR);  // 4->3,img0��ת�����ͼƬ,����������


        auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        imshow("test", img);
        waitKey(100);

        cout << (std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - tt) * 1000 << "ms" << endl;
    }
    //�ͷŶ���
    DeleteDC(hdc);
    DeleteDC(mfdc);
    DeleteObject(BitMap);
    return 0;
}
