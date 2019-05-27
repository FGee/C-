#include <iostream>

using std::cout;
using std::endl;
using std::cin;

//static_cast的用法示例

class CPoint
{
private:
	int x, y;
public:
	CPoint(int xx = 0, int yy = 0)
	{
		x = xx;
		y = yy;
	}
	virtual void Show()
	{
		cout << x << "," << y;
	}
};

class CPoint3D:public CPoint
{
	int z;
public:
	CPoint3D(int xx = 0, int yy = 0, int zz = 0):CPoint(xx, yy)
	{
		z = zz;
	}

	virtual void Show()
	{
		CPoint::Show();
		cout << "," << z;
	}
    virtual void print()
    {
        cout << "hello" << endl;
    }
};

class CString
{
private:
	char *m_pData;
public:
	CString()
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	void Show()
	{
		cout << m_pData << endl;
	};
};

int main()
{
	CPoint3D pt3d(3, 4, 5);
	CString *ps = NULL;

	//下面的转换本来是无意义和非法的，以后使用ps->Show()
	//成员函数时可能会引起内存错误或得到错误的值, 但编译却不出错. 留下隐患
	ps = (CString *)&pt3d;
	ps->Show();

	//但改成下面使用static_cast形式进行转换, 在编译时就报错, 能及时发现错误
	//ps = static_cast<CString *>(&pt3d);

	//而下面这种转换之所以能编译通过，是因为CPoint和CPoint3D的指针本来就可以相互转换
	CPoint *pBase = static_cast<CPoint *>(&pt3d);
	pBase->Show();
	cout << endl;

    CPoint pt2d;
    CPoint3D* pt3d2 = static_cast<CPoint3D*>(&pt2d);//not have dynamic check
    pt3d2->print();


	return 0;
}


