#include <iostream>
using std::string;
using std::cout;
using std::endl;

// Ŀ��ӿ�
class FlowerInfo {
public:
    virtual std::string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual std::string getDescription() const = 0;
    virtual std::string getColor() const = 0;
};

// ��һ�����ܹ�Ӧ�̵�ԭʼ�ӿ�
class FlowerSupplier1 {
public:
    std::string getFlowerName() const {
        return "Supplier1 Flower";
    }

    double getFlowerPrice() const {
        return 0.0;  // �۸�Ĭ��Ϊ0.0������۸�̬����
    }

    std::string getFlowerDescription() const {
        return "Beautiful flower from Supplier1";
    }

    std::string getFlowerColor() const {
        return "Red";
    }
};

// ��һ�����ܹ�Ӧ�̵�������
class FlowerSupplierAdapter1 : public FlowerInfo {
private:
    FlowerSupplier1 source;
    double price;
    std::string name;
    std::string description;
    std::string color;

public:
    FlowerSupplierAdapter1(const FlowerSupplier1& supplier, double p, const std::string& n,
        const std::string& desc, const std::string& col)
        : source(supplier), price(p), name(n), description(desc), color(col) {}

    std::string getName() const override {
        return name.empty() ? source.getFlowerName() : name;
    }

    double getPrice() const override {
        return price;
    }

    std::string getDescription() const override {
        return description.empty() ? source.getFlowerDescription() : description;
    }

    std::string getColor() const override {
        return color.empty() ? source.getFlowerColor() : color;
    }
};

// �ڶ������ܹ�Ӧ�̵�ԭʼ�ӿ�
class FlowerSupplier2 {
public:
    std::string fetchFlower() const {
        return "Supplier2 Flower";
    }

    double getCost() const {
        return 0.0;  // �۸�Ĭ��Ϊ0.0������۸�̬����
    }

    std::string getFlowerDetails() const {
        return "Supplier2 provides high-quality flowers";
    }

    std::string getFlowerColor() const {
        return "Blue";
    }
};

// �ڶ������ܹ�Ӧ�̵�������
class FlowerSupplierAdapter2 : public FlowerInfo {
private:
    FlowerSupplier2 source;
    double price;
    std::string name;
    std::string description;
    std::string color;

public:
    FlowerSupplierAdapter2(const FlowerSupplier2& supplier, double p, const std::string& n,
        const std::string& desc, const std::string& col)
        : source(supplier), price(p), name(n), description(desc), color(col) {}

    std::string getName() const override {
        return name.empty() ? source.fetchFlower() : name;
    }

    double getPrice() const override {
        return price;
    }

    std::string getDescription() const override {
        return description.empty() ? source.getFlowerDetails() : description;
    }

    std::string getColor() const override {
        return color.empty() ? source.getFlowerColor() : color;
    }
};

void testAdaptor();




