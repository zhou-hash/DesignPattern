#include <iostream>
#include <string>

using namespace std;

class IUser {
public:
	virtual void insert() = 0;
	virtual void getUser() = 0;
	virtual ~IUser() {
	
	}
};

class SqlserverUser : public IUser {
public:
	virtual void insert() {
		cout << "insert user data into sqlserver" << endl;
	}

	virtual void getUser() {
		cout << "get user info from sqlserver" << endl;
	}

	virtual ~SqlserverUser() {
	
	}
};

class MysqlUser : public IUser {
public:
	virtual void insert() {
		cout << "insert user data into mysql" << endl;
	}

	virtual void getUser() {
		cout << "get user info from mysql" << endl;
	}

	virtual ~MysqlUser() {
	
	}
};

class IDepartment {
public:
	virtual void insert() = 0;

	virtual void getDepartment() = 0;

	virtual ~IDepartment() {
	
	}
};

class SqlserverDepartment : public IDepartment {
public:

	virtual void insert() {
		cout << "insert department info to sqlserver" << endl;
	}

	virtual void getDepartment() {
		cout << "get department info from sqlserver" << endl;
	}

	virtual ~SqlserverDepartment () {
	
	}
};

class MysqlDepartment : public IDepartment {
public:

	virtual void insert() {
		cout << "insert department info to mysql" << endl;
	}

	virtual void getDepartment() {
		cout << "get department info from mysql" << endl;
	}

	virtual ~MysqlDepartment() {
	
	}
};


// Abstract Factory
class Factory {
public:
	void factoryPrint() {
		cout << "factory" << endl;
	}

	virtual IUser* CreateUser() = 0;
	virtual IDepartment* CreateDepartment() = 0;
	virtual ~Factory() {
	
	}
};

class SqlserverFactory : public Factory {
public:

	virtual IUser* CreateUser() {
		return new SqlserverUser();
	}

	virtual IDepartment* CreateDepartment() {
		return new SqlserverDepartment();
	}

	virtual ~SqlserverFactory() {
	
	}
};

class MysqlFactory : public Factory {
public:

	virtual IUser* CreateUser() {
		return new MysqlUser();
	}

	virtual IDepartment* CreateDepartment() {
		return new MysqlDepartment();
	}

	virtual ~MysqlFactory() {
	
	}
};

int main () {
	Factory* factory = new SqlserverFactory();
	// Factory* factory = new MysqlFactory();
	IUser* iuser = factory->CreateUser();
	iuser->insert();
	iuser->getUser();

	IDepartment* id = factory->CreateDepartment();
	id->insert();
	id->getDepartment();

	delete iuser;
	delete id;
	delete factory;

	return 0;
}