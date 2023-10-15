
class MyGameEngine;

class Module
{
private:
	bool enabled;

public:
	MyGameEngine* Engine;

	Module(MyGameEngine* parent, bool start_enabled = true) : Engine(parent)
	{}

	virtual ~Module()
	{}

	virtual bool Init()
	{
		return true;
	}

	virtual bool Start()
	{
		return true;
	}

	virtual bool PreUpdate() 
	{
		return true;
	}

	virtual bool Update()
	{
		return true;
	}

	virtual bool PostUpdate()
	{
		return true;
	}

	virtual bool CleanUp()
	{
		return true;
	}
};