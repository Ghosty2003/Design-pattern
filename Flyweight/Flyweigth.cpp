#include"Flyweight.h"
#include<iostream>
#include<string>

void testFlyweight()
{
    FlowerFactory flowerFactory;

    // 顾客1购买红色玫瑰
    Flower* redRose = flowerFactory.getFlower("Rose");
    redRose->display("Red");

    // 顾客2购买蓝色玫瑰
    Flower* blueRose = flowerFactory.getFlower("Rose");
    blueRose->display("Blue");

    // 顾客3购买红色郁金香
    Flower* redTulip = flowerFactory.getFlower("Tulip");
    redTulip->display("Red");

    // 顾客4购买白色郁金香
    Flower* whiteTulip = flowerFactory.getFlower("Tulip");
    whiteTulip->display("White");

    // 顾客5购买蓝色玫瑰
    Flower* anotherBlueRose = flowerFactory.getFlower("Rose");
    anotherBlueRose->display("Blue");

    // 释放资源，通过~FlowerFactory() 实现


}