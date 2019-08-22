#pragma once
#include <iostream>
#include <vector>

//#if defined(OS_LINUX) || defined(OS_IOS) || defined(OS_MAC) || defined(_LIB)
//#define XJSON_API
//#define XJSON_TEMPLATE
//#define CALLBACK
//#else
//#ifdef XJSON_EXPORTS
//#define XJSON_API __declspec(dllexport)
//#define XJSON_TEMPLATE __declspec(dllexport)
//#else
//#define XJSON_API __declspec(dllimport)
//#define XJSON_TEMPLATE
//#endif
//#define CALLBACK __stdcall
//#endif
#define XJSON_API
#define XJSON_TEMPLATE
#define CALLBACK


#define NS_NETSDK_CFG_BEGIN namespace XSDK_CFG{
#define NS_NETSDK_CFG_END }
#define USE_NS_NETSDK_CFG using namespace XSDK_CFG;

typedef void* PJSON_DATA;
typedef void* PJSON_STRING;

class XJSON_API JObject
{
public:
	JObject(JObject *pParent = NULL, const char *szName = "");
	virtual ~JObject(void);

public:
	virtual int Parse(const char *szJson);
	virtual int Parse(PJSON_DATA pParent, int index = -1);
	virtual const char *ToString();
	virtual const char* Name(){return name;};
	virtual void SetName(const char*nm);

	virtual int ToInt();
	virtual bool ToBool();
	virtual int SetValue(const char *szValue);
	virtual int SetValue(bool bValue);
	virtual int SetValue(int nValue);
	virtual JObject *NewChild();
	

	virtual int AddChild(JObject *pNew);
	virtual int DelChild(const char *szName);
	virtual char *GetChannelName(int channelNo, const char* strName);
	virtual int GetBoolOfObjs(const char *szKeys, int nDefValue = 0);

	void JSON_SetParent(PJSON_DATA pParent);
	int JSON_AddToArray(JObject *pChild);  
	int JSON_DelFromArray(int nIndex);  

protected:
	virtual void Clear();

protected:
	char *name;
	PJSON_DATA _pJSData;
	PJSON_DATA _pRoot;
	std::vector<JObject *> _items;
	PJSON_STRING _sJsonReslt;
};


class XJSON_API JIntObj : public JObject
{
public:
	JIntObj(JObject *pParent = NULL, const char *szName = "");
	virtual ~JIntObj(void);

public:
	int Value();
	virtual void operator=(const int nValue);
};

class XJSON_API JDoubleObj : public JObject
{
public:
	JDoubleObj(JObject *pParent = NULL, const char *szName = "");
	virtual ~JDoubleObj(void);

public:
	double Value();
	virtual void operator=(const double nValue);
};

class XJSON_API JStrObj : public JObject
{
public:
	JStrObj(JObject *pParent = NULL, const char *szName = "");
	virtual ~JStrObj(void);

public:
	const char *Value();
	virtual void operator=(const char *szValue);

protected:
	void *_sValue;
};

class XJSON_API JIntHex : public JStrObj
{
public:
	JIntHex(JObject *pParent = NULL, const char *szName = "");
	virtual ~JIntHex(void);
	int SetValue(bool bValue);
	int SetValue(int nValue);
	int ToInt();

public:
	int Value();
	virtual void operator=(int);
};

class XJSON_API JBoolObj : public JObject
{
public:
	JBoolObj(JObject *pParent = NULL, const char *szName = "");
	virtual ~JBoolObj(void);

public:
	bool Value();
	virtual void operator=(const bool bValue);
};

template <class T>
class XJSON_TEMPLATE JObjArray : public JObject
{
public:
	JObjArray(JObject *pParent = NULL, const char *szName = ""):
	JObject(pParent, szName)
	{
	};
	virtual ~JObjArray(void){};

public:
	T &operator[] (const int index)
	{
		return *_arrayItems[index];
	};

	void Clear()
	{
		typename std::vector<T*>::iterator iter = _arrayItems.begin();
		while ( iter != _arrayItems.end() )
		{
			if( *iter )
			{
				delete *iter;
			}
			iter++;
		}
		_arrayItems.clear();
		_items.clear();
		JObject::Clear();
	};

	JObject *NewChild()
	{
		T *pNew = new T();
		_arrayItems.push_back(pNew);
		return (JObject *)pNew;
	};
	
	virtual int AddChild(JObject *pChild)
	{
		JSON_AddToArray(pChild);
		pChild->JSON_SetParent(NULL);
		_arrayItems.push_back((T*)pChild);
		return 0;
	};

	virtual int DelChild(int nIndex)
	{
		if (nIndex < 0 || nIndex >= _arrayItems.size())
		{
			return -1;
		}
		JSON_DelFromArray(nIndex);
		delete _arrayItems[nIndex];
		_arrayItems.erase(_arrayItems.begin() + nIndex);
		return 0;
	}

	int Size()
	{
		return (int)_arrayItems.size();
	};

protected:
	std::vector<T*> _arrayItems;
};


template <class T>
class XJSON_TEMPLATE JObjArrayObject : public JObject
{
public:
	JObjArrayObject(JObject *pParent = NULL, const char *szName = ""):
	  JObject(NULL, ""),
	  objs(this, szName)
	{
	};
	virtual ~JObjArrayObject(void){};
	virtual int AddChild(JObject *pNew)
	{
		return objs.AddChild(pNew);
	};

public:
	JObjArray<T> objs;
};


