#include <iostream>
#include <windows.h>
#include <objbase.h>

using namespace std;
#define pure =0

const IID IID_IX =
{ 0x32bb8320, 0xb41b, 0x11cf,
{ 0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82 } };

const IID IID_IY =
{ 0x32bb8321, 0xb41b, 0x11cf,
{ 0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82 } };


void trace(const char *msg)
{
	cout << msg << endl;
}

interface IX : public IUnknown
{
	virtual void fx() pure;
};

interface IY : public IUnknown
{
	virtual void fy() pure;
};

//IX 跟IY 表示一个组件
class CA : public IX, public IY
{
	virtual HRESULT _stdcall QueryInterface(REFIID riid, void **ppvObject);
	virtual ULONG _stdcall AddRef();
	virtual ULONG _stdcall Release();
	virtual void fx();
	virtual void fy();
};

HRESULT CA::QueryInterface(REFIID riid, void **ppvObject)
{
	if (riid == IID_IX)
	{
		trace("interface IID_IX");
		*ppvObject = static_cast<IX*>(this);
	}
	if (riid == IID_IY)
	{
		trace("interface IID_IY");
		*ppvObject = static_cast<IY*>(this);
	}
	return S_OK;
}

ULONG _stdcall CA::AddRef()
{
	return 0;
}

ULONG _stdcall CA::Release()
{
	return 0;
}
void CA::fx()
{
	cout << "fx function" << endl;
}

void CA::fy()
{
	cout << "fx function" <<endl;
}

IUnknown* createinstance()
{
	IUnknown* pI = static_cast<IX*>(new CA());
	return pI;
}

int main()
{
	IUnknown* pI = createinstance();
	IX* pIX = NULL;
	pI->QueryInterface(IID_IX, (void**)(&pIX));
	pIX->fx();

	IY* pIY = NULL;
	pI->QueryInterface(IID_IY, (void**)(&pIY));
	pIY->fy();
	getchar();
	return 0;
}