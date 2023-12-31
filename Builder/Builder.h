#include <string>
#include <memory>

// 订单对象信息类
class Order {
private:
    std::string flowerType;
    int quantity;
    std::string status;
    std::string occasion;           
    std::string packagingMaterial;  

public:
    void setFlowerType(const std::string& type);
    void setQuantity(int qty);
    void setStatus(const std::string& status);
    void setOccasion(const std::string& oc);       
    void setPackagingMaterial(const std::string& mat);
    std::string getInfo(); 
    std::string getGift(); 
};

// 创建订单的抽象接口
class OrderBuilder {
protected:
    std::shared_ptr<Order> order;

public:
    OrderBuilder() : order(std::make_shared<Order>()) {}
    virtual ~OrderBuilder() {}

    std::shared_ptr<Order> getOrder();

    virtual void buildFlowerType() = 0;
    virtual void buildQuantity() = 0;
    virtual void buildStatus() = 0;
    virtual void buildOccasion() = 0;
    virtual void buildPackagingMaterial() = 0;
};

// 具体的订单创建者
class RoseOrderBuilder : public OrderBuilder {
public:
    void buildFlowerType() override;
    void buildQuantity() override;
    void buildStatus() override;
    void buildOccasion() override;
    void buildPackagingMaterial() override;
};

class LilyOrderBuilder : public OrderBuilder {
public:
    void buildFlowerType() override;
    void buildQuantity() override;
    void buildStatus() override;
    void buildOccasion() override;
    void buildPackagingMaterial() override;
};

class BirthdayOrderBuilder : public OrderBuilder {
public:
    void buildFlowerType() override;
    void buildQuantity() override;
    void buildStatus() override;
    void buildOccasion() override;
    void buildPackagingMaterial() override;
};

class ValentineOrderBuilder : public OrderBuilder {
public:
    void buildFlowerType() override;
    void buildQuantity() override;
    void buildStatus() override ;
    void buildOccasion() override;
    void buildPackagingMaterial() override ;
};

// Director 类定义保持不变

// 导演类，指导具体订单的建造
class Director {
private:
    OrderBuilder* builder;

public:
    Director() : builder(nullptr) {}
    ~Director();

    void setBuilder(OrderBuilder* b);
    std::shared_ptr<Order> construct();
};

void testBuilder();
