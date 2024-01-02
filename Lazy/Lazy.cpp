#include <iostream>
#include <map>
#include <string>

using namespace std;

// 花束类
class FlowerBouquet {
private:
    string name;

    // 静态成员变量，用于存储已创建的花束对象，通过类型名索引
    static map<string, FlowerBouquet*> types;

    // 私有构造函数，防止直接创建对象
    FlowerBouquet(const string& name) : name(name) {}

public:
    // 获取花束实例的静态方法
    static FlowerBouquet* getFlowerBouquet(const string& name);

    // 打印当前已创建的花束类型
    static void printCurrentTypes();
};

// 用户类
class User {
private:
    string name;
    string preferredFlower;
    string defaultAddress;
    string contactNumber;

public:
    // 构造函数，用户初始化时设置姓名
    User(const string& name);

    // 设置花束偏好
    void setPreferredFlower(const string& flower);

    // 获取花束偏好
    string getPreferredFlower() const;

    // 设置默认收货地址
    void setDefaultAddress(const string& address);

    // 设置联系方式
    void setContactNumber(const string& number);

    // 下单方法，应用用户设置的偏好和默认信息
    void placeOrder(const string& flowerName);
};

// 初始化静态成员变量
map<string, FlowerBouquet*> FlowerBouquet::types;

// 获取花束实例的静态方法
FlowerBouquet* FlowerBouquet::getFlowerBouquet(const string& name) {
    FlowerBouquet*& bouquet = types[name];   // 尝试在map中获取，如果没有就新建一个

    if (!bouquet) {                          // 如果是NULL
        bouquet = new FlowerBouquet(name);  // 惰性初始化
    }
    return bouquet;
}

// 打印当前已创建的花束类型
void FlowerBouquet::printCurrentTypes() {
    if (!types.empty()) {
        cout << "已创建花束" << types.size() << "种" << endl;
        for (map<string, FlowerBouquet*>::iterator iter = types.begin(); iter != types.end(); ++iter) {
            cout << (*iter).first << " ";
        }
        cout << endl;
    }
}

// 用户初始化
User::User(const string& name) : name(name) {}

// 设置花束偏好
void User::setPreferredFlower(const string& flower) {
    preferredFlower = flower;
}

// 获取花束偏好
string User::getPreferredFlower() const {
    return preferredFlower;
}

// 设置默认收货地址
void User::setDefaultAddress(const string& address) {
    defaultAddress = address;
}

// 设置联系方式
void User::setContactNumber(const string& number) {
    contactNumber = number;
}

// 下单方法，应用用户设置的偏好和默认信息
void User::placeOrder(const string& flowerName) {
    cout << "用户 " << name << " 下单：" << endl;
    cout << "花束：" << flowerName << endl;
    cout << "花束偏好：" << preferredFlower << endl;
    cout << "默认收货地址：" << defaultAddress << endl;
    cout << "联系方式：" << contactNumber << endl;
}

// 测试惰性初始化模式的函数
void testLazyInitialization() {
    // 用户初始化
    User user1("Alice");
    User user2("Bob");

    // 用户设置花束偏好和默认信息
    user1.setPreferredFlower("玫瑰花");
    user1.setDefaultAddress("123 Main Street");
    user1.setContactNumber("555-1234");

    user2.setPreferredFlower("百合花");
    user2.setDefaultAddress("456 Oak Avenue");
    user2.setContactNumber("555-5678");

    // 用户下单，触发花束的惰性初始化
    FlowerBouquet::getFlowerBouquet("玫瑰花");
    FlowerBouquet::getFlowerBouquet("百合花");

    // 用户根据偏好下单
    user1.placeOrder(user1.getPreferredFlower());
    user2.placeOrder(user2.getPreferredFlower());
}
