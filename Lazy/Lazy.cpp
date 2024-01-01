#include <iostream>
#include <map>
#include <string>

using namespace std;

// ������
class FlowerBouquet {
private:
    string name;

    // ��̬��Ա���������ڴ洢�Ѵ����Ļ�������ͨ������������
    static map<string, FlowerBouquet*> types;

    // ˽�й��캯������ֱֹ�Ӵ�������
    FlowerBouquet(const string& name) : name(name) {}

public:
    // ��ȡ����ʵ���ľ�̬����
    static FlowerBouquet* getFlowerBouquet(const string& name);

    // ��ӡ��ǰ�Ѵ����Ļ�������
    static void printCurrentTypes();
};

// �û���
class User {
private:
    string name;
    string preferredFlower;
    string defaultAddress;
    string contactNumber;

public:
    // ���캯�����û���ʼ��ʱ��������
    User(const string& name);

    // ���û���ƫ��
    void setPreferredFlower(const string& flower);

    // ��ȡ����ƫ��
    string getPreferredFlower() const;

    // ����Ĭ���ջ���ַ
    void setDefaultAddress(const string& address);

    // ������ϵ��ʽ
    void setContactNumber(const string& number);

    // �µ�������Ӧ���û����õ�ƫ�ú�Ĭ����Ϣ
    void placeOrder(const string& flowerName);
};

// ��ʼ����̬��Ա����
map<string, FlowerBouquet*> FlowerBouquet::types;

// ��ȡ����ʵ���ľ�̬����
FlowerBouquet* FlowerBouquet::getFlowerBouquet(const string& name) {
    FlowerBouquet*& bouquet = types[name];   // ������map�л�ȡ�����û�о��½�һ��

    if (!bouquet) {                          // �����NULL
        bouquet = new FlowerBouquet(name);  // ���Գ�ʼ��
    }
    return bouquet;
}

// ��ӡ��ǰ�Ѵ����Ļ�������
void FlowerBouquet::printCurrentTypes() {
    if (!types.empty()) {
        cout << "�Ѵ�������" << types.size() << "��" << endl;
        for (map<string, FlowerBouquet*>::iterator iter = types.begin(); iter != types.end(); ++iter) {
            cout << (*iter).first << " ";
        }
        cout << endl;
    }
}

// �û���ʼ��
User::User(const string& name) : name(name) {}

// ���û���ƫ��
void User::setPreferredFlower(const string& flower) {
    preferredFlower = flower;
}

// ��ȡ����ƫ��
string User::getPreferredFlower() const {
    return preferredFlower;
}

// ����Ĭ���ջ���ַ
void User::setDefaultAddress(const string& address) {
    defaultAddress = address;
}

// ������ϵ��ʽ
void User::setContactNumber(const string& number) {
    contactNumber = number;
}

// �µ�������Ӧ���û����õ�ƫ�ú�Ĭ����Ϣ
void User::placeOrder(const string& flowerName) {
    cout << "�û� " << name << " �µ���" << endl;
    cout << "������" << flowerName << endl;
    cout << "����ƫ�ã�" << preferredFlower << endl;
    cout << "Ĭ���ջ���ַ��" << defaultAddress << endl;
    cout << "��ϵ��ʽ��" << contactNumber << endl;
}

// ���Զ��Գ�ʼ��ģʽ�ĺ���
void testLazyInitialization() {
    // �û���ʼ��
    User user1("Alice");
    User user2("Bob");

    // �û����û���ƫ�ú�Ĭ����Ϣ
    user1.setPreferredFlower("õ�廨");
    user1.setDefaultAddress("123 Main Street");
    user1.setContactNumber("555-1234");

    user2.setPreferredFlower("�ٺϻ�");
    user2.setDefaultAddress("456 Oak Avenue");
    user2.setContactNumber("555-5678");

    // �û��µ������������Ķ��Գ�ʼ��
    FlowerBouquet::getFlowerBouquet("õ�廨");
    FlowerBouquet::getFlowerBouquet("�ٺϻ�");

    // �û�����ƫ���µ�
    user1.placeOrder(user1.getPreferredFlower());
    user2.placeOrder(user2.getPreferredFlower());
}
