
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

	virtual update_status PreUpdate() 
	{
		return update_status::UPDATE_CONTINUE;
	}

	virtual update_status Update()
	{
		return update_status::UPDATE_CONTINUE;
	}

	virtual update_status PostUpdate()
	{
		return update_status::UPDATE_CONTINUE;
	}

	virtual bool CleanUp()
	{
		return true;
	}
};